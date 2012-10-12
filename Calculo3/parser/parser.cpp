#include "parser.h"

#include "parser/tokens.h"
#include "parser/exptree.h"
#include "parser/visitor.h"

#include <cstdio>

#include <iostream>
using namespace std;

Parser::Parser()
{
}

/*
    Tokens:
    var [a-Z]+
    num [0-9]+.[0-9]+


    Grammar:
    exp -> num
    exp -> var
    op -> ( exp op exp )
    fun -> fun( exp )
 */

Exp* Parser::parse(std::string exp) const
{
    //-------------------------------------------------
    // Lex
    //-------------------------------------------------
    std::list<Token*> tokens;

    int it = 0;

    int tokBegin = 0;

    TOKEN_TYPE tokType = TOKEN_NONE;

    while(it < exp.size()){

        if( exp.at(it) == ' ' ){
            it++;
            tokBegin = it;
        }

        // case characters
        if( isChar(exp.at(it)) )
        {
            // if sin
            if( exp.at(it) == 's' and exp.at(it+1) == 'i' and exp.at(it+2) == 'n')
            {
                tokType = TOKEN_SIN;
                it += 3;
            }

            // if cos
            if( exp.at(it) == 'c' and exp.at(it+1) == 'o' and exp.at(it+2) == 's')
            {
                tokType = TOKEN_COS;
                it += 3;
            }

            // else
            while( isChar(exp.at(it) ))
            {
                tokType = TOKEN_VARIABLE;
                it++;
            }

            tokens.push_back( new Token(tokType , exp.substr(tokBegin, it-tokBegin) ) );
            tokBegin = it;
        }

        if( isDigit(exp.at(it)))
        {
            while( isDigit(exp.at(it)) )
            {
                tokType = TOKEN_NUMBER;
                it++;
            }
            if( exp.at(it) == '.' )
            {
                //tokType = TOKEN_NUMBER;
                it++;

                while( isDigit(exp.at(it)) )
                {
                    //tokType = TOKEN_NUMBER;
                    it++;
                }
            }

            tokens.push_back( new Token( tokType , exp.substr(tokBegin, it-tokBegin) ) );
            tokBegin = it;
        }
        if( exp.at(it) == '+' )
        {
            tokens.push_back( new Token(TOKEN_OPADD, "+") );
            it += 1;
            tokBegin = it;
        }
        if( exp.at(it) == '-' )
        {
            tokens.push_back( new Token(TOKEN_OPSUB, "-") );
            it += 1;
            tokBegin = it;
        }
        if( exp.at(it) == '(' )
        {
            tokens.push_back( new Token(TOKEN_LPAREN, "(") );
            it += 1;
            tokBegin = it;
        }
        if( exp.at(it) == ')')
        {
            tokens.push_back( new Token(TOKEN_RPAREN, ")") );
            it += 1;
            tokBegin = it;
        }
    }

    //-------------------------------------------------
    // Exp
    //-------------------------------------------------

    //    for(std::list<Token*>::iterator it = tokens.begin(); it!= tokens.end(); it++ ){
    //        cout << (*it)->value << " " << (*it)->type << endl;
    //    }


    return buildExp(&tokens);
}

float Parser::eval(Exp *exp, SymbolTable *table)
{
    if(exp!=NULL){
        float ret;

        Visitor *visitor = new EvalVisitor;

        ret = visitor->visit(exp, table);

        delete visitor;

        return ret;
    }else{
        cout << "ERROR" << endl;
        return 0;
    }
}

Exp *Parser::buildExp(std::list<Token*> *token) const{
    if(token->front() == NULL) return NULL;
    Exp *newExp;
    Exp *auxExp, *auxExp2;
    float f;

    switch(token->front()->type){
    case TOKEN_SIN:
        // 'SIN'
        if( !eat( TOKEN_SIN , token ) ) return NULL;
        // '('
        if( !eat( TOKEN_LPAREN , token ) ) return NULL;

        // Exp
        auxExp = buildExp(token);
        if(auxExp == NULL){ return NULL; }
        newExp = new ExpSin( auxExp );

        // ')'
        if( !eat( TOKEN_RPAREN , token ) ) return NULL;
        break;

    case TOKEN_LPAREN:
        // '('
        if( !eat( TOKEN_LPAREN , token ) ) return NULL;

        auxExp = buildExp(token);
        if(auxExp == NULL){ return NULL; }

        switch( token->front()->type ){
        case TOKEN_OPADD:
            eat(TOKEN_OPADD, token);

            auxExp2 = buildExp(token);
            if(auxExp2 == NULL){ delete auxExp; return NULL; }

            newExp = new ExpAdd(auxExp,auxExp2);

            break;
        case TOKEN_OPSUB:
            eat(TOKEN_OPSUB, token);

            auxExp2 = buildExp(token);
            if(auxExp2 == NULL){ delete auxExp; return NULL; }

            newExp = new ExpSub(auxExp,auxExp2);

            break;
        default:
            //ERROR
            delete auxExp;
            return NULL;
            break;
        }

        // ')'
        if( !eat( TOKEN_RPAREN , token ) ) return NULL;
        break;
    case TOKEN_NUMBER:
        sscanf( token->front()->value.c_str() , "%f", &f);
        newExp = new ExpNumber( f );
        eat(TOKEN_NUMBER,token);
        break;
    case TOKEN_VARIABLE:
        newExp = new ExpVariable( token->front()->value );
        eat(TOKEN_VARIABLE,token);
        break;
    default:
        //ERROR
        return NULL;
        break;
    }

    return newExp;
}

bool Parser::eat(int type, std::list<Token*> *token ) const
{
    if(!token->empty() and (token->front() != NULL) )
    {
        delete token->front();
        token->pop_front();
        return true;
    }
    return false;
}

bool Parser::isChar(char c) const
{
    if( (c >= 'a' and c <= 'z') or (c >= 'A' and c <= 'Z') )
    {
        return true;
    }
    return false;
}

bool Parser::isDigit(char c) const
{
    if( c >= '0' and c <= '9' )
    {
        return true;
    }
    return false;
}

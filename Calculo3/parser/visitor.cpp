#include "visitor.h"

#include "parser/exptree.h"
#include "parser/symboltable.h"

#include <cmath>

#include <iostream>
using namespace std;

float EvalVisitor::visit(Exp *exp, SymbolTable *table){
    float left, right;

    switch (exp->type){
    case EXP_NUMBER:
        return ((ExpNumber*)exp)->value;
        break;
    case EXP_VARIABLE:
        return table->lookup(((ExpVariable*)exp)->value);
        break;
    case EXP_ADD:
        left = visit( ((ExpAdd*)exp)->left , table );
        right = visit( ((ExpAdd*)exp)->right , table );
        return (left + right);
        break;
    case EXP_SUB:
        left = visit( ((ExpAdd*)exp)->left , table );
        right = visit( ((ExpAdd*)exp)->right , table );
        return (left - right);
        break;
    case EXP_SIN:
        left = visit( ((ExpSin*)exp)->param ,table);
        return sin(left*M_PI/180);
        break;
    case EXP_COS:
        left = visit( ((ExpCos*)exp)->param ,table);
        return cos(left*M_PI/180);
        break;
    case EXP_TAN:
        left = visit( ((ExpTan*)exp)->param ,table);
        return tan(left*M_PI/180);
        break;
    case EXP_POW:
        left = visit( ((ExpPow*)exp)->left , table );
        right = visit( ((ExpPow*)exp)->right , table );
        return (pow(left,right));
        break;
    case EXP_DIV:
        left = visit( ((ExpDiv*)exp)->left , table );
        right = visit( ((ExpDiv*)exp)->right , table );
        return (left / right);
        break;
    case EXP_MULT:
        left = visit( ((ExpMult*)exp)->left , table );
        right = visit( ((ExpMult*)exp)->right , table );
        return (left * right);
        break;
    default:
        return 0;
        break;
    }
}

float PrintVisitor::visit(Exp *exp, SymbolTable *table){
    switch (exp->type){
    case EXP_NUMBER:
        cout << ((ExpNumber*)exp)->value;
        break;
    case EXP_VARIABLE:
        cout << ((ExpVariable*)exp)->value;
        break;
    case EXP_ADD:
        cout << "( ";
        visit( ((ExpAdd*)exp)->left , table );
        cout << " + ";
        visit( ((ExpAdd*)exp)->right , table );
        cout << " )";
        break;
    case EXP_SUB:
        cout << "( ";
        visit( ((ExpAdd*)exp)->left , table );
        cout << " - ";
        visit( ((ExpAdd*)exp)->right , table );
        cout << " )";
        break;
    case EXP_SIN:
        cout << "sin( ";
        visit( ((ExpSin*)exp)->param , table );
        cout << " )";
        break;
    case EXP_COS:
        cout << "cos( ";
        visit( ((ExpSin*)exp)->param , table );
        cout << " )";
        break;
    case EXP_TAN:
        cout << "tan( ";
        visit( ((ExpSin*)exp)->param , table );
        cout << " )";
        break;
    case EXP_POW:
        cout << "( ";
        visit( ((ExpAdd*)exp)->left , table );
        cout << " ^ ";
        visit( ((ExpAdd*)exp)->right , table );
        cout << " )";
        break;
    case EXP_DIV:
        cout << "( ";
        visit( ((ExpAdd*)exp)->left , table );
        cout << " / ";
        visit( ((ExpAdd*)exp)->right , table );
        cout << " )";
        break;
    case EXP_MULT:
        cout << "( ";
        visit( ((ExpAdd*)exp)->left , table );
        cout << " * ";
        visit( ((ExpAdd*)exp)->right , table );
        cout << " )";
        break;
    default:
        return 0;
        break;
    }
    return 0;
}

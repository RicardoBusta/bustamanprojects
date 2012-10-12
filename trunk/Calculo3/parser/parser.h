#ifndef PARSER_H
#define PARSER_H

#include "parser/symboltable.h"

#include <string>
#include <list>

class Token;
class Exp;

class Parser
{
public:
    Parser();

    Exp *parse(std::string exp) const;

    float eval(Exp*exp, SymbolTable *table);

    Exp* buildExp(std::list<Token*> *token) const;
    bool eat(int type, std::list<Token*> *token) const;

    bool isChar(char c) const;
    bool isDigit(char c) const;
};

#endif // PARSER_H

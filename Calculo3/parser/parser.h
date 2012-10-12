#ifndef PARSER_H
#define PARSER_H

#include "expression.h"

#include <string>
#include <list>

class Token;
class Exp;

class Parser
{
public:
    Parser();

    Exp* parse(std::string exp) const;

    Exp* buildExp(std::list<Token*> *token) const;
    void eat(TOKEN_TYPE type, std::list *token) const;

    bool isChar(char c) const;
    bool isDigit(char c) const;
};

#endif // PARSER_H

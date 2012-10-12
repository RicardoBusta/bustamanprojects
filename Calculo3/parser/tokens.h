#ifndef TOKENS_H
#define TOKENS_H

enum TOKEN_TYPE{TOKEN_NONE, TOKEN_NUMBER, TOKEN_VARIABLE, TOKEN_LPAREN, TOKEN_RPAREN, TOKEN_OPADD, TOKEN_OPSUB, TOKEN_SIN, TOKEN_COS};

#include <string>

class Token
{
public:
    TOKEN_TYPE type;

    std::string value;

    Token(TOKEN_TYPE type, std::string value){ this->type = type; this->value = value; }
};

#endif // TOKENS_H

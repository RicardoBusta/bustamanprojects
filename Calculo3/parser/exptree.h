#ifndef EXPTREE_H
#define EXPTREE_H

enum EXP_TYPE{EXP_NUMBER, EXP_VARIABLE, EXP_ADD, EXP_SUB, EXP_SIN, EXP_COS};

#include <string>

class Exp
{
public:
    EXP_TYPE type;

    Exp(EXP_TYPE type){ this->type = type; }
    virtual ~Exp(){}
};

class ExpNumber:public Exp
{
public:
    float value;

    ExpNumber(float value):Exp(EXP_NUMBER){ this->value = value; }
    ~ExpNumber(){}
};

class ExpVariable:public Exp
{
public:
    std::string value;

    ExpVariable(std::string value):Exp(EXP_VARIABLE){ this->value = value; }
    ~ExpVariable(){}
};

//Generic
class ExpOp:public Exp
{
public:
    Exp *left;
    Exp *right;

    ExpOp(Exp *left, Exp *right, EXP_TYPE type):Exp(type){ this->left = left; this->right = right; }
};

//Generic
class ExpFun:public Exp
{
public:
    Exp *param;

    ExpFun(Exp *param, EXP_TYPE type):Exp(type){ this->param = param; }
};

class ExpAdd:public ExpOp
{
public:
    ExpAdd(Exp *left, Exp *right):ExpOp(left, right, EXP_ADD){}
};

class ExpSub:public ExpOp
{
public:

    ExpSub(Exp *left, Exp *right):ExpOp(left,right, EXP_SUB){}
};

class ExpSin:public ExpFun
{
public:

    ExpSin(Exp *param):ExpFun(param, EXP_SIN){}
};

class ExpCos:public ExpFun
{
public:

    ExpCos(Exp *param):ExpFun(param, EXP_COS){}
};
#endif // EXPTREE_H

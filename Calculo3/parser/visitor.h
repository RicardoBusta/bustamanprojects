#ifndef VISITOR_H
#define VISITOR_H

class Exp;
class SymbolTable;

class Visitor
{
public:
    Visitor(){}
    ~Visitor(){}

    virtual float visit(Exp *exp, SymbolTable *table)=0;
};

class EvalVisitor:public Visitor
{
public:
    float visit(Exp *exp, SymbolTable *table);

    EvalVisitor():Visitor(){}
    ~EvalVisitor(){}
};

class PrintVisitor:public Visitor
{
public:
    float visit(Exp *exp, SymbolTable *table);

    PrintVisitor():Visitor(){}
    ~PrintVisitor(){}
};

#endif // VISITOR_H

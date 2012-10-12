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
    float visit(Exp *exp, SymbolTable *table) const;

    EvalVisitor():Visitor(){}
    ~EvalVisitor(){}
};

#endif // VISITOR_H

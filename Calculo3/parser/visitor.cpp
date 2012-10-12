#include "visitor.h"

#include "parser/exptree.h"
#include "parser/symboltable.h"

float EvalVisitor::visit(Exp *exp, SymbolTable *table) const{
    float left, right;

    switch (exp->type){
        case EXP_NUMBER:
            return ((ExpNumber*)exp)->value;
            break;
        case EXP_VARIABLE:
            return table->lookup(((ExpVariable*)exp)->value);
            break;
        case EXP_ADD:
            left = visit((((ExpAdd*)exp)->left),table);
            right = visit((((ExpAdd*)exp)->right),table);
            return (left + right);
            break;
        case EXP_SUB:
            left = visit((((ExpAdd*)exp)->left),table);
            right = visit((((ExpAdd*)exp)->right),table);
            return (left - right);
            break;
        default:
            return 0;
            break;
    }
}

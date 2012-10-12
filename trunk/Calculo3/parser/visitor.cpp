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
    default:
        return 0;
        break;
    }
}

float PrintVisitor::visit(Exp *exp, SymbolTable *table){
    switch (exp->type){
    case EXP_NUMBER:
        cout << ((ExpNumber*)exp)->value << "x";
        break;
    case EXP_VARIABLE:
        cout << table->lookup(((ExpVariable*)exp)->value);
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
    default:
        return 0;
        break;
    }
    return 0;
}

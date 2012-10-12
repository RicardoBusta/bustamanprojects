#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <string>
#include <map>

class SymbolTable
{
public:
    SymbolTable(){}

    std::map<std::string,float> symbol;

    void setValue(std::string id, float val);

    float lookup(std::string id){
        if(symbol.count(id)>0){
            return symbol.at(id);
        }else{
            return 0;
        }
    }
};

#endif // SYMBOLTABLE_H

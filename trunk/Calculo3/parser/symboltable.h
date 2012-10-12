#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <string>
#include <map>

class SymbolTable
{
public:
    SymbolTable();

    std::map<std::string,float> symbol;

    float lookup(std::string id){
        if(symbol.at(id)){
            return symbol.at(id);
        }else{
            return 0;
        }
    }
};

#endif // SYMBOLTABLE_H

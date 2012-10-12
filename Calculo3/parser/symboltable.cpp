#include "symboltable.h"


void SymbolTable::setValue(std::string id, float val)
{
    symbol[id] = val;
}

//**************************************
// cSymbolTable.h
//
// Defines a nested symbol table.
// Individual levels of the symbol table use a std::unordered_map from the STL
//
// Author: Jiawei Xu
// Jiawei.xu@oit.edu
//
//

#include "cSymbolTable.h"
#include <iostream>

using std::pair;


/*
* Name: cSymbolTable
* Description:
*   -> Constructor for Symbol table, since the stack starts with no scope,
*   -> thus it needs to increase it's scope upon initialization.
*/
cSymbolTable::cSymbolTable() {
    IncreaseScope();
}

/*
* Name: IncreaseScope
* Description:
*   -> Add a table to the stack of symbol table
*   -> representing begining of scope
*/
symbolTable_t* cSymbolTable::IncreaseScope() {
    symbolTable_t* newTable = new symbolTable_t();
    _default.push(newTable);
    return newTable;
}

/*
* Name: DecreaseScope
* Description:
*   -> remove a table to the stack of symbol table
*   -> representing end of scope
*/
symbolTable_t* cSymbolTable::DecreaseScope() {
    symbolTable_t* prevST = nullptr;
    if (!_default.empty()) {
        prevST = _default.top();
        _default.pop();
    }
    return prevST;
}

/*
* Name: Insert
* Description:
*   -> Insert a symbol into the current table
*/
void cSymbolTable::Insert(cSymbol *sym) {
    _default.top()->insert(pair<string, cSymbol*>(sym->GetName(), sym));
}

/*
* Name: Find
* Description:
*   -> Traverse the stack of tables to search for a symbol
*/
cSymbol* cSymbolTable::Find(string name) {
    stack<symbolTable_t*> tmp = _default;
    for(unsigned int i = tmp.size(); i > 0; --i) {
        symbolTable_t* tmpTable = tmp.top();
        symbolTable_t::iterator it;
        it = tmpTable->find(name);
        if (it == tmpTable->end()) {
            tmp.pop();
        } else {
            return it->second;
        }
    }
    return nullptr;
}

/*
* Name: FindLocal
* Description:
*   -> Traverse the current table to search for a symbol
*/
cSymbol* cSymbolTable::FindLocal(string name) {
    cSymbol* result = nullptr;
    if (!_default.empty()) {
        symbolTable_t* tmp = _default.top();
        symbolTable_t::iterator it;
        it = tmp->find(name);
        if (it != tmp->end())
            result = it->second;
    }
    return result;
}
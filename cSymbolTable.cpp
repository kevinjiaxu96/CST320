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

void cSymbolTable::InitTable() {
    cSymbol *ctype = new cSymbol("char");
    cSymbol *iype = new cSymbol("int");
    cSymbol *fype = new cSymbol("float");
    Insert(ctype);
    Insert(iype);
    Insert(fype);
}

/*
* Name: IncreaseScope
* Description:
*   -> Add a table to the stack of symbol table
*   -> representing begining of scope
*/
symbolTable_t* cSymbolTable::IncreaseScope() {
    symbolTable_t* newTable = new symbolTable_t();
    _default.push_back(newTable);
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
        prevST = _default.back();
        _default.pop_back();
    }
    return prevST;
}

/*
* Name: Insert
* Description:
*   -> Insert a symbol into the current table
*/
void cSymbolTable::Insert(cSymbol *sym) {
    _default.back()->insert(pair<string, cSymbol*>(sym->GetName(), sym));
}

/*
* Name: Find
* Description:
*   -> Traverse the stack of tables to search for a symbol
*/
cSymbol* cSymbolTable::Find(string name) {
    vector<symbolTable_t*>::iterator it;
    for(it = _default.begin(); it != _default.end(); ++it)
    {
        symbolTable_t* tmpTable = *it;
        symbolTable_t::iterator sit;
        sit = tmpTable->find(name);
        if (sit != tmpTable->end())
        {
            return sit->second;
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
        symbolTable_t* tmp = _default.back();
        symbolTable_t::iterator it;
        it = tmp->find(name);
        if (it != tmp->end())
            result = it->second;
    }
    return result;
}
#pragma once
//**************************************
// cSymbolTable.h
//
// Defines a nested symbol table.
// Individual levels of the symbol table use a std::unordered_map from the STL
//
// Author: Phil Howard 
// phil.howard@oit.edu
//
//

#include "cSymbol.h"
#include <vector>
#include <unordered_map>
#include "cBaseTypeNode.h"
using std::vector;
using std::unordered_map;
class cSymbolTable
{
    public:
        class symbolTable_t
        {
            public:
                symbolTable_t() : m_table()
                {}
                cSymbol *Find(string name)
                {
                    std::unordered_map<string, cSymbol*>::iterator ifExist = m_table.find(name);
                    if (ifExist == m_table.end())
                        return nullptr;
                    else
                        return ifExist->second;
                }
                void Insert(cSymbol *sym)
                {
                    std::pair<string, cSymbol*> new_val(sym->GetName(), sym);
                    m_table.insert(new_val);
                }
            protected:
                std::unordered_map<string, cSymbol*> m_table;
        };
        // Create a symbol table
        cSymbolTable()
        {
            IncreaseScope();
        }

        void InitTable()
        {
            cSymbol *baseType;

            baseType = new cSymbol("char");
            baseType->SetIsType(true);
            baseType->SetDecl(new cBaseTypeNode(baseType->GetName(), 1, false));
            Insert(baseType);

            baseType = new cSymbol("int");
            baseType->SetIsType(true);
            baseType->SetDecl(new cBaseTypeNode(baseType->GetName(), 4, false));
            Insert(baseType);

            baseType = new cSymbol("float");
            baseType->SetIsType(true);
            baseType->SetDecl(new cBaseTypeNode(baseType->GetName(), 8, true));
            Insert(baseType);
        }
        // Increase the scope: add a level to the nested symbol table
        // Return value is the newly created scope
        symbolTable_t *IncreaseScope()
        {
            symbolTable_t *table = new symbolTable_t();
            _default.push_back(table);
            return table;
        }

        // Decrease the scope: remove the outer-most scope.
        // Returned value is the outer-most scope AFTER the pop.
        //
        // NOTE: do NOT clean up memory after poping the table. Parts of the
        // AST will probably contain pointers to symbols in the popped table.
        symbolTable_t *DecreaseScope()
        {
            _default.pop_back();
            return _default.back();
        }

        // insert a symbol into the table
        // Assumes the symbol is not already in the table
        void Insert(cSymbol *sym)
        {
            _default.back()->Insert(sym);
        }

        // Do a lookup in the nested table. 
        // Return the symbol for the outer-most match. 
        // Returns nullptr if no match is found.
        cSymbol *Find(string name)
        {
            cSymbol *sym = nullptr;

            for(vector<symbolTable_t*>::reverse_iterator rit = _default.rbegin();
                rit != _default.rend(); ++rit)
            {
                sym = (*rit)->Find(name);
                if (sym != nullptr) return sym;
            }
            return nullptr;
        }

        // Find a symbol in the outer-most scope.
        // NOTE: does not search nested scopes, only the outermost scope.
        // Return the symbol if found.
        // Returns nullptr if the symbol is not found.
        cSymbol *FindLocal(string name)
        {
            return _default.back()->Find(name);
        }
        static cSymbol *FindInTable(symbolTable_t *table, string& name)
        {
            return table->Find(name);
        }
    private:
        vector<symbolTable_t*> _default;
};

// Declaration for the global symbol table.
// Definition is in main.cpp
extern cSymbolTable g_SymbolTable;

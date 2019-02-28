#pragma once
//**************************************
// cStructDeclNode.h
//
// Defines AST node for a struct declaration
//
// Inherits from cDeclNode because this is a type of declaration
//
// Author: Phil Howard 
// phil.howard@oit.edu
//

#include "cAstNode.h"
#include "cDeclNode.h"
#include "cDeclsNode.h"
#include "cSymbol.h"
#include "cSymbolTable.h"

class cStructDeclNode : public cDeclNode
{
    public:
        // params are: 
        //     the symbol table for the declarations that make up this struct
        //     the declarations that make up this struct
        //     the cSymbol for the name of the struct
        cStructDeclNode(cSymbolTable::symbolTable_t *symTbl, 
                        cDeclsNode *decls, 
                        cSymbol *struct_id)
            : cDeclNode()
        {
            cSymbol *name;

            AddChild(decls);
            m_symTbl = symTbl;

            // Figure out if the ID we were passed already exists in the 
            // local symbol table. 
            name = g_SymbolTable.FindLocal(struct_id->GetName());
            if (name == nullptr)
            {
                // No: this is good. A later lab will cause an error if it does
                name = struct_id;

                // If the symbol exists in an outer scope, we need to create
                // a new one instead of re-using the symbol from the outer scope
                if (g_SymbolTable.Find(struct_id->GetName()) != nullptr)
                {
                    name = new cSymbol(struct_id->GetName());
                }

                name->SetIsType(true);

                // insert the name of the struct into the global symbol table
                g_SymbolTable.Insert(name);
            }

            AddChild(name);
        }
        virtual bool IsStruct() { return true; }
        virtual bool IsType()   { return true; }
        virtual string GetName() 
        { 
            cSymbol* name = dynamic_cast<cSymbol*>(GetChild(1));

            return name->GetName(); 
        }

        // return a pointer to a field.
        // returns nullptr if the field does not exist.
        cSymbol* GetField(string name)
        {
            cSymbol* field = cSymbolTable::FindInTable(m_symTbl, name);
            return field;
        }
        // return the symbol for the declaration of the type.
        // Since this IS a type, return our self
        virtual cDeclNode* GetType() { return this; }
        virtual string NodeType() { return string("struct_decl"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
    protected:
        cSymbolTable::symbolTable_t *m_symTbl; 

};

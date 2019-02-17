#pragma once
//**************************************
// cVarDeclNode.h
//
// Defines an AST node for an integer constant (literals).
//
// Inherits from cExprNode so that integer constants can be used anywhere 
// expressions are used.
//
// Author: Jiawei Xu
//

#include "cAstNode.h"
#include "cDeclNode.h"
#include "cSymbolTable.h"
#include <iostream>

class cVarDeclNode : public cDeclNode
{
    public:
        cVarDeclNode(cSymbol* decl, cSymbol* decl2) : cDeclNode()
        {
            if (!g_SymbolTable.Find(decl->GetName()))
            {
                g_SymbolTable.Insert(decl);
            }
            if (!g_SymbolTable.FindLocal(decl2->GetName()))
            {
                g_SymbolTable.Insert(decl2);
            }
            AddChild(decl);
            AddChild(decl2);
        }
        virtual string NodeType() { return string("var_decl"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};

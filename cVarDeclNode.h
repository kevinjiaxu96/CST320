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
        cVarDeclNode(cSymbol* typeID, cSymbol* iden) : cDeclNode()
        {
            cSymbol *ifTypeExist = g_SymbolTable.Find(typeID->GetName());
            cSymbol *ifIdenExist = g_SymbolTable.FindLocal(iden->GetName());
            if (!ifTypeExist)
            {
                ifTypeExist = typeID;
                g_SymbolTable.Insert(ifTypeExist);
            }
            if (!ifIdenExist)
            {
                ifIdenExist = iden;
                g_SymbolTable.Insert(ifIdenExist);
            }
            AddChild(ifTypeExist);
            AddChild(ifIdenExist);
        }
        virtual string NodeType() { return string("var_decl"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};

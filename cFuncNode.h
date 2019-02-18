#pragma once
//**************************************
// cFuncNode.h
//
// Defines an AST node for an integer constant (literals).
//
// Inherits from cExprNode so that integer constants can be used anywhere 
// expressions are used.
//
// Author: Jiawei Xu
//

#include "cAstNode.h"
#include "cDeclsNode.h"
#include "cDeclNode.h"
#include "cStmtsNode.h"

class cFuncNode : public cDeclNode
{
    public:
        cFuncNode(cSymbol* typeId, cSymbol* identifier) : cDeclNode()
        {
            cSymbol* isTypeExist = g_SymbolTable.Find(typeId->GetName());
            cSymbol* isIdenExist = g_SymbolTable.Find(identifier->GetName());
            if (!isTypeExist)
            {
                isTypeExist = typeId;
                g_SymbolTable.Insert(isTypeExist);
            }
            if (!isIdenExist)
            {
                isIdenExist = identifier;
                g_SymbolTable.Insert(isIdenExist);
            }
            AddChild(isTypeExist);
            AddChild(isIdenExist);
        }
        virtual string NodeType() { return string("func"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};

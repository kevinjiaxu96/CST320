#pragma once
//**************************************
// cFunCallNode.h
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

class cFunCallNode : public cExprNode
{
    public:
        cFunCallNode(cSymbol* iden) : cExprNode()
        {
            AddChild(iden);
        }
        cFunCallNode(cSymbol* iden, cDeclNode* param) : cExprNode()
        {
            cSymbol* isExist = g_SymbolTable.Find(iden->GetName());
            if (!isExist) {
                isExist = iden;
            }
            AddChild(isExist);
            AddChild(param);
        }
        cFunCallNode(cSymbol* iden, cDeclsNode* params) : cExprNode()
        {
            cSymbol* isExist = g_SymbolTable.Find(iden->GetName());
            if (!isExist) {
                isExist = iden;
            }
            AddChild(isExist);
            AddChild(params);
        }
        virtual cDeclNode * GetType() { 
            return dynamic_cast<cSymbol*>(GetChild(0))->GetDecl(); 
        }
        virtual string NodeType() { return string("funcCall"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};

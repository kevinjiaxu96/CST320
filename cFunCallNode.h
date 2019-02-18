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

class cFunCallNode : public cStmtNode
{
    public:
        cFunCallNode(cSymbol* iden) : cStmtNode()
        {
            AddChild(iden);
        }
        cFunCallNode(cSymbol* iden, cDeclNode* param) : cStmtNode()
        {
            cSymbol* isExist = g_SymbolTable.Find(iden->GetName());
            if (!isExist) {
                isExist = iden;
            }
            AddChild(isExist);
            AddChild(param);
        }
        cFunCallNode(cSymbol* iden, cDeclsNode* params) : cStmtNode()
        {
            cSymbol* isExist = g_SymbolTable.Find(iden->GetName());
            if (!isExist) {
                isExist = iden;
            }
            AddChild(isExist);
            AddChild(params);
        }
        virtual string NodeType() { return string("funcCall"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};

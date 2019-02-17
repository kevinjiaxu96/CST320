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
        cFunCallNode(cDeclNode* param=nullptr) : cStmtNode()
        {
            if (param) AddChild(param);
        }
        virtual string NodeType() { return string("func"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};

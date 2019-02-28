#pragma once
//**************************************
// cRetNode.h
//
// Defines an AST node for an integer constant (literals).
//
// Inherits from cExprNode so that integer constants can be used anywhere 
// expressions are used.
//
// Author: Jiawei Xu
//

#include "cAstNode.h"
#include "cStmtNode.h"
#include "cExprNode.h"

class cReturnNode : public cStmtNode
{
public:
    cReturnNode(cExprNode *expr) : cStmtNode()
    {
        AddChild(expr);
    }
    virtual string NodeType() { return string("return"); }
    virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
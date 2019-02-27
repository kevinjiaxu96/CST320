#pragma once
//**************************************
// cWhileNode.h
//
// Defines an AST node for an integer constant (literals).
//
// Inherits from cExprNode so that integer constants can be used anywhere 
// expressions are used.
//
// Author: Jiawei Xu
//

#include "cAstNode.h"
#include "cExprNode.h"
#include "cStmtNode.h"

class cWhileNode : public cStmtNode
{
public:
    cWhileNode(cExprNode *expr, cStmtNode *stmt) : cStmtNode()
    {
        AddChild(expr);
        AddChild(stmt);
    }
    virtual string NodeType() { return string("while"); }
    virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
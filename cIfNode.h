#pragma once
//**************************************
// cIfNode.h
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

class cIfNode : public cStmtNode
{
public:
    cIfNode(cExprNode *expr, cStmtsNode *stmts, cStmtsNode *elstmts) : cStmtNode()
    {
        AddChild(expr);
        AddChild(stmts);
        AddChild(elstmts);
    }
    virtual string NodeType() { return string("if"); }
    virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
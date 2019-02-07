#pragma once
//**************************************
// cIntExprNode.h
//
// Defines an AST node for an arithmetic expression.
//
// Inherits from cExprNode so that integer constants can be used anywhere 
// expressions are used.
//
// Author: Jiawei.xu
// jiawei.xu@oit.edu
//

#include "cAstNode.h"
#include "cExprNode.h"

class cBinExprNode : public cExprNode
{
public:
    cBinExprNode(cExprNode *child=nullptr) : cExprNode() 
    {
        if (child) AddChild(child);
    }
    virtual string NodeType() { return string("expr");}
    virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
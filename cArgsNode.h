#pragma once
//**************************************
// cArgNode.h
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
#include "cDeclsNode.h"

class cArgsNode : public cDeclsNode
{
public:
    cArgsNode(cDeclNode *decl) : cDeclsNode()
    {
        AddChild(decl);
    }
    virtual string NodeType() { return string("args"); }
    virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
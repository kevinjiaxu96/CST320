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

class cParamsNode : public cDeclsNode
{
    public:
        cParamsNode(cDeclNode* typeId) : cDeclsNode()
        {
            AddChild(typeId);
        }
        virtual string NodeType() { return string("params"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};

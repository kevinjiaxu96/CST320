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
            AddChild(typeId);
            AddChild(identifier);
        }
        virtual string NodeType() { return string("func"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};

#pragma once
//**************************************
// cVarRefNode.h
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
#include "cSymbolTable.h"

class cVarRefNode : public cExprNode
{
    public:
        cVarRefNode(cSymbol* sym) : cExprNode()
        {
            AddChild(sym);
        }
        virtual string NodeType() { return string("varref"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};

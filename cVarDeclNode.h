#pragma once
//**************************************
// cVarDeclNode.h
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
#include "cSymbolTable.h"

class cVarDeclNode : public cDeclNode
{
    public:
        cVarDeclNode(cDeclNode* decl) : cDeclNode()
        {
            AddChild(decl);
        }
        virtual string NodeType() { return string("var_decl"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};

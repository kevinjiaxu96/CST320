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
#include "cParamNode.h"

class cParamsNode : public cDeclsNode
{
    public:
        cParamsNode() : cDeclsNode()
        {
            
        }
        cParamsNode(cDeclNode* typeId) : cDeclsNode()
        {
            AddChild(typeId);
        }
        void InsertParam(cParamNode *param)
        {
            AddChild(param);
        }
        virtual string NodeType() { return string("params"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};

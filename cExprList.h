#pragma once
//**************************************
// cExprListNode.h
//
// Defines AST node for list of expressions
//
// Author: Jiawei Xu

#include "cAstNode.h"
#include "cExprNode.h"

class cExprListNode : public cAstNode
{
    public:
        // param is first actual param passed to function
        cExprListNode(cExprNode *param = nullptr)
            : cAstNode()
        {
            if (param != nullptr) AddChild(param);
        }

        int NumExpressions() { return NumChildren(); }
        cExprNode *GetExpr(int index) 
        {
            return dynamic_cast<cExprNode*>(GetChild(index));
        }
        virtual string NodeType() { return string("exprList"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};

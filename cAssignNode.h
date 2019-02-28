#pragma once
//**************************************
// cAssignNode.h
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
#include "cStmtNode.h"
#include "cVarExprNode.h"

class cAssignNode : public cStmtNode
{
public:
    cAssignNode(cVarExprNode *lval, cExprNode *expr) : cStmtNode() 
    {
        if (expr && expr->GetType() && lval && lval->GetType())
        {   
            if (lval->GetType()->IsChar())
            {
                if (expr->GetType()->IsInt() && !expr->GetType()->IsChar())
                    SemanticError("Cannot assign int to char");
                else if (expr->GetType()->IsFloat())
                    SemanticError("Cannot assign float to char");
            }
            else if (lval->GetType()->IsInt())
            {
                if (expr->GetType()->IsFloat())
                    SemanticError("Cannot assign float to int");
            }
            AddChild(lval);
            AddChild(expr);
        }
    }
    virtual string NodeType() { return string("assign");}
    virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
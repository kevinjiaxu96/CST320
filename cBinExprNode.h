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
#include "cOpNode.h"

class cBinExprNode : public cExprNode
{
public:
    cBinExprNode(cExprNode *left, int op, cExprNode *right) : cExprNode() 
    {
        m_left = left;
        m_right = right;
        AddChild(left);
        AddChild(new cOpNode(op));
        AddChild(right);
    }
    virtual cDeclNode * GetType()
    {
        if (m_left->GetType()->IsFloat())
            return m_left->GetType();
        else if (m_right->GetType()->IsFloat())
            return m_right->GetType();
        else if (m_left->GetType()->IsInt() && m_right->GetType()->IsChar())
            return m_right->GetType();
        else if (m_left->GetType() == m_right->GetType())
            return m_left->GetType();
        return g_SymbolTable.Find("int")->GetDecl();
    }
    virtual string NodeType() { return string("expr");}
    virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
protected:
    cExprNode *m_left;
    cExprNode *m_right;
};
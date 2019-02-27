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

class cVarExprNode : public cExprNode
{
    public:
        cVarExprNode(cSymbol* sym) : cExprNode()
        {
            cSymbol* isExist = g_SymbolTable.FindLocal(sym->GetName());
            if (!isExist)
            {
                isExist = g_SymbolTable.Find(sym->GetName());
                if (!isExist)
                {
                    SemanticError("Symbol " + sym->GetName() + " not defined");
                }
            }
            if (isExist)
            {
                AddChild(isExist);
                m_name = isExist;
            }
        }
        void InsertExpr(cExprNode* expr)
        {
            AddChild(expr);
        }
        void InsertVarpart(cSymbol* sym)
        {
            AddChild(sym);
        }
        virtual cDeclNode *GetType() 
        { 
            if (m_name)
                return m_name->GetDecl(); 
            return nullptr;
        }
        virtual string NodeType() { return string("varref"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
    protected:
        cSymbol *m_name;
};

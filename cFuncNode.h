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
#include <iostream>

class cFuncNode : public cDeclNode
{
    public:
        cFuncNode(cSymbol* typeId, cSymbol* identifier) : cDeclNode()
        {
            cSymbol* isTypeExist = g_SymbolTable.Find(typeId->GetName());
            cSymbol* isIdenExist = g_SymbolTable.Find(identifier->GetName());
            if (!isTypeExist)
            {
                isTypeExist = typeId;
                g_SymbolTable.Insert(isTypeExist);
            }
            if (!isIdenExist)
            {
                isIdenExist = identifier;
                g_SymbolTable.Insert(isIdenExist);
            }
            if (isTypeExist)
            {
                m_id = isTypeExist;
                AddChild(isTypeExist);
            }
            if (isIdenExist)
            {
                isIdenExist->SetDecl(this);
                AddChild(isIdenExist);
            }
        }
        void InsertParams(cDeclsNode *params)
        {
            AddChild(params);
        }
        void InsertStmts(cStmtsNode *stmts)
        {
            AddChild(stmts);
        }
        void InsertDecls(cDeclsNode *decls)
        {
            AddChild(decls);
        }
        virtual bool IsInt()  { return m_id->GetDecl()->IsInt(); }
        virtual bool IsFloat() { return m_id->GetDecl()->IsFloat(); }
        virtual bool IsChar() { return m_id->GetDecl()->IsChar(); }
        virtual bool IsFunc() { return true; }
        virtual cDeclNode* GetType() { 
            return m_id->GetDecl();
        }
        virtual string NodeType() { return string("func"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
    protected:
        cSymbol * m_id;
};

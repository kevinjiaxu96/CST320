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

class cFuncDeclNode : public cDeclNode
{
    public:
        cFuncDeclNode(cSymbol* typeId, cSymbol* iden) : cDeclNode()
        {
            cDeclNode *decl;
            cFuncDeclNode *funcDecl;
            m_isDefinition = false;
            m_id = typeId;
            m_hasParams = false;
            AddChild(typeId);
            AddChild(iden);
            AddChild(nullptr); // params
            AddChild(nullptr); // local vars
            AddChild(nullptr); // stmts

            cSymbol* ifFound = g_SymbolTable.Find(iden->GetName());
            if (ifFound != nullptr)
            {
                decl = ifFound->GetDecl();
                if (!decl->IsFunc())
                {
                    SemanticError(iden->GetName() + 
                    "previously defined as other than a function");
                }
                else
                {
                    funcDecl = dynamic_cast<cFuncDeclNode*>(decl);
                    if (funcDecl->GetType() != typeId->GetDecl())
                    {
                        SemanticError(iden->GetName() + 
                            " previously defined with different return type");
                    }
                    else
                    {
                        for (int ii = 0; ii < NumChildren(); ii++)
                        {
                            SetChild(ii, funcDecl->GetChild(ii));
                            m_isDefinition = funcDecl->m_isDefinition;
                            m_hasParams = funcDecl->m_hasParams;
                            iden->SetDecl(this);
                        }
                    }
                }
            }
            else
            {
                iden->SetDecl(this);
                g_SymbolTable.Insert(iden);
            }
        }
        void InsertParams(cDeclsNode *params)
        {
            cDeclsNode *o_Params = GetParams();
            if (m_hasParams && (params != nullptr || o_Params != nullptr))
            {
                if ( (params != nullptr && o_Params == nullptr) ||
                     (params == nullptr && o_Params != nullptr) ||
                     (params->ChildCount() != o_Params->ChildCount()) )
                {
                    SemanticError(GetName() + 
                        " redeclared with a different number of parameters");
                    return;
                }

                for (int ii=0; ii<params->ChildCount(); ii++)
                {
                    cDeclNode *decl1 = params->GetDecl(ii);
                    cDeclNode *decl2 = o_Params->GetDecl(ii);

                    assert(decl1 != nullptr && decl2 != nullptr);
                    if (decl1->GetType() != decl2->GetType())
                    {
                        SemanticError(GetName() +
                            " previously defined with different parameters");
                        return;
                    }
                }
            }
            SetChild(2, params);
            m_hasParams = true;
        }
        void InsertStmts(cStmtsNode *stmts)
        {
            if (m_isDefinition)
            {
                SemanticError(GetName() + " already has a definition");
            }
            else
            {
                m_isDefinition = true;
                SetChild(4, stmts);
            }
        }
        void InsertDecls(cDeclsNode *decls)
        {
            SetChild(3, decls);
        }
        bool IsDefinition()
        {
            return m_isDefinition;
        }
        cDeclsNode *GetParams()
        {
            return (cDeclsNode *)GetChild(2);
        }
        virtual string GetName()
        {
            cSymbol* name = dynamic_cast<cSymbol*>(GetChild(1));
            return name->GetName();
        }
        virtual bool IsInt()  { return m_id->GetDecl()->IsInt(); }
        virtual bool IsFloat() { return m_id->GetDecl()->IsFloat(); }
        virtual bool IsChar() { return m_id->GetDecl()->IsChar(); }
        virtual bool IsFunc() { return true; }
        virtual cDeclNode *GetType() 
        { 
            return m_id->GetDecl(); 
        }
        virtual string NodeType() { return string("func"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
    protected:
        bool m_isDefinition;
        bool m_hasParams;
        cSymbol * m_id;
};

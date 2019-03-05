#pragma once
//**************************************
// cSizeComputer.h
//
// Visitor implementation to compute size and offset of symbols, this class inherits from 
// cVisitor
//
// Author: Jiawei Xu 
//

#include "astnodes.h"
#include "cVisitor.h"
#include <iostream>

#define WORD_SIZE 4

class cSizeComputer : public cVisitor
{
    public:
        cSizeComputer() : cVisitor()
        { 
            m_offset = 0;
            m_size = 0;
            m_isParams = false;
        }
        virtual void VisitAllNodes(cAstNode* node) 
        { 
            node->Visit(this); 
        }
        virtual void Visit(cBlockNode *node)
        {
            int old_offset = m_offset;
            int old_size = m_size;
            m_size = 0;
            VisitAllChildren(node);
            node->SetSize(RoundUp(m_size));
            m_offset = old_offset;
            m_size = old_size;
        }
        virtual void Visit(cVarDeclNode* node)
        {
            cDeclNode *type = node->GetType();
            int size = type->Sizeof();
            node->SetSize(RoundUp(size));
            node->SetOffset(RoundUp(m_offset));
            cSymbol *var = nullptr;
            for (int i = 0; i < node->NumDecls(); ++i)
            {
                var = node->GetVar(i);
                var->SetSize(size);
                if (size > 1 || m_isParams) {
                    m_size = RoundUp(m_size);
                    m_offset = RoundUp(m_offset);
                }
                var->SetOffset(m_offset);
                if (m_isParams)
                {
                    m_offset -= size;
                    m_size += size;
                }
                else
                {
                    m_offset += size;
                    m_size += size;
                }
            }
        }
        virtual void Visit(cDeclsNode* node)
        {
            VisitAllChildren(node);
            node->SetSize(m_size);
        }
        // virtual void Visit(cFuncDeclNode *node)
        // {
        //     int old_offset = m_offset;
        //     cSymbol *name = node->GetNameSym();
        //     name->SetOffset(0);
        //     name->SetSize(node->GetType()->Sizeof());
        //     cDeclsNode *params = node->GetParams();
        //     if (params != nullptr)
        //     {
        //         m_offset = -12;
        //         m_isParams = true;
        //         VisitAllChildren(params);
        //         node->SetParamSize(-(RoundUp(m_offset) + 12));
        //         m_isParams;
        //     }
        //     cStmtsNode *stmts = node->GetStmts();
        //     if (stmts != nullptr)
        //     {
        //         m_offset = 4;
        //         stmts->Visit(this);
        //     }
        //     m_offset = old_offset;
        // }
        virtual void Visit(cFuncExprNode *node)
        {
            cSymbol *name = node->GetNameSym();
            if (name != nullptr)
            {
                node->SetParamSize(name->GetDecl()->GetParamSize());
            }
            VisitAllChildren(node);
        }
        // virtual void Visit(cVarExprNode *node)
        // {
        //     cSymbol *sym = node->GetNameSymbol();
        //     node->SetSize(sym->GetSize());
        //     node->SetOffset(sym->GetOffset());
        //     VisitAllChildren(node);
        // }
    protected:
        int m_offset;
        int m_size;
        bool m_isParams;

        int RoundUp(int value)
        {
            if (value % WORD_SIZE == 0) return value;
            if (m_isParams)
                return value - WORD_SIZE - value % WORD_SIZE;
            else
                return value + WORD_SIZE - value % WORD_SIZE;
        }
};

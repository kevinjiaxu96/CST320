#pragma once
//**************************************
// cComputeSize.h
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

class cComputeSize : public cVisitor
{
    public:
        cComputeSize() : cVisitor()
        { 
            m_offset = 0;
            m_highwater = 0;
            is_Params = false;
        }
        virtual void VisitAllNodes(cAstNode* node) 
        { 
            node->Visit(this); 
        }
        virtual void Visit(cProgramNode *node)
        {
            VisitAllChildren(node);
        }
        virtual void Visit(cBlockNode *node)
        {
            VisitAllChildren(node);
            node->SetSize(m_offset);
        }
        virtual void Visit(cVarDeclNode* node)
        {
            cDeclNode *type = node->GetType();
            int size = type->Sizeof();
            m_offset = RoundUp(m_offset);
            node->SetSize(size);
            node->SetOffset(m_offset);
            cSymbol *var = nullptr;
            for (int i = 0; i < node->NumDecls(); ++i)
            {
                var = node->GetVar(i);
                if (size > 1) {
                    m_offset = RoundUp(m_offset);
                }
                var->SetSize(size);
                var->SetOffset(m_offset);
                m_offset += size;
            }
        }
        virtual void Visit(cDeclsNode* node)
        {
            int old_offset = m_offset;
            VisitAllChildren(node);
            if (old_offset > 0)
                m_offset -= (m_offset-old_offset);
            node->SetSize(m_offset - old_offset);
        }
        // virtual void Visit(cStmtsNode* node)
        // {
        //     VisitAllChildren(node);
        //     if (m_offset > m_highwater)
        //         m_highwater = m_offset;
        // }
        // virtual void Visit(cFuncDeclNode* node)
        // {
        //     int old_offset = m_offset;
        //     m_offset = 0;
        //     VisitAllChildren(node);
        //     is_Params = false;
        //     node->SetSize(RoundUp(m_highwater));
        //     m_offset = old_offset;
        // }
        // virtual void Visit(cStructDeclNode *node)
        // {
        //     int old_offset = m_offset;
        //     node->SetOffset(0);
        //     m_offset = 0;
        //     VisitAllChildren(node);
        //     node->SetSize(node->Sizeof());
        //     m_offset = old_offset;
        // }
        // virtual void Visit(cParamsNode *node)
        // {
        //     VisitAllChildren(node);
        //     node->SetSize(RoundUp(m_offset));
        // }
        // virtual void Visit(cVarExprNode *node)
        // {
        //     cSymbol *sym = node->GetNameSymbol();
        //     node->SetSize( sym->GetSize() );
        //     node->SetOffset( sym->GetOffset() );
            
        //     VisitAllChildren(node);
        // }
    protected:
        int m_offset;
        int m_highwater;
        bool is_Params;

        int RoundUp(int value)
        {
            if (value % WORD_SIZE == 0) return value;
            return value + WORD_SIZE - value % WORD_SIZE;
        }
};

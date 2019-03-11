#pragma once
//**************************************
// cComputeSize.h
//
// Visitor implementation to compute size and offset of symbols, this class inherits from 
// cVisitor
//
// Author: Jiawei Xu 

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
        }
        /*************************************************************************
        * Name: VisitAllNodes
        * Parameter: cAstNode
        * Description:
        *   Visit cAstNode node
        *************************************************************************/
        virtual void VisitAllNodes(cAstNode* node) 
        { 
            node->Visit(this); 
        }
        /*************************************************************************
        * Name: Visit
        * Parameter: cProgramNode
        * Description:
        *   Visit all program's child nodes to assign size/offsets.
        *************************************************************************/
        virtual void Visit(cProgramNode *node)
        {
            VisitAllChildren(node);
        }
        virtual void Visit(cBlockNode *node)
        {
            int old_offset = m_offset;
            int old_highwater = m_highwater;
            m_highwater = 0;
            VisitAllChildren(node);
            int stack_height = m_highwater - old_offset;
            if (stack_height < 0)
                stack_height = 0;
            node->SetSize(stack_height);
            m_offset = old_offset;
            if (m_highwater < old_highwater)
                m_highwater = old_highwater;
        }
        /*************************************************************************
        * Name: Visit
        * Parameter: cSymbol
        * Description:
        *   Set the size/offset of the variable symbol node to the size of the
        *   type then increment the current offset.
        * 
        *   if type is not a char then we need to word align the current offset.
        *************************************************************************/
        virtual void Visit(cSymbol* node)
        {
            int offset = node->GetDecl()->GetOffset();
            int size = node->GetDecl()->GetSize();
            node->SetOffset(offset);
            node->SetSize(size);
            m_offset += offset;
        }
        /*************************************************************************
        * Name: Visit
        * Parameter: cVarDeclNode
        * Description:
        *   Set the size/offset of the variable declaring node to the size of the
        *   type then loop all its child nodes.
        * 
        *   If the type size is more than a char then we need to word align the
        *   offset.
        *************************************************************************/
        virtual void Visit(cVarDeclNode* node)
        {
            cDeclNode *type = node->GetType();
            int size = type->Sizeof();
            if (type->IsStruct())
                size = type->GetSize();
            node->SetSize(size);
            if (size > 1)
                m_offset = RoundUp(m_offset);
            node->SetOffset(m_offset);
            m_offset += size;
        }
        /*************************************************************************
        * Name: Visit
        * Parameter: cDeclsNode
        * Description:
        *   Compute all its child decls size and offset then check if the stack
        *   size is taller than the current high water mark, if so then we have
        *   a new high water mark.
        * 
        *   Then set its size by using the current offset subtracting the old
        *   offset to be relative of the current scope.
        *************************************************************************/
        virtual void Visit(cDeclsNode* node)
        {
            int old_offset = m_offset;
            VisitAllChildren(node);
            if (m_offset > m_highwater)
                m_highwater = m_offset;
            node->SetSize(m_offset - old_offset);
        }
        /*************************************************************************
        * Name: Visit
        * Parameter: cFuncDeclNode
        * Description:
        *   Compute all its child nodes' size and offset then resetting
        *   the high water mark and the offset because they are only relative
        *   to the function scope.
        *************************************************************************/
        virtual void Visit(cFuncDeclNode* node)
        {
            int old_offset = m_offset;
            int old_highwater = m_highwater;
            m_offset = 0;
            m_highwater = 0;
            VisitAllChildren(node);
            node->SetOffset(0);
            node->SetSize(RoundUp(m_highwater));
            m_offset = old_offset;
            m_highwater = old_highwater;
        }
        /*************************************************************************
        * Name: Visit
        * Parameter: cStructDeclNode
        * Description:
        *   Compute all its child var decl sizes and offsets relative to the struct
        *   then reset the current offset to the offset it began with.
        *************************************************************************/
        virtual void Visit(cStructDeclNode *node)
        {
            int old_offset = m_offset;
            node->SetOffset(0);
            m_offset = 0;
            VisitAllChildren(node);
            node->SetSize(m_offset);
            m_offset = old_offset;
        }
        /*************************************************************************
        * Name: Visit
        * Parameter: cParamsNode
        * Description:
        *   Compute all its child var decl sizes and offsets then set the size to 
        *   the offset.
        *************************************************************************/
        virtual void Visit(cParamsNode *node)
        {
            for(auto it = node->FirstChild(); it != node->LastChild(); it++)
            {
                cVarDeclNode* param = dynamic_cast<cVarDeclNode*>((*it));
                Visit(param);
                m_offset = RoundUp(m_offset);
            }
            node->SetSize(m_offset);
            if (m_offset > m_highwater)
                m_highwater = m_offset;
        }
        virtual void Visit(cVarExprNode *node)
        {
            int old_offset = m_offset;
            cSymbol *sym = nullptr;
            int offset = 0;
            VisitAllChildren(node);
            for(auto it = node->FirstChild(); it != node->LastChild(); it++)
            {
                sym = dynamic_cast<cSymbol*>((*it));
                if (sym != nullptr)
                {
                    offset += sym->GetOffset();
                }
                if (it == node->LastChild() - 1)
                {
                    node->SetSize(sym->GetSize());
                }
            }
            node->SetOffset(offset);
            m_offset = old_offset;
        }
    protected:
        int m_offset;       // Current offset
        int m_highwater;    // Maximum stack size
        /*************************************************************************
        * Name: RoundUp
        * Parameter: value
        * Description:
        *   Word Align the value.
        * 
        * PostCondition:
        *   If value is already aligned, then return the value.
        *   If value is not aligned, then return the next word aligned value.
        *************************************************************************/
        int RoundUp(int value)
        {
            if (value % WORD_SIZE == 0) return value;
            return value + WORD_SIZE - value % WORD_SIZE;
        }
};

#pragma once
//**************************************
// cArrayNode.h
//
// Defines an AST node for an array.
//
// Author: Jiawei Xu
//

#include "cAstNode.h"
#include "cDeclsNode.h"
#include "cDeclNode.h"

class cArrayNode : public cDeclNode
{
    public:
        cArrayNode(cSymbol *typeID, cSymbol *iden, int size) : cDeclNode()
        {
            cSymbol* isTypeExist = g_SymbolTable.Find(typeID->GetName());
            cSymbol* isIdenExist = g_SymbolTable.FindLocal(iden->GetName());
            if (!isTypeExist) 
            {
                isTypeExist = typeID;
                g_SymbolTable.Insert(isTypeExist);
            }
            if (!isIdenExist) 
            {
                isIdenExist = g_SymbolTable.Find(iden->GetName());
                if (!isIdenExist) 
                {
                    isIdenExist = iden;
                    g_SymbolTable.Insert(isIdenExist);
                }
            }
            AddChild(isTypeExist);
            AddChild(isIdenExist);
            m_size = size;
        }
        virtual string AttributesToString() 
        {
            return " count=\"" + std::to_string(m_size) + "\"";
        }
        virtual string NodeType() { return string("array_decl");}
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
    private:
        int m_size;
};

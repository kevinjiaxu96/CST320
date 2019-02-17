#pragma once
//**************************************
// cStructNode.h
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

class cStructNode : public cDeclNode
{
    public:
        cStructNode(cDeclsNode* decls, cSymbol* typeID) : cDeclNode()
        {
            if (!g_SymbolTable.Find(typeID->GetName()))
            {
                g_SymbolTable.Insert(typeID);
            }
            AddChild(decls);
            AddChild(typeID);
        }
        virtual string NodeType() { return string("struct_decl"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};

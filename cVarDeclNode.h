#pragma once
//**************************************
// cVarDeclNode.h
//
// Defines an AST node for an integer constant (literals).
//
// Inherits from cExprNode so that integer constants can be used anywhere 
// expressions are used.
//
// Author: Jiawei Xu
//

#include "cAstNode.h"
#include "cDeclNode.h"
#include "cSymbolTable.h"
#include <iostream>

class cVarDeclNode : public cDeclNode
{
    public:
        cVarDeclNode(cSymbol* typeID, cSymbol* iden) : cDeclNode()
        {
            cSymbol *ifTypeExist = g_SymbolTable.Find(typeID->GetName());
            cSymbol *ifIdenExist = g_SymbolTable.FindLocal(iden->GetName());
            m_id = typeID;
            if (!ifTypeExist)
            {
                ifTypeExist = typeID;
                g_SymbolTable.Insert(ifTypeExist);
            }
            if (!ifIdenExist)
            {
                ifIdenExist = iden;
                g_SymbolTable.Insert(ifIdenExist);
            }
            else
            {
                SemanticError("Symbol " + ifIdenExist->GetName() + " already defined in current scope");
            }
            if (ifTypeExist)
            {
                AddChild(ifTypeExist);
            }   
            if (ifIdenExist)
            {
                ifIdenExist->SetDecl(this);
                AddChild(ifIdenExist);
            }       
        }
                // return the name of the variable
        virtual string GetName() 
        { 
            cSymbol* name = dynamic_cast<cSymbol*>(GetChild(1));
            return name->GetName(); 
        }

        // return the symbol for the type
        virtual cDeclNode* GetType() 
        { 
            cSymbol* type_id = dynamic_cast<cSymbol*>(GetChild(0));
            return type_id->GetDecl(); 
        }
        virtual bool IsVar() { return true; }
        virtual bool IsInt()    { return m_id->GetDecl()->IsInt(); }
        virtual bool IsFloat()  { return m_id->GetDecl()->IsFloat(); }
        virtual bool IsChar()   { return m_id->GetDecl()->IsChar(); }
        virtual bool IsType()   { return m_id->GetDecl()->IsType(); }        
        virtual bool IsArray()  { return m_id->GetDecl()->IsArray(); }
        virtual string NodeType() { return string("var_decl"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
    private:
        cSymbol *m_id;
};
#pragma once
//**************************************
// cFuncExprNode.h
//
// Defines AST node for function calls
//
// Inherits from cExprNode so that functions can be used in expressions
//
// Author: Phil Howard 
// phil.howard@oit.edu
//
// Date: Feb. 6, 2016
//

#include "cAstNode.h"
#include "cStmtsNode.h"
#include "cParamListNode.h"
#include "cExprNode.h"

class cFuncExprNode : public cExprNode
{
    public:
        // params are the symbol for the func decl, and the params
        cFuncExprNode(cSymbol *name, cParamListNode *params)
            : cExprNode()
        {
            m_paramSize = 0;
            AddChild(name);
            AddChild(params);

            if (name->GetDecl() == nullptr)
            {
                SemanticError(name->GetName() + " is not declared");
                return ;
            }

            if (!name->GetDecl()->IsFunc())
            {
                SemanticError(name->GetName() + " is not a function");
                return;
            }

            // already checked IsFunc() so this should be safe
            cFuncDeclNode* func = dynamic_cast<cFuncDeclNode*>(name->GetDecl());
            if (func == nullptr || !func->IsFullyDefined())
            {
                SemanticError(name->GetName() + " is not fully defined");
                return;
            }

            cDeclsNode *args = func->GetParams();

            if ( (args == nullptr && params != nullptr) ||
                 (args != nullptr && params == nullptr))
            {
                SemanticError(name->GetName() + 
                        " called with wrong number of arguments");
                return;
            }
            else if (args != nullptr && params != nullptr)
            {
                if (args->NumDecls() != params->NumParams())
                {
                    SemanticError(name->GetName() + 
                            " called with wrong number of arguments");
                    return;
                }

                for (int ii=0; ii<args->NumDecls(); ii++)
                {
                    if (!args->GetDecl(ii)->IsCompatibleWith(
                                params->GetParam(ii)->GetType()))
                    {
                        SemanticError(name->GetName() + 
                                " called with incompatible argument");
                        return;
                    }
                }
            }
        }

        // Return the type of the var
        virtual cDeclNode* GetType()
        {
            cSymbol* sym = dynamic_cast<cSymbol*>(GetChild(0));
            return sym->GetDecl()->GetType();
        }

        cSymbol* GetNameSym()
        {
            return dynamic_cast<cSymbol*>(GetChild(1));
        }

        string GetName()
        {
            cSymbol* sym = dynamic_cast<cSymbol*>(GetChild(1));
            return sym->GetName();
        }

        virtual int GetParamSize() { return m_paramSize; }
        virtual void SetParamSize(int size) { m_paramSize = size; }

        // return string representation of the node
        virtual string NodeType() { return string("funcCall"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
    protected:
        int m_paramSize;
};

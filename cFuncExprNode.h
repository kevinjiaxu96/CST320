#pragma once
//**************************************
// cFunCallNode.h
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
#include "cStmtsNode.h"
#include "cParamListNode.h"

class cFuncExprNode : public cExprNode
{
    public:
        cFuncExprNode(cSymbol* iden, cParamListNode *params) : cExprNode()
        {
            AddChild(iden);
            AddChild(params);

            if (iden->GetDecl() == nullptr)
            {
                SemanticError(iden->GetName() + " is not declared");
                return ;
            }

            if (!iden->GetDecl()->IsFunc())
            {
                SemanticError(iden->GetName() + " is not a function");
                return;
            }

            // already checked IsFunc() so this should be safe
            cFuncDeclNode* func = dynamic_cast<cFuncDeclNode*>(iden->GetDecl());
            if (func == nullptr || !func->IsDefinition())
            {
                SemanticError(iden->GetName() + " is not fully defined");
                return;
            }

            cDeclsNode *args = func->GetParams();

            if ( (args == nullptr && params != nullptr) ||
                 (args != nullptr && params == nullptr))
            {
                SemanticError(iden->GetName() + 
                        " called with wrong number of arguments");
                return;
            }
            else if (args != nullptr && params != nullptr)
            {
                if (args->ChildCount() != params->NumParams())
                {
                    SemanticError(iden->GetName() + 
                            " called with wrong number of arguments");
                    return;
                }

                for (int ii=0; ii<args->ChildCount(); ii++)
                {
                    if (!args->GetDecl(ii)->IsCompatibleWith(
                                params->GetParam(ii)->GetType()))
                    {
                        SemanticError(iden->GetName() + 
                                " called with incompatible argument");
                        return;
                    }
                }
            }

        }
        virtual cDeclNode * GetType() { 
            return dynamic_cast<cSymbol*>(GetChild(0))->GetDecl(); 
        }
        virtual string NodeType() { return string("funcCall"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};

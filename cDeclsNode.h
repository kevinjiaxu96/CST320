#pragma once
//**************************************
// cDeclsNode.h
//
// Defines a class to represent a list of declarations.
//
// Author: Phil Howard 
// phil.howard@oit.edu
//

#include "cAstNode.h"
#include "cDeclNode.h"

class cDeclsNode : public cAstNode
{
    public:
        // param is the first decl in this decls
        cDeclsNode(cDeclNode *decl = nullptr) : cAstNode()
        {
            if (decl) AddChild(decl);
        }

        // Add a decl to the list
        void InsertDecl(cDeclNode *decl)
        {
            AddChild(decl);
        }
        void InsertParamSpec(cDeclNode *spec)
        {
            AddChild(spec);
        }
        cDeclNode *GetDecl(int index)
        {
            return (cDeclNode*)GetChild(index);
        }
        cDeclsNode *GetParams()
        {
            return (cDeclsNode *)GetChild(2);
        }
        int ChildCount() { return NumChildren(); }
        virtual string NodeType() { return string("decls"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};

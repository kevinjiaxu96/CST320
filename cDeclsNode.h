#pragma once
//**************************************
// cDeclsNode.h
//
// Defines a class to represent a list of declarations.
//
// Author: Phil Howard 
// phil.howard@oit.edu
//
// Date: Nov. 28, 2015
//

#include "cAstNode.h"
#include "cDeclNode.h"

class cDeclsNode : public cAstNode
{
    public:
        // param is the first decl in this decls
        cDeclsNode(cDeclNode *decl) : cAstNode()
        {
            AddChild(decl);
        }

        // Add a decl to the list
        void Insert(cDeclNode *decl)
        {
            AddChild(decl);
        }

        int NumDecls() 
        { 
            int numDecls = 0;
            for (auto it = FirstChild(); it != LastChild(); it++)
            {
                numDecls += dynamic_cast<cDeclNode*>(*it)->NumDecls();
            }
            return numDecls;
        }

        cDeclNode *GetDecl(int index)
        {
            return (cDeclNode *)GetChild(index);
        }
        void SetSize(int size) { m_size = size;}
        int GetSize() { return m_size; }
        // return the XML node name
        virtual string AttributesToString()
        {
            string result("");
            if (m_size != 0)
            {
                result += " size=\"" + std::to_string(m_size) + "\"";
            }
            return result;
        }
        virtual string NodeType() { return string("decls"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
    protected:
        int m_size;
};

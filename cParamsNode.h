#pragma once
//**************************************
// cParamsNode.h
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

class cParamsNode : public cDeclsNode
{
    public:
        // param is the first decl in this decls
        cParamsNode(cDeclNode *decl) : cDeclsNode(decl)
        {
        }
        virtual string AttributesToString()
        {
            string result("");
            if (m_size != 0)
            {
                result += " size=\"" + std::to_string(m_size) + "\"";
            }
            return result;
        }
        // return the XML node name
        virtual string NodeType() { return string("args"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};

#pragma once
//**************************************
// cSymbol.h
//
// Defines class used to represent symbols.
// Later labs will add features to this class.
//
// Author: Phil Howard 
// phil.howard@oit.edu
//

#include <string>

using std::string;

#include "cAstNode.h"
#include "cDeclNode.h"

class cSymbol : public cAstNode
{
    public:
        // param is name of symbol
        cSymbol(string name) : cAstNode()
        {
            m_id = ++nextId;        // get next available ID
            m_name = name;
            m_isType = false;
        }

        // return name of symbol
        string GetName() { return m_name; }

        virtual string AttributesToString()
        {
            string result(" id=\"");
            result += std::to_string(m_id);
            result += "\" name=\"" + m_name + "\"";
            return result;
        }
        void SetDecl(cDeclNode *decl)
        {
            m_decl = decl;
        }
        bool IsType()
        {
            return m_isType;
        }
        void SetIsType(bool isType)
        {
            m_isType = isType;
        }
        cDeclNode *GetDecl()
        {
            return m_decl;
        }

        virtual bool IsVar() { return true; }
        virtual string NodeType() { return string("sym"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
    protected:
        cDeclNode *m_decl;              // The declaration that defines this sym
        static long long nextId;        // Next avail symbol ID
        long long m_id;                 // Unique ID for this symbol
        bool m_isType;
        string m_name;                  // name of symbol
};

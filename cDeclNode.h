#pragma once
//**************************************
// cDeclNode
//
// Defines virtual base class for all declarations.
//
// Author: Phil Howard 
// phil.howard@oit.edu
//
// Date: Nov. 28, 2015
//

#include "cAstNode.h"

class cDeclNode : public cAstNode
{
    public:
        cDeclNode() : cAstNode(), m_size(0), m_offset(0) {}

        // return the decl for the type of the thing this node represents
        virtual cDeclNode *GetType() = 0;
        virtual cDeclNode *GetType(int depth) { return GetType(); }
        virtual cDeclNode *GetBaseType() { return GetType(); }

        virtual int NumDecls() = 0;

        // return the name of the item that is declared
        virtual string  GetName() = 0;
        virtual int NumParams()  { return 0; }
        virtual int GetParamSize() { return 0; }
        virtual int  Sizeof()  { return GetType()->Sizeof(); }

        virtual int GetSize() { return m_size; }
        virtual int GetOffset() { return m_offset; }
        virtual void SetSize(int size) { m_size = size; }
        virtual void SetOffset(int offset) { m_offset = offset; }

        // virtual functions to define what kind of decl this is.
        // subclasses should override the appropriate functions.
        virtual bool IsArray()  { return false; }
        virtual bool IsStruct() { return false; }
        virtual bool IsType()   { return false; }
        virtual bool IsFunc()   { return false; }
        virtual bool IsVar()    { return false; }
        virtual bool IsFloat()  { return false; }
        virtual bool IsInt()    { return false; }
        virtual bool IsChar()   { return false; }
        virtual string NodeType() { return string("decl"); }
        bool IsCompatibleWith(cDeclNode *decl)
        {
            if (IsFunc()) return false;
            if (this == decl) return true;
            if (IsStruct() || decl->IsStruct()) return false;
            if (IsArray() || decl->IsArray()) return false;
            if (IsFloat() && ! decl->IsStruct()) return true;
            if (Sizeof() >= decl->Sizeof()) return true;
            return false;
        }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
    protected:
        int m_offset;
        int m_size;
};

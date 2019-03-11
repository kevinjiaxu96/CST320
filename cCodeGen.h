#pragma once
//**************************************
// cCodeGen.h
//
// Code Generation class to visit nodes
// generate code
//
// Author: Jiawei Xu 

#include "emit.h"
#include "cVisitor.h"
#include <iostream>

class cCodeGen : public cVisitor
{
public:
    cCodeGen(std::string filename) : cVisitor()
    {
        InitOutput(filename.c_str());
    }
    ~cCodeGen()
    {
        FinalizeOutput();
    }

    void VisitAllNodes(cAstNode *node) { node->Visit(this); }
    virtual void Visit(cProgramNode *node)
    {
        cBlockNode *block = node->GetBlock();
        cDeclsNode *decls = block->GetDecls();
        cStmtsNode *stmts = block->GetStmts();
        if (decls != nullptr)
            decls->Visit(this);
        EmitStringNL("main:");
        if (stmts != nullptr)
            stmts->Visit(this);
    }
    virtual void Visit(cPrintNode *node)
    {
        node->GetExpr()->Visit(this);
        EmitStringNL("CALL @print");
        EmitStringNL("POP");
        EmitStringNL("POP");
    }
    virtual void Visit(cIntExprNode *node)
    {
        EmitString("PUSH ");
        EmitInt(node->GetValue());
        EmitStringNL("");
    }
    virtual void Visit(cFloatExprNode *node)
    {

    }
    virtual void Visit(cVarExprNode *node)
    {
        if (node->GetType()->IsChar())
            EmitStringNL("PUSHCVAR " + to_string(node->GetOffset()));
        else
            EmitStringNL("PUSHVAR " + to_string(node->GetOffset()));
    }
protected:
    virtual void EmitStringNL(std::string str)
    {
        std::string toBeEmitted = str + "\n";
        EmitString(toBeEmitted);
    }
};
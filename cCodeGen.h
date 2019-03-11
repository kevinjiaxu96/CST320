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
        std::cout << block->ToString() << std::endl;
        EmitStringNL("main:");
        VisitAllChildren(node);
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
protected:
    virtual void EmitStringNL(std::string str)
    {
        std::string toBeEmitted = str + "\n";
        EmitString(toBeEmitted);
    }
};
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
#include <string>
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
        EmitStringNL("main:");
        EmitString("ADJSP ");
        EmitInt(block->GetSize());
        EmitStringNL("");
        VisitAllChildren(node);
        EmitStringNL("PUSH 0");
        EmitStringNL("RETURNV");
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
    virtual void Visit(cVarExprNode *node)
    {
        VisitAllChildren(node);
        if (node->GetType()->IsChar())
            EmitStringNL("PUSHCVAR " + std::to_string(node->GetOffset()));
        else
            EmitStringNL("PUSHVAR " + std::to_string(node->GetOffset()));
    }
    virtual void Visit(cAssignNode *node)
    {
        VisitAllChildren(node);
        cVarExprNode *varNode = node->GetExpr();
        if (varNode->GetType()->IsChar())
            EmitStringNL("POPCVAR " + std::to_string(varNode->GetOffset()));
        else
            EmitStringNL("POPVAR " + std::to_string(varNode->GetOffset()));
    }
protected:
    virtual void EmitStringNL(std::string str)
    {
        std::string toBeEmitted = str + "\n";
        EmitString(toBeEmitted);
    }
};
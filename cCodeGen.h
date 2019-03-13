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
        EmitInt(RoundUp(block->GetSize()));
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
        std::cout << node->GetNameSymbol()->GetDecl()->ToString() << std::endl;
        if (node->GetNameSymbol()->GetDecl()->IsChar())
            EmitStringNL("PUSHCVAR " + std::to_string(node->GetOffset()));
        else
            EmitStringNL("PUSHVAR " + std::to_string(node->GetOffset()));
    }
    virtual void Visit(cAssignNode *node)
    {
        node->GetRVal()->Visit(this);
        cVarExprNode *varNode = node->GetLVal();
        if (varNode->GetType()->IsChar())
            EmitStringNL("POPCVAR " + std::to_string(varNode->GetOffset()));
        else
            EmitStringNL("POPVAR " + std::to_string(varNode->GetOffset()));
    }
    virtual void Visit(cBinaryExprNode *node)
    {
        int op = node->GetOp()->GetOpValue();
        node->GetExpr(0)->Visit(this);
        node->GetExpr(2)->Visit(this);
        switch(op)
        {
            case '+':
                EmitStringNL("PLUS");
                break;
            case '-':
                EmitStringNL("MINUS");
                break;
            case '*':
                EmitStringNL("TIMES");
                break;
            case '/':
                EmitStringNL("DIVIDE");
                break;
            case EQUALS:
                EmitStringNL("EQ");
                break;
            case NEQUALS:
                EmitStringNL("NE");
                break;
            case OR:
                EmitStringNL("OR");
                break;
            case AND:
                EmitStringNL("AND");
                break;
        }
    }
protected:
    virtual void EmitStringNL(std::string str)
    {
        std::string toBeEmitted = str + "\n";
        EmitString(toBeEmitted);
    }
};
#pragma once
//**************************************
// cParamNode.h
//
// Defines base class for all params
//
// This is a pure virtual class because there is no definition for
// cAstNode::ToString()
//
// Author: Jiawei Xu
//

#include "cDeclNode.h"

class cParamNode : public cDeclNode
{
    public:
        cParamNode() : cDeclNode() {}
};

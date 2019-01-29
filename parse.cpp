//**************************************
// parse.cpp
//
// Starting point for top-down recursive-descent parser
// Used in CST 320 Lab2
//
// Author: Phil Howard 
// phil.howard@oit.edu
//

#include <iostream>
#include <unordered_set>
#include "lex.h"
#include "parse.h"
#include "utils.h"
#include "tokens.h"

using std::unordered_set;

static unordered_set<int> FirstPROG = {'(', '[', INT_VAL, END};
static unordered_set<int> FirstSTMTS = {'(', '[', INT_VAL};
static unordered_set<int> FirstSTMT = {'(', '[', INT_VAL};
static unordered_set<int> FirstEXPR = {'(', '[', INT_VAL};
static unordered_set<int> FirstEXPR_P = {'+', '-'};
static unordered_set<int> FirstTERM = {'[', INT_VAL};
static unordered_set<int> FirstTERM_P = {'*', '/'};

static bool IsIn(unordered_set<int>& set, int value)
{
    auto found = set.find(value);
    if (found != set.end()) return true;
    return false;
}
/*******************************************
bool FindExample()
{
    if (!FindPART1()) return false;
    
    int token = PeekToken();
    if (token != '+') return false;
    AdvanceToken();         // past '+'

    if (!FindPART2()) return false;

    return true;
}
*/

//*******************************************
// Find a PROG non-terminal
bool FindPROG()
{
    int token = PeekToken();    
    if (IsIn(FirstPROG, token))
    {
        if (!FindSTMTS()) return false;

        token = PeekToken();
        if (token != END)
        {
            Error("'end'");
            return false;
        }
        AdvanceToken();

        return true;
    }
    
    return false;
}

//*******************************************
// Find a STMTS non-terminal
bool FindSTMTS()
{
    int token = PeekToken();
    if (IsIn(FirstSTMTS, token))
    {
        if (!FindSTMT()) return false;

        if (!FindSTMTS()) return false;

        return true;
    }
    else
    {
        return true;
    }

    return false;
}

//*******************************************
// Find a STMT non-terminal
bool FindSTMT()
{
    int token = PeekToken();
    if (IsIn(FirstSTMT, token))
    {
        // If FindEXPR fails, find the next ';' and return true
        if (!FindEXPR())
        {
            token = PeekToken();
            while (token != ';')
            {
               AdvanceToken();
               token = PeekToken();
            }
            AdvanceToken();
            return true;
        }

        token = PeekToken();
        if (token != ';')
        {
            Error("';'");
            token = PeekToken();
            while (token != ';')
            {
                AdvanceToken();
                token = PeekToken();
            }
            AdvanceToken();
            return true;
        }
        AdvanceToken();

        std::cout << "Found a statement"<<std::endl;
        
        return true;
    }
        
    return false;
}

//*******************************************
// Find a EXPR non-terminal
bool FindEXPR()
{
    int token = PeekToken();
    if (IsIn(FirstEXPR, token))
    {
        token = PeekToken();
        if (token == '(')
        {            
            AdvanceToken();
            
            if (!FindEXPR()) return false;
            
            token = PeekToken();
            if (token != ')')
            {
                Error("')'");
                return false;
            }
            AdvanceToken();
            
            if (!FindEXPR_P()) return false;
        }
        else if (!FindTERM()) return false;
        
        return true;
    }

    return false;
}

//*******************************************
// Find a EXPR_P non-terminal
bool FindEXPR_P()
{
    int token = PeekToken();
    if (IsIn(FirstEXPR_P, token))
    {
        token = PeekToken();
        if (token == '+' || token == '-')
        {
            AdvanceToken();
            
            token = PeekToken();
            if (token != '(')
            {
                Error("'('");
                return false;
            }
            AdvanceToken();

            if (!FindEXPR()) return false;

            token = PeekToken();
            if (token != ')')
            {
                Error("')'");
                return false;
            }
            AdvanceToken();

            if (!FindEXPR_P()) return false;

            return true;
        }

        return true;
    }
    else
    {
        // Lambda option
        return true;
    }

    return false;
}

//*******************************************
// Find a TERM non-terminal
bool FindTERM()
{
    int token = PeekToken();
    if (IsIn(FirstTERM, token))
    {
        token = PeekToken();
        if (token == '[')
        {
            AdvanceToken();

            if (!FindEXPR()) return false;

            token = PeekToken();
            if (token != ']')
            {
                Error("']'");
                return false;
            }
            AdvanceToken();

            if (!FindTERM_P()) return false;
            
            return true;
        }
        else if (token == INT_VAL)
        {
            AdvanceToken();
            return true;
        }
        else
        {
            Error("'[' or num");
            return false;
        }
    }

    return false;
}

//*******************************************
// Find a TERM Prime non-terminal
bool FindTERM_P()
{
    int token = PeekToken();
    if (IsIn(FirstTERM_P, token))
    {
        token = PeekToken();
        if (token == '*' || token == '/')
        {
            AdvanceToken();

            token = PeekToken();
            if (token != '[')
            {
                Error("'['");
                return false;
            }
            AdvanceToken();

            if (!FindEXPR()) return false;

            token = PeekToken();
            if (token != ']')
            {
                Error("']'");
                return false;
            }
            AdvanceToken();

            if (!FindTERM_P()) return false;
        }

        return true;
    }
    else
    {
        // Lambda option
        return true;
    }

    return false;
}

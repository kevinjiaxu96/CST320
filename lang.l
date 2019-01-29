%{
//**************************************
// lang.l
//
// scanner definition file. flex uses this file to create the scanner
//
// Author: Jiawei Xu
//

#include "lex.h"
#include "tokens.h"
#include "cSymbolTable.h"
#include <iostream>

// Macros that can be used to create debug output from the scanner
// The first one does NOT create debug output, the second does.
// Uncomment one or the other then use DO_RETURN(val) for all your return 
// statements
#define DO_RETURN(a) return (a)
//#define DO_RETURN(a) return Return(a)

int Return(int val);

%}

%option noyywrap
%option noinput
%option nounput
%option yylineno

    /* definitions go here.*/
    /* NOTE: You do not need to use definitions */

    //Punctuation
PUNCT           [.()[\],+\-*/%=;]
    //Others
INT_VAL         [-+]?[0-9]+
IDENTIFIER      [_a-zA-Z][_a-zA-Z0-9]*
    //Etc
WHITE_SPACE     [[:space:]]
S_COMMENTS      (\/\/(.+))
END             "end"

%%

    // token definitions.
{END}                       DO_RETURN(END);
{INT_VAL}                   DO_RETURN(INT_VAL);
{IDENTIFIER}                {
                                yylval.symbol = g_symbolTable.FindLocal(yytext);
                                if (!yylval.symbol) {
                                    yylval.symbol = new cSymbol(yytext);
                                    g_symbolTable.Insert(yylval.symbol);
                                }
                                DO_RETURN(IDENTIFIER);
                            }
{S_COMMENTS}                {}
{WHITE_SPACE}               {}
"}"                         {g_symbolTable.DecreaseScope(); DO_RETURN(yytext[0]);}
"{"                         {g_symbolTable.IncreaseScope(); DO_RETURN(yytext[0]);}
{PUNCT}                     {DO_RETURN(yytext[0]);}
.                           DO_RETURN(JUNK_TOKEN);

%%

// This function allows us to do extra processing on each token
// It is used to generate lexer debug info
int Return(int val)
{
    printf("Scanned '%s': %d\n", yytext, val);
    return val;
}

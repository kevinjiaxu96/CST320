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

// Macros that can be used to create debug output from the scanner
// The first one does NOT create debug output, the second does.
// Uncomment one or the other then use DO_RETURN(val) for all your return 
// statements
#define DO_RETURN(a) { return (a); }
//#define DO_RETURN(a) { return Return(a); }

#define DO_PUNCT_RETURN() { return ReturnPunct(); }

int Return(int val);
int ReturnPunct();

%}

%option noyywrap
%option noinput
%option nounput
%option yylineno

    /* definitions go here.*/
    /* NOTE: You do not need to use definitions */

    //Punctuation
PUNCT           [.(){}[\];,+\-*/%=]
    //Keywords
PROGRAM         "program"
IF              "if"
ELSE            "else"
ENDIF           "endif"
WHILE           "while"
PRINT           "print"
INT             "int"
FLOAT           "float"
CHAR            "char"
STRUCT          "struct"
ARRAY           "array"
RETURN          "return"
    // Operators
NOT_EQUAL       (!=)
EQUALS          (==)
AND             (&&)
OR              ("||")
    //Others
INT_VAL         [-+]?[0-9]+
FLOAT_VAL       [-+]?[0-9]*\.?[0-9]+
IDENTIFIER      [_a-zA-Z][_a-zA-Z0-9]*
    //Junk 
JUNK            [:@#$'\|!^&\\`]
    //Etc
WHITE_SPACE     [[:space:]]
S_COMMENTS      (\/\/(.+))

%%

    // token definitions.
{PROGRAM}                   DO_RETURN(PROGRAM);
{IF}                        DO_RETURN(IF);
{ELSE}                      DO_RETURN(ELSE);
{ENDIF}                     DO_RETURN(ENDIF);
{WHILE}                     DO_RETURN(WHILE);
{PRINT}                     DO_RETURN(PRINT);
{INT}                       DO_RETURN(INT);
{FLOAT}                     DO_RETURN(FLOAT);
{CHAR}                      DO_RETURN(CHAR);
{INT_VAL}                   DO_RETURN(INT_VAL);
{FLOAT_VAL}                 DO_RETURN(FLOAT_VAL);
{STRUCT}                    DO_RETURN(STRUCT);
{ARRAY}                     DO_RETURN(ARRAY);
{RETURN}                    DO_RETURN(RETURN);
{IDENTIFIER}                DO_RETURN(IDENTIFIER);
{NOT_EQUAL}                 DO_RETURN(NOT_EQUALS);
{EQUALS}                    DO_RETURN(EQUALS);
{AND}                       DO_RETURN(AND);
{OR}                        DO_RETURN(OR);
{S_COMMENTS}                {};
{WHITE_SPACE}               {};
{PUNCT}                     DO_RETURN(yytext[0]);
{JUNK}                      DO_RETURN(JUNK_TOKEN);

%%

// This function allows us to do extra processing on each token
// It is used to generate lexer debug info
int Return(int val)
{
    printf("Scanned '%s': %d\n", yytext, val);
    return val;
}

// This function allows to return ascii value of Punctuations using regex
// rather than listing each punctuation each by each
int ReturnPunct ()
{
    return static_cast<int>(yytext[0]);
}

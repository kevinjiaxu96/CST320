%{
//**************************************
// lang.y
//
// Parser definition file. bison uses this file to generate the parser.
//
// Author: Phil Howard 
// phil.howard@oit.edu
//

#include <iostream>
#include <string>
#include "lex.h"
#include "astnodes.h"

#define CHECK_ERROR() { if (g_semanticErrorHappened) \
    { g_semanticErrorHappened = false; } }
#define PROP_ERROR() { if (g_semanticErrorHappened) \
    { g_semanticErrorHappened = false; YYERROR; } }

%}

%locations

 /* union defines the type for lexical values */
%union{
    int             int_val;
    float           float_val;
    cAstNode*       ast_node;
    cProgramNode*   program_node;
    cBlockNode*     block_node;
    cStmtsNode*     stmts_node;
    cStmtNode*     stmt_node;
    cDeclsNode*     decls_node;
    cDeclNode*      decl_node;
    cExprNode*      expr_node;
    cIntExprNode*   int_node;
    cSymbol*        symbol;
    cFuncNode*      func_node;
    cVarExprNode*    ref_node;
    cParamsNode*    params_node;
    cParamNode*     param_node;
    }

%{
    int yyerror(const char *msg);
    cAstNode *yyast_root;
%}

%start  program

%token <symbol>    IDENTIFIER
%token <symbol>    TYPE_ID
%token <int_val>   CHAR_VAL
%token <int_val>   INT_VAL
%token <float_val> FLOAT_VAL
%token <int_val>   AND
%token <int_val>   OR
%token <int_val>   EQUALS
%token <int_val>   NOT_EQUALS

%token  PROGRAM
%token  PRINT
%token  WHILE IF ELSE ENDIF
%token  STRUCT ARRAY
%token  RETURN
%token  JUNK_TOKEN

%type <program_node> program
%type <block_node> block
%type <ast_node> open
%type <ast_node> close
%type <decls_node> decls
%type <decl_node> decl
%type <decl_node> var_decl
%type <decl_node> struct_decl
%type <decl_node> array_decl
%type <func_node> func_decl
%type <func_node> func_header
%type <func_node> func_prefix
%type <expr_node> func_call
%type <decls_node> paramsspec
%type <decl_node> paramspec
%type <stmts_node> stmts
%type <stmt_node> stmt
%type <ref_node> lval
%type <params_node> params
%type <param_node> param
%type <expr_node> expr
%type <expr_node> addit
%type <expr_node> term
%type <expr_node> fact
%type <ref_node> varref
%type <symbol> varpart

%%

program: PROGRAM block          { $$ = new cProgramNode($2);
                                  yyast_root = $$;
                                  if (yynerrs == 0)
                                      YYACCEPT;
                                  else
                                      YYABORT;
                                }
block:  open decls stmts close  {
                                    $$ = new cBlockNode($2, $3);
                                }
    |   open stmts close        {
                                    $$ = new cBlockNode(nullptr, $2); 
                                }

open:   '{'                     {
                                    $$ = new cBlockNode(nullptr, nullptr);
                                    g_SymbolTable.IncreaseScope();
                                }

close:  '}'                     {
                                    $$ = new cBlockNode(nullptr, nullptr);
                                    g_SymbolTable.DecreaseScope();
                                }

decls:      decls decl          {
                                    $$ = $1;
                                    $$->InsertDecl($2);
                                }
        |   decl                {
                                   $$ = new cDeclsNode($1);
                                }
decl:       var_decl ';'        {  $$ = $1; }
        |   struct_decl ';'     {  $$ = $1; }
        |   array_decl ';'      {  $$ = $1; }
        |   func_decl           {  $$ = $1; }
        |   error ';'           {  PROP_ERROR(); }

var_decl:   TYPE_ID IDENTIFIER  {
                                    $$ = new cVarDeclNode($1, $2);
                                }
        |   IDENTIFIER IDENTIFIER
                                {
                                    $$ = new cVarDeclNode($1, $2);
                                }
struct_decl:  STRUCT open decls close IDENTIFIER    
                                {
                                    $$ = new cStructNode($3, $5);
                                }
array_decl: ARRAY TYPE_ID '[' INT_VAL ']' IDENTIFIER
                                {
                                    $$ = new cArrayNode($2, $6, $4);
                                }
        |   ARRAY IDENTIFIER '[' INT_VAL ']' IDENTIFIER
                                {
                                    $$ = new cArrayNode($2, $6, $4);
                                }
func_decl:  func_header ';'
                                { 
                                    $$ = $1; 
                                    g_SymbolTable.DecreaseScope();
                                }
        |   func_header  '{' decls stmts '}'
                                { 
                                    $$ = $1;
                                    $$->InsertDecls($3);
                                    $$->InsertStmts($4);
                                    g_SymbolTable.DecreaseScope();
                                }
        |   func_header  '{' stmts '}'
                                { 
                                    $$ = $1;
                                    $$->InsertStmts($3);
                                    g_SymbolTable.DecreaseScope();
                                }
func_header: func_prefix paramsspec ')'
                                { 
                                    $$->InsertParams($2); 
                                }
        |    func_prefix ')'    { 
                                    $$ = $1; 
                                }
func_prefix: TYPE_ID IDENTIFIER '('
                                { 
                                    $$ = new cFuncNode($1, $2);
                                    g_SymbolTable.IncreaseScope();
                                }
paramsspec: paramsspec',' paramspec 
                                { 
                                    $$ = $1;
                                    $$->InsertParamSpec($3);
                                }
        |   paramspec           { $$ = new cArgsNode($1); }

paramspec:  var_decl            { $$ = $1; }

stmts:      stmts stmt          {
                                    $$ = $1;
                                    $$->InsertStmt($2);
                                }
        |   stmt                {
                                    $$ = new cStmtsNode($1);
                                }

stmt:       IF '(' expr ')' stmts ENDIF ';'
                                { 
                                    $$ = new cIfNode($3, $5);
                                }
        |   IF '(' expr ')' stmts ELSE stmts ENDIF ';'
                                {  
                                    $$ = new cIfNode($3, $5, $7);
                                }
        |   WHILE '(' expr ')' stmt 
                                { $$ = new cWhileNode($3, $5); }
        |   PRINT '(' expr ')' ';'
                                { $$ = new cPrintNode($3); }
        |   lval '=' expr ';'   { 
                                    $$ = new cAssignNode($1, $3);
                                    CHECK_ERROR();
                                }
        |   lval '=' func_call ';'   
                                {
                                    $$ = new cAssignNode($1, $3);
                                    CHECK_ERROR();
                                }
        |   func_call ';'       { 
                                    $$ = $1; 
                                }
        |   block               {

                                }
        |   RETURN expr ';'     { $$ = new cRetNode($2); }
        |   error ';'           { PROP_ERROR(); }

func_call:  IDENTIFIER '(' params ')' { $$ = new cFunCallNode($1, $3); }
        |   IDENTIFIER '(' ')'  { $$ = new cFunCallNode($1); }

varref:   varref '.' varpart    { 
                                    $$ = $1; 
                                    $$->InsertVarpart($3);
                                }
        | varref '[' expr ']'   { 
                                    $$ = $1;
                                    $$->InsertExpr($3);
                                }
        | varpart               { 
                                    $$ = new cVarExprNode($1); 
                                }

varpart:  IDENTIFIER            { }

lval:     varref                { $$ = $1; }

params:     params',' param     { 
                                    $$ = $1;
                                    $$->InsertParamSpec($3);
                                }
        |   param               {
                                    $$ = new cParamsNode($1);
                                }

param:      expr                {  }

expr:       expr EQUALS addit   {
                                    $$ = new cBinExprNode($1,new cOpNode(EQUALS), $3);
                                }
        |   addit               { $$ = $1; }

addit:      addit '+' term      { 
                                    $$ = new cBinExprNode($1, new cOpNode('+'), $3); 
                                }
        |   addit '-' term      { 
                                    $$ = new cBinExprNode($1, new cOpNode('-'), $3); 
                                }
        |   term                { $$ = $1; }

term:       term '*' fact       { 
                                    $$ = new cBinExprNode($1, new cOpNode('*'), $3); 
                                }
        |   term '/' fact       { 
                                    $$ = new cBinExprNode($1, new cOpNode('/'), $3); 
                                }
        |   term '%' fact       { 
                                    $$ = new cBinExprNode($1, new cOpNode('%'), $3); 
                                }
        |   fact                { $$ = $1; }

fact:        '(' expr ')'       { $$ = $2;  }
        |   INT_VAL             { $$ = new cIntExprNode($1); }
        |   FLOAT_VAL           { $$ = new cFloatExprNode($1); }
        |   varref              { $$ = $1; }

%%

// Function to format error messages
int yyerror(const char *msg)
{
    std::cerr << "ERROR: " << msg << " at symbol "
        << yytext << " on line " << yylineno << "\n";

    return 0;
}

// Function that gets called when a semantic error happens
void SemanticError(std::string error)
{
    std::cout << "ERROR: " << error << " on line " 
              << yylineno << "\n";
    g_semanticErrorHappened = true;
    yynerrs++;
}

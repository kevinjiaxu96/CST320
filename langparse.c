/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     TYPE_ID = 259,
     CHAR_VAL = 260,
     INT_VAL = 261,
     FLOAT_VAL = 262,
     PROGRAM = 263,
     PRINT = 264,
     WHILE = 265,
     IF = 266,
     ELSE = 267,
     ENDIF = 268,
     STRUCT = 269,
     ARRAY = 270,
     RETURN = 271,
     AND = 272,
     OR = 273,
     NEQUALS = 274,
     EQUALS = 275,
     JUNK_TOKEN = 276
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define TYPE_ID 259
#define CHAR_VAL 260
#define INT_VAL 261
#define FLOAT_VAL 262
#define PROGRAM 263
#define PRINT 264
#define WHILE 265
#define IF 266
#define ELSE 267
#define ENDIF 268
#define STRUCT 269
#define ARRAY 270
#define RETURN 271
#define AND 272
#define OR 273
#define NEQUALS 274
#define EQUALS 275
#define JUNK_TOKEN 276




/* Copy the first part of user declarations.  */
#line 1 "lang.y"

//**************************************
// lang.y
//
// Parser definition file. bison uses this file to generate the parser.
//
// Author: Phil Howard 
// phil.howard@oit.edu
//
// Date: Nov. 28, 2015
//
#include <iostream>
#include "lex.h"
#include "astnodes.h"



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 21 "lang.y"
{
    int             int_val;
    double          float_val;
    cAstNode*       ast_node;
    cProgramNode*   program_node;
    cBlockNode*     block_node;
    cStmtsNode*     stmts_node;
    cStmtNode*      stmt_node;
    cExprNode*      expr_node;
    cFuncDeclNode*  func_node;
    cFuncExprNode*  funccall_node;
    cSymbol*        symbol;
    cSymbolTable::symbolTable_t*  sym_table;
    cDeclsNode*     decls_node;
    cParamsNode*    params_node;
    cDeclNode*      decl_node;
    cVarExprNode*   varref_node;
    cParamListNode* paramlist_node;
    }
/* Line 193 of yacc.c.  */
#line 175 "langparse.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */
#line 41 "lang.y"

    int yyerror(const char *msg);

    cAstNode *yyast_root;

    static bool g_semanticErrorHappened = false;

#define CHECK_ERROR() { if (g_semanticErrorHappened) \
    { g_semanticErrorHappened = false; } }
#define PROP_ERROR() { if (g_semanticErrorHappened) \
    { g_semanticErrorHappened = false; YYERROR; } }


/* Line 216 of yacc.c.  */
#line 212 "langparse.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   224

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNRULES -- Number of states.  */
#define YYNSTATES  140

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   276

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    36,     2,     2,
      28,    27,    34,    32,    29,    33,    31,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    24,
       2,    30,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    25,     2,    26,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    22,     2,    23,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,    11,    15,    17,    19,    22,    24,
      27,    30,    33,    35,    38,    41,    47,    54,    57,    63,
      68,    72,    75,    79,    83,    85,    87,    90,    92,   100,
     110,   116,   122,   127,   130,   132,   136,   139,   144,   148,
     152,   157,   159,   161,   163,   167,   169,   171,   175,   177,
     181,   183,   187,   191,   193,   197,   201,   203,   207,   211,
     215,   217,   221,   223,   225,   227
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      38,     0,    -1,     8,    39,    -1,    40,    42,    52,    41,
      -1,    40,    52,    41,    -1,    22,    -1,    23,    -1,    42,
      43,    -1,    43,    -1,    44,    24,    -1,    46,    24,    -1,
      45,    24,    -1,    47,    -1,     1,    24,    -1,     4,     3,
      -1,    14,    40,    42,    41,     3,    -1,    15,     4,    25,
       6,    26,     3,    -1,    48,    24,    -1,    48,    22,    42,
      52,    23,    -1,    48,    22,    52,    23,    -1,    49,    50,
      27,    -1,    49,    27,    -1,     4,     3,    28,    -1,    50,
      29,    51,    -1,    51,    -1,    44,    -1,    52,    53,    -1,
      53,    -1,    11,    28,    60,    27,    52,    13,    24,    -1,
      11,    28,    60,    27,    52,    12,    52,    13,    24,    -1,
      10,    28,    60,    27,    53,    -1,     9,    28,    60,    27,
      24,    -1,    57,    30,    60,    24,    -1,    54,    24,    -1,
      39,    -1,    16,    60,    24,    -1,     1,    24,    -1,     3,
      28,    58,    27,    -1,     3,    28,    27,    -1,    55,    31,
      56,    -1,    55,    25,    60,    26,    -1,    56,    -1,     3,
      -1,    55,    -1,    58,    29,    59,    -1,    59,    -1,    60,
      -1,    60,    18,    61,    -1,    61,    -1,    61,    17,    62,
      -1,    62,    -1,    62,    20,    63,    -1,    62,    19,    63,
      -1,    63,    -1,    63,    32,    64,    -1,    63,    33,    64,
      -1,    64,    -1,    64,    34,    65,    -1,    64,    35,    65,
      -1,    64,    36,    65,    -1,    65,    -1,    28,    60,    27,
      -1,     6,    -1,     7,    -1,    55,    -1,    54,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   101,   101,   108,   109,   111,   113,   115,   116,   117,
     118,   119,   120,   121,   123,   127,   131,   135,   139,   145,
     151,   155,   156,   162,   164,   166,   168,   169,   171,   173,
     175,   177,   179,   183,   184,   185,   186,   188,   192,   197,
     198,   199,   201,   203,   205,   206,   208,   210,   211,   213,
     214,   216,   217,   218,   220,   221,   222,   224,   225,   226,
     227,   229,   230,   231,   232,   233
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "TYPE_ID", "CHAR_VAL",
  "INT_VAL", "FLOAT_VAL", "PROGRAM", "PRINT", "WHILE", "IF", "ELSE",
  "ENDIF", "STRUCT", "ARRAY", "RETURN", "AND", "OR", "NEQUALS", "EQUALS",
  "JUNK_TOKEN", "'{'", "'}'", "';'", "'['", "']'", "')'", "'('", "','",
  "'='", "'.'", "'+'", "'-'", "'*'", "'/'", "'%'", "$accept", "program",
  "block", "open", "close", "decls", "decl", "var_decl", "struct_decl",
  "array_decl", "func_decl", "func_header", "func_prefix", "paramsspec",
  "paramspec", "stmts", "stmt", "func_call", "varref", "varpart", "lval",
  "paramlist", "param", "expr", "and", "equal", "add", "term", "fact", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   123,   125,    59,    91,    93,    41,    40,    44,
      61,    46,    43,    45,    42,    47,    37
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    41,    42,    42,    43,
      43,    43,    43,    43,    44,    45,    46,    47,    47,    47,
      48,    48,    49,    50,    50,    51,    52,    52,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    54,    54,    55,
      55,    55,    56,    57,    58,    58,    59,    60,    60,    61,
      61,    62,    62,    62,    63,    63,    63,    64,    64,    64,
      64,    65,    65,    65,    65,    65
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     4,     3,     1,     1,     2,     1,     2,
       2,     2,     1,     2,     2,     5,     6,     2,     5,     4,
       3,     2,     3,     3,     1,     1,     2,     1,     7,     9,
       5,     5,     4,     2,     1,     3,     2,     4,     3,     3,
       4,     1,     1,     1,     3,     1,     1,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       1,     3,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     5,     2,     0,     1,     0,    42,     0,
       0,     0,     0,     0,     0,     0,    34,     0,     8,     0,
       0,     0,    12,     0,     0,     0,    27,     0,    43,    41,
       0,    13,     0,    14,     0,     0,     0,     0,     0,    62,
      63,     0,    65,    64,     0,    48,    50,    53,    56,    60,
       7,     0,     9,    11,    10,     0,    17,     0,    21,    25,
       0,    24,     0,     6,     4,    26,    33,     0,     0,     0,
      38,     0,    45,    46,    22,     0,     0,     0,     0,     0,
       0,     0,     0,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     3,     0,     0,    14,    20,     0,    36,     0,
      42,    39,     0,    37,     0,     0,     0,     0,    13,     0,
       0,    61,    47,    49,    52,    51,    54,    55,    57,    58,
      59,     0,    19,    23,    40,    32,    44,    31,    30,     0,
      15,     0,    18,     0,     0,    16,     0,    28,     0,    29
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    16,     5,    64,    17,    18,    19,    20,    21,
      22,    23,    24,    60,    61,    25,    26,    42,    43,    29,
      30,    71,    72,    73,    45,    46,    47,    48,    49
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -46
static const yytype_int16 yypact[] =
{
       0,    -1,    25,   -46,   -46,   158,   -46,    20,    11,    56,
      36,    45,    48,    -1,   111,    10,   -46,   158,   -46,    93,
      98,    99,   -46,    63,    15,    46,   -46,   101,    -7,   -46,
     102,    61,     4,   106,    10,    10,    10,    39,   115,   -46,
     -46,    10,   -46,    -7,    53,   124,    91,    81,    60,   -46,
     -46,    46,   -46,   -46,   -46,   158,   -46,   141,   -46,   -46,
      79,   -46,   122,   -46,   -46,   -46,   -46,    10,   144,    10,
     -46,    80,   -46,   132,   -46,    33,    40,    47,   130,    22,
     149,    54,    10,   -46,    10,    10,    10,    10,    10,    10,
      10,    10,   -46,   158,   126,   -46,   -46,   152,   -46,    57,
     -46,   -46,    68,   -46,    10,   133,   202,   202,   -46,   157,
     137,   -46,   124,    91,    81,    81,    60,    60,   -46,   -46,
     -46,   142,   -46,   -46,   -46,   -46,   -46,   -46,   -46,   174,
     -46,   163,   -46,   202,   146,   -46,   188,   -46,   147,   -46
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -46,   -46,   175,   165,   -45,   -22,   -13,   -19,   -46,   -46,
     -46,   -46,   -46,   -46,    82,   -14,   -24,    -5,    -3,   113,
     -46,   -46,    78,    -6,   110,   104,    35,    51,     9
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -37
static const yytype_int16 yytable[] =
{
      27,    65,    28,    51,    50,    59,    92,     8,     1,    44,
      39,    40,    27,     8,    28,    79,    39,    40,    67,    57,
      27,     3,    28,    78,    68,     6,     9,    65,    75,    76,
      77,    70,    41,    93,   109,    81,    13,    14,    41,    32,
      78,    94,    58,     9,    31,    63,    27,    62,    28,     8,
      27,    82,    28,    13,    14,    10,    11,    12,    82,    33,
     105,    99,    15,   102,    34,    82,    50,   106,     3,    63,
      65,    82,    82,    35,   107,    82,    36,    83,    59,   121,
      50,   111,   128,   124,   -36,    55,    82,    56,    27,    27,
      28,    28,   125,   129,    89,    90,    91,    65,   118,   119,
     120,    27,    27,    28,    28,    65,    96,   103,    97,   104,
      85,    86,    65,    87,    88,    38,    27,    52,    28,   136,
     114,   115,    53,    54,    27,    66,    28,    62,    27,     8,
      28,    27,    69,    28,    74,    10,    11,    12,   116,   117,
      80,    84,    15,    62,    95,     8,    98,   100,     3,   122,
      82,    10,    11,    12,   108,   110,    57,   127,    15,     7,
     130,     8,     9,   131,     3,   132,   135,    10,    11,    12,
     137,   139,    13,    14,    15,    62,     4,     8,    37,   123,
       3,   101,   126,    10,    11,    12,   133,   134,   113,    62,
      15,     8,   112,     0,     0,     0,     3,    10,    11,    12,
       0,   138,     0,    62,    15,     8,     0,     0,     0,     0,
       3,    10,    11,    12,     0,     0,     0,     0,    15,     0,
       0,     0,     0,     0,     3
};

static const yytype_int16 yycheck[] =
{
       5,    25,     5,    17,    17,    24,    51,     3,     8,    15,
       6,     7,    17,     3,    17,    37,     6,     7,    25,     4,
      25,    22,    25,     1,    31,     0,     4,    51,    34,    35,
      36,    27,    28,    55,    79,    41,    14,    15,    28,    28,
       1,    55,    27,     4,    24,    23,    51,     1,    51,     3,
      55,    18,    55,    14,    15,     9,    10,    11,    18,     3,
      27,    67,    16,    69,    28,    18,    79,    27,    22,    23,
      94,    18,    18,    28,    27,    18,    28,    24,    97,    93,
      93,    27,   106,    26,    23,    22,    18,    24,    93,    94,
      93,    94,    24,   107,    34,    35,    36,   121,    89,    90,
      91,   106,   107,   106,   107,   129,    27,    27,    29,    29,
      19,    20,   136,    32,    33,     4,   121,    24,   121,   133,
      85,    86,    24,    24,   129,    24,   129,     1,   133,     3,
     133,   136,    30,   136,    28,     9,    10,    11,    87,    88,
      25,    17,    16,     1,     3,     3,    24,     3,    22,    23,
      18,     9,    10,    11,    24,     6,     4,    24,    16,     1,
       3,     3,     4,    26,    22,    23,     3,     9,    10,    11,
      24,    24,    14,    15,    16,     1,     1,     3,    13,    97,
      22,    68,   104,     9,    10,    11,    12,    13,    84,     1,
      16,     3,    82,    -1,    -1,    -1,    22,     9,    10,    11,
      -1,    13,    -1,     1,    16,     3,    -1,    -1,    -1,    -1,
      22,     9,    10,    11,    -1,    -1,    -1,    -1,    16,    -1,
      -1,    -1,    -1,    -1,    22
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    38,    22,    39,    40,     0,     1,     3,     4,
       9,    10,    11,    14,    15,    16,    39,    42,    43,    44,
      45,    46,    47,    48,    49,    52,    53,    54,    55,    56,
      57,    24,    28,     3,    28,    28,    28,    40,     4,     6,
       7,    28,    54,    55,    60,    61,    62,    63,    64,    65,
      43,    52,    24,    24,    24,    22,    24,     4,    27,    44,
      50,    51,     1,    23,    41,    53,    24,    25,    31,    30,
      27,    58,    59,    60,    28,    60,    60,    60,     1,    42,
      25,    60,    18,    24,    17,    19,    20,    32,    33,    34,
      35,    36,    41,    42,    52,     3,    27,    29,    24,    60,
       3,    56,    60,    27,    29,    27,    27,    27,    24,    41,
       6,    27,    61,    62,    63,    63,    64,    64,    65,    65,
      65,    52,    23,    51,    26,    24,    59,    24,    53,    52,
       3,    26,    23,    12,    13,     3,    52,    24,    13,    24
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;
/* Location data for the look-ahead symbol.  */
YYLTYPE yylloc;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[2];

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;
#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 0;
#endif

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
	YYSTACK_RELOCATE (yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 101 "lang.y"
    { (yyval.program_node) = new cProgramNode((yyvsp[(2) - (2)].block_node));
                                  yyast_root = (yyval.program_node);
                                  if (yynerrs == 0) 
                                      YYACCEPT;
                                  else
                                      YYABORT;
                                ;}
    break;

  case 3:
#line 108 "lang.y"
    { (yyval.block_node) = new cBlockNode((yyvsp[(2) - (4)].decls_node), (yyvsp[(3) - (4)].stmts_node)); ;}
    break;

  case 4:
#line 109 "lang.y"
    { (yyval.block_node) = new cBlockNode(nullptr, (yyvsp[(2) - (3)].stmts_node)); ;}
    break;

  case 5:
#line 111 "lang.y"
    { (yyval.sym_table) = g_SymbolTable.IncreaseScope(); ;}
    break;

  case 6:
#line 113 "lang.y"
    { (yyval.sym_table) = g_SymbolTable.DecreaseScope(); ;}
    break;

  case 7:
#line 115 "lang.y"
    { (yyval.decls_node) = (yyvsp[(1) - (2)].decls_node); (yyval.decls_node)->Insert((yyvsp[(2) - (2)].decl_node)); ;}
    break;

  case 8:
#line 116 "lang.y"
    { (yyval.decls_node) = new cDeclsNode((yyvsp[(1) - (1)].decl_node)); ;}
    break;

  case 9:
#line 117 "lang.y"
    { (yyval.decl_node) = (yyvsp[(1) - (2)].decl_node); CHECK_ERROR(); ;}
    break;

  case 10:
#line 118 "lang.y"
    { (yyval.decl_node) = (yyvsp[(1) - (2)].decl_node); ;}
    break;

  case 11:
#line 119 "lang.y"
    { (yyval.decl_node) = (yyvsp[(1) - (2)].decl_node); ;}
    break;

  case 12:
#line 120 "lang.y"
    { (yyval.decl_node) = (yyvsp[(1) - (1)].func_node); ;}
    break;

  case 13:
#line 121 "lang.y"
    {;}
    break;

  case 14:
#line 123 "lang.y"
    { 
                                  (yyval.decl_node) = new cVarDeclNode((yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].symbol));
                                  CHECK_ERROR();
                                ;}
    break;

  case 15:
#line 128 "lang.y"
    { (yyval.decl_node) = new cStructDeclNode((yyvsp[(2) - (5)].sym_table), (yyvsp[(3) - (5)].decls_node), (yyvsp[(5) - (5)].symbol)); 
                                  PROP_ERROR();
                                ;}
    break;

  case 16:
#line 132 "lang.y"
    { (yyval.decl_node) = new cArrayDeclNode((yyvsp[(2) - (6)].symbol), (yyvsp[(6) - (6)].symbol), (yyvsp[(4) - (6)].int_val)); 
                                  PROP_ERROR();
                                ;}
    break;

  case 17:
#line 136 "lang.y"
    { (yyval.func_node) = (yyvsp[(1) - (2)].func_node);  
                                  g_SymbolTable.DecreaseScope();  
                                ;}
    break;

  case 18:
#line 140 "lang.y"
    { (yyval.func_node) = (yyvsp[(1) - (5)].func_node); 
                                  (yyval.func_node)->AddDecls((yyvsp[(3) - (5)].decls_node)); 
                                  (yyval.func_node)->AddStmts((yyvsp[(4) - (5)].stmts_node)); 
                                  g_SymbolTable.DecreaseScope();  
                                ;}
    break;

  case 19:
#line 146 "lang.y"
    { (yyval.func_node) = (yyvsp[(1) - (4)].func_node); 
                                  (yyval.func_node)->AddDecls(nullptr); 
                                  (yyval.func_node)->AddStmts((yyvsp[(3) - (4)].stmts_node)); 
                                  g_SymbolTable.DecreaseScope();  
                                ;}
    break;

  case 20:
#line 152 "lang.y"
    { 
                                  (yyval.func_node) = (yyvsp[(1) - (3)].func_node); (yyval.func_node)->AddParams((yyvsp[(2) - (3)].params_node)); 
                                ;}
    break;

  case 21:
#line 155 "lang.y"
    { (yyval.func_node) = (yyvsp[(1) - (2)].func_node); (yyval.func_node)->AddParams(nullptr);;}
    break;

  case 22:
#line 157 "lang.y"
    { 
                                  (yyval.func_node) = new cFuncDeclNode((yyvsp[(1) - (3)].symbol), (yyvsp[(2) - (3)].symbol)); 
                                  g_SymbolTable.IncreaseScope();
                                  CHECK_ERROR();
                                ;}
    break;

  case 23:
#line 163 "lang.y"
    { (yyval.params_node) = (yyvsp[(1) - (3)].params_node); (yyval.params_node)->Insert((yyvsp[(3) - (3)].decl_node)); ;}
    break;

  case 24:
#line 164 "lang.y"
    { (yyval.params_node) = new cParamsNode((yyvsp[(1) - (1)].decl_node)); ;}
    break;

  case 25:
#line 166 "lang.y"
    { (yyval.decl_node) = (yyvsp[(1) - (1)].decl_node); ;}
    break;

  case 26:
#line 168 "lang.y"
    { (yyval.stmts_node) = (yyvsp[(1) - (2)].stmts_node); (yyval.stmts_node)->Insert((yyvsp[(2) - (2)].stmt_node)); ;}
    break;

  case 27:
#line 169 "lang.y"
    { (yyval.stmts_node) = new cStmtsNode((yyvsp[(1) - (1)].stmt_node)); ;}
    break;

  case 28:
#line 172 "lang.y"
    { (yyval.stmt_node) = new cIfNode((yyvsp[(3) - (7)].expr_node), (yyvsp[(5) - (7)].stmts_node), nullptr); ;}
    break;

  case 29:
#line 174 "lang.y"
    { (yyval.stmt_node) = new cIfNode((yyvsp[(3) - (9)].expr_node), (yyvsp[(5) - (9)].stmts_node), (yyvsp[(7) - (9)].stmts_node)); ;}
    break;

  case 30:
#line 176 "lang.y"
    { (yyval.stmt_node) = new cWhileNode((yyvsp[(3) - (5)].expr_node), (yyvsp[(5) - (5)].stmt_node)); ;}
    break;

  case 31:
#line 178 "lang.y"
    { (yyval.stmt_node) = new cPrintNode((yyvsp[(3) - (5)].expr_node)); ;}
    break;

  case 32:
#line 179 "lang.y"
    { 
                                  (yyval.stmt_node) = new cAssignNode((yyvsp[(1) - (4)].varref_node), (yyvsp[(3) - (4)].expr_node)); 
                                  CHECK_ERROR(); 
                                ;}
    break;

  case 33:
#line 183 "lang.y"
    { (yyval.stmt_node) = (yyvsp[(1) - (2)].funccall_node); ;}
    break;

  case 34:
#line 184 "lang.y"
    { (yyval.stmt_node) = (yyvsp[(1) - (1)].block_node); ;}
    break;

  case 35:
#line 185 "lang.y"
    { (yyval.stmt_node) = new cReturnNode((yyvsp[(2) - (3)].expr_node)); ;}
    break;

  case 36:
#line 186 "lang.y"
    {;}
    break;

  case 37:
#line 188 "lang.y"
    { 
                                  (yyval.funccall_node) = new cFuncExprNode((yyvsp[(1) - (4)].symbol), (yyvsp[(3) - (4)].paramlist_node)); 
                                  CHECK_ERROR();
                                ;}
    break;

  case 38:
#line 192 "lang.y"
    { 
                                    (yyval.funccall_node) = new cFuncExprNode((yyvsp[(1) - (3)].symbol), nullptr);
                                  CHECK_ERROR();
                                ;}
    break;

  case 39:
#line 197 "lang.y"
    { (yyval.varref_node) = (yyvsp[(1) - (3)].varref_node); (yyval.varref_node)->AddElement((yyvsp[(3) - (3)].symbol)); PROP_ERROR(); ;}
    break;

  case 40:
#line 198 "lang.y"
    { (yyval.varref_node) = (yyvsp[(1) - (4)].varref_node); (yyval.varref_node)->AddElement((yyvsp[(3) - (4)].expr_node)); PROP_ERROR(); ;}
    break;

  case 41:
#line 199 "lang.y"
    { (yyval.varref_node) = new cVarExprNode((yyvsp[(1) - (1)].symbol)); PROP_ERROR(); ;}
    break;

  case 42:
#line 201 "lang.y"
    { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); ;}
    break;

  case 43:
#line 203 "lang.y"
    { (yyval.varref_node) = (yyvsp[(1) - (1)].varref_node); ;}
    break;

  case 44:
#line 205 "lang.y"
    { (yyval.paramlist_node) = (yyvsp[(1) - (3)].paramlist_node); (yyval.paramlist_node)->Insert((yyvsp[(3) - (3)].expr_node)); ;}
    break;

  case 45:
#line 206 "lang.y"
    { (yyval.paramlist_node) = new cParamListNode((yyvsp[(1) - (1)].expr_node)); ;}
    break;

  case 46:
#line 208 "lang.y"
    { (yyval.expr_node) = (yyvsp[(1) - (1)].expr_node); ;}
    break;

  case 47:
#line 210 "lang.y"
    { (yyval.expr_node) = new cBinaryExprNode((yyvsp[(1) - (3)].expr_node), OR, (yyvsp[(3) - (3)].expr_node)); ;}
    break;

  case 48:
#line 211 "lang.y"
    { (yyval.expr_node) = (yyvsp[(1) - (1)].expr_node); ;}
    break;

  case 49:
#line 213 "lang.y"
    { (yyval.expr_node) = new cBinaryExprNode((yyvsp[(1) - (3)].expr_node), AND, (yyvsp[(3) - (3)].expr_node)); ;}
    break;

  case 50:
#line 214 "lang.y"
    { (yyval.expr_node) = (yyvsp[(1) - (1)].expr_node); ;}
    break;

  case 51:
#line 216 "lang.y"
    { (yyval.expr_node) = new cBinaryExprNode((yyvsp[(1) - (3)].expr_node), EQUALS, (yyvsp[(3) - (3)].expr_node)); ;}
    break;

  case 52:
#line 217 "lang.y"
    { (yyval.expr_node) = new cBinaryExprNode((yyvsp[(1) - (3)].expr_node), NEQUALS, (yyvsp[(3) - (3)].expr_node)); ;}
    break;

  case 53:
#line 218 "lang.y"
    { (yyval.expr_node) = (yyvsp[(1) - (1)].expr_node); ;}
    break;

  case 54:
#line 220 "lang.y"
    { (yyval.expr_node) = new cBinaryExprNode((yyvsp[(1) - (3)].expr_node), '+', (yyvsp[(3) - (3)].expr_node)); ;}
    break;

  case 55:
#line 221 "lang.y"
    { (yyval.expr_node) = new cBinaryExprNode((yyvsp[(1) - (3)].expr_node), '-', (yyvsp[(3) - (3)].expr_node)); ;}
    break;

  case 56:
#line 222 "lang.y"
    { (yyval.expr_node) = (yyvsp[(1) - (1)].expr_node); ;}
    break;

  case 57:
#line 224 "lang.y"
    { (yyval.expr_node) = new cBinaryExprNode((yyvsp[(1) - (3)].expr_node), '*', (yyvsp[(3) - (3)].expr_node)); ;}
    break;

  case 58:
#line 225 "lang.y"
    { (yyval.expr_node) = new cBinaryExprNode((yyvsp[(1) - (3)].expr_node), '/', (yyvsp[(3) - (3)].expr_node)); ;}
    break;

  case 59:
#line 226 "lang.y"
    { (yyval.expr_node) = new cBinaryExprNode((yyvsp[(1) - (3)].expr_node), '%', (yyvsp[(3) - (3)].expr_node)); ;}
    break;

  case 60:
#line 227 "lang.y"
    { (yyval.expr_node) = (yyvsp[(1) - (1)].expr_node); ;}
    break;

  case 61:
#line 229 "lang.y"
    { (yyval.expr_node) = (yyvsp[(2) - (3)].expr_node); ;}
    break;

  case 62:
#line 230 "lang.y"
    { (yyval.expr_node) = new cIntExprNode((yyvsp[(1) - (1)].int_val)); ;}
    break;

  case 63:
#line 231 "lang.y"
    { (yyval.expr_node) = new cFloatExprNode((yyvsp[(1) - (1)].float_val)); ;}
    break;

  case 64:
#line 232 "lang.y"
    { (yyval.expr_node) = (yyvsp[(1) - (1)].varref_node); ;}
    break;

  case 65:
#line 233 "lang.y"
    { (yyval.expr_node) = (yyvsp[(1) - (1)].funccall_node); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 1918 "langparse.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[0] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the look-ahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 235 "lang.y"


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
    std::cout << "ERROR: " << error << " on line " << yylineno << "\n";
    g_semanticErrorHappened = true;
    yynerrs++;
}


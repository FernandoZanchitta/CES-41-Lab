/****************************************************/
/* File: tiny.y                                     */
/* The TINY Yacc/Bison specification file           */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/
%{
#define YYPARSER /* distinguishes Yacc output from other code files */

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"

#define YYSTYPE TreeNode *
static char * savedName; /* for use in assignments */
static int savedLineNo;  /* ditto */
static TreeNode * savedTree; /* stores syntax tree for later return */
static int yylex(void);
int yyerror(char *s);

%}

%token ID NUM 
%token IF ELSE INT RETURN VOID WHILE WRITE
%token PLUS MINUS TIMES OVER LESS LEQ GREATER GEQ COMPARE
%token DIFF ASSIGN SEMI COMMA LPAREN RPAREN LCOLCH RCOLCH LBRAC RBRAC
%token BEGCOM ENDCOM
%token ERROR
%token ENDFILE

%% /* Grammar for C- */

program     
      : decl_lista {} 
      ;
decl_lista    
      : decl_lista decl {}
      | decl  {}
      ;
decl        
      : var_decl {}
      | func_decl {}
      | error {}
      ;
var_decl    
      : type_esp ID SEMI {}
      | type_esp ID LCOLCH NUM RCOLCH {}
      ;
type_esp    
      : VOID
      | INT
      ;
func_decl   
      : type_esp ID LPAREN params RPAREN comp_decl {}
      ;
params
      : param_list {}
      | VOID
      ;
param_list
      : param_list COMMA param {}
      | param {}
      ;
param
    :type_esp ID {}
    |type_esp ID LCOLCH RCOLCH {}
    ;
comp_decl
    : LBRAC local_decl stmt_lista RBRAC {}
    ;
local_decl
    : local_decl var_decl {}
    | VOID
    ;
stmt_lista
    : stmt_lista stmt {}
    | VOID
    ;
stmt
    : exp_decl {}
    | comp_decl {}
    | sel_decl {}
    | repeat_decl {}
    | return_decl {}
    ;
exp_decl
    : exp SEMI {}
    | SEMI
    ;
sel_decl
    : IF LPAREN exp RPAREN stmt {}
    | IF LPAREN exp RPAREN stmt ELSE stmt {}
    ;
repeat_decl
    : WHILE LPAREN exp RPAREN stmt {}
    ;
return_decl
    : RETURN SEMI {}
    | RETURN exp SEMI {}
    ;
exp
    : var ASSIGN exp {}
    | simple_exp {}
    ;
var
    : ID {}
    | ID LCOLCH exp RCOLCH {}
    ;
simple_exp
    : soma_exp relacional soma_exp {}
    | soma_exp {}
    ;
relacional 
    : LEQ
    | LESS
    | GREATER
    | GEQ
    | COMPARE
    | DIFF
    ;
soma_exp
    : soma_exp soma term {}
    | term {}
    ;
soma
    : PLUS
    | MINUS
    ;
term
    : term mult factor {}
    | factor {}
    ;
mult
    : TIMES
    | OVER
    ;
factor
    : LPAREN exp RPAREN {}
    | var {}
    | ativation {}
    | NUM
    ;
ativation
    : ID LPAREN args RPAREN {}
    ;
args
    : arg_lista {}
    | VOID
    ;
arg_lista
    : arg_lista COMMA exp {}
    | exp {}
    ;
%%

int yyerror(char * message)
{ fprintf(listing,"Syntax error at line %d: %s\n",lineno,message);
  fprintf(listing,"Current token: ");
  printToken(yychar,tokenString);
  Error = TRUE;
  return 0;
}

/* yylex calls getToken to make Yacc/Bison output
 * compatible with ealier versions of the TINY scanner
 */
static int yylex(void)
{ return getToken(); }

TreeNode * parse(void)
{ yyparse();
  return savedTree;
}


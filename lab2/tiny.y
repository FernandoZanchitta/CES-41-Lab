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
%token LPAREN
%token RPAREN
%token DIFF ASSIGN SEMI COMMA  LCOLCH RCOLCH LBRAC RBRAC
%token BEGCOM ENDCOM
%token ERROR
%token ENDFILE

%% /* Grammar for C- */

program     
      : decl_lista {savedTree = $1;} 
      ;
decl_lista    
      : decl_lista decl {YYSTYPE t = $1;
                         if (t != NULL)
                         { while (t->sibling != NULL)
                             t = t->sibling;
                           t->sibling = $2;
                           $$ = $1;
                         }
                         else $$ = $2;
                        }
      | decl {
            $$ = $1;
        }
      ;
decl        
      : var_decl {$$ = $1;}
      | func_decl {printf(" Entrou em func_decl\n");}
      ;
var_decl    
      : type_esp ID{
        printf("tokenString: %s\n", tokenString);
        savedName = copyString(tokenString);
        savedLineNo = lineno; 
        
        }
        SEMI{
        $$ = $1;
        $$->child[0] = newDeclNode(VarK);

        $$->child[0]->type = $1->type;
        $$->child[0]->attr.name = savedName;
        $$->child[0]->lineno = savedLineNo;
        printf("lineno: %d\n", $$->child[0]->lineno);
        }
      | type_esp ID {
        savedName = copyString(tokenString);
        savedLineNo = lineno; 
        } LCOLCH NUM RCOLCH SEMI {
            $$ = $1;
            $$->child[0] = newDeclNode(ArrayK);
            $$->child[0]->type = $1->type;
            $$->child[0]->attr.name = savedName;
            $$->child[0]->lineno = savedLineNo;
        }
      ;
type_esp    
      : INT {$$ = newTypeNode(Integer);}
      | VOID {$$ = newTypeNode(Void);}
      ;
func_decl   
      : type_esp ID {
        savedName = copyString(tokenString);
        savedLineNo = lineno; 
      }LPAREN params RPAREN comp_decl {
        printf(" Entrou em type_esp ID LPAREN params RPAREN comp_decl\n");
        $$ = $1;
        $$->child[0] = newFuncNode();
        $$->child[0]->type = $1->type;
        $$->child[0]->attr.name = savedName;
        $$->child[0]->lineno = savedLineNo;
        $$->child[0]->child[0] = $5;
        $$->child[0]->child[1] = $7;
        }
      ;
params
      : param_list {
        printf(" Entrou em param_list\n");
        $$ = $1;
      }
      | VOID {printf(" Entrou em VOID\n");}
      ;
param_list
      : param_list COMMA param {
        printf(" Entrou em param_list COMMA param\n");
        YYSTYPE t = $1;
        if (t != NULL)
        { while (t->sibling != NULL)
            t = t->sibling;
        t->sibling = $3;
        $$ = $1;
        }
        else $$ = $3;
                        
        }
      | param {
        printf(" Entrou em param\n");
        $$ = $1;
        }
      ;
param
    :type_esp ID {
        printf(" Entrou em type_esp ID\n");
        savedName = copyString(tokenString);
        savedLineNo = lineno; 
        $$ = $1;
        $$->child[0] = newParamNode(VarK);
        $$->child[0]->type = $1->type;
        $$->child[0]->attr.name = savedName;
        $$->child[0]->lineno = lineno;
        }
    |type_esp ID{
        savedName = copyString(tokenString);
        savedLineNo = lineno;
    } LCOLCH RCOLCH {
        printf(" Entrou em type_esp ID LCOLCH RCOLCH\n");
        $$ = $1;
        $$->child[0] = newParamNode(ArrayK);
        $$->child[0]->type = $1->type;
        $$->child[0]->attr.name = savedName;
        $$->child[0]->lineno = lineno;
    }
    ;
comp_decl
    : LBRAC local_decl stmt_lista RBRAC {
        printf(" Entrou em LBRAC local_decl stmt_lista RBRAC\n");
        // considerando o local_decl e stmt_lista irmãos
    }
    ;
local_decl
    : local_decl var_decl {
        printf(" Entrou em local_decl var_decl\n");
        YYSTYPE t = $1;
        if (t != NULL)
        { while (t->sibling != NULL)
            t = t->sibling;
        t->sibling = $2;
        $$ = $1;
        }
        else $$ = $2;
        }
    | %empty {
        printf(" Entrou em empty\n");
        }
    ;
stmt_lista
    : stmt_lista stmt {
        printf(" Entrou em stmt_lista stmt\n");
        YYSTYPE t = $1;
        if (t != NULL)
        { while (t->sibling != NULL)
            t = t->sibling;
        t->sibling = $2;
        $$ = $1;
        }
        else $$ = $2;
        }
    | %empty {
        printf(" Entrou em empty\n");
        }
    ;
stmt
    : exp_decl {printf(" Entrou em exp_decl\n");}
    | comp_decl {printf(" Entrou em comp_decl\n");}
    | sel_decl {printf(" Entrou em sel_decl\n");}
    | repeat_decl {printf(" Entrou em repeat_decl\n");}
    | return_decl {printf(" Entrou em return_decl\n");}
    ;
exp_decl
    : exp SEMI {printf(" Entrou em exp SEMI\n");}
    | SEMI {printf(" Entrou em SEMI\n");}
    ;
sel_decl
    : IF LPAREN exp RPAREN stmt {printf(" Entrou em IF LPAREN exp RPAREN stmt\n");}
    | IF LPAREN exp RPAREN stmt ELSE stmt {printf(" Entrou em IF LPAREN exp RPAREN stmt ELSE stmt\n");}
    ;
repeat_decl
    : WHILE LPAREN exp RPAREN stmt {printf(" Entrou em WHILE LPAREN exp RPAREN stmt\n");}
    ;
return_decl
    : RETURN SEMI {printf(" Entrou em RETURN SEMI\n");}
    | RETURN exp SEMI {printf(" Entrou em RETURN exp SEMI\n");}
    ;
exp
    : var ASSIGN exp {printf(" Entrou em var ASSIGN exp\n");}
    | simple_exp {printf(" Entrou em simple_exp\n");}
    ;
var
    : ID {printf(" Entrou em ID\n");}
    | ID LCOLCH exp RCOLCH {printf(" Entrou em ID LCOLCH exp RCOLCH\n");}
    ;
simple_exp
    : soma_exp relacional soma_exp {printf(" Entrou em soma_exp relacional soma_exp\n");}
    | soma_exp {printf(" Entrou em soma_exp\n");}
    ;
relacional 
    : LEQ {printf(" Entrou em LEQ\n");}
    | LESS {printf(" Entrou em LESS\n");}
    | GREATER {printf(" Entrou em GREATER\n");}
    | GEQ {printf(" Entrou em GEQ\n");}
    | COMPARE{printf(" Entrou em COMPARE\n");}
    | DIFF {printf(" Entrou em DIFF\n");}
    ;
soma_exp
    : soma_exp soma term {printf(" Entrou em soma_exp soma term\n");}
    | term {printf(" Entrou em term\n");}
    ;
soma
    : PLUS {printf(" Entrou em PLUS\n");}
    | MINUS {printf(" Entrou em MINUS\n");}
    ;
term
    : term mult factor {printf(" Entrou em term mult factor\n");}
    | factor {printf(" Entrou em factor\n");}
    ;
mult
    : TIMES {printf(" Entrou em TIMES\n");}
    | OVER {printf(" Entrou em OVER\n");}
    ;
factor
    : LPAREN exp RPAREN {printf(" Entrou em LPAREN\n");}
    | var {printf(" Entrou em var\n");}
    | ativation {printf(" Entrou em activation\n");}
    | NUM {printf(" Entrou em NUM\n");}
    ;
ativation
    : ID LPAREN args RPAREN {printf(" Entrou em ID LPAREN args RPAREN\n");}
    ;
args
    : arg_lista {printf(" Entrou em arg_lista\n");}
    | %empty {printf(" Entrou em empty\n");}
    ;
arg_lista
    : arg_lista COMMA exp {printf(" Entrou em arg_lista COMMA exp\n");}
    | exp {printf(" Entrou em exp\n");}
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


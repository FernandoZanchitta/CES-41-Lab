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
      | func_decl {
        // printf(" Entrou em func_decl\n");
        $$ = $1;
      }
      ;
var_decl    
      : type_esp ID{
        // printf("ID_name em var_decl: %s\n", ID_name);
        savedName = copyString(ID_name);
        savedLineNo = lineno; 
        
        }
        SEMI{
        $$ = $1;
        $$->child[0] = newDeclNode(VarK);

        $$->child[0]->type = $1->type;
        $$->child[0]->attr.name = savedName;
        $$->child[0]->lineno = savedLineNo;
        // printf("lineno: %d\n", $$->child[0]->lineno);
        }
      | type_esp ID {
        savedName = copyString(ID_name);
        savedLineNo = lineno; 
        } LCOLCH NUM RCOLCH SEMI {
            $$ = $1;
            $$->child[0] = newDeclNode(ArrayK);
            $$->child[0]->type = $1->type;
            $$->child[0]->attr.name = savedName;
            $$->child[0]->lineno = savedLineNo;
            $$->child[0]->child[1] = newExpNode(ConstK);
            $$->child[0]->child[1]->attr.val = atoi(copyString(NUM_name));
        }
      ;
type_esp    
      : INT {$$ = newTypeNode(Integer);}
      | VOID {$$ = newTypeNode(Void);}
      ;
func_decl   
      : type_esp ID {
        savedName = copyString(ID_name);
        savedLineNo = lineno;
        $$ = $1;
        $$->child[0] = newDeclNode(FuncK);
        $$->child[0]->attr.name = savedName;
        $$->child[0]->lineno = savedLineNo;
      }LPAREN params RPAREN comp_decl {
        // fprintf(listing," Entrou em type_esp ID LPAREN params RPAREN comp_decl\n");
        $$ = $3;
        $$->child[0]->type = $1->type;        
        $$->child[0]->child[0] = $5;
        $$->child[0]->child[1] = $7;
        }
      ;
params
      : param_list {
        // printf(" Entrou em param_list\n");
        $$ = $1;
      }
      | VOID {
        // printf(" Entrou em VOID\n");
        $$ = NULL;
        }
      ;
param_list
      : param_list COMMA param {
        // printf(" Entrou em param_list COMMA param\n");
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
        // printf(" Entrou em param\n");
        $$ = $1;
        }
      ;
param
    :type_esp ID {
        // fprintf(listing,"ID_name em param: %s\n", ID_name); 
        $$ = $1;
        $$->child[0] = newParamNode(VarK);
        $$->child[0]->type = $1->type;
        $$->child[0]->attr.name = copyString(ID_name);
        $$->child[0]->lineno = lineno;
        }
    |type_esp ID LCOLCH RCOLCH {
        // printf(" Entrou em type_esp ID LCOLCH RCOLCH\n");
        $$ = $1;
        $$->child[0] = newParamNode(ArrayK);
        $$->child[0]->type = $1->type;
        $$->child[0]->attr.name = copyString(ID_name);
        $$->child[0]->lineno = lineno;
    }
    ;
comp_decl
    : LBRAC local_decl stmt_lista RBRAC {
        // printf(" Entrou em LBRAC local_decl stmt_lista RBRAC\n");
        // considerando o local_decl e stmt_lista irmãos
        YYSTYPE t = $2;
        if (t != NULL)
        { while (t->sibling != NULL)
            t = t->sibling;
        t->sibling = $3;
        $$ = $2;
        }
        else{
            $$ = $3;
        } 
    }
    ;
local_decl
    : local_decl var_decl {
        // printf(" Entrou em local_decl var_decl\n");
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
        // printf(" Entrou em empty\n");
        $$ = NULL;
        }
    ;
stmt_lista
    : stmt_lista stmt {
        // printf(" Entrou em stmt_lista stmt\n");
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
        // printf(" Entrou em empty\n");
        $$ = NULL;
        }
    ;
stmt
    : exp_decl {
        // printf(" Entrou em exp_decl\n");
        $$ = $1;
        }
    | comp_decl {
        // printf(" Entrou em comp_decl\n");
        $$ = $1;
        }
    | sel_decl {
        // printf(" Entrou em sel_decl\n");
        $$ = $1;
        }
    | repeat_decl {
        // printf(" Entrou em repeat_decl\n");
        $$ = $1;
        }
    | return_decl {
        // printf(" Entrou em return_decl\n");
        $$ = $1;
        }
    ;
exp_decl
    : exp SEMI {
        // printf(" Entrou em exp SEMI\n");
        $$ = $1;
        }
    | SEMI {
        // printf(" Entrou em SEMI\n");
        }
    ;
sel_decl
    : IF LPAREN exp RPAREN stmt {
        // printf(" Entrou em IF LPAREN exp RPAREN stmt\n");
        $$ = newStmtNode(IfK);
        $$->child[0] = $3;
        $$->child[1] = $5;

        }
    | IF LPAREN exp RPAREN stmt ELSE stmt {
        // printf(" Entrou em IF LPAREN exp RPAREN stmt ELSE stmt\n");
        $$ = newStmtNode(IfK);
        $$->child[0] = $3;
        $$->child[1] = $5;
        $$->child[2] = $7;
        }
    ;
repeat_decl
    : WHILE LPAREN exp RPAREN stmt {
        // printf(" Entrou em WHILE LPAREN exp RPAREN stmt\n");
        $$ = newStmtNode(RepeatK);
        $$->child[0] = $3;
        $$->child[1] = $5;
        }
    ;
return_decl
    : RETURN SEMI {
        // printf(" Entrou em RETURN SEMI\n");
        $$ = newStmtNode(ReturnK);
        $$->attr.name = copyString(tokenString);
        }
    | RETURN exp SEMI {
        // printf(" Entrou em RETURN exp SEMI\n");
        $$ = newStmtNode(ReturnK);
        $$->child[0] = $2;
        $$->attr.name = copyString(tokenString);
        }

    ;
exp
    : var ASSIGN exp {
        // printf(" Entrou em var ASSIGN exp\n");
        $$ = newStmtNode(AssignK);
        $$->child[0] = $1;
        $$->child[1] = $3;
        // $$->attr.op = ASSIGN;
        //$$->attr.name = $1->attr.name; // atribui o nome da variável
        }
    | simple_exp {
        // printf(" Entrou em simple_exp\n");
        $$ = $1;
        }
    ;
var
    : ID {
        // printf(" Entrou em ID\n");
        $$ = newExpNode(IdK);
        $$->attr.name = copyString(ID_name);
        }
    | ID {
        savedName = copyString(ID_name);
        savedLineNo = lineno;
        }
    LCOLCH exp RCOLCH {
        // printf(" Entrou em ID LCOLCH exp RCOLCH\n");
        // todo: entender qual tipo de no é esse
        $$ = newExpNode(IdK);
        $$->attr.name = savedName;
        $$->child[0] = $4;
        $$->lineno = savedLineNo;
        }
    ;
simple_exp
    : soma_exp relacional soma_exp {
        // printf(" Entrou em soma_exp relacional soma_exp\n");
        $$ = $2;
        $$->child[0] = $1;
        $$->child[1] = $3;
        $$->lineno = lineno;
        }
    | soma_exp {
        // printf(" Entrou em soma_exp\n");
        $$ = $1;
        }
    ;
relacional 
    : LEQ {
        // printf(" Entrou em LEQ\n");
        $$ = newExpNode(OpK);
        $$->attr.op = LEQ;
    }
    | LESS {
        // printf(" Entrou em LESS\n");
        $$ = newExpNode(OpK);
        $$->attr.op = LESS;
        }
    | GREATER {
        // printf(" Entrou em GREATER\n");
        $$ = newExpNode(OpK);
        $$->attr.op = GREATER;
        }
    | GEQ {
        // printf(" Entrou em GEQ\n");
        $$ = newExpNode(OpK);
        $$->attr.op = GEQ;
        }
    | COMPARE{
        // printf(" Entrou em COMPARE\n");
        $$ = newExpNode(OpK);
        $$->attr.op = COMPARE;
        }
    | DIFF {
        // printf(" Entrou em DIFF\n");
        $$ = newExpNode(OpK);
        $$->attr.op = DIFF;
        }
    ;
soma_exp
    : soma_exp soma term {
        // printf(" Entrou em soma_exp soma term\n");
        $$ = $2;
        $$->child[0] = $1;
        $$->child[1] = $3;
        $$->lineno = lineno;
    }
    | term {
        // printf(" Entrou em term\n");
        $$ = $1;
        }
    ;
soma
    : PLUS {
        // printf(" Entrou em PLUS\n");
        $$ = newExpNode(OpK);
        $$->attr.op = PLUS;
        }
    | MINUS {
        // printf(" Entrou em MINUS\n");
        $$ = newExpNode(OpK);
        $$->attr.op = MINUS;
        }
    ;
term
    : term mult factor {
        // printf(" Entrou em term mult factor\n");
        $$ = $2;
        $$->child[0] = $1;
        $$->child[1] = $3;
        $$->attr.op = $2->attr.op;
        }
    | factor {
        // printf(" Entrou em factor\n");
        $$ = $1;
        }
    ;
mult
    : TIMES {
        // printf(" Entrou em TIMES\n");
        $$ = newExpNode(OpK);
        $$->attr.op = TIMES;
        }
    | OVER {
        // printf(" Entrou em OVER\n");
        $$ = newExpNode(OpK);
        $$->attr.op = OVER;
        }
    ;
factor
    : LPAREN exp RPAREN {
        // printf(" Entrou em LPAREN exp RPAREN\n");
        $$ = $2;
        }
    | var {
        // printf(" Entrou em var\n");
        $$ = $1;
        }
    | ativation {
        // printf(" Entrou em activation\n");
        $$ = $1;
        }
    | NUM {
        // printf(" Entrou em NUM\n");
        $$ = newExpNode(ConstK);
        // fprintf(listing, "NUM: %s\n", tokenString);
        $$->attr.val = atoi(tokenString);
        }
    ;
ativation
    : ID {
        savedName = copyString(ID_name);
        savedLineNo = lineno;
    }LPAREN args RPAREN {
        // printf(" Entrou em ID LPAREN args RPAREN\n");
        $$ = newExpNode(ActivationK);
        $$->attr.name = savedName;
        $$->child[0] = $4;
        $$->lineno = savedLineNo;
        }
    ;
args
    : arg_lista {
        // printf(" Entrou em arg_lista\n");
        $$ = $1;
        }
    | %empty {
        // printf(" Entrou em empty\n");
        $$ = NULL;
        }
    ;
arg_lista
    : arg_lista COMMA exp {
        // printf(" Entrou em arg_lista COMMA exp\n");
        YYSTYPE t = $1;
        if (t != NULL)
        { while (t->sibling != NULL)
            t = t->sibling;
        t->sibling = $3;
        $$ = $1;
        }
        else $$ = $3;}
    | exp {
        // printf(" Entrou em exp\n");
        $$ = $1;
        }
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


/****************************************************/
/* File: util.c                                     */
/* Utility function implementation                  */
/* for the TINY compiler                            */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include "globals.h"
#include "util.h"

/* Procedure printToken prints a token 
 * and its lexeme to the listing file
 */
void printToken( TokenType token, const char* tokenString)
{ 
  
  switch (token)
  { 
    case BEGCOM:
      FlagComment = 1;
      break;
    case ENDCOM: 
      FlagComment = 0;
      break;
    case IF:
    case INT:
    case ELSE:
    case RETURN:
    case VOID:
    case WHILE:
    case WRITE:
      if(FlagComment == 0){
      fprintf(listing,"\t%d: ",lineno);
      fprintf(listing,
         "reserved word: %s\n",tokenString);
      }
      break;
    case PLUS: if(FlagComment == 0){ fprintf(listing,"\t%d: ",lineno); fprintf(listing,"+\n");} break;
    case MINUS: if(FlagComment == 0){ fprintf(listing,"\t%d: ",lineno); fprintf(listing,"-\n");} break;
    case TIMES: if(FlagComment == 0){ fprintf(listing,"\t%d: ",lineno); fprintf(listing,"*\n");} break;
    case OVER: if(FlagComment == 0){ fprintf(listing,"\t%d: ",lineno); fprintf(listing,"/\n");} break;
    case LESS: if(FlagComment == 0){ fprintf(listing,"\t%d: ",lineno); fprintf(listing,"<\n");} break;
    case LEQ: if(FlagComment == 0){ fprintf(listing,"\t%d: ",lineno); fprintf(listing,"<=\n");} break;
    case GREATER: if(FlagComment == 0){ fprintf(listing,"\t%d: ",lineno); fprintf(listing,">\n");} break;
    case GEQ: if(FlagComment == 0){ fprintf(listing,"\t%d: ",lineno); fprintf(listing,">=\n");} break;
    case ASSIGN: if(FlagComment == 0){ fprintf(listing,"\t%d: ",lineno); fprintf(listing,"=\n");} break;
    case COMPARE: if(FlagComment == 0){ fprintf(listing,"\t%d: ",lineno); fprintf(listing,"==\n");} break;
    case DIFF: if(FlagComment == 0){ fprintf(listing,"\t%d: ",lineno); fprintf(listing,"!=\n");} break;
    case SEMI: if(FlagComment == 0){ fprintf(listing,"\t%d: ",lineno); fprintf(listing,";\n");} break;
    case COMMA: if(FlagComment == 0){ fprintf(listing,"\t%d: ",lineno); fprintf(listing,",\n");} break;
    case LPAREN: if(FlagComment == 0){ fprintf(listing,"\t%d: ",lineno); fprintf(listing,"(\n");} break;
    case RPAREN: if(FlagComment == 0){ fprintf(listing,"\t%d: ",lineno); fprintf(listing,")\n");} break;
    case LCOLCH: if(FlagComment == 0){ fprintf(listing,"\t%d: ",lineno); fprintf(listing,"[\n");} break;
    case RCOLCH: if(FlagComment == 0){ fprintf(listing,"\t%d: ",lineno); fprintf(listing,"]\n");} break;
    case LBRAC: if(FlagComment == 0){ fprintf(listing,"\t%d: ",lineno); fprintf(listing,"{\n");} break;
    case RBRAC: if(FlagComment == 0){ fprintf(listing,"\t%d: ",lineno); fprintf(listing,"}\n");} break;
    case ENDFILE: if(FlagComment == 0){ fprintf(listing,"\t%d: ",lineno); fprintf(listing,"EOF\n");} break;
    case NUM: 
      if(FlagComment == 0){
        fprintf(listing,"\t%d: ",lineno);
      fprintf(listing,
          "NUM, val= %s\n",tokenString);
      }
      break;
    case ID:
      if(FlagComment == 0){
        fprintf(listing,"\t%d: ",lineno);
      fprintf(listing,
          "ID, name= %s\n",tokenString);
      }
      break;
    case ERROR:
      if(FlagComment == 0){
        fprintf(listing,"\t%d: ",lineno);
      fprintf(listing,
          "ERROR: %s\n",tokenString);
      }
      break;
    default: /* should never happen */
      fprintf(listing,"\t%d: ",lineno);
      fprintf(listing,"Unknown token: %d\n",token);
  }
}

/* Function newStmtNode creates a new statement
 * node for syntax tree construction
 */
TreeNode * newStmtNode(StmtKind kind)
{ TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
  int i;
  if (t==NULL)
    fprintf(listing,"Out of memory error at line %d\n",lineno);
  else {
    for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
    t->sibling = NULL;
    t->nodekind = StmtK;
    t->kind.stmt = kind;
    t->lineno = lineno;
  }
  return t;
}

/* Function newExpNode creates a new expression 
 * node for syntax tree construction
 */
TreeNode * newExpNode(ExpKind kind)
{ TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
  int i;
  if (t==NULL)
    fprintf(listing,"Out of memory error at line %d\n",lineno);
  else {
    for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
    t->sibling = NULL;
    t->nodekind = ExpK;
    t->kind.exp = kind;
    t->lineno = lineno;
    t->type = Void;
  }
  return t;
}

/* Function copyString allocates and makes a new
 * copy of an existing string
 */
char * copyString(char * s)
{ int n;
  char * t;
  if (s==NULL) return NULL;
  n = strlen(s)+1;
  t = malloc(n);
  if (t==NULL)
    fprintf(listing,"Out of memory error at line %d\n",lineno);
  else strcpy(t,s);
  return t;
}

/* Variable indentno is used by printTree to
 * store current number of spaces to indent
 */
static int indentno = 0;

/* macros to increase/decrease indentation */
#define INDENT indentno+=2
#define UNINDENT indentno-=2

/* printSpaces indents by printing spaces */
static void printSpaces(void)
{ int i;
  for (i=0;i<indentno;i++)
    fprintf(listing," ");
}

/* procedure printTree prints a syntax tree to the 
 * listing file using indentation to indicate subtrees
 */
void printTree( TreeNode * tree )
{ int i;
  INDENT;
  while (tree != NULL) {
    printSpaces();
    if (tree->nodekind==StmtK)
    { switch (tree->kind.stmt) {
        case IfK:
          fprintf(listing,"If\n");
          break;
        case RepeatK:
          fprintf(listing,"Repeat\n");
          break;
        case AssignK:
          fprintf(listing,"Assign to: %s\n",tree->attr.name);
          break;
        case ReadK:
          fprintf(listing,"Read: %s\n",tree->attr.name);
          break;
        case WriteK:
          fprintf(listing,"Write\n");
          break;
        default:
          fprintf(listing,"Unknown ExpNode kind\n");
          break;
      }
    }
    else if (tree->nodekind==ExpK)
    { switch (tree->kind.exp) {
        case OpK:
          fprintf(listing,"Op: ");
          printToken(tree->attr.op,"\0");
          break;
        case ConstK:
          fprintf(listing,"Const: %d\n",tree->attr.val);
          break;
        case IdK:
          fprintf(listing,"Id: %s\n",tree->attr.name);
          break;
        default:
          fprintf(listing,"Unknown ExpNode kind\n");
          break;
      }
    }
    else fprintf(listing,"Unknown node kind\n");
    for (i=0;i<MAXCHILDREN;i++)
         printTree(tree->child[i]);
    tree = tree->sibling;
  }
  UNINDENT;
}

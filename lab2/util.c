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
void printToken( TokenType token, const char* tokenString )
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
/*
Stack_id functions
*/
void create_stack_id(Stack_id * stack){
  stack = (Stack_id *) malloc(sizeof(Stack_id));
  stack->next = NULL;
}
void push_back_id(char *id,Stack_id * stack){
  Stack_id * new = (Stack_id *)malloc(sizeof(Stack_id));
  new->id = id;
  new->next = NULL;
  if(stack == NULL){
    // allocate memory for stack
    stack = new;
  }
  else if(stack->next == NULL){
    stack->next = new;
  }else{
    fprintf(listing,"Pushing %s\n",id);
    Stack_id * aux = stack->next;
    while(aux->next != NULL){
      aux = aux->next;
    }
    aux->next = new;
  }
}
void pop_id(Stack_id * stack){
  if(stack->next != NULL){
    Stack_id * aux = stack->next;
    while(aux->next->next != NULL){
      aux = aux->next;
    }
    free(aux->next);
    aux->next = NULL;
  }
}
char * top_id(Stack_id * stack){
  if(stack->next != NULL){
    Stack_id * aux = stack->next;
    while(aux->next != NULL){
      aux = aux->next;
    }
    fprintf(listing,"Top id\n"); 
    return aux->id;
  }
  else{
     
    return stack->id;
  }
  return NULL;
}
    

/* Function newStmtNode creates a new statement
 * node for syntax tree construction
 */
TreeNode * newStmtNode(StmtKind kind)
{ TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
  int i;
  if (t==NULL) // so entra se não conseguir alocar memória
    fprintf(listing,"Out of memory error at line %d\n",lineno);
  else { // se conseguiu alocar memória
    for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;// inicializa os filhos
    t->sibling = NULL; // inicializa o irmão
    t->nodekind = StmtK; // define o tipo de nó
    t->kind.stmt = kind; // Pode ser: IfK, RepeatK, AssignK, ReadK, WriteK
    t->lineno = lineno; // define a linha
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
    t->nodekind = ExpK;// Poder ser: StmtK, ExpK, DeclK
    t->kind.exp = kind;// Pode ser: OpK, ConstK, IdK
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
  n = strlen(s)+1; // +1 para o '\0'
  t = malloc(n); // aloca memória
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
          fprintf(listing,"Enter Assign\n");
          break;
        case ReturnK:
          fprintf(listing,"Return\n");
          break;
        default:
          fprintf(listing,"Unknown ExpNode kind\n");
          break;
      }
    }
    else if (tree->nodekind==ExpK)
    { switch (tree->kind.exp) {
        case OpK:
          fprintf(listing,"Op:");
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
    else if(tree->nodekind == TypeK){
      switch(tree->type){
        case Integer:
          fprintf(listing,"Integer Node\n");
          break;
        case Void:
          fprintf(listing,"Void Node\n");
          break;
        default:
          fprintf(listing,"Unknown TypeNode kind\n");
          break;
      }
    }
    else if(tree->nodekind==DeclK)
    { 
          
          // if(tree->type == Integer)
          //   fprintf(listing,"Type: Integer\n");
          // else if(tree->type == Void)
          //   fprintf(listing,"Type: Void\n");
          // else
          //   fprintf(listing,"Type: Unknown\n");
          switch (tree->kind.decl) 
          {
          case VarK:
              fprintf(listing, "ID: %s\n", tree->attr.name);
              break;
          case ArrayK:
              fprintf(listing, "ID: %s\n",tree->attr.name);
              break;
          default:
              break;
          }
    }
    else if(tree->nodekind == FuncK){
      fprintf(listing, "Function: %s\n", tree->attr.name);
    }
    else if(tree->nodekind == ParamK){
      fprintf(listing, "Param: %s\n", tree->attr.name);
    }
    else fprintf(listing,"Unknown node kind\n");
    for (i=0;i<MAXCHILDREN;i++)
         printTree(tree->child[i]);
    tree = tree->sibling;
  }
  UNINDENT;
}


TreeNode * newDeclNode(DeclKind kind)
{
  TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
  int i;
  if (t==NULL)
    fprintf(listing,"Out of memory error at line %d\n",lineno);
  else {
    for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
    t->sibling = NULL;
    t->nodekind = DeclK;
    t->kind.decl = kind;
    t->lineno = lineno;
  }
  return t;
}
TreeNode * newTypeNode(ExpType type){
  TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
  int i;
  if (t==NULL)
    fprintf(listing,"Out of memory error at line %d\n",lineno);
  else {
    for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
    t->sibling = NULL;
    t->nodekind = TypeK;
    t->type = type;
    t->lineno = lineno;
  }
  return t;
}

TreeNode * newParamNode(DeclKind kind)
{
  TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
  int i;
  if (t==NULL)
    fprintf(listing,"Out of memory error at line %d\n",lineno);
  else {
    for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
    t->sibling = NULL;
    t->nodekind = ParamK;
    t->kind.decl = kind;
    t->lineno = lineno;
  }
  return t;
}
TreeNode * newFuncNode(){
  TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
  int i;
  if (t==NULL)
    fprintf(listing,"Out of memory error at line %d",lineno);
  else {
    for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
    t->sibling = NULL;
    t->nodekind = FuncK;
    t->lineno = lineno;
  }
  return t;
}
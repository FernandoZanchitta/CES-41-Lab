/****************************************************/
/* File: analyze.c                                  */
/* Semantic analyzer implementation                 */
/* for the TINY compiler                            */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include "globals.h"
#include "symtab.h"
#include "analyze.h"

/* counter for variable memory locations */
static int location = 0;

static void typeError(TreeNode * t, char * message)
{ fprintf(listing,"Type error at line %d: %s\n",t->lineno,message);
  Error = TRUE;
}



/* Procedure traverse is a generic recursive 
 * syntax tree traversal routine:
 * it applies preProc in preorder and postProc 
 * in postorder to tree pointed to by t
 */
static void traverse( TreeNode * t,
               void (* preProc) (TreeNode *),
               void (* postProc) (TreeNode *) )
{ if (t != NULL)
  { preProc(t);
    { int i;
      for (i=0; i < MAXCHILDREN; i++)
        traverse(t->child[i],preProc,postProc);
    }
    postProc(t);
    traverse(t->sibling,preProc,postProc);
  }
}

/* nullProc is a do-nothing procedure to 
 * generate preorder-only or postorder-only
 * traversals from traverse
 */
static void nullProc(TreeNode * t)
{ if (t==NULL) return;
  else return;
}

/* Procedure insertNode inserts 
 * identifiers stored in t into 
 * the symbol table 
 */

/*
  Colocar na tabela de simbolos somentes as local_decl e param_decl (CUIDADO COM OS ESCOPOS);
  todo: Ainda não foi levado em consideração o escopo;
*/
static void insertNode( TreeNode * t)
{ switch (t->nodekind)
  {
    case DeclK:
      switch (t->kind.decl)
      { case VarK:
        case ArrayK:
          if (st_lookup_scope(t->attr.name, getScope()) == -1){
          /* not yet in table, so treat as new definition */
            if(t->type == Integer)
              st_insert(t->attr.name,t->lineno,location++, t->kind.decl, t->type);
            else
              typeError(t,"Type not supported");
          }else{
          /* already in table, so ignore location, 
             add line number of use only */
            typeError(t,"ERROR: Variable redeclared\n");

          }
          break;

        case FuncK:
          if (st_lookup_scope(t->attr.name,getScope()) == -1){
          /* not yet in table, so treat as new definition */
            st_insert(t->attr.name,t->lineno,location++, t->kind.decl, t->type);
            changeScope(t->attr.name);
          }
          else
          /* already in table, so print error message */
            typeError(t,"ERROR: Function redeclared\n");
          break;
        default:
          break;
      }
      break;
    case ParamK:
      switch (t->kind.decl)
      { case VarK:
        case ArrayK:
          if (st_lookup_scope(t->attr.name,getScope()) == -1)
          /* not yet in table, so treat as new definition */
            st_insert(t->attr.name,t->lineno,location++,t->kind.decl, t->type);
          else
          /* already in table, so ignore location, 
             add line number of use only */ 
            st_insert(t->attr.name,t->lineno,0,t->kind.decl, t->type);
          break;
        default:
          break;
      }
      break;
    case ExpK:
      switch (t->kind.exp)
      { case IdK:
          if(st_lookup_scope(t->attr.name,getScope()) == -1)
            fprintf(listing,"ERROR: Variable %s not declared in line %d", t->attr.name, t->lineno);
          else{
            st_insert(t->attr.name,t->lineno,0,t->kind.decl, t->type);
          }
          break;
        default:
          break;
      }
      break;
    default:
      break;
  }
}

/* Function buildSymtab constructs the symbol 
 * table by preorder traversal of the syntax tree
 */
void buildSymtab(TreeNode * syntaxTree)
{ 
  changeScope("global");
  traverse(syntaxTree,insertNode,checkScopeOver);
  if (TraceAnalyze)
  { fprintf(listing,"\nSymbol table:\n\n");
    printSymTab(listing);
  }
}


/* Procedure checkNode performs
 * type checking at a single tree node
 */
static void checkNode(TreeNode * t)
{ switch (t->nodekind)
  { case ExpK:
      switch (t->kind.exp)
      { case OpK:
          if ((t->child[0]->type != Integer) ||
              (t->child[1]->type != Integer)){
            // typeError(t,"Op applied to non-integer");

              }
          if ((t->attr.op == COMPARE) || (t->attr.op == LESS) || (t->attr.op == GREATER) 
             || (t->attr.op == DIFF) || (t->attr.op == LEQ) || (t->attr.op == GEQ))
            t->type = Void;
          else
            t->type = Integer;
          break;
        case ConstK:
          t->type = Integer;
          break;
        case IdK:
          t->type = st_lookup_type_data(t->attr.name);
          break;
        case ActivationK:
          t->type = st_lookup_type_data(t->attr.name);
          break;
        default:
          break;
      }
      break;
    case StmtK:
      switch (t->kind.stmt)
      { case IfK:
          if (t->child[0]->type == Integer) //TODO: resolver problema no IF
            typeError(t->child[0],"if test is not int");
          break;
        case AssignK:
          if (t->child[0]->type != Integer)//stm
            {
              typeError(t->child[0],"Left side assignment of non-integer value");
            }
          if(t->child[1]->type != t->child[0]->type)
            typeError(t->child[1],"Right side assignment of diferent type");
          break;
        default:
          break;
      }
      break;
    default:
      break;

  }
}

/* Procedure typeCheck performs type checking 
 * by a postorder syntax tree traversal
 */
void typeCheck(TreeNode * syntaxTree)
{ traverse(syntaxTree,nullProc,checkNode);
}

void checkMain(){
  st_find_main_bucket();
}


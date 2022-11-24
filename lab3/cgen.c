/****************************************************/
/* File: cgen.c                                     */
/* The code generator implementation                */
/* for the TINY compiler                            */
/* (generates code for the TM machine)              */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/
#include <stdio.h>
#include <string.h>
#include "globals.h"
#include "symtab.h"
#include "code.h"
#include "cgen.h"
#include "util.h"

/* tmpOffset is the memory offset for temps
   It is decremented each time a temp is
   stored, and incremeted when loaded again
*/
static int tmpOffset = 0;
static int ident = 0;
int registerNum = 0;
int codeBlockNum = 0;
/* prototype for internal recursive code generator */
static void cGen (TreeNode * tree);

/* Procedure genStmt generates code at a statement node */
static void genStmt( TreeNode * tree)
{ TreeNode * p1, * p2, * p3;
  int currentLoc, nextLoc;
  int loc;
  int registerId;

  switch (tree->kind.stmt) {

      case IfK :
         // printf("---- if k------\n");

         // if (TraceCode) emitComment("-> if") ;
         p1 = tree->child[0] ;
         p2 = tree->child[1] ;
         p3 = tree->child[2] ;
         /* generate code for test expression */
         int registerId = ac;
         cGen(p1);
         currentLoc = codeBlockNum;
         emitValidCondition(currentLoc, currentLoc);
         cGen(p3);
         nextLoc = codeBlockNum ;
         codeBlockNum++;
         emitIFK3(codeBlockNum);
         emitIFK4(nextLoc);
         cGen(p2);
         emitIFK4(nextLoc+1);
         // if (TraceCode)  emitComment("<- if") ;
         break; /* if_k */

      case RepeatK:
         // printf("---- repeat k------\n");

         p1 = tree->child[0] ;
         p2 = tree->child[1] ;
         registerId = ac;
         switch(p1->attr.op){
            case LESS:
               p1->attr.op = GEQ;
               break;
            case LEQ:
               p1->attr.op = GREATER;
               break;
            case GREATER:
               p1->attr.op = LEQ;
               break;
            case GEQ:
               p1->attr.op = LESS;
               break;
            case COMPARE:
               p1->attr.op = DIFF;
               break;
            case DIFF:
               p1->attr.op = COMPARE;
               break;
            default:
               break;;
         }
         currentLoc = codeBlockNum;
         emitCodeBlock(currentLoc);
         cGen(p1);
         emitValidCondition(registerId, currentLoc + 1);
         cGen(p2);
         emitIFK3(currentLoc);
         nextLoc = codeBlockNum ;
         codeBlockNum++;
         emitCodeBlock(nextLoc+1);
         /* generate code for test */
         // emitRM_Abs("JEQ",ac,savedLoc1,"repeat: jmp back to body");
         // if (TraceCode)  emitComment("<- repeat") ;
         break; /* repeat */

      case AssignK:
         // printf("---- assign k------\n");
         // if (TraceCode) emitComment("-> assign") ;
         /* generate code for rhs */
         p1 = tree->child[0];
         p2 = tree->child[1];
         registerId = ac;
         cGen(p2);
         // printTree(p1);
         // printf("\n\naqui teremos: %d\n", p1->kind.decl);
         if(p2->kind.exp == IdK){
            if (p2->child[0] != NULL ){
               if(p2->child[0]->kind.exp == ConstK){
                  if (p1->child[0] == NULL){
                     emitAssignArrayConstK(p1->attr.name, p2->attr.name, p2->child[0]->attr.val, registerId);
                  }
                  else {
                     if (p1->child[0]->kind.exp == ConstK){
                        emitAssignArrayConstKWithConst(p1->attr.name, p1->child[0]->attr.val,p2->attr.name, p2->child[0]->attr.val, registerId);
                     }
                     else {
                        emitAssignArrayConstKWithIdK(p1->attr.name, p1->child[0]->attr.name, p2->attr.name, p2->child[0]->attr.val, registerId);
                     }
                  }
               }
               else if (p2->child[0]->kind.exp == IdK){
                  if (p1->child[0] == NULL){
                     emitAssignArrayIdK(p1->attr.name, p2->attr.name, p2->child[0]->attr.name, registerId);
                  }
                  else {
                     if (p1->child[0]->kind.exp == ConstK){
                        emitAssignArrayIdKWithConst(p1->attr.name, p1->child[0]->attr.val,p2->attr.name, p2->child[0]->attr.name, registerId);
                     }
                     else {
                        emitAssignArrayIdKWithIdK(p1->attr.name, p1->child[0]->attr.name, p2->attr.name, p2->child[0]->attr.name, registerId);
                     }

                  }
               }
               else{
                  emitAssignArrayK(p2->attr.name, p2->child[0]->attr.name, registerId);
                  }
            }
            else{
            emitAssignKWithIdK(p1->attr.name, p2->attr.name,registerId);
            }
         }else{
            emitAssignK(p1->attr.name, registerId);
          }

         // if (TraceCode)  emitComment("<- assign") ;
         break; /* assign_k */
      default:
         // printf("\n---- default------\n");
         break;
    }
} /* genStmt */

void processExp(char* op, TreeNode * p1, TreeNode * p2, ExpKind p1_type, ExpKind p2_type, int op1, int op2){
   if (p1_type == OpK && p2_type == OpK){
      emitOp(op, ac, &op1, NULL, NULL, &op2, NULL, NULL, op);
   }
   else if (p1_type == OpK && p2_type == ConstK){
      emitOp(op, ac, &op1, NULL, NULL, NULL, &p2->attr.val, NULL, op);
   }
   else if (p1_type == OpK && p2_type == IdK){
      emitOp(op, ac, &op1, NULL, NULL, NULL, NULL, p2->attr.name, op);
   }
   else if (p1_type == IdK && p2_type == OpK){
      emitOp(op, ac, NULL, NULL, p1->attr.name, &op2, NULL, NULL, op);
   }
   else if (p1_type == IdK && p2_type == ConstK){
      emitOp(op, ac, NULL, NULL, p1->attr.name, NULL, &p2->attr.val, NULL, op);
   }
   else if (p1_type == IdK && p2_type == IdK){
      emitOp(op, ac, NULL, NULL, p1->attr.name, NULL, NULL, p2->attr.name,op);
   }
   else if (p1_type == ConstK && p2_type == OpK){
      emitOp(op, ac, NULL, &p1->attr.val, NULL, &op2, NULL, NULL, op);
   }
   else if (p1_type == ConstK && p2_type == IdK){
      emitOp(op, ac, NULL, &p1->attr.val, NULL, NULL, NULL, p2->attr.name, op);
   }
   else if (p1_type == ConstK && p2_type == ConstK){
      emitOp(op, ac, NULL, &p1->attr.val, NULL, NULL, &p2->attr.val, NULL, op);
   }
}

/* Procedure genExp generates code at an expression node */
static void genExp( TreeNode * tree)
{ int loc;
  TreeNode * p1, * p2;
  switch (tree->kind.exp) {

    case ConstK :
      // printf("----ConstK---\n");
      // if (TraceCode) emitComment("-> Const") ;
      /* gen code to load integer constant using LDC */
      // emitRM("LDC",ac,tree->attr.val,0,"load const");
      // emitConst(ac, tree->attr.val, "load const"); 
      // if (TraceCode)  emitComment("<- Const") ;
      break; /* ConstK */
    
    case IdK :
      // printf("----IdK---\n");
      if (TraceCode) emitComment("-> Id") ;
      loc = st_lookup(tree->attr.name);
      // emitRM("LD",ac,loc,gp,"load id value");
      // emitID(ac, loc, tree->attr.name,"load id value");
      // if (TraceCode)  emitComment("<- Id") ;
      break; /* IdK */
    case ActivationK:
      // printf("----ActivationK---\n");
      if (TraceCode) emitComment("-> Activation") ;
      int n_children = 3;
      emitActivation(tree->type, tree->attr.name, n_children);
      if (TraceCode)  emitComment("<- Activation") ;
      break; /* ActivationK */

    case OpK :
         // printf("----OpK---\n");
         // if (TraceCode) emitComment("-> Op") ; 
         p1 = tree->child[0];
         p2 = tree->child[1];
         // printTree(tree);
         /* gen code for ac = left arg */
         int p1_type = OpK;
         int p2_type = OpK;

         if (p1->nodekind == ExpK){
            if (p1->kind.exp == OpK){
               p1_type = OpK;
            }
            else{
               if (p1->kind.exp == IdK){
                  p1_type = IdK;
               }
               else {
                  p1_type = ConstK;
               }
            }
         }
         cGen(p1);
         int op1 = registerNum-1;


         if (p2->nodekind == ExpK){
            if (p2->kind.exp == OpK){
               p2_type = OpK;
            }
            else{
               if (p2->kind.exp == IdK){
                  p2_type = IdK;
               }
               else {
                  p2_type = ConstK;
               }
            }
         }
         cGen(p2);
         int op2 = registerNum-1;
   
         switch (tree->attr.op) {
            case PLUS :
               processExp("+", p1, p2, p1_type, p2_type, op1,op2); 
               break;
            case MINUS :
               processExp("-", p1, p2, p1_type, p2_type, op1,op2); 
               break;
            case TIMES :
               processExp("*", p1, p2, p1_type, p2_type, op1,op2); 
               break;
            case OVER :
               processExp("/", p1, p2, p1_type, p2_type, op1,op2); 
               break;
            case LESS :
               processExp("-", p1, p2, p1_type, p2_type, op1,op2); 
               break;
            case LEQ :
               processExp("<=", p1, p2, p1_type, p2_type, op1,op2); 
               break;
            case GREATER :
               processExp(">", p1, p2, p1_type, p2_type, op1,op2); 
               break;
            case GEQ :
               processExp(">=", p1, p2, p1_type, p2_type, op1,op2); 
               break;
            case COMPARE :
               processExp("==", p1, p2, p1_type, p2_type, op1,op2); 
               break;
            default:
               emitComment("BUG: Unknown operator");
               break;
         } /* case op */
         break; /* OpK */

    default:
      break;
  }
} /* genExp */



/* Procedure genType generates code at an expression node */
static void genType( TreeNode * tree)
{ 
  switch (tree->type) {
    case Void :
      if (TraceCode) emitComment("Ignored Void Declaration");
      cGen(tree->child[0]);
      break; /* Void */
    case Integer :
      if (TraceCode) emitComment("Ignored Integer Declaration");
      cGen(tree->child[0]);
      break; /* Integer */
    default:
      break;
      if (TraceCode)  emitComment("<- Not Recognized Type") ;
  }
} /* genType */

/* Procedure genType generates code at an expression node */
static void genDecl( TreeNode * tree)
{ 
   TreeNode * p1;
  switch (tree->kind.decl) {
    case VarK :
      // if (TraceCode) emitComment("Vark");
      cGen(tree->child[0]);
      break; /* Void */    
    case ArrayK :
      // if (TraceCode) emitComment("ArrayK");
      p1 = tree->child[1];

      cGen(tree->child[0]);
      break; /* Integer */
   case FuncK :
      // if (TraceCode) emitComment("FuncK");
      if (tree->type == Void) {
         fprintf(code, "void %s:\t", tree->attr.name);
      }
      else {
         fprintf(code, "int %s:\t", tree->attr.name);
      }
      int i = 0;
      char* param = malloc(2000);

      while (i < 10000){
         if (tree->child[i] != NULL) {
            cGen(tree->child[i]);
            if (tree->child[i+1] != NULL){
               if (tree->child[i]->child[0] != NULL){ 
                  if (tree->child[i]->child[0]->nodekind == ParamK && tree->child[i+1]->child[0]->nodekind != ParamK){
                     fprintf(code, "\n");
                  } 
               }
            }
         }
         else {
            break;
         }
         i++;
      }
      if (tree->type == Void) {
         fprintf(code, "return;\n");
      }
      else {
         fprintf(code, "return %s;\n", tree->child[i-1]->child[0]->attr.name);
      }
      break; /* Integer */
    default:
      break;
      if (TraceCode)  emitComment("default genDecl");
  }
} /* genType */

/* Procedure cGen recursively generates code by
 * tree traversal
 */
static void cGen( TreeNode * tree)
{ 
   if (tree != NULL)
  {  
   // ident ++;
   // for (int i = 0;i<ident;i++){
   //    printf("  ");
   // }
   switch (tree->nodekind) {
      case StmtK:
      //   printf("StmtK\n");
        genStmt(tree);
        break;
      case ExpK:
      //   printf("ExpK\n");
        genExp(tree);
        break;
      case DeclK:
      //   printf("DeclK\n");
        genDecl(tree);
        break;
      case TypeK:
         // printf("TypeK\n");
         genType(tree);
         break;
      case ParamK:
         // printf("ParamK\n");
         fprintf(code, "param %s ",tree->attr.name); 
         // genParam(tree);
         break;
      default:
        break;
    }

   if(tree->sibling != NULL){
      cGen(tree->sibling);
   }
  }
}

/**********************************************/
/* the primary function of the code generator */
/**********************************************/
/* Procedure codeGen generates code to a code
 * file by traversal of the syntax tree. The
 * second parameter (codefile) is the file name
 * of the code file, and is used to print the
 * file name as a comment in the code file
 */
void codeGen(TreeNode * syntaxTree, char * codefile)
{  char * s = malloc(strlen(codefile)+7);
   strcpy(s,"File: ");
   strcat(s,codefile);
   emitComment("TINY Compilation to TM Code");
   emitComment(s);
   /* generate standard prelude */
   // emitComment("Standard prelude:");
   // emitRM("LD",mp,0,ac,"load maxaddress from location 0");
   // emitRM("ST",ac,0,ac,"clear location 0");
   emitComment("Begin of execution.");
   /* generate code for TINY program */ 
   cGen(syntaxTree);
   /* finish */
   emitComment("End of execution.");
   // emitRO("HALT",0,0,0,"");
}

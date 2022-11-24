/****************************************************/
/* File: cgen.c                                     */
/* The code generator implementation                */
/* for the TINY compiler                            */
/* (generates code for the TM machine)              */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

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
registerNum = 0;
codeBlockNum = 0;
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
         printf("---- if k------\n");

         // if (TraceCode) emitComment("-> if") ;
         p1 = tree->child[0] ;
         p2 = tree->child[1] ;
         p3 = tree->child[2] ;
         /* generate code for test expression */
         int registerId = ac;
         cGen(p1);
         currentLoc = codeBlockNum;
         emitValidCondition(currentLoc);
         cGen(p3);
         nextLoc = codeBlockNum ;
         codeBlockNum++;
         emitIFK3(codeBlockNum);
         emitIFK4(nextLoc);
         cGen(p2);
         // if (TraceCode)  emitComment("<- if") ;
         break; /* if_k */

      case RepeatK:
         printf("---- repeat k------\n");

         // if (TraceCode) emitComment("-> repeat") ;
         p1 = tree->child[0] ;
         p2 = tree->child[1] ;
         // emitComment("repeat: jump after body comes back here");
         /* generate code for body */
         emitComment("L1: ");
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
         emitCheckCondition(registerId);
         cGen(p1);
         emitValidCondition(registerId);
         cGen(p2);
         emitComment("goto L1");
         /* generate code for test */
         // emitRM_Abs("JEQ",ac,savedLoc1,"repeat: jmp back to body");
         // if (TraceCode)  emitComment("<- repeat") ;
         break; /* repeat */

      case AssignK:
         printf("---- assign k------\n");
         // if (TraceCode) emitComment("-> assign") ;
         /* generate code for rhs */
         p1 = tree->child[0];
         p2 = tree->child[1];
         registerId = ac;
         cGen(p2);
         emitAssignK(p1->attr.name, registerId);

         // if (TraceCode)  emitComment("<- assign") ;
         break; /* assign_k */
      default:
         printf("\n---- default------\n");
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
      printf("----ConstK---\n");
      // if (TraceCode) emitComment("-> Const") ;
      /* gen code to load integer constant using LDC */
      // emitRM("LDC",ac,tree->attr.val,0,"load const");
      // emitConst(ac, tree->attr.val, "load const"); 
      // if (TraceCode)  emitComment("<- Const") ;
      break; /* ConstK */
    
    case IdK :
      printf("----IdK---\n");
      // if (TraceCode) emitComment("-> Id") ;
      loc = st_lookup(tree->attr.name);
      // emitRM("LD",ac,loc,gp,"load id value");
      // emitID(ac, loc, tree->attr.name,"load id value");
      // if (TraceCode)  emitComment("<- Id") ;
      break; /* IdK */

    case OpK :
         printf("----OpK---\n");
         // if (TraceCode) emitComment("-> Op") ;
         if (tree->child[0] == NULL){
            printf("c1 null");
         }
         if (tree->child[1] == NULL){
            printf("c2 null");
         }
         p1 = tree->child[0];
         p2 = tree->child[1];
         printTree(tree);
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

         int nested_ops = 0;
         if (p2->nodekind == ExpK){
            struct treeNode* current_op;
            current_op = p2;
            while (current_op->nodekind == ExpK && current_op->kind.exp == OpK){
               current_op = current_op->child[0];
               nested_ops++;
            }
         } 
         else {
            nested_ops = 0;
         }
         
         int op1 = registerNum - 1;
         int op2 = registerNum - 2 - (2*nested_ops);
         printf("registerNum: %d\n", registerNum);
         /* now load left operand */
         // emitRM("LD",ac1,++tmpOffset,mp,"op: load left");
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
         // if (TraceCode)  emitComment("<- Op") ;
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
  switch (tree->kind.decl) {
    case VarK :
      // if (TraceCode) emitComment("Vark");
      cGen(tree->child[0]);
      break; /* Void */    
    case ArrayK :
      // if (TraceCode) emitComment("ArrayK");
      cGen(tree->child[0]);
      break; /* Integer */
   case FuncK :
      // if (TraceCode) emitComment("FuncK");
      for (int i = 0; i < 10000; i ++){
         if (tree->child[i] != NULL) {
            cGen(tree->child[i]);
         }
         else {
            break;
         }
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
        printf("StmtK\n");
        genStmt(tree);
        break;
      case ExpK:
        printf("ExpK\n");
        genExp(tree);
        break;
      case DeclK:
        printf("DeclK\n");
        genDecl(tree);
        break;
      case TypeK:
         printf("TypeK\n");
         genType(tree);
         break;
      case ParamK:
         printf("ParamK\n");
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

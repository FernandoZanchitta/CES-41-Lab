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
         printf("---- repeat k------\n");

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
         nextLoc = codeBlockNum ;
         codeBlockNum++;
         emitCodeBlock(nextLoc+1);
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
      emitConst(ac, tree->attr.val, "load const"); 
      // if (TraceCode)  emitComment("<- Const") ;
      break; /* ConstK */
    
    case IdK :
      printf("----IdK---\n");
      // if (TraceCode) emitComment("-> Id") ;
      loc = st_lookup(tree->attr.name);
      // emitRM("LD",ac,loc,gp,"load id value");
      emitID(ac, loc, tree->attr.name,"load id value");
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
         int is_p1_value = 1;
         int is_p2_value = 1;

         if (p1->nodekind == ExpK){
            if (p1->kind.exp == OpK){
               cGen(p1);
            }
            else{
               is_p1_value = 0;
            }
         }
         /* gen code to push left operand */
         // emitRM("ST",ac,tmpOffset--,mp,"op: push left");
         /* gen code for ac = right operand */
         if (p2->nodekind == ExpK){
            if (p2->kind.exp == OpK){
               cGen(p2);
            }
            else{
               is_p2_value = 0;
            }
         }
         
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
         
         printf("registerNum: %d\n", registerNum);
         /* now load left operand */
         // emitRM("LD",ac1,++tmpOffset,mp,"op: load left");
         switch (tree->attr.op) {
            case PLUS :
               emitOp("+", ac, registerNum - 1 , is_p1_value,registerNum - 2 - (2*nested_ops), is_p2_value,"op +");
               break;
            case MINUS :
               emitOp("-", ac, registerNum - 1 , 1,registerNum - 2- (2*nested_ops), 1,"op -");
               break;
            case TIMES :
               emitOp("*", ac, registerNum - 1 , is_p1_value,registerNum - 2 - (2*nested_ops), is_p2_value,"op *");
               break;
            case OVER :
               emitOp("/", ac, registerNum - 1 , 1,registerNum - 2- (2*nested_ops), 1,"op /");
               break;
            case LESS :
               emitOp("<", ac, registerNum - 1 , 1,registerNum - 2- (2*nested_ops), 1,"op <");
               break;
            // todo: check
            case LEQ :
               emitOp("<=", ac, registerNum - 1 , 1,registerNum - 2- (2*nested_ops), 1,"op <=");
               break;
            // todo: check
            case GREATER :
               emitOp(">", ac, registerNum - 1 , 1,registerNum - 2- (2*nested_ops), 1,"op >");
               break;
            // todo: check
            case GEQ :
               emitOp(">=", ac, registerNum - 1 , 1,registerNum - 2- (2*nested_ops), 1,"op >=");
               break;
            case COMPARE :
               emitOp("==", ac, registerNum - 1 , 1,registerNum - 2- (2*nested_ops), 1,"op ==");
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

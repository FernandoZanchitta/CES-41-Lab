/****************************************************/
/* File: code.c                                     */
/* TM Code emitting utilities                       */
/* implementation for the TINY compiler             */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include "globals.h"
#include "code.h"

/* TM location number for current instruction emission */
emitLoc = 0 ;
/* Highest TM location emitted so far
   For use in conjunction with emitSkip,
   emitBackup, and emitRestore */
static int highEmitLoc = 0;

/* Procedure emitComment prints a comment line 
 * with comment c in the code file
 */
void emitComment( char * c )
{ if (TraceCode) fprintf(code,"* %s\n",c);}

void emitActivation(int type, char* name, int children_count){
  if (type == Void){
      fprintf(code, "%3d: call %s, %d\n", emitLoc++, name, children_count);
  }
  else {
      fprintf(code, "%3d: r_%d = call %s, %d\n", emitLoc++, registerNum++, name, children_count);

  }
}
void emitOp( char *op, int counter, int* op1, int* const_1, char* id_1, int* op2, int* const_2, char* id_2,char *c)
{ 
  while (registerNum < 0) {
    registerNum = registerNum + 1;
  }
  if (op1 != NULL && op2 != NULL){
    fprintf(code,"%3d: r_%d = r_%d %s r_%d;", emitLoc++, registerNum++, *op1, op, *op2);
  }
  else if (op1 != NULL && const_2 != NULL){
    fprintf(code,"%3d: r_%d = r_%d %s %d;", emitLoc++, registerNum++, *op1, op, *const_2);
  }
  else if (op1 != NULL && id_2 != NULL){
    fprintf(code,"%3d: r_%d = r_%d %s %s;", emitLoc++, registerNum++, *op1, op, id_2);
  }
  else if (const_1 != NULL && op2 != NULL){
    fprintf(code,"%3d: r_%d = %d %s r_%d;", emitLoc++, registerNum++, *const_1, op, *op2);
  }
  else if (id_1 != NULL && op2 != NULL){
    fprintf(code,"%3d: r_%d = %s %s r_%d;", emitLoc++, registerNum++, id_1, op, *op2);
  }
  else if (const_1 != NULL && id_2 != NULL){
    fprintf(code,"%3d: r_%d = %d %s %s;", emitLoc++, registerNum++, *const_1, op, id_2);
  }
  else if (id_1 != NULL && id_2 != NULL){
    fprintf(code,"%3d: r_%d = %s %s %s;", emitLoc++, registerNum++, id_1, op, id_2);
  }
  else if (id_1 != NULL && const_2 != NULL){
    fprintf(code,"%3d: r_%d = %s %s %d;", emitLoc++, registerNum++, id_1, op, *const_2);
  }
  else if (const_1 != NULL && const_2 != NULL){
    fprintf(code,"%3d: r_%d = %d %s %d;", emitLoc++, registerNum++, *const_1, op, *const_2);
  }
   
  if (TraceCode) fprintf(code,"\top %s",c) ;
  fprintf(code,"\n") ;
  if (highEmitLoc < emitLoc) highEmitLoc = emitLoc ;
} /* emitRO */


void emitConst ( int counter, int val, char* c)
{ 
  fprintf(code,"%3d: r_%d = %d;",emitLoc++, registerNum++, val);
  if (TraceCode) fprintf(code,"\t%s",c) ;
  fprintf(code,"\n") ;
  if (highEmitLoc < emitLoc) highEmitLoc = emitLoc ;
} /* emitConst */

void emitID ( int counter, int loc, char* name, char* c)
{ 
  fprintf(code,"%3d: r_%d = %s;",emitLoc++, registerNum++, name);
  if (TraceCode) fprintf(code,"\t%s",c) ;
  fprintf(code,"\n") ;
  if (highEmitLoc < emitLoc) highEmitLoc = emitLoc ;
} /* emitID */



void emitCodeBlock(int codeBlockVar){
  fprintf(code, "L%d:\n", codeBlockVar);
}

void emitCheckCondition(int savedLoc){
  fprintf(code, "%3d: r_%d = ",emitLoc++, registerNum-1);
  fprintf(code,"\n") ;
}

void emitValidCondition(int currentLoc, int currentLocAux){
  fprintf(code, "%3d: if_true r_%d goto L%d\n",emitLoc++, registerNum-1, currentLocAux);
}

void emitIFK3(int savedLoc){
  fprintf(code, "%3d: goto L%d\n",emitLoc++, savedLoc);
}

void emitIFK4(int savedLoc){
  fprintf(code, "%3d: L%d: \n",emitLoc++, savedLoc);
}

void emitAssignK(char * nameVar, int registerId){
  while (registerNum < 1) {
    registerNum = registerNum + 1;
  }
  fprintf(code, "%3d: %s = r_%d;\n",emitLoc++, nameVar, registerNum-1);
}
void emitAssignArrayK(char * nameVar, char * indexArray, int registerId){
  fprintf(code, "%3d:  %s[%s] = r_%d;\n",emitLoc++, nameVar, indexArray, registerNum-1);
}
void emitAssignArrayConstK(char * nameVar, int indexArray, int registerId){
  fprintf(code, "%3d:  %s[%d] = r_%d;\n",emitLoc++, nameVar, indexArray, registerNum-1);
}

void emitCompare(char *s1, int d){
  fprintf(code, "%s == %d", s1, d);
}

/* Function emitSkip skips "howMany" code
 * locations for later backpatch. It also
 * returns the current code position
 */
int emitSkip( int howMany)
{  int i = emitLoc;
   emitLoc += howMany ;
   if (highEmitLoc < emitLoc)  highEmitLoc = emitLoc ;
   return i;
} /* emitSkip */

/* Procedure emitBackup backs up to 
 * loc = a previously skipped location
 */
void emitBackup( int loc)
{ if (loc > highEmitLoc) emitComment("BUG in emitBackup");
  emitLoc = loc ;
} /* emitBackup */

/* Procedure emitRestore restores the current 
 * code position to the highest previously
 * unemitted position
 */
void emitRestore(void)
{ emitLoc = highEmitLoc;}


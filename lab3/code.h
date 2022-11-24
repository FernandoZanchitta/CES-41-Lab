/****************************************************/
/* File: code.h                                     */
/* Code emitting utilities for the TINY compiler    */
/* and interface to the TM machine                  */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/
#ifndef _CODE_H_
#define _CODE_H_

/* pc = program counter  */
#define  pc 7

/* mp = "memory pointer" points
 * to top of memory (for temp storage)
 */
#define  mp 6

/* gp = "global pointer" points
 * to bottom of memory for (global)
 * variable storage
 */
#define gp 5

/* accumulator */
#define  ac 0

/* 2nd accumulator */
#define  ac1 1

/* code emitting utilities */

/* Procedure emitComment prints a comment line 
 * with comment c in the code file
 */
void emitComment( char * c );

/* Procedure emitRO emits a register-only
 * TM instruction
 * op = the opcode
 * r = target register
 * s = 1st source register
 * t = 2nd source register
 * c = a comment to be printed if TraceCode is TRUE
 */

void emitCodeBlock(int codeBlockVar);

void emitCheckCondition(int savedLoc);
void emitValidCondition(int currentLoc, int currentLocAux);
void emitIFK3(int savedLoc);
void emitIFK4(int savedLoc);

void emitAssignK(char * nameVar, int registerId);

void emitCompare(char *s1, int d);

/* Function emitSkip skips "howMany" code
 * locations for later backpatch. It also
 * returns the current code position
 */
int emitSkip( int howMany);

void emitActivation(int type, char* name, int children_count);
void emitConst( int counter, int val, char*c);
void emitID ( int counter, int loc, char* name, char* c);
void emitOp( char *op, int counter, int* op1, int* const_1, char* id_1, int* op2, int* const_2, char* id_2,char *c);
#endif

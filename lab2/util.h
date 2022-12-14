/****************************************************/
/* File: util.h                                     */
/* Utility functions for the TINY compiler          */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#ifndef _UTIL_H_
#define _UTIL_H_

/* Procedure printToken prints a token 
 * and its lexeme to the listing file
 */
void printToken( TokenType, const char* );

/*
* Stack_id functions
*/
void create_stack_id(Stack_id * );
void push_back_id(char * ,Stack_id * );
void pop_id(Stack_id *);
char* top_id(Stack_id *);

/* Function newStmtNode creates a new statement
 * node for syntax tree construction
 */
TreeNode * newStmtNode(StmtKind);

/* Function newExpNode creates a new expression 
 * node for syntax tree construction
 */
TreeNode * newExpNode(ExpKind);

/* Function copyString allocates and makes a new
 * copy of an existing string
 */
char * copyString( char * );

/* procedure printTree prints a syntax tree to the 
 * listing file using indentation to indicate subtrees
 */
void printTree( TreeNode * );

/* Function newDeclNode creates a new declaration
 * node for syntax tree construction
 */
TreeNode * newDeclNode(DeclKind);

/* 
* Function newTypeNode creates a new type node for syntax tree construction
*/
TreeNode * newTypeNode(ExpType);

/*
* Function newFuncNode creates a new function node for syntax tree construction
*/
TreeNode * newFuncNode();

/*
* Function newParamNode creates a new param node for syntax tree construction
*/
TreeNode * newParamNode(DeclKind);
#endif

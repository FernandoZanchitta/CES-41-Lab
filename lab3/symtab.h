/****************************************************/
/* File: symtab.h                                   */
/* Symbol table interface for the TINY compiler     */
/* (allows only one symbol table)                   */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#ifndef _SYMTAB_H_
#define _SYMTAB_H_

char * mapType(int type);
char * mapType_Data(int type_data);
/* Procedure st_insert inserts line numbers and
 * memory locations into the symbol table
 * loc = memory location is inserted only the
 * first time, otherwise ignored
 */
void st_insert( char * name, int lineno, int loc, int type, int type_data, char * scope);
char Scope[100];

/* Function st_lookup returns the memory 
 * location of a variable or -1 if not found
 */
void changeScope(char * var);
char * getScope();

int st_lookup ( char * name );
int st_lookup_type_data ( char * name );
int st_lookup_scope ( char * name, char* scope );
int st_lookup_type ( char * name );
/* Procedure printSymTab prints a formatted 
 * listing of the symbol table contents 
 * to the listing file
 */
void printSymTab(FILE * listing);

int st_find_main_bucket();
#endif

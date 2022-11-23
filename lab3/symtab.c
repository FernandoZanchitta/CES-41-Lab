/****************************************************/
/* File: symtab.c                                   */
/* Symbol table implementation for the TINY compiler*/
/* (allows only one symbol table)                   */
/* Symbol table is implemented as a chained         */
/* hash table                                       */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"
#include "globals.h"
/* SIZE is the size of the hash table */
#define SIZE 211

/* SHIFT is the power of two used as multiplier
   in hash function  */
#define SHIFT 4

/* the hash function */
static int hash ( char * key )
{ int temp = 0;
  int i = 0;
  while (key[i] != '\0')
  { temp = ((temp << SHIFT) + key[i]) % SIZE;
    ++i;
  }
  return temp;
}
void changeScope(char * var){
    strcpy(Scope, var);
}
void checkScopeOver(TreeNode * t){
    if(t->nodekind == DeclK){
        if(t->kind.decl == FuncK){
            changeScope("global");
        }
    }
}
char * getScope(){
    return Scope;
}
/* the list of line numbers of the source 
 * code in which a variable is referenced
 */
typedef struct LineListRec
   { int lineno;
     struct LineListRec * next;
   } * LineList;

/* The record in the bucket lists for
 * each variable, including name, 
 * assigned memory location, and
 * the list of line numbers in which
 * it appears in the source code
 */
typedef struct BucketListRec
   { char * name;
     int type;
     char * scope;
     int type_data;
     LineList lines;
     int memloc ; /* memory location for variable */

     struct BucketListRec * next;
   } * BucketList;

/* the hash table */
static BucketList hashTable[SIZE];

char * mapType(int type){
  switch(type){
    case 0:
      return "var";
    case 1:
      return "ary";
    case 2:
      return "func";
    default:
      return "ukn";
  }
}
char * mapType_Data(int type_data){
  switch(type_data){
    case 0:
      return "void";
    case 1:
      return "int";
    default:
      return "ukn";
  }
}


/* Procedure st_insert inserts line numbers and
 * memory locations into the symbol table
 * loc = memory location is inserted only the
 * first time, otherwise ignored
 */
void st_insert( char * name, int lineno, int loc,int type ,int type_data,char * scope)
{ int h = hash(name);
  BucketList l =  hashTable[h];
  while ((l != NULL) && (strcmp(name,l->name) != 0) ||
   ((l != NULL) && (strcmp(name,l->name) == 0)  && (strcmp(scope,l->scope) != 0))){
    l = l->next;
  }
  // fprintf(listing, "stopped at %s in Scope: %s\n", name, getScope());
  if (l == NULL) /* variable not yet in table */
  { l = (BucketList) malloc(sizeof(struct BucketListRec));
    l->name = name;
    l->lines = (LineList) malloc(sizeof(struct LineListRec));
    l->lines->lineno = lineno;
    l->memloc = loc;
    l->type = type;
    // fprintf(listing, "Scope: %s\n",Scope);
    // strcpy(l->scope,Scope);
    l->scope = (char *)malloc(sizeof(char)*100);
    strcpy(l->scope,scope);
    l->type_data = type_data;
    l->lines->next = NULL;
    l->next = hashTable[h];
    hashTable[h] = l; }
  else /* found in table, so just add line number */
  { LineList t = l->lines;
    while (t->next != NULL) t = t->next;
    t->next = (LineList) malloc(sizeof(struct LineListRec));
    t->next->lineno = lineno;
    t->next->next = NULL;
  }
} /* st_insert */

/* Function st_lookup returns the memory 
 * location of a variable or -1 if not found
 */
int st_lookup ( char * name )
{ int h = hash(name);
  BucketList l =  hashTable[h];
  while ((l != NULL) && (strcmp(name,l->name) != 0))
    l = l->next;
  if (l == NULL) return -1;
  else return l->memloc;
}
int st_lookup_scope ( char * name, char* scope )
{ int h = hash(name);
  BucketList l =  hashTable[h];
  if(l!=NULL){
  }
  while ((l != NULL) && (strcmp(name,l->name) != 0) || ((l != NULL) && (strcmp(name,l->name) == 0)  && (strcmp(scope,l->scope) != 0))){
    l = l->next;
  }
  if (l == NULL) return -1;
  else {
    return l->memloc;
  }
}
/* Function st_lookup_type returns the type
 * of a variable or -1 if not found
 */
int st_lookup_type_data ( char * name )
{ int h = hash(name);
  BucketList l =  hashTable[h];
  while ((l != NULL) && (strcmp(name,l->name) != 0))
    l = l->next;
  if (l == NULL) {
    fprintf(listing,"Error: %s not found in symbol table\n", name);
    return -1;
  }
  else return l->type_data;
}
/* Procedure printSymTab prints a formatted 
 * listing of the symbol table contents 
 * to the listing file
 */
void printSymTab(FILE * listing)
{ int i;
  fprintf(listing,"Variable Name  Type  Scope  Type of Data  Location  Line Numbers\n");
  fprintf(listing,"-------------  ----  -----  ------------  --------  ------------\n");
  for (i=0;i<SIZE;++i)
  { if (hashTable[i] != NULL)
    { BucketList l = hashTable[i];
      while (l != NULL)
      { LineList t = l->lines;
        fprintf(listing,"%-14s ",l->name);
        fprintf(listing,"%-5s  ",mapType(l->type));
        fprintf(listing,"%-5s  ",l->scope);
        fprintf(listing,"%-12s  ",mapType_Data(l->type_data));
        fprintf(listing,"%-8d  ",l->memloc);
        while (t != NULL)
        { fprintf(listing,"%4d ",t->lineno);
          t = t->next;
        }
        fprintf(listing,"\n");
        l = l->next;
      }
    }
  }
} /* printSymTab */

//find main bucket
int st_find_main_bucket(){
  char* name = "main";
  int h = hash(name);
  BucketList l =  hashTable[h];
  while ((l != NULL) && (strcmp(name,l->name) != 0))
    l = l->next;
  if (l == 0) {
    fprintf(listing,"Error: %s not found in symbol table\n", name);
    return 0;
  }
  if(l->type != 2){
    fprintf(listing,"Error: %s is not a function\n", name);
    return 0;
  }
  if (l->type_data != 0){
    fprintf(listing,"Error: %s is not a void function\n", name);
    return 0;
  }
  return 1;
}
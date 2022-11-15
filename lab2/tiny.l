/****************************************************/
/* File: lexical.l                                 */
/* Lex specification for C-                         */
/****************************************************/

%{
#include "globals.h"
#include "util.h"
#include "scan.h"
#include <string.h>
/* lexeme of identifier or reserved word */
char tokenString[MAXTOKENLEN+1];
int FlagComment = 0;
Stack_id * stack;
char ID_name[MAXTOKENLEN+1];
%}
digit       [0-9]
number      {digit}+
letter      [a-zA-Z]
identifier  {letter}+
newline     \n
whitespace  [ \t]+
%%
"if"            {return IF;}
"else"          {return ELSE;}
"int"          {return INT;}
"return"          {return RETURN;}
"void"          {return VOID;}
"while"          {return WHILE;}
"+"            {return PLUS;}
"-"             {return MINUS;}
"*"             {return TIMES;}
"/"             {return OVER;}
"<"             {return LESS;}
"<="             {return LEQ;}
">"             {return GREATER;}
">="             {return GEQ;}
"="             {return ASSIGN;}
"=="             {return COMPARE;}
"!="             {return DIFF;}
";"             {return SEMI;}
","             {return COMMA;}
"("             {return LPAREN;}
")"             {return RPAREN;}
"["             {return LCOLCH;}
"]"             {return RCOLCH;}
"{"             {return LBRAC;}
"}"             {return RBRAC;}
{number}        {return NUM;}
{identifier}    {return ID;}
{newline}       {lineno++;}
{whitespace}    {/* skip whitespace */}
"/*"            {return BEGCOM;}  
"*/"            {return ENDCOM;}  
.               {return ERROR;}
%%
TokenType getToken(void)
{ static int firstTime = TRUE;
  TokenType currentToken;
  if (firstTime)
  { firstTime = FALSE;
    create_stack_id(stack);
    lineno++;
    yyin = source;
    yyout = listing;
  }
  currentToken = yylex();
  strncpy(tokenString,yytext,MAXTOKENLEN);
  if(currentToken == ID){
    //fprintf(listing,"Empilhando tokenString = %s\n", tokenString);
    //push_back_id(tokenString, stack);
    //char * topo = top_id(stack);
    //fprintf(listing," topo da pilha: %s\n", topo);
    strcpy(ID_name, tokenString);
    //fprintf(listing, "ID_name = %s\n", ID_name);
  }
  if (TraceScan) {
    printToken(currentToken,tokenString);
  }
  return currentToken;
}

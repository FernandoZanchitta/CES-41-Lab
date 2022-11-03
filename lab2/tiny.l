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
FlagComment = 0;
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
    lineno++;
    yyin = source;
    yyout = listing;
  }
  currentToken = yylex();
  strncpy(tokenString,yytext,MAXTOKENLEN);
  if (TraceScan) {
    printToken(currentToken,tokenString);
  }
  return currentToken;
}

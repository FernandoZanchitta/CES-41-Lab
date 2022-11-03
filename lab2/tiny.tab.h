/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     NUM = 259,
     IF = 260,
     ELSE = 261,
     INT = 262,
     RETURN = 263,
     VOID = 264,
     WHILE = 265,
     WRITE = 266,
     PLUS = 267,
     MINUS = 268,
     TIMES = 269,
     OVER = 270,
     LESS = 271,
     LEQ = 272,
     GREATER = 273,
     GEQ = 274,
     COMPARE = 275,
     DIFF = 276,
     ASSIGN = 277,
     SEMI = 278,
     COMMA = 279,
     LPAREN = 280,
     RPAREN = 281,
     LCOLCH = 282,
     RCOLCH = 283,
     LBRAC = 284,
     RBRAC = 285,
     BEGCOM = 286,
     ENDCOM = 287,
     ERROR = 288,
     ENDFILE = 289
   };
#endif
/* Tokens.  */
#define ID 258
#define NUM 259
#define IF 260
#define ELSE 261
#define INT 262
#define RETURN 263
#define VOID 264
#define WHILE 265
#define WRITE 266
#define PLUS 267
#define MINUS 268
#define TIMES 269
#define OVER 270
#define LESS 271
#define LEQ 272
#define GREATER 273
#define GEQ 274
#define COMPARE 275
#define DIFF 276
#define ASSIGN 277
#define SEMI 278
#define COMMA 279
#define LPAREN 280
#define RPAREN 281
#define LCOLCH 282
#define RCOLCH 283
#define LBRAC 284
#define RBRAC 285
#define BEGCOM 286
#define ENDCOM 287
#define ERROR 288
#define ENDFILE 289




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;


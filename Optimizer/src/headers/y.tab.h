/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    FOR = 258,
    WHILE = 259,
    DO = 260,
    IF = 261,
    ELSE = 262,
    RETURN = 263,
    INT = 264,
    VOID = 265,
    FLOAT = 266,
    CONST_Q = 267,
    CONST_INT = 268,
    CONST_FLOAT = 269,
    IDENTIFIER = 270,
    STRING = 271,
    CONST = 272,
    AND_OP = 273,
    OR_OP = 274,
    LE_OP = 275,
    GE_OP = 276,
    EQ_OP = 277,
    NE_OP = 278,
    INC = 279,
    DEC = 280,
    LEFT_OP = 281,
    RIGHT_OP = 282
  };
#endif
/* Tokens.  */
#define FOR 258
#define WHILE 259
#define DO 260
#define IF 261
#define ELSE 262
#define RETURN 263
#define INT 264
#define VOID 265
#define FLOAT 266
#define CONST_Q 267
#define CONST_INT 268
#define CONST_FLOAT 269
#define IDENTIFIER 270
#define STRING 271
#define CONST 272
#define AND_OP 273
#define OR_OP 274
#define LE_OP 275
#define GE_OP 276
#define EQ_OP 277
#define NE_OP 278
#define INC 279
#define DEC 280
#define LEFT_OP 281
#define RIGHT_OP 282

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 11 "grammar/c_syn.y" /* yacc.c:1921  */

	struct {
		int count_p;
		int count_m;
		int type;
		int size;
		int val;
		float fval;
		void * sentry;
		int t[4];
		char* string_val;
		int type_counter;


		char * string_exp;
	}vv;

	struct {
		int size, strideX, strideY;
		char *X, *Y;		
	} vec;

#line 135 "y.tab.h" /* yacc.c:1921  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

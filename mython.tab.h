/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_MYTHON_TAB_H_INCLUDED
# define YY_YY_MYTHON_TAB_H_INCLUDED
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
    DEF_T = 258,
    FED_T = 259,
    IF_T = 260,
    FI_T = 261,
    ELSE_T = 262,
    WHILE_T = 263,
    ELIHW_T = 264,
    INPUT_T = 265,
    PRINT_T = 266,
    RETURN_T = 267,
    ID = 268,
    INT_LIT = 269,
    RP = 270,
    LP = 271,
    RB = 272,
    LB = 273,
    COMMA = 274,
    COLON = 275,
    ASSIGN = 276,
    TRUE_T = 277,
    FALSE_T = 278,
    OR = 279,
    AND = 280,
    LT = 281,
    LE = 282,
    GT = 283,
    GE = 284,
    EQ = 285,
    NE = 286,
    NOT = 287,
    PLUS = 288,
    MINUS = 289,
    MULT = 290
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 38 "mython.y" /* yacc.c:1909  */

    int val;
    char* name;
    int boolean;
    char op;
    

#line 98 "mython.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MYTHON_TAB_H_INCLUDED  */

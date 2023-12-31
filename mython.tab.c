/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "mython.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int lineno;
extern char* yytext;
extern int yylex();

typedef struct SymbolNode {
    char* name;
    int lineno;
    int type; //1=int, 2==boolean, 3==Array, 4==ArrayFunc, 5==Intfucnt, 6==BooleanF , 7==Procedure, 8==defFunc,9==file, 10 == error
    int param;
    struct SymbolNode* next;
} SymbolNode;

typedef struct SymbolTable {
    SymbolNode* head;
    struct SymbolTable* parent;
} SymbolTable;

void enterScope();
void exitScope();
void insert(char* name, int lineno,int type,int param);
int lookup(char* name, int lineno);
int lookupType(char* name_1);
int updateVar(char* name, int type);
int getTopType();

SymbolTable* current_scope = NULL;
char* dataType[]={NULL,"Integer","Boolean","Array","ArrayFunc","Intfunction","BooleanF","Procedure","defFunct"};
int paramCount = 0;
int frq = 0;
int begin = 0;

#line 103 "mython.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "mython.tab.h".  */
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
#line 38 "mython.y" /* yacc.c:355  */

    int val;
    char* name;
    int boolean;
    char op;
    

#line 187 "mython.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MYTHON_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 204 "mython.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   257

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  136

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    38,    35,     2,    36,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      37
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    62,    62,    62,    65,    65,    66,    69,    69,    77,
      87,    96,   105,   114,   126,   126,   127,   127,   129,   130,
     131,   132,   133,   134,   135,   138,   138,   144,   147,   157,
     157,   169,   182,   203,   209,   215,   221,   227,   233,   239,
     246,   252,   256,   268,   281,   293,   299,   307,   314,   323,
     332,   337,   345,   349,   355,   356,   359,   367,   379,   379,
     387,   388,   391,   391,   399,   404,   414,   415,   418,   419,
     420,   424,   428,   432
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DEF_T", "FED_T", "IF_T", "FI_T",
  "ELSE_T", "WHILE_T", "ELIHW_T", "INPUT_T", "PRINT_T", "RETURN_T", "ID",
  "INT_LIT", "RP", "LP", "RB", "LB", "COMMA", "COLON", "ASSIGN", "TRUE_T",
  "FALSE_T", "OR", "AND", "LT", "LE", "GT", "GE", "EQ", "NE", "NOT",
  "PLUS", "MINUS", "'+'", "'-'", "MULT", "'*'", "$accept", "program",
  "$@1", "function_list", "$@2", "function", "$@3", "parameters",
  "statements", "$@4", "$@5", "statement", "return_stmt", "$@6",
  "call_stmt", "$@7", "assignment_stmt", "exp", "int_list", "print_stmt",
  "input_stmt", "condition_stmt", "$@8", "optional_else", "while_stmt",
  "$@9", "param_list", "end_list", "end", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,    43,    45,   290,    42
};
# endif

#define YYPACT_NINF -87

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-87)))

#define YYTABLE_NINF -62

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-62)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -87,     2,   -87,   -87,    38,   111,   -15,     8,   -87,   -87,
      38,   -87,    47,   -87,   111,   -87,   -87,   111,   111,   181,
      -7,   111,    30,    26,   -87,   -87,    96,   111,    68,   -19,
      23,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   -87,   111,   122,   -87,    28,   181,    59,   -87,
     181,     4,   137,   -87,   195,   208,   220,   220,   220,   220,
     220,   220,    23,    23,   -87,     5,    55,   -87,    53,    58,
     -87,   111,   -87,   -87,   111,   -87,    60,    62,    67,     6,
     181,   181,   -87,    65,   -87,    80,    75,   -87,    99,    73,
     -87,    86,   -87,    73,   111,   111,   111,   -11,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   102,    97,   -87,   167,
     181,   181,   111,    45,   -87,   -87,   -87,    93,   -87,   152,
     -87,   181,   -87,   -87,   -87,    94,    50,   107,   111,   100,
     115,   -87,   181,   -87,   -87,   116
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     6,     1,     4,     0,     0,     0,    68,    69,
       3,    67,    51,    50,     0,    52,    53,     0,     0,    56,
      29,     0,     0,     0,     5,    66,     0,     0,     0,    41,
      45,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    28,     0,     0,    70,     0,    71,     0,    48,
      65,     0,     0,    46,    40,    39,    35,    36,    37,    38,
      33,    34,    42,    43,    44,     0,     0,    55,     0,     0,
      49,     0,    47,    30,     0,    72,     0,    12,     0,     0,
      64,    73,    54,     0,    16,     0,     0,    13,    14,     0,
      16,    10,     9,     0,     0,     0,    27,     0,    17,    24,
      23,    18,    19,    20,    21,    22,    14,     0,    15,     0,
      62,    25,     0,     0,     7,    11,    58,     0,    26,     0,
      57,    31,     8,    16,    16,     0,    14,    14,     0,     0,
       0,    63,    32,    16,    59,    14
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -86,   -87,
     -87,    24,   -87,   -87,   -48,   -87,   -87,    -5,   -87,   -39,
     -87,   -87,   -87,   -87,   -87,   -87,    83,   -87,   119
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     4,     7,    24,   122,    79,    88,    93,
      89,    98,    99,   118,     8,    43,   101,    50,    68,     9,
     103,   104,   123,   130,   105,   117,    51,    10,    11
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      19,    20,     3,    21,   106,    20,    22,   112,    42,    28,
     113,    23,    29,    30,    39,    40,    44,    47,    41,    70,
      73,    85,    52,    71,    71,    86,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,   126,   127,    48,
      45,   100,    67,    12,    13,   100,    14,   135,    46,     5,
     102,     6,    15,    16,   102,   120,   -61,   129,    12,    13,
      41,    14,    17,    26,    18,    27,    80,    15,    16,    81,
      75,    77,    76,    78,    82,    69,    74,    17,    94,    18,
      83,    95,    87,    53,     5,    96,    97,    84,    91,   109,
     110,   111,    31,    32,    33,    34,    35,    36,    37,    38,
      90,    39,    40,    92,   107,    41,   114,   119,   121,    12,
      13,    49,    14,   124,   115,   128,   131,   108,    15,    16,
     133,   134,   -60,   132,    12,    13,    65,    14,    17,    25,
      18,     0,     0,    15,    16,     0,     0,     0,     0,    66,
       0,     0,     0,    17,     0,    18,    31,    32,    33,    34,
      35,    36,    37,    38,    72,    39,    40,     0,     0,    41,
       0,    31,    32,    33,    34,    35,    36,    37,    38,   125,
      39,    40,     0,     0,    41,     0,    31,    32,    33,    34,
      35,    36,    37,    38,     0,    39,    40,   116,     0,    41,
       0,    31,    32,    33,    34,    35,    36,    37,    38,     0,
      39,    40,     0,     0,    41,    31,    32,    33,    34,    35,
      36,    37,    38,     0,    39,    40,     0,     0,    41,   -62,
      32,    33,    34,    35,    36,    37,    38,     0,    39,    40,
       0,     0,    41,   -62,    33,    34,    35,    36,    37,    38,
       0,    39,    40,     0,     0,    41,   -62,   -62,   -62,   -62,
     -62,   -62,     0,    39,    40,     0,     0,    41
};

static const yytype_int16 yycheck[] =
{
       5,    16,     0,    18,    90,    16,    21,    18,    15,    14,
      21,     3,    17,    18,    33,    34,    21,    22,    37,    15,
      15,    15,    27,    19,    19,    19,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,   123,   124,    13,
      10,    89,    14,    13,    14,    93,    16,   133,    18,    11,
      89,    13,    22,    23,    93,    10,     6,     7,    13,    14,
      37,    16,    32,    16,    34,    18,    71,    22,    23,    74,
      17,    13,    19,    15,    14,    16,    21,    32,     5,    34,
      18,     8,    17,    15,    11,    12,    13,    20,    13,    94,
      95,    96,    24,    25,    26,    27,    28,    29,    30,    31,
      20,    33,    34,     4,    18,    37,     4,   112,   113,    13,
      14,    15,    16,    20,    17,    21,     9,    93,    22,    23,
      20,     6,     6,   128,    13,    14,    43,    16,    32,    10,
      34,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    17,
      -1,    -1,    -1,    32,    -1,    34,    24,    25,    26,    27,
      28,    29,    30,    31,    17,    33,    34,    -1,    -1,    37,
      -1,    24,    25,    26,    27,    28,    29,    30,    31,    17,
      33,    34,    -1,    -1,    37,    -1,    24,    25,    26,    27,
      28,    29,    30,    31,    -1,    33,    34,    20,    -1,    37,
      -1,    24,    25,    26,    27,    28,    29,    30,    31,    -1,
      33,    34,    -1,    -1,    37,    24,    25,    26,    27,    28,
      29,    30,    31,    -1,    33,    34,    -1,    -1,    37,    24,
      25,    26,    27,    28,    29,    30,    31,    -1,    33,    34,
      -1,    -1,    37,    25,    26,    27,    28,    29,    30,    31,
      -1,    33,    34,    -1,    -1,    37,    26,    27,    28,    29,
      30,    31,    -1,    33,    34,    -1,    -1,    37
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    40,    41,     0,    42,    11,    13,    43,    53,    58,
      66,    67,    13,    14,    16,    22,    23,    32,    34,    56,
      16,    18,    21,     3,    44,    67,    16,    18,    56,    56,
      56,    24,    25,    26,    27,    28,    29,    30,    31,    33,
      34,    37,    15,    54,    56,    10,    18,    56,    13,    15,
      56,    65,    56,    15,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    65,    17,    14,    57,    16,
      15,    19,    17,    15,    21,    17,    19,    13,    15,    46,
      56,    56,    14,    18,    20,    15,    19,    17,    47,    49,
      20,    13,     4,    48,     5,     8,    12,    13,    50,    51,
      53,    55,    58,    59,    60,    63,    47,    18,    50,    56,
      56,    56,    18,    21,     4,    17,    20,    64,    52,    56,
      10,    56,    45,    61,    20,    17,    47,    47,    21,     7,
      62,     9,    56,    20,     6,    47
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    41,    40,    43,    42,    42,    45,    44,    44,
      46,    46,    46,    46,    48,    47,    49,    47,    50,    50,
      50,    50,    50,    50,    50,    52,    51,    51,    53,    54,
      53,    55,    55,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    57,    57,    58,    59,    61,    60,
      62,    62,    64,    63,    65,    65,    66,    66,    67,    67,
      67,    67,    67,    67
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     0,     3,     0,     0,     9,     7,
       3,     5,     1,     3,     0,     3,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     0,     3,     1,     3,     0,
       5,     3,     6,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     3,     3,     3,     2,     3,     4,     3,     4,
       1,     1,     1,     1,     3,     1,     2,     3,     0,     7,
       3,     0,     0,     6,     3,     1,     2,     1,     1,     1,
       3,     3,     5,     6
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 62 "mython.y" /* yacc.c:1646  */
    {enterScope();}
#line 1398 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 62 "mython.y" /* yacc.c:1646  */
    {exitScope();}
#line 1404 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 65 "mython.y" /* yacc.c:1646  */
    {enterScope(); paramCount = 0; begin = 1;}
#line 1410 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 69 "mython.y" /* yacc.c:1646  */
    {exitScope();}
#line 1416 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 70 "mython.y" /* yacc.c:1646  */
    {   
                    if(lookup((yyvsp[-7].name),lineno)== 0){
                        printf("Line %d: Duplicate function in scope: %s\n", lineno-begin, (yyvsp[-7].name));
                    }else{
                        insert((yyvsp[-7].name),lineno,8,paramCount);//add paramcount for function only
                    }                        
                }
#line 1428 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 78 "mython.y" /* yacc.c:1646  */
    {
                    if(lookup((yyvsp[-5].name),lineno)== 0){
                        printf("Line %d: Duplicate function in scope: %s\n", lineno-begin, (yyvsp[-5].name));
                    }else{
                        insert((yyvsp[-5].name),lineno,8,paramCount);//add paramcount for function only
                    }
                }
#line 1440 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 88 "mython.y" /* yacc.c:1646  */
    {   
                paramCount++;    
                if(lookup((yyvsp[0].name),lineno)== 0){
                    printf("Line %d: Duplicate variable in scope: %s\n", lineno, (yyvsp[0].name));
                }else{
                    insert((yyvsp[0].name),lineno,1,-1);
                }
            }
#line 1453 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 97 "mython.y" /* yacc.c:1646  */
    {
                paramCount++;
                if(lookup((yyvsp[-2].name),lineno)== 0){
                    printf("Line %d: Duplicate variable in scope: %s\n", lineno, (yyvsp[-2].name));
                }else{
                    insert((yyvsp[-2].name),lineno,3,-1);
                }
            }
#line 1466 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 106 "mython.y" /* yacc.c:1646  */
    {
                paramCount++;
                if(lookup((yyvsp[0].name),lineno)== 0){
                    printf("Line %d: Duplicate variable in scope: %s\n", lineno, (yyvsp[0].name));
                }else{
                    insert((yyvsp[0].name),lineno,-1,-1);
                }
            }
#line 1479 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 115 "mython.y" /* yacc.c:1646  */
    {   
                paramCount++;
                if(lookup((yyvsp[-2].name),lineno)== 0){
                    printf("Line %d: Duplicate variable in scope: %s\n", lineno, (yyvsp[-2].name));
                }else{
                    insert((yyvsp[-2].name),lineno,3,-1);
                }
                
            }
#line 1493 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 126 "mython.y" /* yacc.c:1646  */
    {begin++;}
#line 1499 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 127 "mython.y" /* yacc.c:1646  */
    {begin++;}
#line 1505 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 138 "mython.y" /* yacc.c:1646  */
    {begin =1;}
#line 1511 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 139 "mython.y" /* yacc.c:1646  */
    {
                    if(lookupType((yyvsp[-1].name)) == 8 ){
                        printf("Line %d: Recursive function not supported: %s\n", lineno, (yyvsp[-1].name));
                    }
                }
#line 1521 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 144 "mython.y" /* yacc.c:1646  */
    {begin =1;}
#line 1527 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 148 "mython.y" /* yacc.c:1646  */
    {
                    if(lookup((yyvsp[-2].name),lineno)==-1){
                        printf("Line %d: Function not declared: %s\n", lineno, (yyvsp[-2].name));
                    }
                    if((lookup((yyvsp[-2].name),lineno)== 0) && (lookupType((yyvsp[-2].name))== 8) && (getParam((yyvsp[-2].name)) != frq)){//if exist
                        printf("Line %d: Illegal number of parameters: function : %s\n", lineno, (yyvsp[-2].name));
                    }
                    
                }
#line 1541 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 157 "mython.y" /* yacc.c:1646  */
    {frq = 0;}
#line 1547 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 158 "mython.y" /* yacc.c:1646  */
    {
                    if(lookup((yyvsp[-4].name),lineno)==-1){ //does not exist
                        printf("Line %d: Function not declared: %s\n", lineno, (yyvsp[-4].name));
                    }
                    if((lookup((yyvsp[-4].name),lineno)== 0) && (lookupType((yyvsp[-4].name))== 8) && (getParam((yyvsp[-4].name)) != frq)){//if exist
                        printf("Line %d: Illegal number of parameters: function : %s\n", lineno, (yyvsp[-4].name));
                    }
                    
                }
#line 1561 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 170 "mython.y" /* yacc.c:1646  */
    {
                    if(lookup((yyvsp[-2].name),lineno) == 0 ){//if it exists
                        if(lookupType((yyvsp[-2].name)) == lookupType((yyvsp[0].name))){
                            updateVar((yyvsp[-2].name),lookupType((yyvsp[0].name)));
                        }else{
                            printf("Line %d: Type mismatch in assignment statement\n", lineno);
                        }                       
                    }else{
                        insert((yyvsp[-2].name),lineno,lookupType((yyvsp[0].name)),getParam((yyvsp[-2].name)));
                    }
                             
                }
#line 1578 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 183 "mython.y" /* yacc.c:1646  */
    {
                    if(lookup((yyvsp[-5].name),lineno) == 0 ){//if it exists
                        if(lookupType((yyvsp[-5].name)) == lookupType((yyvsp[0].name))){
                            updateVar((yyvsp[-5].name),lookupType((yyvsp[0].name)));
                        }if(lookupType((yyvsp[0].name)) != 1){
                            printf("Line %d: Can only assign integers to arrays\n", lineno);
                        }if(lookupType((yyvsp[-3].name)) != 1){
                            printf("Line %d: Array indices must be type integer\n", lineno);
                        }if(lookupType((yyvsp[-5].name)) != 3){
                            printf("Line %d: Use of non-array type as an array: %s\n", lineno,(yyvsp[-5].name));
                        }
                        else{
                            printf("Line %d: Type mismatch in assignment statement\n", lineno);
                        }                       
                    }else{
                        insert((yyvsp[-5].name),lineno,lookupType((yyvsp[0].name)),getParam((yyvsp[-5].name)));
                    }
                }
#line 1601 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 204 "mython.y" /* yacc.c:1646  */
    {
                    if((lookupType((yyvsp[-2].name)) != 1) || (lookupType((yyvsp[0].name)) != 1)){
                        printf("Line %d: Illegal types in expression operator and expects Integer\n", lineno);
                    }
                }
#line 1611 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 210 "mython.y" /* yacc.c:1646  */
    {
                    if((lookupType((yyvsp[-2].name)) != 1) || (lookupType((yyvsp[0].name)) != 1)){
                        printf("Line %d: Illegal types in expression operator and expects Integer\n", lineno);
                    }
                }
#line 1621 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 216 "mython.y" /* yacc.c:1646  */
    {
                    if((lookupType((yyvsp[-2].name)) != 1) || (lookupType((yyvsp[0].name)) != 1)){
                        printf("Line %d: Illegal types in expression operator and expects Integer\n", lineno);
                    }
                }
#line 1631 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 222 "mython.y" /* yacc.c:1646  */
    {
                    if((lookupType((yyvsp[-2].name)) != 1) || (lookupType((yyvsp[0].name)) != 1)){
                        printf("Line %d: Illegal types in expression operator and expects Integer\n", lineno);
                    }
                }
#line 1641 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 228 "mython.y" /* yacc.c:1646  */
    {
                    if((lookupType((yyvsp[-2].name)) != 1) || (lookupType((yyvsp[0].name)) != 1)){
                        printf("Line %d: Illegal types in expression operator and expects Integer\n", lineno);
                    }
                }
#line 1651 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 234 "mython.y" /* yacc.c:1646  */
    {
                    if((lookupType((yyvsp[-2].name)) != 1) || (lookupType((yyvsp[0].name)) != 1)){
                        printf("Line %d: Illegal types in expression operator and expects Integer\n", lineno);
                    }
                }
#line 1661 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 240 "mython.y" /* yacc.c:1646  */
    {
                    if((lookupType((yyvsp[-2].name)) != 2) || (lookupType((yyvsp[0].name)) != 2)){
                        printf("Line %d: Illegal types in expression operator and expects Boolean\n", lineno);
                    }

                }
#line 1672 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 247 "mython.y" /* yacc.c:1646  */
    {
                    if((lookupType((yyvsp[-2].name)) != 2) || (lookupType((yyvsp[0].name)) != 2)){
                        printf("Line %d: Illegal types in expression operator and expects Boolean\n", lineno);
                    }
                }
#line 1682 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 253 "mython.y" /* yacc.c:1646  */
    {

                }
#line 1690 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 257 "mython.y" /* yacc.c:1646  */
    {
                    if((lookupType((yyvsp[-2].name)) != 1) || (lookupType((yyvsp[0].name)) != 1)) {
                        printf("Line %d: Illegal types in expression operator + expects Integers\n", lineno);
                    }
                    if(lookupType((yyvsp[-2].name)) == 8){
                        printf("Line %d: Illegal function usage: %s\n", lineno,(yyvsp[-2].name));
                    }
                    if(lookupType((yyvsp[0].name)) == 8){
                        printf("Line %d: Illegal function usage: %s\n", lineno,(yyvsp[0].name));
                    }
                }
#line 1706 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 269 "mython.y" /* yacc.c:1646  */
    {
                    if((lookupType((yyvsp[-2].name)) != 1) || (lookupType((yyvsp[0].name)) != 1)){
                        printf("Line %d: Illegal types in expression operator - expects Integers\n", lineno);
                    }
                    if(lookupType((yyvsp[-2].name)) == 8){
                        printf("Line %d: Illegal function usage: %s\n", lineno,(yyvsp[-2].name));
                    }
                    if(lookupType((yyvsp[0].name)) == 8){
                        printf("Line %d: Illegal function usage: %s\n", lineno,(yyvsp[0].name));
                    }

                }
#line 1723 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 282 "mython.y" /* yacc.c:1646  */
    {
                    if((lookupType((yyvsp[-2].name)) != 1) || (lookupType((yyvsp[0].name)) != 1)){
                        printf("Line %d: Illegal types in expression operator * expects Integers\n", lineno);
                    }
                    if(lookupType((yyvsp[-2].name)) == 8){
                        printf("Line %d: Illegal function usage: %s\n", lineno,(yyvsp[-2].name));
                    }
                    if(lookupType((yyvsp[0].name)) == 8){
                        printf("Line %d: Illegal function usage: %s\n", lineno,(yyvsp[0].name));
                    }
                }
#line 1739 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 294 "mython.y" /* yacc.c:1646  */
    {
                     if(lookupType((yyvsp[0].name)) != 1){
                        printf("Line %d: Illegal types in expression operator expects Integers\n", lineno);
                    }
                }
#line 1749 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 300 "mython.y" /* yacc.c:1646  */
    {
                    if(lookup((yyvsp[-1].name),lineno)== -1){ //not exist
                        printf("Line %d: Undefined variable: %s\n", lineno, (yyvsp[-1].name));
                    }else{

                    }
                }
#line 1761 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 308 "mython.y" /* yacc.c:1646  */
    {
                    if(lookup((yyvsp[-3].name),lineno)==-1){
                        printf("Line %d: Array not declared: %s\n", lineno, (yyvsp[-3].name));
                    }
                    
                }
#line 1772 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 315 "mython.y" /* yacc.c:1646  */
    {
                    if(lookup((yyvsp[-2].name),lineno)==-1){
                        printf("Line %d: Function not declared: %s\n", lineno, (yyvsp[-2].name));
                    }if(lookupType((yyvsp[-2].name)) != 8){
                        printf("Line %d: Non-function variable used as a function: %s\n", lineno, (yyvsp[-2].name));
                    }
                    
                }
#line 1785 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 324 "mython.y" /* yacc.c:1646  */
    {
                    if(lookup((yyvsp[-3].name),lineno)==-1){//not exist
                        printf("Line %d: Function not declared: %s\n", lineno, (yyvsp[-3].name));
                    }if(lookupType((yyvsp[-3].name)) != 8){
                        printf("Line %d: Non-function variable used as a function: %s\n", lineno, (yyvsp[-3].name));
                    }
                    
                }
#line 1798 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 333 "mython.y" /* yacc.c:1646  */
    {
                    insert((char *)(yyvsp[0].val),lineno,1,-1);
                    (yyval.name) = (yyvsp[0].val);
                }
#line 1807 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 338 "mython.y" /* yacc.c:1646  */
    {
                    if(lookup((yyvsp[0].name),lineno)==-1){
                        printf("Line %d: Undefined variable: %s\n", lineno, (yyvsp[0].name));
                    }
                    (yyval.name) = (yyvsp[0].name);
                    
                }
#line 1819 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 346 "mython.y" /* yacc.c:1646  */
    {
                    insert((yyvsp[0].name),lineno,2,-1);
                }
#line 1827 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 350 "mython.y" /* yacc.c:1646  */
    {
                    insert((yyvsp[0].name),lineno,2,-1);
                }
#line 1835 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 360 "mython.y" /* yacc.c:1646  */
    {
                    if(lookupType((yyvsp[0].name)) != 1 && lookupType((yyvsp[0].name)) != 9){ //if its a boolean
                        printf("Line %d: Print statement expect integers: %s\n", lineno, (yyvsp[0].name));
                    }
                }
#line 1845 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 368 "mython.y" /* yacc.c:1646  */
    {
                    if(lookup((yyvsp[-2].name),lineno) == 0 && lookupType((yyvsp[-2].name)) != 9 && lookupType((yyvsp[-2].name)) != -1){
                        printf("Line %d: Can only input integer type: %s\n", lineno, (yyvsp[-2].name));
                    }else{
                        insert((yyvsp[-2].name),lineno,9,-1);
                    }
                    
                    
                }
#line 1859 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 379 "mython.y" /* yacc.c:1646  */
    {begin =1;}
#line 1865 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 380 "mython.y" /* yacc.c:1646  */
    {
                    if(lookupType((yyvsp[-5].name)) != 2){
                        printf("Line %d: While statement requires boolean condition \n", lineno-begin);
                    }
                }
#line 1875 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 391 "mython.y" /* yacc.c:1646  */
    {begin =1;}
#line 1881 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 392 "mython.y" /* yacc.c:1646  */
    {
                    if(lookupType((yyvsp[-4].name)) != 2){
                        printf("Line %d: While statement requires boolean condition \n", lineno-begin);
                    }
                }
#line 1891 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 400 "mython.y" /* yacc.c:1646  */
    {
                    frq++;

                }
#line 1900 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 405 "mython.y" /* yacc.c:1646  */
    {
                    frq++;
                    if(lookupType((yyvsp[0].name)) == 2){
                        printf("Line %d: Illegal parameter type: Integer or array expected on function : %s\n", lineno, (yyvsp[0].name));
                    }
                    
                }
#line 1912 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 421 "mython.y" /* yacc.c:1646  */
    {
                    insert((yyvsp[-2].name),lineno,9,-1);
                }
#line 1920 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 425 "mython.y" /* yacc.c:1646  */
    {
                    insert((yyvsp[-2].name),lineno,lookupType((yyvsp[0].name)),-1);
                }
#line 1928 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 429 "mython.y" /* yacc.c:1646  */
    {
                    insert((yyvsp[-4].name),lineno,3,-1);
                }
#line 1936 "mython.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 433 "mython.y" /* yacc.c:1646  */
    {
                    if(lookupType((yyvsp[-3].name)) != lookupType((yyvsp[0].name))){
                        printf("Line %d: Array variable miss match declared: %s != %s\n", lineno, (yyvsp[-3].name),(yyvsp[0].name));
                    }else{
                        insert((yyvsp[-5].name),lineno,3,-1);
                    }
                    
                }
#line 1949 "mython.tab.c" /* yacc.c:1646  */
    break;


#line 1953 "mython.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 442 "mython.y" /* yacc.c:1906  */


yyerror() {
  fprintf(stderr,"Syntax error: line %d\n",lineno);
}

int yywrap() {
    return 1;
}


main(int argc, char **argv) {
    yyparse();
}



void enterScope() {
    SymbolTable* new_scope = (SymbolTable*) malloc(50*sizeof(SymbolTable));
    new_scope->head = NULL;
    new_scope->parent = current_scope;
    current_scope = new_scope;
}

void exitScope() {
    current_scope = current_scope->parent;
}

void insert(char* name, int lineno,int type,int param) {
    SymbolNode* node = (SymbolNode*) malloc(50*sizeof(SymbolNode));
    node->name = name;
    node->lineno = lineno;
    node->type = type;
    node->param =param;
    node->next = current_scope->head;
    current_scope->head = node;
}

int lookup(char* name, int lineno) {
    SymbolTable* scope = current_scope;
    while (scope != NULL) {
        SymbolNode* node = scope->head;
        while (node != NULL) {
            if (strcmp(node->name, name) == 0) {
                return 0;
            }
            node = node->next;
        }
        scope = scope->parent;
    }
    return -1;
}

int lookupType(char* name_1) {
    int first =-99; //default values

    SymbolTable* scope = current_scope; //check first
    while (scope != NULL) {
        SymbolNode* node = scope->head;
        while (node != NULL) {
            if (strcmp(node->name, name_1) == 0) {
                first = node->type;
                return first;
            }
            node = node->next;
        }
        scope = scope->parent;
    }
    return -1;// type mismatch
}

int getParam(char* name){
     SymbolTable* scope = current_scope;
    while (scope != NULL) {
        SymbolNode* node = scope->head;
        while (node != NULL) {
            if (strcmp(node->name, name) == 0) {
                return node->param;
            }
            node = node->next;
        }
        scope = scope->parent;
    }
    return -1;
}

int updateVar(char* name, int type) {
    SymbolTable* scope = current_scope;
    while (scope != NULL) {
        SymbolNode* node = scope->head;
        while (node != NULL) {
            if (strcmp(node->name, name) == 0) {
                node->type = type;
                return 0;
            }
            node = node->next;
        }
        scope = scope->parent;
    }
    return -1;
}



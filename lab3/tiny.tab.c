/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 7 "tiny.y"

#define YYPARSER /* distinguishes Yacc output from other code files */

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"

#define YYSTYPE TreeNode *
static char * savedName; /* for use in assignments */
static int savedLineNo;  /* ditto */
static TreeNode * savedTree; /* stores syntax tree for later return */
static int yylex(void);
int yyerror(char *s);


#line 88 "tiny.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "tiny.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_NUM = 4,                        /* NUM  */
  YYSYMBOL_IF = 5,                         /* IF  */
  YYSYMBOL_ELSE = 6,                       /* ELSE  */
  YYSYMBOL_INT = 7,                        /* INT  */
  YYSYMBOL_RETURN = 8,                     /* RETURN  */
  YYSYMBOL_VOID = 9,                       /* VOID  */
  YYSYMBOL_WHILE = 10,                     /* WHILE  */
  YYSYMBOL_WRITE = 11,                     /* WRITE  */
  YYSYMBOL_PLUS = 12,                      /* PLUS  */
  YYSYMBOL_MINUS = 13,                     /* MINUS  */
  YYSYMBOL_TIMES = 14,                     /* TIMES  */
  YYSYMBOL_OVER = 15,                      /* OVER  */
  YYSYMBOL_LESS = 16,                      /* LESS  */
  YYSYMBOL_LEQ = 17,                       /* LEQ  */
  YYSYMBOL_GREATER = 18,                   /* GREATER  */
  YYSYMBOL_GEQ = 19,                       /* GEQ  */
  YYSYMBOL_COMPARE = 20,                   /* COMPARE  */
  YYSYMBOL_LPAREN = 21,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 22,                    /* RPAREN  */
  YYSYMBOL_DIFF = 23,                      /* DIFF  */
  YYSYMBOL_ASSIGN = 24,                    /* ASSIGN  */
  YYSYMBOL_SEMI = 25,                      /* SEMI  */
  YYSYMBOL_COMMA = 26,                     /* COMMA  */
  YYSYMBOL_LCOLCH = 27,                    /* LCOLCH  */
  YYSYMBOL_RCOLCH = 28,                    /* RCOLCH  */
  YYSYMBOL_LBRAC = 29,                     /* LBRAC  */
  YYSYMBOL_RBRAC = 30,                     /* RBRAC  */
  YYSYMBOL_BEGCOM = 31,                    /* BEGCOM  */
  YYSYMBOL_ENDCOM = 32,                    /* ENDCOM  */
  YYSYMBOL_ERROR = 33,                     /* ERROR  */
  YYSYMBOL_ENDFILE = 34,                   /* ENDFILE  */
  YYSYMBOL_YYACCEPT = 35,                  /* $accept  */
  YYSYMBOL_program = 36,                   /* program  */
  YYSYMBOL_decl_lista = 37,                /* decl_lista  */
  YYSYMBOL_decl = 38,                      /* decl  */
  YYSYMBOL_var_decl = 39,                  /* var_decl  */
  YYSYMBOL_40_1 = 40,                      /* $@1  */
  YYSYMBOL_41_2 = 41,                      /* $@2  */
  YYSYMBOL_type_esp = 42,                  /* type_esp  */
  YYSYMBOL_func_decl = 43,                 /* func_decl  */
  YYSYMBOL_44_3 = 44,                      /* @3  */
  YYSYMBOL_params = 45,                    /* params  */
  YYSYMBOL_param_list = 46,                /* param_list  */
  YYSYMBOL_param = 47,                     /* param  */
  YYSYMBOL_comp_decl = 48,                 /* comp_decl  */
  YYSYMBOL_local_decl = 49,                /* local_decl  */
  YYSYMBOL_stmt_lista = 50,                /* stmt_lista  */
  YYSYMBOL_stmt = 51,                      /* stmt  */
  YYSYMBOL_exp_decl = 52,                  /* exp_decl  */
  YYSYMBOL_sel_decl = 53,                  /* sel_decl  */
  YYSYMBOL_repeat_decl = 54,               /* repeat_decl  */
  YYSYMBOL_return_decl = 55,               /* return_decl  */
  YYSYMBOL_exp = 56,                       /* exp  */
  YYSYMBOL_var = 57,                       /* var  */
  YYSYMBOL_58_4 = 58,                      /* $@4  */
  YYSYMBOL_simple_exp = 59,                /* simple_exp  */
  YYSYMBOL_relacional = 60,                /* relacional  */
  YYSYMBOL_soma_exp = 61,                  /* soma_exp  */
  YYSYMBOL_soma = 62,                      /* soma  */
  YYSYMBOL_term = 63,                      /* term  */
  YYSYMBOL_mult = 64,                      /* mult  */
  YYSYMBOL_factor = 65,                    /* factor  */
  YYSYMBOL_ativation = 66,                 /* ativation  */
  YYSYMBOL_67_5 = 67,                      /* $@5  */
  YYSYMBOL_args = 68,                      /* args  */
  YYSYMBOL_arg_lista = 69                  /* arg_lista  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   102

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  107

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    37,    37,    40,    49,    54,    55,    61,    61,    76,
      76,    88,    89,    92,    92,   108,   112,   118,   130,   136,
     145,   155,   171,   182,   188,   199,   205,   209,   213,   217,
     221,   227,   231,   236,   243,   252,   260,   265,   274,   282,
     288,   293,   293,   306,   313,   319,   324,   329,   334,   339,
     344,   351,   358,   364,   369,   376,   383,   389,   394,   401,
     405,   409,   413,   422,   422,   433,   437,   443,   453
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ID", "NUM", "IF",
  "ELSE", "INT", "RETURN", "VOID", "WHILE", "WRITE", "PLUS", "MINUS",
  "TIMES", "OVER", "LESS", "LEQ", "GREATER", "GEQ", "COMPARE", "LPAREN",
  "RPAREN", "DIFF", "ASSIGN", "SEMI", "COMMA", "LCOLCH", "RCOLCH", "LBRAC",
  "RBRAC", "BEGCOM", "ENDCOM", "ERROR", "ENDFILE", "$accept", "program",
  "decl_lista", "decl", "var_decl", "$@1", "$@2", "type_esp", "func_decl",
  "@3", "params", "param_list", "param", "comp_decl", "local_decl",
  "stmt_lista", "stmt", "exp_decl", "sel_decl", "repeat_decl",
  "return_decl", "exp", "var", "$@4", "simple_exp", "relacional",
  "soma_exp", "soma", "term", "mult", "factor", "ativation", "$@5", "args",
  "arg_lista", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-43)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-64)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       2,   -43,   -43,    13,     2,   -43,   -43,    28,   -43,   -43,
     -43,   -20,    -9,     6,    21,   -43,    43,    39,    30,    46,
      49,    48,    45,   -43,    47,    50,    44,     2,   -43,    51,
     -43,   -43,   -43,   -43,     2,   -43,    71,     0,    54,   -15,
     -43,    55,    11,    57,    24,   -43,   -43,   -43,   -43,   -43,
     -43,   -43,   -43,    58,    56,   -43,    37,    23,   -43,   -43,
      59,    61,    24,   -43,    60,    24,    62,   -43,    24,   -43,
     -43,   -43,   -43,   -43,   -43,   -43,   -43,    24,    24,   -43,
     -43,    24,    24,    24,    65,   -43,    66,   -43,   -43,   -43,
      53,    23,   -43,    63,   -43,    67,    64,    14,    14,   -43,
     -43,    24,    69,   -43,   -43,    14,   -43
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    11,    12,     0,     2,     4,     5,     0,     6,     1,
       3,     7,     0,     0,     0,     8,     0,     0,     0,    12,
       0,     0,    15,    18,     0,    19,     0,     0,    10,     0,
      23,    14,    17,    20,    25,    22,     0,     0,     7,    40,
      62,     0,     0,     0,     0,    32,    21,    27,    24,    26,
      28,    29,    30,     0,    60,    39,    44,    52,    56,    61,
       0,     0,     0,    36,     0,     0,     0,    31,     0,    53,
      54,    46,    45,    47,    48,    49,    50,     0,     0,    57,
      58,     0,     0,    66,     0,    37,     0,    59,    38,    60,
      43,    51,    55,     0,    68,     0,    65,     0,     0,    42,
      64,     0,    33,    35,    67,     0,    34
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -43,   -43,   -43,    88,    68,   -43,   -43,    17,   -43,   -43,
     -43,   -43,    70,    72,   -43,   -43,   -36,   -43,   -43,   -43,
     -43,   -42,   -14,   -43,   -43,   -43,    16,   -43,    18,   -43,
      19,   -43,   -43,   -43,   -43
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,     6,    12,    13,     7,     8,    14,
      21,    22,    23,    47,    34,    37,    48,    49,    50,    51,
      52,    53,    54,    60,    55,    77,    56,    78,    57,    81,
      58,    59,    61,    95,    96
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      64,   -13,    66,    39,    40,    41,   -63,    -9,    42,     1,
      43,     2,   -41,     9,    39,    40,    15,    39,    40,    41,
      84,    44,    42,    86,    43,    45,    88,    39,    40,    30,
      46,    11,    44,    16,    20,    44,    63,    79,    80,    45,
      93,    94,    17,    30,    20,    44,     1,    18,    19,    69,
      70,    36,    25,    71,    72,    73,    74,    75,    24,   104,
      76,   102,   103,    89,    89,    69,    70,    89,   -16,   106,
      26,    27,    28,    30,    38,   105,    62,    29,    65,    33,
      68,    -9,    83,    67,    87,    85,    82,    97,    98,   100,
     101,    99,    10,    90,     0,     0,    91,    32,    31,     0,
      92,     0,    35
};

static const yytype_int8 yycheck[] =
{
      42,    21,    44,     3,     4,     5,    21,    27,     8,     7,
      10,     9,    27,     0,     3,     4,    25,     3,     4,     5,
      62,    21,     8,    65,    10,    25,    68,     3,     4,    29,
      30,     3,    21,    27,    17,    21,    25,    14,    15,    25,
      82,    83,    21,    29,    27,    21,     7,     4,     9,    12,
      13,    34,     3,    16,    17,    18,    19,    20,    28,   101,
      23,    97,    98,    77,    78,    12,    13,    81,    22,   105,
      22,    26,    25,    29,     3,     6,    21,    27,    21,    28,
      24,    27,    21,    25,    22,    25,    27,    22,    22,    22,
      26,    28,     4,    77,    -1,    -1,    78,    27,    26,    -1,
      81,    -1,    34
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,     9,    36,    37,    38,    39,    42,    43,     0,
      38,     3,    40,    41,    44,    25,    27,    21,     4,     9,
      42,    45,    46,    47,    28,     3,    22,    26,    25,    27,
      29,    48,    47,    28,    49,    39,    42,    50,     3,     3,
       4,     5,     8,    10,    21,    25,    30,    48,    51,    52,
      53,    54,    55,    56,    57,    59,    61,    63,    65,    66,
      58,    67,    21,    25,    56,    21,    56,    25,    24,    12,
      13,    16,    17,    18,    19,    20,    23,    60,    62,    14,
      15,    64,    27,    21,    56,    25,    56,    22,    56,    57,
      61,    63,    65,    56,    56,    68,    69,    22,    22,    28,
      22,    26,    51,    51,    56,     6,    51
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    36,    37,    37,    38,    38,    40,    39,    41,
      39,    42,    42,    44,    43,    45,    45,    46,    46,    47,
      47,    48,    49,    49,    50,    50,    51,    51,    51,    51,
      51,    52,    52,    53,    53,    54,    55,    55,    56,    56,
      57,    58,    57,    59,    59,    60,    60,    60,    60,    60,
      60,    61,    61,    62,    62,    63,    63,    64,    64,    65,
      65,    65,    65,    67,    66,    68,    68,    69,    69
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     0,     4,     0,
       7,     1,     1,     0,     7,     1,     1,     3,     1,     2,
       4,     4,     2,     0,     2,     0,     1,     1,     1,     1,
       1,     2,     1,     5,     7,     5,     2,     3,     3,     1,
       1,     0,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     0,     5,     1,     0,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* program: decl_lista  */
#line 37 "tiny.y"
                   {savedTree = yyvsp[0];}
#line 1216 "tiny.tab.c"
    break;

  case 3: /* decl_lista: decl_lista decl  */
#line 40 "tiny.y"
                        {YYSTYPE t = yyvsp[-1];
                         if (t != NULL)
                         { while (t->sibling != NULL)
                             t = t->sibling;
                           t->sibling = yyvsp[0];
                           yyval = yyvsp[-1];
                         }
                         else yyval = yyvsp[0];
                        }
#line 1230 "tiny.tab.c"
    break;

  case 4: /* decl_lista: decl  */
#line 49 "tiny.y"
             {
            yyval = yyvsp[0];
        }
#line 1238 "tiny.tab.c"
    break;

  case 5: /* decl: var_decl  */
#line 54 "tiny.y"
                 {yyval = yyvsp[0];}
#line 1244 "tiny.tab.c"
    break;

  case 6: /* decl: func_decl  */
#line 55 "tiny.y"
                  {
        // printf(" Entrou em func_decl\n");
        yyval = yyvsp[0];
      }
#line 1253 "tiny.tab.c"
    break;

  case 7: /* $@1: %empty  */
#line 61 "tiny.y"
                   {
        // printf("ID_name em var_decl: %s\n", ID_name);
        savedName = copyString(ID_name);
        savedLineNo = lineno; 
        
        }
#line 1264 "tiny.tab.c"
    break;

  case 8: /* var_decl: type_esp ID $@1 SEMI  */
#line 67 "tiny.y"
            {
        yyval = yyvsp[-3];
        yyval->child[0] = newDeclNode(VarK);

        yyval->child[0]->type = yyvsp[-3]->type;
        yyval->child[0]->attr.name = savedName;
        yyval->child[0]->lineno = savedLineNo;
        // printf("lineno: %d\n", $$->child[0]->lineno);
        }
#line 1278 "tiny.tab.c"
    break;

  case 9: /* $@2: %empty  */
#line 76 "tiny.y"
                    {
        savedName = copyString(ID_name);
        savedLineNo = lineno; 
        }
#line 1287 "tiny.tab.c"
    break;

  case 10: /* var_decl: type_esp ID $@2 LCOLCH NUM RCOLCH SEMI  */
#line 79 "tiny.y"
                                 {
            yyval = yyvsp[-6];
            yyval->child[0] = newDeclNode(ArrayK);
            yyval->child[0]->type = yyvsp[-6]->type;
            yyval->child[0]->attr.name = savedName;
            yyval->child[0]->lineno = savedLineNo;
        }
#line 1299 "tiny.tab.c"
    break;

  case 11: /* type_esp: INT  */
#line 88 "tiny.y"
            {yyval = newTypeNode(Integer);}
#line 1305 "tiny.tab.c"
    break;

  case 12: /* type_esp: VOID  */
#line 89 "tiny.y"
             {yyval = newTypeNode(Void);}
#line 1311 "tiny.tab.c"
    break;

  case 13: /* @3: %empty  */
#line 92 "tiny.y"
                    {
        savedName = copyString(ID_name);
        savedLineNo = lineno; 
        yyval = yyvsp[-1];
        yyval->child[0] = newFuncNode();
        yyval->child[0]->attr.name = savedName;
      }
#line 1323 "tiny.tab.c"
    break;

  case 14: /* func_decl: type_esp ID @3 LPAREN params RPAREN comp_decl  */
#line 98 "tiny.y"
                                      {
        // fprintf(listing," Entrou em type_esp ID LPAREN params RPAREN comp_decl\n");
        yyval = yyvsp[-4];
        yyval->child[0]->type = yyvsp[-6]->type;
        yyval->child[0]->lineno = savedLineNo;
        yyval->child[0]->child[0] = yyvsp[-2];
        yyval->child[0]->child[1] = yyvsp[0];
        }
#line 1336 "tiny.tab.c"
    break;

  case 15: /* params: param_list  */
#line 108 "tiny.y"
                   {
        // printf(" Entrou em param_list\n");
        yyval = yyvsp[0];
      }
#line 1345 "tiny.tab.c"
    break;

  case 16: /* params: VOID  */
#line 112 "tiny.y"
             {
        // printf(" Entrou em VOID\n");
        yyval = NULL;
        }
#line 1354 "tiny.tab.c"
    break;

  case 17: /* param_list: param_list COMMA param  */
#line 118 "tiny.y"
                               {
        // printf(" Entrou em param_list COMMA param\n");
        YYSTYPE t = yyvsp[-2];
        if (t != NULL)
        { while (t->sibling != NULL)
            t = t->sibling;
        t->sibling = yyvsp[0];
        yyval = yyvsp[-2];
        }
        else yyval = yyvsp[0];
                        
        }
#line 1371 "tiny.tab.c"
    break;

  case 18: /* param_list: param  */
#line 130 "tiny.y"
              {
        // printf(" Entrou em param\n");
        yyval = yyvsp[0];
        }
#line 1380 "tiny.tab.c"
    break;

  case 19: /* param: type_esp ID  */
#line 136 "tiny.y"
                 {
        // fprintf(listing,"ID_name em param: %s\n", ID_name);
        savedLineNo = lineno; 
        yyval = yyvsp[-1];
        yyval->child[0] = newParamNode(VarK);
        yyval->child[0]->type = yyvsp[-1]->type;
        yyval->child[0]->attr.name = copyString(ID_name);
        yyval->child[0]->lineno = lineno;
        }
#line 1394 "tiny.tab.c"
    break;

  case 20: /* param: type_esp ID LCOLCH RCOLCH  */
#line 145 "tiny.y"
                               {
        // printf(" Entrou em type_esp ID LCOLCH RCOLCH\n");
        yyval = yyvsp[-3];
        yyval->child[0] = newParamNode(ArrayK);
        yyval->child[0]->type = yyvsp[-3]->type;
        yyval->child[0]->attr.name = copyString(ID_name);
        yyval->child[0]->lineno = savedLineNo;
    }
#line 1407 "tiny.tab.c"
    break;

  case 21: /* comp_decl: LBRAC local_decl stmt_lista RBRAC  */
#line 155 "tiny.y"
                                        {
        // printf(" Entrou em LBRAC local_decl stmt_lista RBRAC\n");
        // considerando o local_decl e stmt_lista irmãos
        YYSTYPE t = yyvsp[-2];
        if (t != NULL)
        { while (t->sibling != NULL)
            t = t->sibling;
        t->sibling = yyvsp[-1];
        yyval = yyvsp[-2];
        }
        else{
            yyval = yyvsp[-1];
        } 
    }
#line 1426 "tiny.tab.c"
    break;

  case 22: /* local_decl: local_decl var_decl  */
#line 171 "tiny.y"
                          {
        // printf(" Entrou em local_decl var_decl\n");
        YYSTYPE t = yyvsp[-1];
        if (t != NULL)
        { while (t->sibling != NULL)
            t = t->sibling;
        t->sibling = yyvsp[0];
        yyval = yyvsp[-1];
        }
        else yyval = yyvsp[0];
        }
#line 1442 "tiny.tab.c"
    break;

  case 23: /* local_decl: %empty  */
#line 182 "tiny.y"
             {
        // printf(" Entrou em empty\n");
        yyval = NULL;
        }
#line 1451 "tiny.tab.c"
    break;

  case 24: /* stmt_lista: stmt_lista stmt  */
#line 188 "tiny.y"
                      {
        // printf(" Entrou em stmt_lista stmt\n");
        YYSTYPE t = yyvsp[-1];
        if (t != NULL)
        { while (t->sibling != NULL)
            t = t->sibling;
        t->sibling = yyvsp[0];
        yyval = yyvsp[-1];
        }
        else yyval = yyvsp[0];
         }
#line 1467 "tiny.tab.c"
    break;

  case 25: /* stmt_lista: %empty  */
#line 199 "tiny.y"
             {
        // printf(" Entrou em empty\n");
        yyval = NULL;
        }
#line 1476 "tiny.tab.c"
    break;

  case 26: /* stmt: exp_decl  */
#line 205 "tiny.y"
               {
        // printf(" Entrou em exp_decl\n");
        yyval = yyvsp[0];
        }
#line 1485 "tiny.tab.c"
    break;

  case 27: /* stmt: comp_decl  */
#line 209 "tiny.y"
                {
        // printf(" Entrou em comp_decl\n");
        yyval = yyvsp[0];
        }
#line 1494 "tiny.tab.c"
    break;

  case 28: /* stmt: sel_decl  */
#line 213 "tiny.y"
               {
        // printf(" Entrou em sel_decl\n");
        yyval = yyvsp[0];
        }
#line 1503 "tiny.tab.c"
    break;

  case 29: /* stmt: repeat_decl  */
#line 217 "tiny.y"
                  {
        // printf(" Entrou em repeat_decl\n");
        yyval = yyvsp[0];
        }
#line 1512 "tiny.tab.c"
    break;

  case 30: /* stmt: return_decl  */
#line 221 "tiny.y"
                  {
        // printf(" Entrou em return_decl\n");
        yyval = yyvsp[0];
        }
#line 1521 "tiny.tab.c"
    break;

  case 31: /* exp_decl: exp SEMI  */
#line 227 "tiny.y"
               {
        // printf(" Entrou em exp SEMI\n");
        yyval = yyvsp[-1];
        }
#line 1530 "tiny.tab.c"
    break;

  case 32: /* exp_decl: SEMI  */
#line 231 "tiny.y"
           {
        // printf(" Entrou em SEMI\n");
        }
#line 1538 "tiny.tab.c"
    break;

  case 33: /* sel_decl: IF LPAREN exp RPAREN stmt  */
#line 236 "tiny.y"
                                {
        // printf(" Entrou em IF LPAREN exp RPAREN stmt\n");
        yyval = newStmtNode(IfK);
        yyval->child[0] = yyvsp[-2];
        yyval->child[1] = yyvsp[0];

        }
#line 1550 "tiny.tab.c"
    break;

  case 34: /* sel_decl: IF LPAREN exp RPAREN stmt ELSE stmt  */
#line 243 "tiny.y"
                                          {
        // printf(" Entrou em IF LPAREN exp RPAREN stmt ELSE stmt\n");
        yyval = newStmtNode(IfK);
        yyval->child[0] = yyvsp[-4];
        yyval->child[1] = yyvsp[-2];
        yyval->child[2] = yyvsp[0];
        }
#line 1562 "tiny.tab.c"
    break;

  case 35: /* repeat_decl: WHILE LPAREN exp RPAREN stmt  */
#line 252 "tiny.y"
                                   {
        // printf(" Entrou em WHILE LPAREN exp RPAREN stmt\n");
        yyval = newStmtNode(RepeatK);
        yyval->child[0] = yyvsp[-2];
        yyval->child[1] = yyvsp[0];
        }
#line 1573 "tiny.tab.c"
    break;

  case 36: /* return_decl: RETURN SEMI  */
#line 260 "tiny.y"
                  {
        // printf(" Entrou em RETURN SEMI\n");
        yyval = newStmtNode(ReturnK);
        yyval->attr.name = copyString(tokenString);
        }
#line 1583 "tiny.tab.c"
    break;

  case 37: /* return_decl: RETURN exp SEMI  */
#line 265 "tiny.y"
                      {
        // printf(" Entrou em RETURN exp SEMI\n");
        yyval = newStmtNode(ReturnK);
        yyval->child[0] = yyvsp[-1];
        yyval->attr.name = copyString(tokenString);
        }
#line 1594 "tiny.tab.c"
    break;

  case 38: /* exp: var ASSIGN exp  */
#line 274 "tiny.y"
                     {
        // printf(" Entrou em var ASSIGN exp\n");
        yyval = newStmtNode(AssignK);
        yyval->child[0] = yyvsp[-2];
        yyval->child[1] = yyvsp[0];
        // $$->attr.op = ASSIGN;
        //$$->attr.name = $1->attr.name; // atribui o nome da variável
        }
#line 1607 "tiny.tab.c"
    break;

  case 39: /* exp: simple_exp  */
#line 282 "tiny.y"
                 {
        // printf(" Entrou em simple_exp\n");
        yyval = yyvsp[0];
        }
#line 1616 "tiny.tab.c"
    break;

  case 40: /* var: ID  */
#line 288 "tiny.y"
         {
        // printf(" Entrou em ID\n");
        yyval = newExpNode(IdK);
        yyval->attr.name = copyString(ID_name);
        }
#line 1626 "tiny.tab.c"
    break;

  case 41: /* $@4: %empty  */
#line 293 "tiny.y"
         {
        savedName = copyString(ID_name);
        savedLineNo = lineno;
        }
#line 1635 "tiny.tab.c"
    break;

  case 42: /* var: ID $@4 LCOLCH exp RCOLCH  */
#line 297 "tiny.y"
                      {
        // printf(" Entrou em ID LCOLCH exp RCOLCH\n");
        // todo: entender qual tipo de no é esse
        yyval = newExpNode(IdK);
        yyval->attr.name = savedName;
        yyval->child[0] = yyvsp[-1];
        }
#line 1647 "tiny.tab.c"
    break;

  case 43: /* simple_exp: soma_exp relacional soma_exp  */
#line 306 "tiny.y"
                                   {
        // printf(" Entrou em soma_exp relacional soma_exp\n");
        yyval = yyvsp[-1];
        yyval->child[0] = yyvsp[-2];
        yyval->child[1] = yyvsp[0];
        yyval->lineno = lineno;
        }
#line 1659 "tiny.tab.c"
    break;

  case 44: /* simple_exp: soma_exp  */
#line 313 "tiny.y"
               {
        // printf(" Entrou em soma_exp\n");
        yyval = yyvsp[0];
        }
#line 1668 "tiny.tab.c"
    break;

  case 45: /* relacional: LEQ  */
#line 319 "tiny.y"
          {
        // printf(" Entrou em LEQ\n");
        yyval = newExpNode(OpK);
        yyval->attr.op = LEQ;
    }
#line 1678 "tiny.tab.c"
    break;

  case 46: /* relacional: LESS  */
#line 324 "tiny.y"
           {
        // printf(" Entrou em LESS\n");
        yyval = newExpNode(OpK);
        yyval->attr.op = LESS;
        }
#line 1688 "tiny.tab.c"
    break;

  case 47: /* relacional: GREATER  */
#line 329 "tiny.y"
              {
        // printf(" Entrou em GREATER\n");
        yyval = newExpNode(OpK);
        yyval->attr.op = GREATER;
        }
#line 1698 "tiny.tab.c"
    break;

  case 48: /* relacional: GEQ  */
#line 334 "tiny.y"
          {
        // printf(" Entrou em GEQ\n");
        yyval = newExpNode(OpK);
        yyval->attr.op = GEQ;
        }
#line 1708 "tiny.tab.c"
    break;

  case 49: /* relacional: COMPARE  */
#line 339 "tiny.y"
             {
        // printf(" Entrou em COMPARE\n");
        yyval = newExpNode(OpK);
        yyval->attr.op = COMPARE;
        }
#line 1718 "tiny.tab.c"
    break;

  case 50: /* relacional: DIFF  */
#line 344 "tiny.y"
           {
        // printf(" Entrou em DIFF\n");
        yyval = newExpNode(OpK);
        yyval->attr.op = DIFF;
        }
#line 1728 "tiny.tab.c"
    break;

  case 51: /* soma_exp: soma_exp soma term  */
#line 351 "tiny.y"
                         {
        // printf(" Entrou em soma_exp soma term\n");
        yyval = yyvsp[-1];
        yyval->child[0] = yyvsp[-2];
        yyval->child[1] = yyvsp[0];
        yyval->lineno = lineno;
    }
#line 1740 "tiny.tab.c"
    break;

  case 52: /* soma_exp: term  */
#line 358 "tiny.y"
           {
        // printf(" Entrou em term\n");
        yyval = yyvsp[0];
        }
#line 1749 "tiny.tab.c"
    break;

  case 53: /* soma: PLUS  */
#line 364 "tiny.y"
           {
        // printf(" Entrou em PLUS\n");
        yyval = newExpNode(OpK);
        yyval->attr.op = PLUS;
        }
#line 1759 "tiny.tab.c"
    break;

  case 54: /* soma: MINUS  */
#line 369 "tiny.y"
            {
        // printf(" Entrou em MINUS\n");
        yyval = newExpNode(OpK);
        yyval->attr.op = MINUS;
        }
#line 1769 "tiny.tab.c"
    break;

  case 55: /* term: term mult factor  */
#line 376 "tiny.y"
                       {
        // printf(" Entrou em term mult factor\n");
        yyval = yyvsp[-1];
        yyval->child[0] = yyvsp[-2];
        yyval->child[1] = yyvsp[0];
        yyval->attr.op = yyvsp[-1]->attr.op;
        }
#line 1781 "tiny.tab.c"
    break;

  case 56: /* term: factor  */
#line 383 "tiny.y"
             {
        // printf(" Entrou em factor\n");
        yyval = yyvsp[0];
        }
#line 1790 "tiny.tab.c"
    break;

  case 57: /* mult: TIMES  */
#line 389 "tiny.y"
            {
        // printf(" Entrou em TIMES\n");
        yyval = newExpNode(OpK);
        yyval->attr.op = TIMES;
        }
#line 1800 "tiny.tab.c"
    break;

  case 58: /* mult: OVER  */
#line 394 "tiny.y"
           {
        // printf(" Entrou em OVER\n");
        yyval = newExpNode(OpK);
        yyval->attr.op = OVER;
        }
#line 1810 "tiny.tab.c"
    break;

  case 59: /* factor: LPAREN exp RPAREN  */
#line 401 "tiny.y"
                        {
        // printf(" Entrou em LPAREN exp RPAREN\n");
        yyval = yyvsp[-1];
        }
#line 1819 "tiny.tab.c"
    break;

  case 60: /* factor: var  */
#line 405 "tiny.y"
          {
        // printf(" Entrou em var\n");
        yyval = yyvsp[0];
        }
#line 1828 "tiny.tab.c"
    break;

  case 61: /* factor: ativation  */
#line 409 "tiny.y"
                {
        // printf(" Entrou em activation\n");
        yyval = yyvsp[0];
        }
#line 1837 "tiny.tab.c"
    break;

  case 62: /* factor: NUM  */
#line 413 "tiny.y"
          {
        // printf(" Entrou em NUM\n");
        yyval = newExpNode(ConstK);
        // fprintf(listing, "NUM: %s\n", tokenString);
        yyval->attr.val = atoi(tokenString);
        yyval-> type = Integer;
        }
#line 1849 "tiny.tab.c"
    break;

  case 63: /* $@5: %empty  */
#line 422 "tiny.y"
         {
        savedName = copyString(ID_name);
        savedLineNo = lineno;
    }
#line 1858 "tiny.tab.c"
    break;

  case 64: /* ativation: ID $@5 LPAREN args RPAREN  */
#line 425 "tiny.y"
                        {
        // printf(" Entrou em ID LPAREN args RPAREN\n");
        yyval = newExpNode(ActivationK);
        yyval->attr.name = savedName;
        yyval->child[0] = yyvsp[-1];
        }
#line 1869 "tiny.tab.c"
    break;

  case 65: /* args: arg_lista  */
#line 433 "tiny.y"
                {
        // printf(" Entrou em arg_lista\n");
        yyval = yyvsp[0];
        }
#line 1878 "tiny.tab.c"
    break;

  case 66: /* args: %empty  */
#line 437 "tiny.y"
             {
        // printf(" Entrou em empty\n");
        yyval = NULL;
        }
#line 1887 "tiny.tab.c"
    break;

  case 67: /* arg_lista: arg_lista COMMA exp  */
#line 443 "tiny.y"
                          {
        // printf(" Entrou em arg_lista COMMA exp\n");
        YYSTYPE t = yyvsp[-2];
        if (t != NULL)
        { while (t->sibling != NULL)
            t = t->sibling;
        t->sibling = yyvsp[0];
        yyval = yyvsp[-2];
        }
        else yyval = yyvsp[0];}
#line 1902 "tiny.tab.c"
    break;

  case 68: /* arg_lista: exp  */
#line 453 "tiny.y"
          {
        // printf(" Entrou em exp\n");
        yyval = yyvsp[0];
        }
#line 1911 "tiny.tab.c"
    break;


#line 1915 "tiny.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 458 "tiny.y"


int yyerror(char * message)
{ fprintf(listing,"Syntax error at line %d: %s\n",lineno,message);
  fprintf(listing,"Current token: ");
  printToken(yychar,tokenString);
  Error = TRUE;
  return 0;
}

/* yylex calls getToken to make Yacc/Bison output
 * compatible with ealier versions of the TINY scanner
 */
static int yylex(void)
{ return getToken(); }

TreeNode * parse(void)
{ yyparse();
  return savedTree;
}


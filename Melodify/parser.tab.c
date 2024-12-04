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
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodes.h"

void yyerror(const char *s);
int yylex();
extern int yylineno;
extern FILE *yyin; 
extern char *yytext;

#define YYDEBUG 1
extern int yydebug;

Node *ast_root; // Raiz da AST

// void init_codegen();
// void codegen(Node *node);
// void finalize_codegen();

#line 93 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUM = 3,                        /* NUM  */
  YYSYMBOL_STRING = 4,                     /* STRING  */
  YYSYMBOL_NOTE = 5,                       /* NOTE  */
  YYSYMBOL_CHORD_NAME = 6,                 /* CHORD_NAME  */
  YYSYMBOL_IDENTIFIER = 7,                 /* IDENTIFIER  */
  YYSYMBOL_DURATION = 8,                   /* DURATION  */
  YYSYMBOL_OPERATOR = 9,                   /* OPERATOR  */
  YYSYMBOL_SET = 10,                       /* SET  */
  YYSYMBOL_PLAY = 11,                      /* PLAY  */
  YYSYMBOL_REPEAT = 12,                    /* REPEAT  */
  YYSYMBOL_IF = 13,                        /* IF  */
  YYSYMBOL_ELSE = 14,                      /* ELSE  */
  YYSYMBOL_FUNCTION = 15,                  /* FUNCTION  */
  YYSYMBOL_RETURN = 16,                    /* RETURN  */
  YYSYMBOL_TEMPO = 17,                     /* TEMPO  */
  YYSYMBOL_INSTRUMENT = 18,                /* INSTRUMENT  */
  YYSYMBOL_VOLUME = 19,                    /* VOLUME  */
  YYSYMBOL_CHORD = 20,                     /* CHORD  */
  YYSYMBOL_ASSIGN = 21,                    /* ASSIGN  */
  YYSYMBOL_SEMICOLON = 22,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 23,                     /* COMMA  */
  YYSYMBOL_LBRACE = 24,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 25,                    /* RBRACE  */
  YYSYMBOL_LPAREN = 26,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 27,                    /* RPAREN  */
  YYSYMBOL_EQ = 28,                        /* EQ  */
  YYSYMBOL_NEQ = 29,                       /* NEQ  */
  YYSYMBOL_AND = 30,                       /* AND  */
  YYSYMBOL_OR = 31,                        /* OR  */
  YYSYMBOL_32_ = 32,                       /* '>'  */
  YYSYMBOL_33_ = 33,                       /* '<'  */
  YYSYMBOL_34_ = 34,                       /* '+'  */
  YYSYMBOL_35_ = 35,                       /* '-'  */
  YYSYMBOL_36_ = 36,                       /* '*'  */
  YYSYMBOL_37_ = 37,                       /* '/'  */
  YYSYMBOL_UMINUS = 38,                    /* UMINUS  */
  YYSYMBOL_39_ = 39,                       /* '('  */
  YYSYMBOL_40_ = 40,                       /* ')'  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_program = 42,                   /* program  */
  YYSYMBOL_statement_list = 43,            /* statement_list  */
  YYSYMBOL_statement = 44,                 /* statement  */
  YYSYMBOL_variable_declaration = 45,      /* variable_declaration  */
  YYSYMBOL_assignment = 46,                /* assignment  */
  YYSYMBOL_musical_instruction = 47,       /* musical_instruction  */
  YYSYMBOL_conditional = 48,               /* conditional  */
  YYSYMBOL_loop = 49,                      /* loop  */
  YYSYMBOL_function_declaration = 50,      /* function_declaration  */
  YYSYMBOL_function_call = 51,             /* function_call  */
  YYSYMBOL_condition = 52,                 /* condition  */
  YYSYMBOL_expression = 53,                /* expression  */
  YYSYMBOL_term = 54,                      /* term  */
  YYSYMBOL_factor = 55                     /* factor  */
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
#define YYFINAL  30
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   173

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  51
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  117

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   287


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
      39,    40,    36,    34,     2,    35,     2,    37,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      33,     2,    32,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    38
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    53,    53,    59,    62,    73,    76,    79,    82,    85,
      88,    91,    97,   101,   105,   114,   121,   126,   131,   136,
     141,   146,   152,   156,   162,   165,   174,   181,   188,   195,
     199,   203,   207,   211,   215,   222,   225,   229,   233,   237,
     241,   247,   251,   255,   261,   264,   268,   271,   274,   277,
     280,   283
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
  "\"end of file\"", "error", "\"invalid token\"", "NUM", "STRING",
  "NOTE", "CHORD_NAME", "IDENTIFIER", "DURATION", "OPERATOR", "SET",
  "PLAY", "REPEAT", "IF", "ELSE", "FUNCTION", "RETURN", "TEMPO",
  "INSTRUMENT", "VOLUME", "CHORD", "ASSIGN", "SEMICOLON", "COMMA",
  "LBRACE", "RBRACE", "LPAREN", "RPAREN", "EQ", "NEQ", "AND", "OR", "'>'",
  "'<'", "'+'", "'-'", "'*'", "'/'", "UMINUS", "'('", "')'", "$accept",
  "program", "statement_list", "statement", "variable_declaration",
  "assignment", "musical_instruction", "conditional", "loop",
  "function_declaration", "function_call", "condition", "expression",
  "term", "factor", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-54)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     143,   -13,    47,    10,    15,    -4,    20,    32,   143,   -54,
     -54,   -54,   -54,   -54,   -54,   -54,   -54,     2,     9,     7,
       2,    45,     2,    36,    48,    53,    34,    50,     2,    52,
     -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,    40,     2,
      16,    31,   -54,    54,    65,     2,    62,    92,    66,    97,
      71,    78,    81,   117,   127,   143,     4,   112,   115,   -54,
     -54,   125,   -54,    40,    40,    40,    40,    40,    40,   -54,
     -54,   102,   -54,   -54,   -54,   -54,   -54,   -54,   -54,    84,
     121,    70,   128,     2,     2,     2,     2,     2,     2,   133,
     -54,    31,    31,   -54,   -54,   -54,   -54,   -54,   -54,   -54,
     -54,   143,   -54,   134,   132,   132,   132,   132,   143,    79,
      98,   137,   -54,   139,   143,   105,   -54
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     2,     3,
       5,     6,     7,     8,     9,    10,    11,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     4,    35,    51,    47,    48,    49,    50,     0,     0,
       0,    40,    43,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    46,
      45,     0,    15,     0,     0,     0,     0,     0,     0,    28,
      14,     0,    13,    21,    22,    23,    16,    17,    20,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      44,    36,    37,    38,    39,    41,    42,    12,    19,    18,
      26,     0,    33,    34,    31,    32,    30,    29,     0,     0,
       0,    24,    27,     0,     0,     0,    25
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -54,   -54,   -53,    -8,   -54,   -54,   -54,   -54,   -54,   -54,
     -54,    38,   -16,   107,    -5
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    56,    57,    41,    42
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      31,    40,    81,    46,    47,    32,    49,    33,    17,    34,
      32,    44,    33,    18,    34,    23,    24,    25,    27,    35,
      36,    37,    28,    61,    35,    36,    37,    29,    45,    71,
      26,    82,    30,    60,    83,    84,    43,    38,    62,    53,
      54,    39,    38,    59,    50,    33,    39,    34,   109,    48,
      63,    64,    65,    66,    19,   110,    51,    35,    36,    37,
      52,   115,    95,    96,    20,    21,    22,    67,    68,   104,
     105,   106,   107,    31,    55,    38,    69,     1,    58,    39,
       2,     3,     4,     5,    72,     6,     1,    70,    74,     2,
       3,     4,     5,    76,     6,   100,    63,    64,    65,    66,
      77,    31,    31,    78,   111,     1,    98,    31,     2,     3,
       4,     5,     1,     6,    73,     2,     3,     4,     5,    75,
       6,   102,   103,   112,    97,    79,    63,    64,    65,    66,
     116,    63,    64,    65,    66,    80,    63,    64,    65,    66,
      85,    86,    89,    99,    87,    88,    63,    64,    65,    66,
       1,   113,   101,     2,     3,     4,     5,   108,     6,    63,
      64,    65,    66,   114,    83,    90,    63,    64,    65,    66,
      91,    92,    93,    94
};

static const yytype_int8 yycheck[] =
{
       8,    17,    55,    19,    20,     3,    22,     5,    21,     7,
       3,     4,     5,    26,     7,     5,     6,     7,     3,    17,
      18,    19,    26,    39,    17,    18,    19,     7,    21,    45,
      20,    27,     0,    38,    30,    31,    27,    35,    22,     5,
       6,    39,    35,     3,     8,     5,    39,     7,   101,     4,
      34,    35,    36,    37,     7,   108,     8,    17,    18,    19,
       7,   114,    67,    68,    17,    18,    19,    36,    37,    85,
      86,    87,    88,    81,    24,    35,    22,     7,    26,    39,
      10,    11,    12,    13,    22,    15,     7,    22,    22,    10,
      11,    12,    13,    22,    15,    25,    34,    35,    36,    37,
      22,   109,   110,    22,    25,     7,    22,   115,    10,    11,
      12,    13,     7,    15,    22,    10,    11,    12,    13,    22,
      15,    83,    84,    25,    22,     8,    34,    35,    36,    37,
      25,    34,    35,    36,    37,     8,    34,    35,    36,    37,
      28,    29,    27,    22,    32,    33,    34,    35,    36,    37,
       7,    14,    24,    10,    11,    12,    13,    24,    15,    34,
      35,    36,    37,    24,    30,    40,    34,    35,    36,    37,
      63,    64,    65,    66
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,    10,    11,    12,    13,    15,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    21,    26,     7,
      17,    18,    19,     5,     6,     7,    20,     3,    26,     7,
       0,    44,     3,     5,     7,    17,    18,    19,    35,    39,
      53,    54,    55,    27,     4,    21,    53,    53,     4,    53,
       8,     8,     7,     5,     6,    24,    52,    53,    26,     3,
      55,    53,    22,    34,    35,    36,    37,    36,    37,    22,
      22,    53,    22,    22,    22,    22,    22,    22,    22,     8,
       8,    43,    27,    30,    31,    28,    29,    32,    33,    27,
      40,    54,    54,    54,    54,    55,    55,    22,    22,    22,
      25,    24,    52,    52,    53,    53,    53,    53,    24,    43,
      43,    25,    25,    14,    24,    43,    25
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    44,    44,    44,
      44,    44,    45,    45,    45,    46,    47,    47,    47,    47,
      47,    47,    47,    47,    48,    48,    49,    50,    51,    52,
      52,    52,    52,    52,    52,    53,    53,    53,    53,    53,
      53,    54,    54,    54,    55,    55,    55,    55,    55,    55,
      55,    55
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     5,     4,     4,     4,     4,     4,     5,     5,
       4,     4,     4,     4,     7,    11,     5,     7,     4,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     2,     1,     1,     1,     1,
       1,     1
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
  case 2: /* program: statement_list  */
#line 53 "parser.y"
                   {
        ast_root = create_node(NODE_PROGRAM, (yyvsp[0].node), NULL);
    }
#line 1218 "parser.tab.c"
    break;

  case 3: /* statement_list: statement  */
#line 59 "parser.y"
                {
          (yyval.node) = create_node(NODE_STATEMENT_LIST, (yyvsp[0].node), NULL);
      }
#line 1226 "parser.tab.c"
    break;

  case 4: /* statement_list: statement_list statement  */
#line 62 "parser.y"
                               {
          Node *node = (yyvsp[-1].node);
          while (node->next != NULL) {
              node = node->next;
          }
          node->next = create_node(NODE_STATEMENT_LIST, (yyvsp[0].node), NULL);
          (yyval.node) = (yyvsp[-1].node);
      }
#line 1239 "parser.tab.c"
    break;

  case 5: /* statement: variable_declaration  */
#line 73 "parser.y"
                           {
          (yyval.node) = (yyvsp[0].node);
      }
#line 1247 "parser.tab.c"
    break;

  case 6: /* statement: assignment  */
#line 76 "parser.y"
                 {
          (yyval.node) = (yyvsp[0].node);
      }
#line 1255 "parser.tab.c"
    break;

  case 7: /* statement: musical_instruction  */
#line 79 "parser.y"
                          {
          (yyval.node) = (yyvsp[0].node);
      }
#line 1263 "parser.tab.c"
    break;

  case 8: /* statement: conditional  */
#line 82 "parser.y"
                  {
          (yyval.node) = (yyvsp[0].node);
      }
#line 1271 "parser.tab.c"
    break;

  case 9: /* statement: loop  */
#line 85 "parser.y"
           {
          (yyval.node) = (yyvsp[0].node);
      }
#line 1279 "parser.tab.c"
    break;

  case 10: /* statement: function_declaration  */
#line 88 "parser.y"
                           {
          (yyval.node) = (yyvsp[0].node);
      }
#line 1287 "parser.tab.c"
    break;

  case 11: /* statement: function_call  */
#line 91 "parser.y"
                    {
          (yyval.node) = (yyvsp[0].node);
      }
#line 1295 "parser.tab.c"
    break;

  case 12: /* variable_declaration: SET IDENTIFIER ASSIGN expression SEMICOLON  */
#line 97 "parser.y"
                                                 {
          Node *id_node = create_leaf_node(NODE_IDENTIFIER, 0, (yyvsp[-3].str), 0);
          (yyval.node) = create_node(NODE_VARIABLE_DECLARATION, id_node, (yyvsp[-1].node));
      }
#line 1304 "parser.tab.c"
    break;

  case 13: /* variable_declaration: SET IDENTIFIER expression SEMICOLON  */
#line 101 "parser.y"
                                          {
          Node *id_node = create_leaf_node(NODE_IDENTIFIER, 0, (yyvsp[-2].str), 0);
          (yyval.node) = create_node(NODE_VARIABLE_DECLARATION, id_node, (yyvsp[-1].node));
      }
#line 1313 "parser.tab.c"
    break;

  case 14: /* variable_declaration: SET IDENTIFIER STRING SEMICOLON  */
#line 105 "parser.y"
                                      {
          Node *id_node = create_leaf_node(NODE_IDENTIFIER, 0, (yyvsp[-2].str), 0);
          Node *value_node = create_leaf_node(NODE_STRING, 0, (yyvsp[-1].str), 0);
          (yyval.node) = create_node(NODE_VARIABLE_DECLARATION, id_node, value_node);
      }
#line 1323 "parser.tab.c"
    break;

  case 15: /* assignment: IDENTIFIER ASSIGN expression SEMICOLON  */
#line 114 "parser.y"
                                             {
          Node *id_node = create_leaf_node(NODE_IDENTIFIER, 0, (yyvsp[-3].str), 0);
          (yyval.node) = create_node(NODE_ASSIGNMENT, id_node, (yyvsp[-1].node));
      }
#line 1332 "parser.tab.c"
    break;

  case 16: /* musical_instruction: PLAY NOTE DURATION SEMICOLON  */
#line 121 "parser.y"
                                   {
          Node *note_node = create_leaf_node(NODE_NOTE, 0, (yyvsp[-2].str), 0);
          Node *duration_node = create_leaf_node(NODE_DURATION, 0, (yyvsp[-1].str), 0);
          (yyval.node) = create_node(NODE_PLAY_NOTE, note_node, duration_node);
      }
#line 1342 "parser.tab.c"
    break;

  case 17: /* musical_instruction: PLAY CHORD_NAME DURATION SEMICOLON  */
#line 126 "parser.y"
                                         {
          Node *chord_node = create_leaf_node(NODE_CHORD_NAME, 0, (yyvsp[-2].str), 0);
          Node *duration_node = create_leaf_node(NODE_DURATION, 0, (yyvsp[-1].str), 0);
          (yyval.node) = create_node(NODE_PLAY_CHORD, chord_node, duration_node);
      }
#line 1352 "parser.tab.c"
    break;

  case 18: /* musical_instruction: PLAY CHORD CHORD_NAME DURATION SEMICOLON  */
#line 131 "parser.y"
                                               {
          Node *chord_node = create_leaf_node(NODE_CHORD_NAME, 0, (yyvsp[-2].str), 0);
          Node *duration_node = create_leaf_node(NODE_DURATION, 0, (yyvsp[-1].str), 0);
          (yyval.node) = create_node(NODE_PLAY_CHORD, chord_node, duration_node);
      }
#line 1362 "parser.tab.c"
    break;

  case 19: /* musical_instruction: PLAY CHORD NOTE DURATION SEMICOLON  */
#line 136 "parser.y"
                                         {
          Node *note_node = create_leaf_node(NODE_NOTE, 0, (yyvsp[-2].str), 0);
          Node *duration_node = create_leaf_node(NODE_DURATION, 0, (yyvsp[-1].str), 0);
          (yyval.node) = create_node(NODE_PLAY_CHORD, note_node, duration_node);
      }
#line 1372 "parser.tab.c"
    break;

  case 20: /* musical_instruction: PLAY IDENTIFIER IDENTIFIER SEMICOLON  */
#line 141 "parser.y"
                                           {
          Node *note_node = create_leaf_node(NODE_IDENTIFIER, 0, (yyvsp[-2].str), 0);
          Node *duration_node = create_leaf_node(NODE_IDENTIFIER, 0, (yyvsp[-1].str), 0);
          (yyval.node) = create_node(NODE_PLAY_NOTE, note_node, duration_node);
      }
#line 1382 "parser.tab.c"
    break;

  case 21: /* musical_instruction: SET TEMPO expression SEMICOLON  */
#line 146 "parser.y"
                                     {
      // printf("DEBUG: Recebendo valor %d de expression para NODE_SET_TEMPO\n", $3->value.num);
      (yyval.node) = create_node(NODE_SET_TEMPO, (yyvsp[-1].node), NULL);
      // $$->value.num = $3->value.num; // Propagando valor numérico explicitamente
      // printf("DEBUG: Propagando valor %d para NODE_SET_TEMPO\n", $$->value.num);
      }
#line 1393 "parser.tab.c"
    break;

  case 22: /* musical_instruction: SET INSTRUMENT STRING SEMICOLON  */
#line 152 "parser.y"
                                      {
          Node *instrument_node = create_leaf_node(NODE_STRING, 0, (yyvsp[-1].str), 0);
          (yyval.node) = create_node(NODE_SET_INSTRUMENT, instrument_node, NULL);
      }
#line 1402 "parser.tab.c"
    break;

  case 23: /* musical_instruction: SET VOLUME expression SEMICOLON  */
#line 156 "parser.y"
                                      {
          (yyval.node) = create_node(NODE_SET_VOLUME, (yyvsp[-1].node), NULL);
      }
#line 1410 "parser.tab.c"
    break;

  case 24: /* conditional: IF LPAREN condition RPAREN LBRACE statement_list RBRACE  */
#line 162 "parser.y"
                                                              {
          (yyval.node) = create_node(NODE_CONDITIONAL, (yyvsp[-4].node), (yyvsp[-1].node)); // $3 = condição, $6 = bloco if
      }
#line 1418 "parser.tab.c"
    break;

  case 25: /* conditional: IF LPAREN condition RPAREN LBRACE statement_list RBRACE ELSE LBRACE statement_list RBRACE  */
#line 165 "parser.y"
                                                                                                {
          Node *if_node = create_node(NODE_CONDITIONAL, (yyvsp[-8].node), (yyvsp[-5].node)); // $3 = condição, $6 = bloco if
          if_node->next = (yyvsp[-1].node); // Armazene o bloco else no `next`
          (yyval.node) = if_node;
      }
#line 1428 "parser.tab.c"
    break;

  case 26: /* loop: REPEAT NUM LBRACE statement_list RBRACE  */
#line 174 "parser.y"
                                            {
        Node *num_node = create_leaf_node(NODE_NUM, (yyvsp[-3].num), NULL, 0);
        (yyval.node) = create_node(NODE_LOOP, num_node, (yyvsp[-1].node));
    }
#line 1437 "parser.tab.c"
    break;

  case 27: /* function_declaration: FUNCTION IDENTIFIER LPAREN RPAREN LBRACE statement_list RBRACE  */
#line 181 "parser.y"
                                                                     {
          Node *id_node = create_leaf_node(NODE_IDENTIFIER, 0, (yyvsp[-5].str), 0);
          (yyval.node) = create_node(NODE_FUNCTION_DECLARATION, id_node, (yyvsp[-1].node));
      }
#line 1446 "parser.tab.c"
    break;

  case 28: /* function_call: IDENTIFIER LPAREN RPAREN SEMICOLON  */
#line 188 "parser.y"
                                         {
          Node *id_node = create_leaf_node(NODE_IDENTIFIER, 0, (yyvsp[-3].str), 0);
          (yyval.node) = create_node(NODE_FUNCTION_CALL, id_node, NULL);
      }
#line 1455 "parser.tab.c"
    break;

  case 29: /* condition: expression '<' expression  */
#line 195 "parser.y"
                                {
          (yyval.node) = create_node(NODE_CONDITION, (yyvsp[-2].node), (yyvsp[0].node));
          (yyval.node)->value.op = '<';
      }
#line 1464 "parser.tab.c"
    break;

  case 30: /* condition: expression '>' expression  */
#line 199 "parser.y"
                                {
          (yyval.node) = create_node(NODE_CONDITION, (yyvsp[-2].node), (yyvsp[0].node));
          (yyval.node)->value.op = '>';
      }
#line 1473 "parser.tab.c"
    break;

  case 31: /* condition: expression EQ expression  */
#line 203 "parser.y"
                               {
          (yyval.node) = create_node(NODE_CONDITION, (yyvsp[-2].node), (yyvsp[0].node));
          (yyval.node)->value.op = '=';
      }
#line 1482 "parser.tab.c"
    break;

  case 32: /* condition: expression NEQ expression  */
#line 207 "parser.y"
                                {
          (yyval.node) = create_node(NODE_CONDITION, (yyvsp[-2].node), (yyvsp[0].node));
          (yyval.node)->value.op = '!';
      }
#line 1491 "parser.tab.c"
    break;

  case 33: /* condition: condition AND condition  */
#line 211 "parser.y"
                              {
          (yyval.node) = create_node(NODE_CONDITION, (yyvsp[-2].node), (yyvsp[0].node));
          (yyval.node)->value.op = '&';
      }
#line 1500 "parser.tab.c"
    break;

  case 34: /* condition: condition OR condition  */
#line 215 "parser.y"
                             {
          (yyval.node) = create_node(NODE_CONDITION, (yyvsp[-2].node), (yyvsp[0].node));
          (yyval.node)->value.op = '|';
      }
#line 1509 "parser.tab.c"
    break;

  case 35: /* expression: NUM  */
#line 222 "parser.y"
        {
        (yyval.node) = create_leaf_node(NODE_NUM, (yyvsp[0].num), NULL, 0);
    }
#line 1517 "parser.tab.c"
    break;

  case 36: /* expression: expression '+' term  */
#line 225 "parser.y"
                          {
          (yyval.node) = create_node(NODE_EXPRESSION, (yyvsp[-2].node), (yyvsp[0].node));
          (yyval.node)->value.op = '+';
      }
#line 1526 "parser.tab.c"
    break;

  case 37: /* expression: expression '-' term  */
#line 229 "parser.y"
                          {
          (yyval.node) = create_node(NODE_EXPRESSION, (yyvsp[-2].node), (yyvsp[0].node));
          (yyval.node)->value.op = '-';
      }
#line 1535 "parser.tab.c"
    break;

  case 38: /* expression: expression '*' term  */
#line 233 "parser.y"
                          {
          (yyval.node) = create_node(NODE_EXPRESSION, (yyvsp[-2].node), (yyvsp[0].node));
          (yyval.node)->value.op = '*';
      }
#line 1544 "parser.tab.c"
    break;

  case 39: /* expression: expression '/' term  */
#line 237 "parser.y"
                          {
          (yyval.node) = create_node(NODE_EXPRESSION, (yyvsp[-2].node), (yyvsp[0].node));
          (yyval.node)->value.op = '/';
      }
#line 1553 "parser.tab.c"
    break;

  case 40: /* expression: term  */
#line 241 "parser.y"
           {
          (yyval.node) = (yyvsp[0].node);
      }
#line 1561 "parser.tab.c"
    break;

  case 41: /* term: term '*' factor  */
#line 247 "parser.y"
                      {
          (yyval.node) = create_node(NODE_TERM, (yyvsp[-2].node), (yyvsp[0].node));
          (yyval.node)->value.op = '*';
      }
#line 1570 "parser.tab.c"
    break;

  case 42: /* term: term '/' factor  */
#line 251 "parser.y"
                      {
          (yyval.node) = create_node(NODE_TERM, (yyvsp[-2].node), (yyvsp[0].node));
          (yyval.node)->value.op = '/';
      }
#line 1579 "parser.tab.c"
    break;

  case 43: /* term: factor  */
#line 255 "parser.y"
             {
          (yyval.node) = (yyvsp[0].node);
      }
#line 1587 "parser.tab.c"
    break;

  case 44: /* factor: '(' expression ')'  */
#line 261 "parser.y"
                         {
          (yyval.node) = (yyvsp[-1].node);
      }
#line 1595 "parser.tab.c"
    break;

  case 45: /* factor: '-' factor  */
#line 264 "parser.y"
                              {
          (yyval.node) = create_node(NODE_FACTOR, (yyvsp[0].node), NULL);
          (yyval.node)->value.op = '-';
      }
#line 1604 "parser.tab.c"
    break;

  case 46: /* factor: NUM  */
#line 268 "parser.y"
          {
          (yyval.node) = create_leaf_node(NODE_NUM, (yyvsp[0].num), NULL, 0);
      }
#line 1612 "parser.tab.c"
    break;

  case 47: /* factor: IDENTIFIER  */
#line 271 "parser.y"
                 {
          (yyval.node) = create_leaf_node(NODE_IDENTIFIER, 0, (yyvsp[0].str), 0);
      }
#line 1620 "parser.tab.c"
    break;

  case 48: /* factor: TEMPO  */
#line 274 "parser.y"
            {
          (yyval.node) = create_leaf_node(NODE_IDENTIFIER, 0, "tempo", 0);
      }
#line 1628 "parser.tab.c"
    break;

  case 49: /* factor: INSTRUMENT  */
#line 277 "parser.y"
                 {
          (yyval.node) = create_leaf_node(NODE_IDENTIFIER, 0, "instrument", 0);
      }
#line 1636 "parser.tab.c"
    break;

  case 50: /* factor: VOLUME  */
#line 280 "parser.y"
             {
          (yyval.node) = create_leaf_node(NODE_IDENTIFIER, 0, "volume", 0);
      }
#line 1644 "parser.tab.c"
    break;

  case 51: /* factor: NOTE  */
#line 283 "parser.y"
           {
          (yyval.node) = create_leaf_node(NODE_NOTE, 0, (yyvsp[0].str), 0);
      }
#line 1652 "parser.tab.c"
    break;


#line 1656 "parser.tab.c"

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

#line 288 "parser.y"


/* Funções auxiliares */
void yyerror(const char *s) {
    fprintf(stderr, "Erro na linha %d: %s. Token atual: %s\n", yylineno, s, yytext);
}

int main(int argc, char **argv) {
    yydebug = 0; // Desabilitar depuração do Bison
    FILE *file;

    if (argc > 1) {
        file = fopen(argv[1], "r");
        if (!file) {
            perror("Erro ao abrir o arquivo");
            return 1;
        }
        yyin = file;
    } else {
        // Use stdin se nenhum arquivo for fornecido
        yyin = stdin;
    }

    // Inicializar o parser
    if (yyparse() == 0) {
        printf("Parsing completed successfully.\n");

        // Serializar a AST para um arquivo (opcional, em YAML ou JSON)
        serialize_ast_to_file(ast_root, "ast.yaml");
    } else {
        printf("Parsing failed.\n");
    }

    if (argc > 1) fclose(file);
    return 0;
}

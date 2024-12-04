%{
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
%}

%union {
    int num;        /* Para valores numéricos */
    char *str;      /* Para strings, notas e nomes de acordes */
    char op;        /* Para operadores */
    struct Node *node; /* Para nós da AST */
}

/* Associando tokens ao tipo correto */
%token <num> NUM
%token <str> STRING NOTE CHORD_NAME IDENTIFIER DURATION
%token <op> OPERATOR
%token SET PLAY REPEAT IF ELSE FUNCTION RETURN TEMPO INSTRUMENT VOLUME CHORD
%token ASSIGN SEMICOLON COMMA LBRACE RBRACE LPAREN RPAREN
%token EQ NEQ AND OR

%type <node> program statement_list statement variable_declaration assignment musical_instruction conditional loop function_declaration function_call expression term factor condition

%start program

%left OR
%left AND
%nonassoc '>' '<' EQ NEQ
%left '+' '-'
%left '*' '/'
%left UMINUS

%%

/* Regras de produção */
program:
    statement_list {
        ast_root = create_node(NODE_PROGRAM, $1, NULL);
    }
    ;

statement_list:
      statement {
          $$ = create_node(NODE_STATEMENT_LIST, $1, NULL);
      }
    | statement_list statement {
          Node *node = $1;
          while (node->next != NULL) {
              node = node->next;
          }
          node->next = create_node(NODE_STATEMENT_LIST, $2, NULL);
          $$ = $1;
      }
    ;

statement:
      variable_declaration {
          $$ = $1;
      }
    | assignment {
          $$ = $1;
      }
    | musical_instruction {
          $$ = $1;
      }
    | conditional {
          $$ = $1;
      }
    | loop {
          $$ = $1;
      }
    | function_declaration {
          $$ = $1;
      }
    | function_call {
          $$ = $1;
      }
    ;

variable_declaration:
      SET IDENTIFIER ASSIGN expression SEMICOLON {
          Node *id_node = create_leaf_node(NODE_IDENTIFIER, 0, $2, 0);
          $$ = create_node(NODE_VARIABLE_DECLARATION, id_node, $4);
      }
    | SET IDENTIFIER expression SEMICOLON {
          Node *id_node = create_leaf_node(NODE_IDENTIFIER, 0, $2, 0);
          $$ = create_node(NODE_VARIABLE_DECLARATION, id_node, $3);
      }
    | SET IDENTIFIER STRING SEMICOLON {
          Node *id_node = create_leaf_node(NODE_IDENTIFIER, 0, $2, 0);
          Node *value_node = create_leaf_node(NODE_STRING, 0, $3, 0);
          $$ = create_node(NODE_VARIABLE_DECLARATION, id_node, value_node);
      }
    ;


assignment:
      IDENTIFIER ASSIGN expression SEMICOLON {
          Node *id_node = create_leaf_node(NODE_IDENTIFIER, 0, $1, 0);
          $$ = create_node(NODE_ASSIGNMENT, id_node, $3);
      }
    ;

musical_instruction:
      PLAY NOTE DURATION SEMICOLON {
          Node *note_node = create_leaf_node(NODE_NOTE, 0, $2, 0);
          Node *duration_node = create_leaf_node(NODE_DURATION, 0, $3, 0);
          $$ = create_node(NODE_PLAY_NOTE, note_node, duration_node);
      }
    | PLAY CHORD_NAME DURATION SEMICOLON {
          Node *chord_node = create_leaf_node(NODE_CHORD_NAME, 0, $2, 0);
          Node *duration_node = create_leaf_node(NODE_DURATION, 0, $3, 0);
          $$ = create_node(NODE_PLAY_CHORD, chord_node, duration_node);
      }
    | PLAY CHORD CHORD_NAME DURATION SEMICOLON {
          Node *chord_node = create_leaf_node(NODE_CHORD_NAME, 0, $3, 0);
          Node *duration_node = create_leaf_node(NODE_DURATION, 0, $4, 0);
          $$ = create_node(NODE_PLAY_CHORD, chord_node, duration_node);
      }
    | PLAY CHORD NOTE DURATION SEMICOLON {
          Node *note_node = create_leaf_node(NODE_NOTE, 0, $3, 0);
          Node *duration_node = create_leaf_node(NODE_DURATION, 0, $4, 0);
          $$ = create_node(NODE_PLAY_CHORD, note_node, duration_node);
      }
    | PLAY IDENTIFIER IDENTIFIER SEMICOLON {
          Node *note_node = create_leaf_node(NODE_IDENTIFIER, 0, $2, 0);
          Node *duration_node = create_leaf_node(NODE_IDENTIFIER, 0, $3, 0);
          $$ = create_node(NODE_PLAY_NOTE, note_node, duration_node);
      }
    | SET TEMPO expression SEMICOLON {
      // printf("DEBUG: Recebendo valor %d de expression para NODE_SET_TEMPO\n", $3->value.num);
      $$ = create_node(NODE_SET_TEMPO, $3, NULL);
      // $$->value.num = $3->value.num; // Propagando valor numérico explicitamente
      // printf("DEBUG: Propagando valor %d para NODE_SET_TEMPO\n", $$->value.num);
      }
    | SET INSTRUMENT STRING SEMICOLON {
          Node *instrument_node = create_leaf_node(NODE_STRING, 0, $3, 0);
          $$ = create_node(NODE_SET_INSTRUMENT, instrument_node, NULL);
      }
    | SET VOLUME expression SEMICOLON {
          $$ = create_node(NODE_SET_VOLUME, $3, NULL);
      }
    ;

conditional:
      IF LPAREN condition RPAREN LBRACE statement_list RBRACE {
          $$ = create_node(NODE_CONDITIONAL, $3, $6); // $3 = condição, $6 = bloco if
      }
    | IF LPAREN condition RPAREN LBRACE statement_list RBRACE ELSE LBRACE statement_list RBRACE {
          Node *if_node = create_node(NODE_CONDITIONAL, $3, $6); // $3 = condição, $6 = bloco if
          if_node->next = $10; // Armazene o bloco else no `next`
          $$ = if_node;
      }
    ;


loop:
    REPEAT NUM LBRACE statement_list RBRACE {
        Node *num_node = create_leaf_node(NODE_NUM, $2, NULL, 0);
        $$ = create_node(NODE_LOOP, num_node, $4);
    }
    ;

function_declaration:
      FUNCTION IDENTIFIER LPAREN RPAREN LBRACE statement_list RBRACE {
          Node *id_node = create_leaf_node(NODE_IDENTIFIER, 0, $2, 0);
          $$ = create_node(NODE_FUNCTION_DECLARATION, id_node, $6);
      }
    ;

function_call:
      IDENTIFIER LPAREN RPAREN SEMICOLON {
          Node *id_node = create_leaf_node(NODE_IDENTIFIER, 0, $1, 0);
          $$ = create_node(NODE_FUNCTION_CALL, id_node, NULL);
      }
    ;

condition:
      expression '<' expression {
          $$ = create_node(NODE_CONDITION, $1, $3);
          $$->value.op = '<';
      }
    | expression '>' expression {
          $$ = create_node(NODE_CONDITION, $1, $3);
          $$->value.op = '>';
      }
    | expression EQ expression {
          $$ = create_node(NODE_CONDITION, $1, $3);
          $$->value.op = '=';
      }
    | expression NEQ expression {
          $$ = create_node(NODE_CONDITION, $1, $3);
          $$->value.op = '!';
      }
    | condition AND condition {
          $$ = create_node(NODE_CONDITION, $1, $3);
          $$->value.op = '&';
      }
    | condition OR condition {
          $$ = create_node(NODE_CONDITION, $1, $3);
          $$->value.op = '|';
      }
    ;

expression:
    NUM {
        $$ = create_leaf_node(NODE_NUM, $1, NULL, 0);
    }
    | expression '+' term {
          $$ = create_node(NODE_EXPRESSION, $1, $3);
          $$->value.op = '+';
      }
    | expression '-' term {
          $$ = create_node(NODE_EXPRESSION, $1, $3);
          $$->value.op = '-';
      }
    | expression '*' term {
          $$ = create_node(NODE_EXPRESSION, $1, $3);
          $$->value.op = '*';
      }
    | expression '/' term {
          $$ = create_node(NODE_EXPRESSION, $1, $3);
          $$->value.op = '/';
      }
    | term {
          $$ = $1;
      }
    ;

term:
      term '*' factor {
          $$ = create_node(NODE_TERM, $1, $3);
          $$->value.op = '*';
      }
    | term '/' factor {
          $$ = create_node(NODE_TERM, $1, $3);
          $$->value.op = '/';
      }
    | factor {
          $$ = $1;
      }
    ;

factor:
      '(' expression ')' {
          $$ = $2;
      }
    | '-' factor %prec UMINUS {
          $$ = create_node(NODE_FACTOR, $2, NULL);
          $$->value.op = '-';
      }
    | NUM {
          $$ = create_leaf_node(NODE_NUM, $1, NULL, 0);
      }
    | IDENTIFIER {
          $$ = create_leaf_node(NODE_IDENTIFIER, 0, $1, 0);
      }
    | TEMPO {
          $$ = create_leaf_node(NODE_IDENTIFIER, 0, "tempo", 0);
      }
    | INSTRUMENT {
          $$ = create_leaf_node(NODE_IDENTIFIER, 0, "instrument", 0);
      }
    | VOLUME {
          $$ = create_leaf_node(NODE_IDENTIFIER, 0, "volume", 0);
      }
    | NOTE {
          $$ = create_leaf_node(NODE_NOTE, 0, $1, 0);
      }
    ;

%%

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
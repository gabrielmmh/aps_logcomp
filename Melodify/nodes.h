#ifndef NODES_H
#define NODES_H

typedef enum
{
    NODE_PROGRAM,
    NODE_STATEMENT_LIST,
    NODE_STATEMENT,
    NODE_VARIABLE_DECLARATION,
    NODE_ASSIGNMENT,
    NODE_MUSICAL_INSTRUCTION,
    NODE_CONDITIONAL,
    NODE_LOOP,
    NODE_FUNCTION_DECLARATION,
    NODE_FUNCTION_CALL,
    NODE_RETURN,
    NODE_EXPRESSION,
    NODE_TERM,
    NODE_FACTOR,
    NODE_PARAMETER_LIST,
    NODE_ARGUMENT_LIST,
    NODE_CONDITION,
    NODE_IDENTIFIER,
    NODE_NUM,
    NODE_STRING,
    NODE_NOTE,
    NODE_CHORD_NAME,
    NODE_DURATION,
    NODE_OPERATOR,
    NODE_SET_TEMPO,
    NODE_SET_INSTRUMENT,
    NODE_SET_VOLUME,
    NODE_PLAY_NOTE,
    NODE_PLAY_CHORD,
    // Adicione outros tipos conforme necessário
} NodeType;

typedef struct Node
{
    NodeType type;
    struct Node *left;
    struct Node *right;
    struct Node *next; // Para listas
    union
    {
        int num;
        char *str;
        char op;
    } value;
} Node;

// Funções para criar nós
Node *create_node(NodeType type, Node *left, Node *right);
Node *create_leaf_node(NodeType type, int num, char *str, char op);

#endif
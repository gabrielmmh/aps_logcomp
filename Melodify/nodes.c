#include "nodes.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Node *create_node(NodeType type, Node *left, Node *right)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (!node)
    {
        perror("Erro ao alocar memória para Node");
        exit(EXIT_FAILURE);
    }
    node->type = type;
    node->left = left;
    node->right = right;
    node->next = NULL;

    // Depuração
    if (left && left->type == NODE_NUM) {
        // printf("DEBUG: Propagando valor %d para %d\n", left->value.num, type);
        node->value.num = left->value.num;
    }
    
    return node;
}

Node *create_leaf_node(NodeType type, int num, char *str, char op)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (!node)
    {
        perror("Erro ao alocar memória para Node");
        exit(EXIT_FAILURE);
    }
    node->type = type;
    node->left = NULL;
    node->right = NULL;
    node->next = NULL;

    // Inicialize apenas o campo relevante com base no tipo do nó
    if (type == NODE_NUM) {
        node->value.num = num; // Atribua apenas o número
        node->value.str = NULL; // Evite conflitos
    } else if (str != NULL) {
        node->value.str = strdup(str); // Atribua a string se relevante
    } else {
        node->value.str = NULL;
    }

    node->value.op = op;

    return node;
}

Node *create_leaf(NodeType type, const char *str_value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->type = type;
    node->left = NULL;
    node->right = NULL;
    node->next = NULL;
    if (str_value != NULL)
    {
        node->value.str = strdup(str_value);
    }
    else
    {
        node->value.str = NULL;
    }
    return node;
}

void serialize_ast_node(Node *node, FILE *file, int depth) {
    if (!node) return;

    // Indentação baseada na profundidade
    for (int i = 0; i < depth; i++) fprintf(file, "  ");

    fprintf(file, "type: %d\n", node->type);

    if (node->type == NODE_NUM) {
        for (int i = 0; i < depth; i++) fprintf(file, "  ");
        fprintf(file, "value: %d\n", node->value.num);
    } else if (node->type == NODE_CONDITION || node->type == NODE_EXPRESSION) {
        for (int i = 0; i < depth; i++) fprintf(file, "  ");
        fprintf(file, "operator: '%c'\n", node->value.op); // Adiciona o operador
    } else if (node->value.str) {
        for (int i = 0; i < depth; i++) fprintf(file, "  ");
        fprintf(file, "value: %s\n", node->value.str);
    }

    if (node->left) {
        for (int i = 0; i < depth; i++) fprintf(file, "  ");
        fprintf(file, "left:\n");
        serialize_ast_node(node->left, file, depth + 1);
    }

    if (node->type == NODE_CONDITIONAL) {
        if (node->right) { // Bloco if
            for (int i = 0; i < depth; i++) fprintf(file, "  ");
            fprintf(file, "if_block:\n");
            serialize_ast_node(node->right, file, depth + 1);
        }
        if (node->next) { // Bloco else
            for (int i = 0; i < depth; i++) fprintf(file, "  ");
            fprintf(file, "else_block:\n");
            serialize_ast_node(node->next, file, depth + 1);
        }
    } else if (node->right) {
        for (int i = 0; i < depth; i++) fprintf(file, "  ");
        fprintf(file, "right:\n");
        serialize_ast_node(node->right, file, depth + 1);
    }

    if (node->next && node->type != NODE_CONDITIONAL) {
        for (int i = 0; i < depth; i++) fprintf(file, "  ");
        fprintf(file, "next:\n");
        serialize_ast_node(node->next, file, depth + 1);
    }
}

void serialize_ast_to_file(Node *root, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Erro ao abrir o arquivo para salvar a AST");
        exit(1);
    }

    serialize_ast_node(root, file, 0); // Iniciar com profundidade 0

    fclose(file);
}

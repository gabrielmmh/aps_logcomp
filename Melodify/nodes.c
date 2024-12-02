#include "nodes.h"
#include <stdlib.h>
#include <string.h>

Node *create_node(NodeType type, Node *left, Node *right)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->type = type;
    node->left = left;
    node->right = right;
    node->next = NULL;
    return node;
}

Node *create_leaf_node(NodeType type, int num, char *str, char op)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->type = type;
    node->left = NULL;
    node->right = NULL;
    node->next = NULL;
    if (str != NULL)
    {
        node->value.str = strdup(str);
    }
    else
    {
        node->value.str = NULL;
    }
    node->value.num = num;
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

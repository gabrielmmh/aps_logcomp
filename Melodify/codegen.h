#ifndef CODEGEN_H
#define CODEGEN_H

#include "nodes.h"

// Declarações das funções do codegen
void init_codegen();
void codegen(Node *node);
void finalize_codegen();

#endif // CODEGEN_H

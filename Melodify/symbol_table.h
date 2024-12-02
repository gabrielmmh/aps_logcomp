#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdlib.h>
#include <string.h>

typedef struct Symbol
{
    char *name;
    int value;
    struct Symbol *next;
} Symbol;

typedef struct SymbolTable
{
    Symbol *head;
} SymbolTable;

void symbol_table_init(SymbolTable *table)
{
    table->head = NULL;
}

void symbol_table_insert(SymbolTable *table, char *name, int value)
{
    Symbol *new_symbol = (Symbol *)malloc(sizeof(Symbol));
    new_symbol->name = strdup(name);
    new_symbol->value = value;
    new_symbol->next = table->head;
    table->head = new_symbol;
}

int symbol_table_lookup(SymbolTable *table, char *name)
{
    Symbol *current = table->head;
    while (current)
    {
        if (strcmp(current->name, name) == 0)
        {
            return current->value;
        }
        current = current->next;
    }
    return 0; // Retorna 0 se não encontrado (ou você pode lançar um erro)
}

#endif

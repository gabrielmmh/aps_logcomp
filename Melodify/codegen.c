// codegen.c
#include "codegen.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <llvm-c/Core.h>
#include <llvm-c/Analysis.h>
#include <llvm-c/ExecutionEngine.h>
#include <llvm-c/Target.h>
#include <llvm-c/TargetMachine.h>
#include <llvm-c/BitWriter.h>

// Declarações de tipos e variáveis globais
LLVMModuleRef module;
LLVMBuilderRef builder;
LLVMExecutionEngineRef engine;
LLVMValueRef main_function;
LLVMValueRef current_function;
LLVMTypeRef int_type;
LLVMTypeRef void_type;
LLVMTypeRef str_type;

// Funções externas para manipulação de MIDI
LLVMValueRef func_play_note;
LLVMValueRef func_set_tempo;
LLVMValueRef func_set_instrument;

// Declaração antecipada da função codegen_expression
LLVMValueRef codegen_expression(Node *node);

void init_codegen()
{
    // Inicializar componentes do LLVM
    LLVMInitializeNativeTarget();
    LLVMInitializeNativeAsmPrinter();
    LLVMInitializeNativeAsmParser();

    module = LLVMModuleCreateWithName("melodify_module");
    builder = LLVMCreateBuilder();

    char *error = NULL;
    if (LLVMCreateExecutionEngineForModule(&engine, module, &error) != 0)
    {
        fprintf(stderr, "Failed to create execution engine: %s\n", error);
        LLVMDisposeMessage(error);
        exit(1);
    }

    int_type = LLVMInt32Type();
    void_type = LLVMVoidType();
    str_type = LLVMPointerType(LLVMInt8Type(), 0);

    // Declarar funções externas
    // Função: void play_note_midi(const char *note, const char *duration)
    LLVMTypeRef play_note_params[] = {str_type, str_type};
    LLVMTypeRef play_note_type = LLVMFunctionType(void_type, play_note_params, 2, 0);
    func_play_note = LLVMAddFunction(module, "play_note_midi", play_note_type);

    // Função: void set_tempo_midi(int tempo)
    LLVMTypeRef set_tempo_params[] = {int_type};
    LLVMTypeRef set_tempo_type = LLVMFunctionType(void_type, set_tempo_params, 1, 0);
    func_set_tempo = LLVMAddFunction(module, "set_tempo_midi", set_tempo_type);

    // Função: void set_instrument_midi(const char *instrument)
    LLVMTypeRef set_instrument_params[] = {str_type};
    LLVMTypeRef set_instrument_type = LLVMFunctionType(void_type, set_instrument_params, 1, 0);
    func_set_instrument = LLVMAddFunction(module, "set_instrument_midi", set_instrument_type);
}

void codegen_program(Node *node)
{
    // Criar a função main
    LLVMTypeRef main_type = LLVMFunctionType(int_type, NULL, 0, 0);
    main_function = LLVMAddFunction(module, "main", main_type);
    LLVMBasicBlockRef entry = LLVMAppendBasicBlock(main_function, "entry");
    LLVMPositionBuilderAtEnd(builder, entry);

    current_function = main_function;

    codegen(node->left);

    // Retornar 0
    LLVMBuildRet(builder, LLVMConstInt(int_type, 0, 0));
}

void codegen_statement_list(Node *node)
{
    while (node != NULL)
    {
        codegen(node->left);
        node = node->next;
    }
}

void codegen_variable_declaration(Node *node)
{
    // Implementação futura (se necessário)
}

void codegen_assignment(Node *node)
{
    // Implementação futura (se necessário)
}

void codegen_musical_instruction(Node *node)
{
    switch (node->type)
    {
    case NODE_PLAY_NOTE:
    {
        Node *note_node = node->left;
        Node *duration_node = node->right;

        // Verificar se note_node e duration_node não são nulos
        if (note_node == NULL)
        {
            fprintf(stderr, "Error: note_node is NULL in NODE_PLAY_NOTE\n");
            exit(1);
        }
        if (note_node->value.str == NULL)
        {
            fprintf(stderr, "Error: note_node->value.str is NULL in NODE_PLAY_NOTE\n");
            exit(1);
        }
        if (duration_node == NULL)
        {
            fprintf(stderr, "Error: duration_node is NULL in NODE_PLAY_NOTE\n");
            exit(1);
        }
        if (duration_node->value.str == NULL)
        {
            fprintf(stderr, "Error: duration_node->value.str is NULL in NODE_PLAY_NOTE\n");
            exit(1);
        }

        printf("Debug: node->left->value.str = '%s'\n", node->left->value.str);

        LLVMValueRef note_value = LLVMBuildGlobalStringPtr(builder, note_node->value.str, "note");
        LLVMValueRef duration_value = LLVMBuildGlobalStringPtr(builder, duration_node->value.str, "duration");

        LLVMValueRef args[] = {note_value, duration_value};

        LLVMTypeRef func_play_note_type = LLVMTypeOf(func_play_note);

        LLVMBuildCall2(builder, func_play_note_type, func_play_note, args, 2, "");
        break;
    }
    case NODE_SET_TEMPO:
    {
        if (node->left == NULL)
        {
            fprintf(stderr, "Error: node->left is NULL in NODE_SET_TEMPO\n");
            exit(1);
        }

        if (node->left->type != NODE_NUM)
        {
            fprintf(stderr, "Error: node->left is not a number in NODE_SET_TEMPO\n");
            exit(1);
        }

        if (node->left->value.num < 0)
        {
            fprintf(stderr, "Error: tempo value is negative in NODE_SET_TEMPO\n");
            exit(1);
        }

        LLVMValueRef tempo_value = codegen_expression(node->left);
        LLVMValueRef args[] = {tempo_value};

        LLVMTypeRef func_set_tempo_type = LLVMTypeOf(func_set_tempo);

        // Chamar a função usando LLVMBuildCall2
        LLVMBuildCall2(builder, func_set_tempo_type, func_set_tempo, args, 1, "");
        break;
    }
    case NODE_SET_INSTRUMENT:
    {
        // Verificar se node->left não é nulo
        if (node->left == NULL)
        {
            fprintf(stderr, "Error: node->left is NULL in NODE_SET_INSTRUMENT\n");
            exit(1);
        }

        // Verificar se node->left->value.str não é nulo
        if (node->left->value.str == NULL)
        {
            fprintf(stderr, "Error: node->left->value.str is NULL in NODE_SET_INSTRUMENT\n");
            exit(1);
        }
        
        printf("Debug: node->left->value.str = '%s'\n", node->left->value.str);

        LLVMValueRef instrument_value = LLVMBuildGlobalStringPtr(builder, node->left->value.str, "instrument");
        LLVMValueRef args[] = {instrument_value};

        LLVMTypeRef func_set_instrument_type = LLVMTypeOf(func_set_instrument);

        // Chamar a função usando LLVMBuildCall2
        LLVMBuildCall2(builder, func_set_instrument_type, func_set_instrument, args, 1, "");
        break;
    }
    case NODE_SET_VOLUME:
    {
        if (node->left == NULL)
        {
            fprintf(stderr, "Error: node->left is NULL in NODE_SET_VOLUME\n");
            exit(1);
        }

        if (node->left->type != NODE_NUM)
        {
            fprintf(stderr, "Error: node->left is not a number in NODE_SET_VOLUME\n");
            exit(1);
        }

        if (node->left->value.num < 0)
        {
            fprintf(stderr, "Error: volume value is negative in NODE_SET_VOLUME\n");
            exit(1);
        }
        LLVMValueRef volume_value = codegen_expression(node->left);
        LLVMValueRef args[] = {volume_value};

        // Supondo que você tenha uma função externa 'set_volume_midi(int volume)'
        LLVMTypeRef set_volume_type = LLVMFunctionType(void_type, &int_type, 1, 0);
        LLVMValueRef func_set_volume = LLVMAddFunction(module, "set_volume_midi", set_volume_type);

        LLVMBuildCall2(builder, set_volume_type, func_set_volume, args, 1, "");
        break;
    }
    default:
        fprintf(stderr, "Unknown musical instruction node type: %d\n", node->type);
        exit(1);
    }
}

void codegen_play_chord(Node *node)
{
    Node *chord_node = node->left;
    Node *duration_node = node->right;

    LLVMValueRef chord_value = LLVMBuildGlobalStringPtr(builder, chord_node->value.str, "chord");
    LLVMValueRef duration_value = LLVMBuildGlobalStringPtr(builder, duration_node->value.str, "duration");

    LLVMValueRef args[] = {chord_value, duration_value};

    // Declarar ou obter a função externa para tocar acordes
    // Supondo que seja: void play_chord_midi(const char *chord, const char *duration)
    LLVMTypeRef play_chord_params[] = {str_type, str_type};
    LLVMTypeRef play_chord_type = LLVMFunctionType(void_type, play_chord_params, 2, 0);

    LLVMValueRef func_play_chord = LLVMGetNamedFunction(module, "play_chord_midi");
    if (!func_play_chord)
    {
        func_play_chord = LLVMAddFunction(module, "play_chord_midi", play_chord_type);
    }

    // Chamar a função usando LLVMBuildCall2
    LLVMBuildCall2(builder, play_chord_type, func_play_chord, args, 2, "");
}

LLVMValueRef codegen_expression(Node *node)
{
    if (node == NULL)
    {
        fprintf(stderr, "Error: node is NULL in codegen_expression\n");
        exit(1);
    }

    switch (node->type)
    {
    case NODE_EXPRESSION:
    case NODE_TERM:
    {
        LLVMValueRef left = codegen_expression(node->left);
        LLVMValueRef right = codegen_expression(node->right);
        switch (node->value.op)
        {
        case '+':
            return LLVMBuildAdd(builder, left, right, "addtmp");
        case '-':
            return LLVMBuildSub(builder, left, right, "subtmp");
        case '*':
            return LLVMBuildMul(builder, left, right, "multmp");
        case '/':
            return LLVMBuildSDiv(builder, left, right, "divtmp");
        default:
            fprintf(stderr, "Unknown operator in expression: %c\n", node->value.op);
            exit(1);
        }
    }
    case NODE_FACTOR:
    {
        if (node->value.op == '-')
        {
            LLVMValueRef val = codegen_expression(node->left);
            return LLVMBuildNeg(builder, val, "negtmp");
        }
        else
        {
            return codegen_expression(node->left);
        }
    }
    case NODE_NUM:
        return LLVMConstInt(int_type, node->value.num, 0);
    case NODE_IDENTIFIER:
        // Implementar busca de variável (se necessário)
        fprintf(stderr, "Variable lookup not implemented for %s\n", node->value.str);
        return LLVMConstInt(int_type, 0, 0);
    default:
        fprintf(stderr, "Unknown node type in expression: %d\n", node->type);
        exit(1);
    }
}

void codegen_condition(Node *node, LLVMBasicBlockRef true_block, LLVMBasicBlockRef false_block)
{
    LLVMValueRef cond = NULL;
    LLVMValueRef left = codegen_expression(node->left);
    LLVMValueRef right = codegen_expression(node->right);

    switch (node->value.op)
    {
    case '<':
        cond = LLVMBuildICmp(builder, LLVMIntSLT, left, right, "cmptmp");
        break;
    case '>':
        cond = LLVMBuildICmp(builder, LLVMIntSGT, left, right, "cmptmp");
        break;
    case '=':
        cond = LLVMBuildICmp(builder, LLVMIntEQ, left, right, "cmptmp");
        break;
    case '!':
        cond = LLVMBuildICmp(builder, LLVMIntNE, left, right, "cmptmp");
        break;
    default:
        fprintf(stderr, "Unknown operator in condition: %c\n", node->value.op);
        exit(1);
    }

    LLVMBuildCondBr(builder, cond, true_block, false_block);
}

void codegen_conditional(Node *node)
{
    LLVMBasicBlockRef true_block = LLVMAppendBasicBlock(current_function, "iftrue");
    LLVMBasicBlockRef false_block = LLVMAppendBasicBlock(current_function, "iffalse");
    LLVMBasicBlockRef merge_block = LLVMAppendBasicBlock(current_function, "ifend");

    codegen_condition(node->left, true_block, false_block);

    // Bloco verdadeiro
    LLVMPositionBuilderAtEnd(builder, true_block);
    codegen(node->right); // Instruções do 'if'
    LLVMBuildBr(builder, merge_block);

    // Bloco falso (se existir)
    LLVMPositionBuilderAtEnd(builder, false_block);
    if (node->next != NULL)
    {
        codegen(node->next); // Instruções do 'else'
    }
    LLVMBuildBr(builder, merge_block);

    // Bloco de merge
    LLVMPositionBuilderAtEnd(builder, merge_block);
}

void codegen_loop(Node *node)
{
    LLVMBasicBlockRef loop_block = LLVMAppendBasicBlock(current_function, "loop");
    LLVMBasicBlockRef after_loop_block = LLVMAppendBasicBlock(current_function, "afterloop");

    // Inicialização do contador
    LLVMValueRef counter = LLVMBuildAlloca(builder, int_type, "counter");
    LLVMBuildStore(builder, LLVMConstInt(int_type, 0, 0), counter);

    // Pular para o bloco do loop
    LLVMBuildBr(builder, loop_block);

    // Bloco do loop
    LLVMPositionBuilderAtEnd(builder, loop_block);

    // Carregar o valor do contador usando LLVMBuildLoad2
    LLVMValueRef counter_val = LLVMBuildLoad2(builder, int_type, counter, "counter_val");

    LLVMValueRef limit = LLVMConstInt(int_type, node->left->value.num, 0);
    LLVMValueRef cond = LLVMBuildICmp(builder, LLVMIntSLT, counter_val, limit, "loopcond");

    LLVMBasicBlockRef body_block = LLVMAppendBasicBlock(current_function, "loopbody");
    LLVMBuildCondBr(builder, cond, body_block, after_loop_block);

    // Bloco do corpo do loop
    LLVMPositionBuilderAtEnd(builder, body_block);
    codegen(node->right); // Corpo do loop

    // Incrementar contador
    LLVMValueRef one = LLVMConstInt(int_type, 1, 0);
    LLVMValueRef new_counter_val = LLVMBuildAdd(builder, counter_val, one, "counter_inc");
    LLVMBuildStore(builder, new_counter_val, counter);

    // Voltar ao início do loop
    LLVMBuildBr(builder, loop_block);

    // Bloco após o loop
    LLVMPositionBuilderAtEnd(builder, after_loop_block);
}

void codegen_function_definition(Node *node)
{
    char *function_name = node->value.str;
    Node *function_body = node->left;

    // Criar o tipo da função (sem parâmetros, retornando void)
    LLVMTypeRef func_type = LLVMFunctionType(void_type, NULL, 0, 0);
    LLVMValueRef function = LLVMAddFunction(module, function_name, func_type);

    // Criar o bloco básico de entrada
    LLVMBasicBlockRef entry = LLVMAppendBasicBlock(function, "entry");
    LLVMPositionBuilderAtEnd(builder, entry);

    // Salvar a função atual
    LLVMValueRef prev_function = current_function;
    current_function = function;

    // Gerar o código do corpo da função
    codegen(function_body);

    // Finalizar a função com um retorno void
    LLVMBuildRetVoid(builder);

    // Restaurar a função atual
    current_function = prev_function;
}

void codegen_function_call(Node *node)
{
    char *function_name = node->value.str;

    // Obter a função do módulo
    LLVMValueRef function = LLVMGetNamedFunction(module, function_name);
    if (function == NULL)
    {
        fprintf(stderr, "Undefined function: %s\n", function_name);
        exit(1);
    }

    // Sem argumentos neste exemplo
    LLVMValueRef *args = NULL;
    unsigned arg_count = 0;

    LLVMTypeRef func_type = LLVMTypeOf(function);

    // Chamar a função
    LLVMBuildCall2(builder, func_type, function, args, arg_count, "");
}

void codegen(Node *node)
{
    if (node == NULL)
        return;

    printf("Generating code for node type: %d\n", node->type);

    switch (node->type)
    {
    case NODE_PROGRAM:
        codegen_program(node);
        break;
    case NODE_STATEMENT_LIST:
        codegen_statement_list(node);
        break;
    case NODE_VARIABLE_DECLARATION:
        codegen_variable_declaration(node);
        break;
    case NODE_ASSIGNMENT:
        codegen_assignment(node);
        break;
    case NODE_PLAY_NOTE:
    case NODE_SET_TEMPO:
    case NODE_SET_INSTRUMENT:
    case NODE_SET_VOLUME:
        codegen_musical_instruction(node);
        break;
    case NODE_CONDITIONAL:
        codegen_conditional(node);
        break;
    case NODE_LOOP:
        codegen_loop(node);
        break;
    case NODE_FUNCTION_DECLARATION:
        codegen_function_definition(node);
        break;
    case NODE_FUNCTION_CALL:
        codegen_function_call(node);
        break;
    case NODE_PLAY_CHORD:
        codegen_play_chord(node);
        break;
    default:
        fprintf(stderr, "Unknown node type in codegen: %d\n", node->type);
        exit(1);
    }
}

void finalize_codegen()
{
    // Verificar o módulo
    char *error = NULL;
    if (LLVMVerifyModule(module, LLVMAbortProcessAction, &error) != 0)
    {
        fprintf(stderr, "Error verifying module: %s\n", error);
        LLVMDisposeMessage(error);
        exit(1);
    }

    // Dump do módulo LLVM (para depuração)
    LLVMDumpModule(module);

    // Escrever o bitcode para um arquivo
    if (LLVMWriteBitcodeToFile(module, "output.bc") != 0)
    {
        fprintf(stderr, "Error writing bitcode to file\n");
        exit(1);
    }

    // Liberar recursos
    LLVMDisposeBuilder(builder);
    LLVMDisposeExecutionEngine(engine);
}

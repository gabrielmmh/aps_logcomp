# **Resumo Detalhado do Projeto e Orientações para Continuação**

## **Introdução**

Olá,

Este resumo detalhado tem o objetivo de fornecer todas as informações necessárias para que você possa dar continuidade ao projeto **Melodify**. Entenda que você está iniciando agora e não teve contato prévio com o trabalho. Portanto, incluiremos todos os detalhes, desde a configuração do ambiente de desenvolvimento até a descrição dos problemas atuais e as etapas realizadas até o momento.

## **Descrição do Projeto**

- **Nome do Projeto**: Melodify
- **Objetivo**: Desenvolver um compilador que converte uma linguagem de script musical personalizada em código LLVM, permitindo a geração de música programaticamente.

## **Configuração do Ambiente de Desenvolvimento**

Para trabalhar no projeto Melodify, você precisará configurar o ambiente de desenvolvimento com as seguintes ferramentas:

### **1. Sistema Operacional**

- **Recomendado**: Ubuntu 20.04 LTS ou superior (ou qualquer distribuição Linux compatível).

### **2. Dependências Necessárias**

- **GNU Compiler Collection (GCC)**: Para compilar o código C.
- **GNU Make**: Para automatizar o processo de compilação.
- **Flex**: Para gerar o analisador léxico.
- **Bison**: Para gerar o analisador sintático.
- **LLVM**: Biblioteca para geração de código LLVM.
  - **Versão Recomendada**: LLVM 14 (ou compatível).

### **3. Passos de Instalação**

#### **Atualizar o Sistema**

```bash
sudo apt update
sudo apt upgrade
```

#### **Instalar o GCC e Make**

```bash
sudo apt install build-essential
```

#### **Instalar o Flex e Bison**

```bash
sudo apt install flex bison
```

#### **Instalar o LLVM**

```bash
sudo apt install llvm
sudo apt install llvm-dev
sudo apt install llvm-14
sudo apt install llvm-14-dev
```

**Nota**: Certifique-se de que a versão instalada do LLVM é compatível com o projeto (LLVM 14).

#### **Verificar as Instalações**

- **GCC**:

  ```bash
  gcc --version
  ```

- **Make**:

  ```bash
  make --version
  ```

- **Flex**:

  ```bash
  flex --version
  ```

- **Bison**:

  ```bash
  bison --version
  ```

- **LLVM**:

  ```bash
  llvm-config --version
  ```

### **4. Clonar o Repositório do Projeto**

Se o projeto estiver em um repositório Git, clone-o:

```bash
git clone <URL_DO_REPOSITORIO>
```

### **5. Estrutura do Projeto**

- **src/**: Código-fonte do projeto.
- **include/**: Arquivos de cabeçalho (.h).
- **tests/**: Arquivos de teste (.melody).
- **Makefile**: Arquivo para automatizar a compilação.

## **Compilação do Projeto**

Navegue até o diretório /Melodify do projeto e execute:

```bash
make clean
make
```

- **make clean**: Remove arquivos objeto e executáveis anteriores.
- **make**: Compila o projeto e gera o executável `melodify`.

**Possíveis Erros de Compilação**:

- Se encontrar erros relacionados a bibliotecas do LLVM, verifique se os caminhos de inclusão e as versões estão corretos.
- Certifique-se de que as bibliotecas do LLVM estão corretamente instaladas e acessíveis.

## **Execução do Programa**

Para executar o programa com um arquivo de teste:

```bash
./melodify tests/complex.melody
```

**Nota**: O arquivo `complex.melody` contém instruções na linguagem personalizada que o compilador deve processar.

## **Problema Atual**

### **Descrição do Erro**

- **Sintoma**: O programa encerra com um erro de falha de segmentação (segmentation fault) ao processar o arquivo `tests/complex.melody`.
- **Localização**: A falha ocorre na função `codegen_musical_instruction` dentro do arquivo `codegen.c`, especificamente na chamada para `LLVMBuildGlobalStringPtr`.
- **Contexto**: O erro acontece ao processar a instrução `set instrument "organ";` presente no arquivo de teste.

### **Comportamento Observado**

Ao executar o programa com o GDB (GNU Debugger), o seguinte backtrace é obtido:

```plaintext
Program received signal SIGSEGV, Segmentation fault.
__strlen_evex () at ../sysdeps/x86_64/multiarch/strlen-evex.S:77
#0  __strlen_evex () at ../sysdeps/x86_64/multiarch/strlen-evex.S:77
#1  0x00007ffff25cedbd in LLVMBuildGlobalStringPtr () from /lib/x86_64-linux-gnu/libLLVM-14.so.1
#2  0x000055555555b95e in codegen_musical_instruction (node=0x5555555dec90) at codegen.c:191
#3  0x000055555555c626 in codegen (node=0x5555555dec90) at codegen.c:481
#4  0x000055555555b56a in codegen_statement_list (node=0x5555555decc0) at codegen.c:90
#5  0x000055555555c5f3 in codegen (node=0x5555555debf0) at codegen.c:469
#6  0x000055555555b517 in codegen_program (node=0x5555555dfc40) at codegen.c:80
#7  0x000055555555c5e2 in codegen (node=0x5555555dfc40) at codegen.c:466
#8  0x000055555555872b in main (argc=2, argv=0x7fffffffdc28) at parser.y:346
```

### **Análise Inicial**

- **Ponto de Falha**: A falha ocorre ao chamar `LLVMBuildGlobalStringPtr`, que internamente utiliza `strlen` para determinar o tamanho da string.
- **Possível Causa**: O ponteiro passado para `LLVMBuildGlobalStringPtr` (`node->left->value.str`) pode ser nulo ou apontar para uma região de memória inválida.

## **Etapas de Depuração Realizadas**

### **1. Verificações de Ponteiros Nulos**

- Foram adicionadas verificações antes da chamada problemática para garantir que `node`, `node->left` e `node->left->value.str` não são nulos.
- As verificações confirmaram que esses ponteiros não são nulos, indicando que o problema pode ser outro.

### **2. Uso do GDB para Inspeção de Variáveis**

- Tentou-se imprimir o valor de `node->left->value.str` no GDB para verificar o conteúdo da string.
- Foram enfrentados erros de sintaxe no GDB, mas posteriormente foi possível obter o valor de `node->left->value.str`.

### **3. Análise da String**

- **Observação**: É possível que a string em `node->left->value.str` esteja corrompida, não seja válida ou não esteja corretamente terminada com `\0`.
- **Hipótese**: Se a string não for válida, a chamada para `strlen` falhará, causando o segmentation fault.

### **4. Revisão do Lexer e Parser**

#### **Lexer (`lexer.l`)**

- Verificou-se a regra para reconhecer literais de string:

  ```lex
  \"([^\"]|\\\")*\" {
      yylval.str = strdup(yytext + 1); // Ignora a aspa dupla inicial
      yylval.str[strlen(yylval.str) - 1] = '\0'; // Remove a aspa dupla final
      return STRING_LITERAL;
  }
  ```

- **Possível Problema**: A manipulação das aspas pode não estar correta, resultando em strings mal formadas.

#### **Parser (`parser.y`)**

- Verificou-se como o nó para `NODE_SET_INSTRUMENT` é criado:

  ```yacc
  set_instruction:
      SET INSTRUMENT STRING_LITERAL ';' {
          $$ = create_node(NODE_SET_INSTRUMENT, create_leaf(NODE_STRING, $3), NULL);
      }
  ```

- **Possível Problema**: O valor `$3` pode não estar sendo passado corretamente para `create_leaf`, ou `create_leaf` pode não estar alocando e copiando a string corretamente.

### **5. Revisão das Funções de Criação de Nós**

- Função `create_leaf`:

  ```c
  Node* create_leaf(NodeType type, const char* str_value) {
      Node* node = (Node*)malloc(sizeof(Node));
      node->type = type;
      node->left = NULL;
      node->right = NULL;
      node->next = NULL;
      if (str_value != NULL) {
          node->value.str = strdup(str_value);
      } else {
          node->value.str = NULL;
      }
      return node;
  }
  ```

- **Observação**: Garantir que `strdup` está sendo utilizado para alocar e copiar a string corretamente.

### **6. Adição de Mensagens de Depuração**

- Foram adicionados `printf` no código para exibir o valor de `node->left->value.str` antes da chamada problemática.

## **Descobertas**

- **Strings Inválidas**: A string em `node->left->value.str` pode estar inválida ou corrompida.
- **Problemas na Manipulação de Strings**: A forma como as strings estão sendo tratadas no lexer e no parser pode estar causando o problema.

## **Próximos Passos**

### **1. Verificar o Conteúdo da String**

- Utilizar o GDB ou mensagens de depuração para verificar o conteúdo real de `node->left->value.str`.
- Certificar-se de que a string contém o valor esperado (`"organ"`) e está corretamente terminada.

### **2. Ajustar o Lexer**

- Revisar a regra que trata de `STRING_LITERAL` para garantir que as aspas são removidas corretamente e que a string resultante é válida.
- Possível ajuste:

  ```lex
  \"([^\"]|\\\")*\" {
      size_t len = yyleng - 2; // Desconta as aspas
      yylval.str = (char*)malloc(len + 1);
      strncpy(yylval.str, yytext + 1, len);
      yylval.str[len] = '\0';
      return STRING_LITERAL;
  }
  ```

### **3. Verificar a Criação de Nós no Parser**

- Certificar-se de que o valor passado para `create_leaf` é o correto e que a função está manipulando a string adequadamente.

### **4. Testar com Arquivos Simplificados**

- Criar um arquivo de teste mínimo que contenha apenas a instrução problemática:

  ```melody
  set instrument "organ";
  ```

- Executar o programa com este arquivo para isolar o problema.

### **5. Recompilar com Flags de Depuração**

- Recompilar o projeto com as flags `-g` e `-O0` para incluir informações de depuração e desabilitar otimizações:

  ```bash
  make clean
  make CFLAGS="-Wall -g -O0"
  ```

### **6. Continuar a Depuração com o GDB**

- Utilizar o GDB para inspecionar as variáveis após as alterações e verificar se o problema persiste.

## **Conclusão**

O erro atual parece estar relacionado à manipulação incorreta de strings no lexer ou no parser, resultando em uma string inválida sendo passada para `LLVMBuildGlobalStringPtr`. Ao ajustar a forma como as strings são processadas e garantir que estão corretamente terminadas e válidas, espera-se resolver o problema da falha de segmentação.

## **Recursos Adicionais**

- **Documentação do LLVM**: [LLVM Language Reference Manual](https://llvm.org/docs/LangRef.html)
- **Tutorial de Flex e Bison**: [Flex & Bison Tutorial](http://westes.github.io/flex/manual/)
- **Guia de Depuração com GDB**: [GDB Documentation](https://www.gnu.org/software/gdb/documentation/)

## **Palavras Finais**

Se precisar de qualquer assistência adicional ou tiver dúvidas sobre qualquer parte do projeto ou das etapas realizadas, não hesite em entrar em contato. Estamos confiantes de que, com essas orientações, você será capaz de continuar o trabalho e resolver o problema atual.

Bom trabalho e sucesso no desenvolvimento do Melodify!
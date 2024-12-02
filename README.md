A EBNF definida é bastante abrangente e se alinha bem com o objetivo da linguagem musical. Agora, vamos trabalhar na **documentação detalhada para o README do repositório** com base nessa EBNF.

---

## **README - Linguagem Musical**

### **Nome da Linguagem**
**Melodify** - Uma linguagem de programação projetada para compor música de forma simples e intuitiva.

---

### **Motivação**
A música é uma linguagem universal. No entanto, a composição musical pode ser complexa para quem não é músico ou não possui ferramentas avançadas. **Melodify** foi criada para simplificar a criação de músicas, oferecendo uma sintaxe acessível e intuitiva, com comandos básicos que permitem gerar notas, acordes e até padrões rítmicos.

---

### **Características Principais**
1. **Declaração de Variáveis**: Manipule variáveis para controlar o andamento, volume e outras propriedades musicais.
2. **Condicionais e Loops**: Use estruturas de controle para criar padrões musicais dinâmicos.
3. **Instruções Musicais**: Toque notas, acorde, defina instrumentos e ajuste o tempo de forma simples.
4. **Funções Personalizadas**: Crie blocos reutilizáveis de código para escalar suas composições.
5. **Exportação para MIDI**: Compile o código para um arquivo `.midi`, que pode ser reproduzido em qualquer software de música.

---

### **Gramática Formal (EBNF)**
```ebnf
program = { statement };

statement = 
      variable_declaration
    | assignment
    | musical_instruction
    | conditional
    | loop
    | function_declaration
    | function_call
    | "return", expression, ";";

variable_declaration = ("set", identifier, "to", expression, ";");
assignment = identifier, "=", expression, ";";

musical_instruction = 
      ("play", note, duration, ";")
    | ("play", "chord", chord, duration, ";")
    | ("set", "instrument", string, ";")
    | ("set", "volume", expression, ";")
    | ("set", "tempo", expression, ";");

conditional = "if", "(", condition, ")", "{", { statement }, "}", ["else", "{", { statement }, "}"];

loop = "repeat", integer, "{", { statement }, "}";

function_declaration = "function", identifier, "(", [parameters], ")", "{", { statement }, "}";
function_call = identifier, "(", [arguments], ");";

parameters = parameter, { ",", parameter };
parameter = type, identifier;

arguments = expression, { ",", expression };

condition = expression, comparator, expression, { logical_operator, condition };
comparator = ">", "<", ">=", "<=", "==", "!=";
logical_operator = "&&", "||";

expression = term, { ("+" | "-"), term };
term = factor, { ("*" | "/"), factor };
factor = 
      integer 
    | string 
    | identifier 
    | function_call 
    | "(", expression, ")";

note = string;  (* Example: "C4", "D#5" *)
chord = string; (* Example: "C_major", "G7" *)
duration = "whole" | "half" | "quarter" | "eighth";
type = "int" | "str";

integer = digit, { digit };
digit = "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9";

string = '"', { character }, '"';
character = ? any valid ASCII character except '"' ?;

identifier = letter, { letter | digit | "_" };
letter = "a" | "b" | "c" | ... | "z" | "A" | "B" | ... | "Z";
```

---

### **Exemplos de Código**

#### **1. Composição Básica**
```plaintext
set tempo to 120;
set instrument "piano";

play "C4" quarter;
play "E4" quarter;
play "G4" half;
```

#### **2. Loop**
```plaintext
repeat 3 {
    play "C4" eighth;
    play "E4" eighth;
}
```

#### **3. Condicional**
```plaintext
set tempo to 120;

if tempo > 100 {
    play "C4" quarter;
} else {
    play "C4" half;
}
```

#### **4. Função**
```plaintext
function play_scale(start_note, steps) {
    repeat steps {
        play start_note quarter;
        set start_note to start_note + 1;
    }
}

play_scale("C4", 7);
```

---

### **Como Compilar e Executar**
1. **Pré-requisitos**:
   - Flex e Bison instalados no sistema.
   - Compilador C ou C++ (como GCC).
   - Biblioteca MIDI (opcional para exportação).

2. **Passos para Compilar**:
   - Clone o repositório:
     ```bash
     git clone <link-do-repositorio>
     cd Melodify
     ```
   - Gere o analisador:
     ```bash
     flex lexer.l
     bison -d parser.y
     gcc -o melodify lex.yy.c parser.tab.c -lm
     ```

3. **Executar um Programa**:
   - Escreva um arquivo de código `program.melody` e execute:
     ```bash
     ./melodify program.melody
     ```

4. **Gerar Arquivo MIDI**:
   - O arquivo MIDI será salvo como `output.midi` na mesma pasta.

---

### **Conjunto de Testes**
Incluímos um conjunto de testes na pasta `tests/` com exemplos como:
- Composição básica (`basic.melody`).
- Uso de loops (`loop.melody`).
- Funções avançadas (`functions.melody`).

Execute os testes com:
```bash
./melodify tests/basic.melody
```

---
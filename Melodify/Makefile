# Makefile
CC = gcc
CFLAGS = -Wall -Wno-unused-function -g -DDEBUG
BISON = bison -d
FLEX = flex

# Fontes e Objetos
SRCS = parser.y lexer.l nodes.c
OBJS = parser.tab.o lex.yy.o nodes.o

# Alvo principal
all: melodify

# Compilar o executável final
melodify: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Gerar arquivos do Bison
parser.tab.c parser.tab.h: parser.y
	$(BISON) $<

# Gerar arquivos do Flex
lex.yy.c: lexer.l parser.tab.h
	$(FLEX) $<

# Compilar objetos
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# Limpeza
clean:
	rm -f melodify $(OBJS) parser.tab.* lex.yy.c

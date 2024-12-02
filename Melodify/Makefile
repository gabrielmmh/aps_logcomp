# Makefile
CC = gcc
CFLAGS = -Wall -Wno-unused-function -g
BISON = bison -d
FLEX = flex

LLVM_CONFIG = /usr/bin/llvm-config
LLVM_CFLAGS = `$(LLVM_CONFIG) --cflags`
LLVM_LDFLAGS = `$(LLVM_CONFIG) --ldflags --libs`
LLVM_LIBS = `$(LLVM_CONFIG) --libs`

OBJS = parser.tab.o lex.yy.o nodes.o codegen.o

all: melodify

melodify: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LLVM_LDFLAGS) $(LLVM_LIBS)

parser.tab.c parser.tab.h: parser.y
	$(BISON) parser.y

lex.yy.c: lexer.l parser.tab.h
	$(FLEX) lexer.l

parser.tab.o: parser.tab.c nodes.h codegen.h
	$(CC) $(CFLAGS) -c parser.tab.c

lex.yy.o: lex.yy.c
	$(CC) $(CFLAGS) -c lex.yy.c

nodes.o: nodes.c nodes.h
	$(CC) $(CFLAGS) -c nodes.c

codegen.o: codegen.c codegen.h nodes.h
	$(CC) $(CFLAGS) $(LLVM_CFLAGS) -c codegen.c

clean:
	rm -f melodify $(OBJS) parser.tab.c parser.tab.h lex.yy.c

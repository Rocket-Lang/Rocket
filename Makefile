IDIR=./src
ODIR=./
CC=g++

BASE=$(IDIR)/main.cpp
LEXER=$(IDIR)/lexer/chartest.cpp $(IDIR)/lexer/file_reader.cpp $(IDIR)/lexer/iskeyword.cpp $(IDIR)/lexer/lexe.cpp $(IDIR)/lexer/lexeme.cpp $(IDIR)/lexer/specialsequence.cpp
PARSER=$(IDIR)/parser/ast_llvm_base.cpp $(IDIR)/parser/lexemecheck.cpp $(IDIR)/parser/parsekeys.cpp $(IDIR)/parser/parse.cpp
COMPILER=$(IDIR)/compiler/compiler.cpp $(IDIR)/compiler/codegen.cpp

FILES=$(BASE) $(LEXER) $(PARSER) $(COMPILER)
CFLAGS=-Wall -O2
DBGFLAGS=-g3 -g -fsanitize=address

Rocket:
	$(CC) $(CFLAGS) -o $(ODIR)/Rocket $(FILES)

debug:
	$(CC) $(CFLAGS) $(DBGFLAGS) -o $(ODIR)/Rocket-Debug $(FILES)

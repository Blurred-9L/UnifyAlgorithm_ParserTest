OBJECTS = unify.o \
		AbstractAutomata.o \
		FloatNode.o \
		FormulaNode.o \
		IntegerNode.o \
		KeywordSet.o \
		LineFileReader.o \
		Parser.o \
		ParserTableAction.o \
		ParserTable.o \
		ParserTableKey.o \
		SymbolNode.o \
		SyntaxNode.o \
		TermListNode.o \
		TermNode.o \
		Token.o \
		Tokenizer.o \
		Unifier.o \
		UnifyAutomata.o \
		UnifyNode.o \
		UnifyParser.o \
		UnifyParserTable.o \
		VarNode.o

all: $(OBJECTS)
	g++ $(OBJECTS) -o unify

unify.o: unify.cpp
	g++ -c unify.cpp

AbstractAutomata.o: AbstractAutomata.cpp AbstractAutomata.h
	g++ -c AbstractAutomata.cpp

FloatNode.o: FloatNode.cpp FloatNode.h
	g++ -c FloatNode.cpp

FormulaNode.o: FormulaNode.cpp FormulaNode.h
	g++ -c FormulaNode.cpp

IntegerNode.o: IntegerNode.cpp IntegerNode.h
	g++ -c IntegerNode.cpp

KeywordSet.o: KeywordSet.cpp KeywordSet.h
	g++ -c KeywordSet.cpp

LineFileReader.o: LineFileReader.cpp LineFileReader.h
	g++ -c LineFileReader.cpp

Parser.o: Parser.cpp Parser.h
	g++ -c Parser.cpp

ParserTableAction.o: ParserTableAction.cpp ParserTableAction.h
	g++ -c ParserTableAction.cpp

ParserTable.o: ParserTable.cpp ParserTable.h
	g++ -c ParserTable.cpp

ParserTableKey.o: ParserTableKey.cpp ParserTableKey.h
	g++ -c ParserTableKey.cpp

SymbolNode.o: SymbolNode.cpp SymbolNode.h
	g++ -c SymbolNode.cpp

SyntaxNode.o: SyntaxNode.cpp SyntaxNode.h
	g++ -c SyntaxNode.cpp

TermListNode.o: TermListNode.cpp TermListNode.h
	g++ -c TermListNode.cpp

TermNode.o: TermNode.cpp TermNode.h
	g++ -c TermNode.cpp

Token.o: Token.cpp Token.h
	g++ -c Token.cpp

Tokenizer.o: Tokenizer.cpp Tokenizer.h
	g++ -c Tokenizer.cpp

Unifier.o: Unifier.cpp Unifier.h
	g++ -c Unifier.cpp

UnifyAutomata.o: UnifyAutomata.cpp UnifyAutomata.h
	g++ -c UnifyAutomata.cpp

UnifyNode.o: UnifyNode.cpp UnifyNode.h
	g++ -c UnifyNode.cpp

UnifyParser.o: UnifyParser.cpp UnifyParser.h
	g++ -c UnifyParser.cpp

UnifyParserTable.o: UnifyParserTable.cpp UnifyParserTable.h
	g++ -c UnifyParserTable.cpp

VarNode.o: VarNode.cpp VarNode.h
	g++ -c VarNode.cpp

clean:
	rm -f $(OBJECTS)

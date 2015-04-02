OBJECTS = unify.o \
		FloatNode.o \
		FormulaNode.o \
		IntegerNode.o \
		SyntaxNode.o \
		SymbolNode.o \
		TermListNode.o \
		TermNode.o \
		Unifier.o \
		UnifyAutomata.o \
		UnifyNode.o \
		UnifyParser.o \
		UnifyParserTable.o \
		VarNode.o
		
BLUR_PARSER_OBJS = BlurParser/ErrorData.o \
				   BlurParser/ErrorKeeper.o \
				   BlurParser/LineFileReader.o \
				   BlurParser/Token.o \
				   BlurParser/TokenData.o \
				   BlurParser/AbstractAutomata.o \
				   BlurParser/KeywordSet.o \
				   BlurParser/Tokenizer.o \
				   BlurParser/Parser.o \
				   BlurParser/ParserTable.o \
				   BlurParser/ParserTableAction.o \
				   BlurParser/ParserTableKey.o \

all: blurparser $(OBJECTS)
	g++ $(OBJECTS) $(BLUR_PARSER_OBJS) -o unify
	
blurparser:
	cd BlurParser && make

unify.o: unify.cpp
	g++ -c unify.cpp

FloatNode.o: FloatNode.cpp FloatNode.h
	g++ -c FloatNode.cpp

FormulaNode.o: FormulaNode.cpp FormulaNode.h
	g++ -c FormulaNode.cpp

IntegerNode.o: IntegerNode.cpp IntegerNode.h
	g++ -c IntegerNode.cpp

SyntaxNode.o: SyntaxNode.cpp SyntaxNode.h
	g++ -c SyntaxNode.cpp

SymbolNode.o: SymbolNode.cpp SymbolNode.h
	g++ -c SymbolNode.cpp

TermListNode.o: TermListNode.cpp TermListNode.h
	g++ -c TermListNode.cpp

TermNode.o: TermNode.cpp TermNode.h
	g++ -c TermNode.cpp

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
	cd BlurParser && make clean

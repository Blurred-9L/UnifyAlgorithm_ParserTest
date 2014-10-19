#include "UnifyParser.h"
#include "UnifyParserTable.h"
#include "ParserTableAction.h"
#include "ParserTableKey.h"
#include "Tokenizer.h"
#include "Token.h"
#include "UnifyAutomata.h"
#include "KeywordSet.h"

#include "VarNode.h"
#include "SymbolNode.h"
#include "IntegerNode.h"
#include "FloatNode.h"
#include "TermNode.h"
#include "TermListNode.h"
#include "FormulaNode.h"
#include "UnifyNode.h"

#include <iostream>
using std::cout;
using std::endl;

UnifyParser::UnifyParser() :
    Parser()
{
    setEndOfInput(UnifyAutomata::END_OF_INPUT);
}

UnifyParser::UnifyParser(ParserTable * table, Tokenizer * tokenizer) :
    Parser(table, tokenizer)
{
    setEndOfInput(UnifyAutomata::END_OF_INPUT);
}

UnifyParser::~UnifyParser()
{
    while (!states.empty()) { states.pop(); }
    while (!symbols.empty()) { symbols.pop(); }
}

SyntaxNode * UnifyParser::getSyntaxTreeRoot()
{
    SyntaxNode * root = symbols.top();
    symbols.pop();
    
    return root;
}

///////////////
// Protected //
///////////////

int UnifyParser::getRuleLength(int ruleNumber)
{
    int popTimes[] = {0, 3, 1, 1, 1, 1, 1, 3, 4, 1, 3};
    
    return popTimes[ruleNumber];
}

int UnifyParser::getNonTerminalType(int ruleNumber)
{
    int nonTermType;
    
    switch (ruleNumber) {
        case 1:
            nonTermType = UnifyParserTable::UNIFICATION;
            break;
        case 2: case 3: case 4: case 5: case 6:
            nonTermType = UnifyParserTable::TERM;
            break;
        case 7: case 8:
            nonTermType = UnifyParserTable::ATOMIC_FORMULA;
            break;
        case 9: case 10:
            nonTermType = UnifyParserTable::TERM_LIST;
            break;
    }
    
    return nonTermType;
}

SyntaxNode * UnifyParser::toSyntaxNode(Token * token)
{
    SyntaxNode * node = 0;
    
    switch (token->type()) {
    case UnifyAutomata::VARIABLE:
        node = new VarNode(token);
        break;
    case UnifyAutomata::SYMBOL:
        node = new SymbolNode(token);
        break;
    case UnifyAutomata::INT_CONST:
        node = new IntegerNode(token);
        break;
    case UnifyAutomata::FLOAT_CONST:
        node = new FloatNode(token);
        break;
    default:
        node = new SyntaxNode();
        break;
    }
    
    return node;
}

SyntaxNode * UnifyParser::reduce(int ruleNumber)
{
    SyntaxNode * node = 0;
    SyntaxNode * aux;
    TermNode * right, * left, * term;
    VarNode * var;
    SymbolNode * symbol;
    IntegerNode * intNode;
    FloatNode * floatNode;
    FormulaNode * formula;
    TermListNode * termList;
    
    switch (ruleNumber) {
    case 1:
        right = dynamic_cast<TermNode *>(symbols.top());
        symbols.pop();
        aux = symbols.top();
        delete aux;
        symbols.pop();
        left = dynamic_cast<TermNode *>(symbols.top());
        symbols.pop();
        node = new UnifyNode(left, right);
        break;
    case 2:
        var = dynamic_cast<VarNode *>(symbols.top());
        symbols.pop();
        node = new TermNode(var);
        break;
    case 3:
        symbol = dynamic_cast<SymbolNode *>(symbols.top());
        symbols.pop();
        node = new TermNode(symbol);
        break;
    case 4:
        intNode = dynamic_cast<IntegerNode *>(symbols.top());
        symbols.pop();
        node = new TermNode(intNode);
        break;
    case 5:
        floatNode = dynamic_cast<FloatNode *>(symbols.top());
        symbols.pop();
        node = new TermNode(floatNode);
        break;
    case 6:
        formula = dynamic_cast<FormulaNode *>(symbols.top());
        symbols.pop();
        node = new TermNode(formula);
        break;
    case 7:
        aux = symbols.top();
        symbols.pop();
        delete aux;
        aux = symbols.top();
        symbols.pop();
        delete aux;
        symbol = dynamic_cast<SymbolNode *>(symbols.top());
        symbols.pop();
        node = new FormulaNode(symbol, 0);
    case 8:
        aux = symbols.top();
        symbols.pop();
        delete aux;
        termList = dynamic_cast<TermListNode *>(symbols.top());
        symbols.pop();
        aux = symbols.top();
        symbols.pop();
        delete aux;
        symbol = dynamic_cast<SymbolNode *>(symbols.top());
        symbols.pop();
        node = new FormulaNode(symbol, termList);
        break;
        break;
    case 9:
        term = dynamic_cast<TermNode *>(symbols.top());
        symbols.pop();
        node = new TermListNode(term, 0);
        break;
    case 10:
        termList = dynamic_cast<TermListNode *>(symbols.top());
        symbols.pop();
        aux = symbols.top();
        symbols.pop();
        delete aux;
        term = dynamic_cast<TermNode *>(symbols.top());
        symbols.pop();
        node = new TermListNode(term, termList);
        break;
    }
    
    return node;
}

void UnifyParser::raiseError(const char * what)
{
    errorRaised_ = true;
    cout << what << endl;
}

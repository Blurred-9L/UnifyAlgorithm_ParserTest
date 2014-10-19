#ifndef PARSER_H
#define PARSER_H

#include <string>
using std::string;
#include <stack>
using std::stack;

class ParserTable;
class ParserTableAction;
class SyntaxNode;
class Tokenizer;
class Token;

/**
 *  @class  Parser
 */
class Parser {
protected:
    ///
    ParserTable * table_;
    ///
    Tokenizer * tokenizer_;
    ///
    Token * curToken;
    ///
    int endOfInput_;
    ///
    bool errorRaised_;
    ///
    stack<int> states;
    ///
    stack<SyntaxNode *> symbols;
    
    ///
    virtual bool doAction(int state, int tokenType);
    ///
    virtual bool applyAction(ParserTableAction * action);
    ///
    virtual bool applyReduction(int ruleNumber);
    ///
    virtual int getRuleLength(int ruleNumber) = 0;
    ///
    virtual int getNonTerminalType(int ruleNumber) = 0;
    ///
    virtual SyntaxNode * toSyntaxNode(Token * token) = 0;
    ///
    virtual SyntaxNode * reduce(int ruleNumber) = 0;
    ///
    virtual void raiseError(const char * what);
    
public:
    ///
    Parser();
    ///
    Parser(ParserTable * table, Tokenizer * tokenizer);
    ///
    virtual ~Parser();
    ///
    const ParserTable & table() const;
    ///
    ParserTable & table();
    ///
    const Tokenizer & tokenizer() const;
    ///
    Tokenizer & tokenizer();
    ///
    int endOfInput() const;
    ///
    void setTable(ParserTable * table);
    ///
    void setTokenizer(Tokenizer * tokenizer);
    ///
    void setEndOfInput(int endOfInput);
    ///
    virtual bool parse(const string & line);
    ///
    virtual SyntaxNode * getSyntaxTreeRoot() = 0;
};

#endif /// NOT PARSER_H

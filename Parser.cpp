#include "Parser.h"
#include "ParserTable.h"
#include "ParserTableKey.h"
#include "ParserTableAction.h"
#include "Tokenizer.h"
#include "Token.h"

Parser::Parser() :
    table_(0), tokenizer_(0), curToken(0), endOfInput_(-1), errorRaised_(false)
{
}
Parser::Parser(ParserTable * table, Tokenizer * tokenizer) :
    table_(table), tokenizer_(tokenizer), curToken(0), endOfInput_(-1), errorRaised_(false)
{
}

Parser::~Parser()
{
    if (table_ != 0) {
        delete table_;
    }
    if (tokenizer_ != 0) {
        delete tokenizer_;
    }
}

const ParserTable & Parser::table() const
{
    return *table_;
}

ParserTable & Parser::table()
{
    return *table_;
}

const Tokenizer & Parser::tokenizer() const
{
    return *tokenizer_;
}

Tokenizer & Parser::tokenizer()
{
    return *tokenizer_;
}

int Parser::endOfInput() const
{
    return endOfInput_;
}

void Parser::setTable(ParserTable * table)
{
    if (table != 0) {
        if (table_ != 0) {
            delete table_;
        }
        table_ = table;
    }
}

void Parser::setTokenizer(Tokenizer * tokenizer)
{
    if (tokenizer != 0) {
        if (tokenizer_ != 0) {
            delete tokenizer_;
        }
        tokenizer_ = tokenizer;
    }
}

void Parser::setEndOfInput(int endOfInput)
{
    endOfInput_ = endOfInput;
}

bool Parser::parse(const string & line)
{
    bool done = false;
    bool ok;
    
    while (!states.empty()) { states.pop(); }
    while (!symbols.empty()) { symbols.pop(); }
    states.push(0);
    tokenizer_->setLine(line);
    errorRaised_ = false;
    
    curToken = tokenizer_->getToken();
    while (!errorRaised_ && !done) {
        if (curToken != 0) {
            done = doAction(states.top(), curToken->type());
        } else {
            done = doAction(states.top(), endOfInput_);
        }
    }
    
    if (errorRaised_) {
        ok = false;
    } else if (done) {
        ok = true;
    }
    
    return ok;
}

///////////////
// Protected //
///////////////

bool Parser::doAction(int state, int tokenType) {
    ParserTableKey key(state, tokenType);
    ParserTableAction * action;
    bool done = false;
    
    if (table_->hasKey(key)) {
        action = table_->getAction(key);
        done = applyAction(action);
        delete action;
    } else {
        raiseError("Could not find transition according to input given.");
    }
    
    return done;
}

bool Parser::applyAction(ParserTableAction * action)
{
    bool done = false;
    
    switch (action->type()) {
    case ParserTable::SHIFT:
        states.push(action->value());
        symbols.push(toSyntaxNode(curToken));
        curToken = tokenizer_->getToken();
        break;
    case ParserTable::REDUCE:
        done = applyReduction(action->value());
        break;
    case ParserTable::CHANGE:
        raiseError("Reached part of code that shouldn't be reached.");
        break;
    case ParserTable::ACCEPT:
        done = true;
        break;
    }
    
    return done;
}

bool Parser::applyReduction(int ruleNumber)
{
    ParserTableKey key;
    ParserTableAction * action;
    SyntaxNode * nextNode;
    int i, nonTermType, ruleLength;
    bool done = false;
    
    ruleLength = getRuleLength(ruleNumber);
    for (i = 0; i < ruleLength; i++) {
        states.pop();
    }
    nextNode = reduce(ruleNumber);
    nonTermType = getNonTerminalType(ruleNumber);
    
    key.setState(states.top());
    key.setTokenType(nonTermType);
    if (table_->hasKey(key)) {
        action = table_->getAction(key);
        states.push(action->value());
        symbols.push(nextNode);
        delete action;
    } else {
        raiseError("Could not find transiton after applying reduction.");
    }
    
    return done;
}

void Parser::raiseError(const char * what)
{
    errorRaised_ = true;
}

#ifndef UNIFY_PARSER_H
#define UNIFY_PARSER_H

#include "BlurParser/Parser/Parser.h"

/**
 *  @class  UnifyParser
 */
class UnifyParser : public Parser {
protected:
    ///
    virtual SyntaxNode * toSyntaxNode(Token * token);
    ///
    virtual SyntaxNode * reduce(int ruleNumber);
    ///
    virtual void raiseError(const char * what);

public:
    ///
    UnifyParser();
    ///
    UnifyParser(ParserTable * table, Tokenizer * tokenizer);
    ///
    virtual ~UnifyParser();
    ///
    virtual SyntaxNode * getSyntaxTreeRoot();
};

#endif /// NOT UNIFY_PARSER_H

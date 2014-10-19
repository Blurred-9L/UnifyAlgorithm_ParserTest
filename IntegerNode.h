#ifndef INTEGER_NODE_H
#define INTEGER_NODE_H

#include "SyntaxNode.h"

class Token;

/**
 *  @class  IntegerNode
 */
class IntegerNode : public SyntaxNode {
private:
    ///
    Token * intToken_;
    
public:
    ///
    IntegerNode(Token * intToken);
    ///
    IntegerNode(const IntegerNode & i);
    ///
    virtual ~IntegerNode();
    ///
    virtual void printNode();
    ///
    virtual bool equals(SyntaxNode * node);
    ///
    const Token & intToken() const;
    ///
    Token & intToken();
};

#endif /// NOT INTEGER_NODE_H

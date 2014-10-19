#ifndef FLOAT_NODE_H
#define FLOAT_NODE_H

#include "SyntaxNode.h"

class Token;

/**
 *  @class  FloatNode
 */
class FloatNode : public SyntaxNode {
private:
    ///
    Token * floatToken_;
    
public:
    ///
    FloatNode(Token * floatToken);
    ///
    FloatNode(const FloatNode & f);
    ///
    virtual ~FloatNode();
    ///
    virtual void printNode();
    ///
    virtual bool equals(SyntaxNode * node);
    ///
    const Token & floatToken() const;
    ///
    Token & floatToken();
};

#endif /// NOT FLOAT_NODE_H

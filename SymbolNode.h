#ifndef SYMBOL_NODE_H
#define SYMBOL_NODE_H

#include "SyntaxNode.h"

class Token;

/**
 *  @class  SymbolNode
 */
class SymbolNode : public SyntaxNode {
private:
    ///
    Token * symbolToken_;
    
public:
    ///
    SymbolNode(Token * symbolToken);
    ///
    SymbolNode(const SymbolNode & s);
    ///
    virtual ~SymbolNode();
    ///
    virtual void printNode();
    ///
    virtual bool equals(SyntaxNode * node);
    ///
    const Token & symbolToken() const;
    ///
    Token & symbolToken();
};

#endif /// NOT SYMBOL_NODE_H

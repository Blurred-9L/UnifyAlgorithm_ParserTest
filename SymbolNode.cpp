#include "SymbolNode.h"
#include "Token.h"

#include <iostream>
using std::cout;
using std::endl;

SymbolNode::SymbolNode(Token * symbolToken) :
    SyntaxNode(), symbolToken_(symbolToken)
{
}

SymbolNode::SymbolNode(const SymbolNode & s) :
    SyntaxNode(), symbolToken_(new Token(s.symbolToken()))
{
}

SymbolNode::~SymbolNode()
{
    if (symbolToken_ != 0) {
        delete symbolToken_;
    }
}

void SymbolNode::printNode()
{
    cout << symbolToken_->symbol();
}

bool SymbolNode::equals(SyntaxNode * node)
{
    SymbolNode *sNode = dynamic_cast<SymbolNode *>(node);
    
    return ((sNode != 0) && (symbolToken_->symbol() == sNode->symbolToken().symbol()));
}

const Token & SymbolNode::symbolToken() const
{
    return *symbolToken_;
}

Token & SymbolNode::symbolToken()
{
    return *symbolToken_;
}

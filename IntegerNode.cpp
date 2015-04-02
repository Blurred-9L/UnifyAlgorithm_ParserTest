#include "IntegerNode.h"
#include "BlurParser/Core/Token.h"

#include <iostream>
using std::cout;
using std::endl;

IntegerNode::IntegerNode(Token * intToken) :
    SyntaxNode(), intToken_(intToken)
{
}

IntegerNode::IntegerNode(const IntegerNode & i) :
    SyntaxNode(), intToken_(new Token(i.intToken()))
{
}

IntegerNode::~IntegerNode()
{
    if (intToken_ != 0) {
        delete intToken_;
    }
}

void IntegerNode::printNode()
{
    cout << intToken_->symbol();
}

bool IntegerNode::equals(SyntaxNode * node)
{
    IntegerNode * iNode = dynamic_cast<IntegerNode *>(node);
    
    return ((iNode != 0) && (intToken_->symbol() == iNode->intToken().symbol()));
}

const Token & IntegerNode::intToken() const
{
    return *intToken_;
}

Token & IntegerNode::intToken()
{
    return *intToken_;
}

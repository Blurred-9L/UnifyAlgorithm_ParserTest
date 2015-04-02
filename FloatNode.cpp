#include "FloatNode.h"
#include "BlurParser/Core/Token.h"

#include <iostream>
using std::cout;
using std::endl;

FloatNode::FloatNode(Token * floatToken) :
    SyntaxNode(), floatToken_(floatToken)
{
}

FloatNode::FloatNode(const FloatNode & f) :
    SyntaxNode(), floatToken_(new Token(f.floatToken()))
{
}

FloatNode::~FloatNode()
{
    if (floatToken_ != 0) {
        delete floatToken_;
    }
}

void FloatNode::printNode()
{
    cout << floatToken_->symbol();
}

bool FloatNode::equals(SyntaxNode * node)
{
    FloatNode * fNode = dynamic_cast<FloatNode *>(node);
    
    return ((fNode != 0) && (floatToken_->symbol() == fNode->floatToken().symbol()));
}

const Token & FloatNode::floatToken() const
{
    return *floatToken_;
}

Token & FloatNode::floatToken()
{
    return *floatToken_;
}

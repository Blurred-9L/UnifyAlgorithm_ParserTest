#include "VarNode.h"
#include "Token.h"

#include <iostream>
using std::cout;
using std::endl;

VarNode::VarNode(Token * varToken) :
    SyntaxNode(), varToken_(varToken)
{
}

VarNode::VarNode(const VarNode & v) :
    SyntaxNode(), varToken_(new Token(v.varToken()))
{
}

VarNode::~VarNode()
{
    if (varToken_ != 0) {
        delete varToken_;
    }
}

void VarNode::printNode()
{
    cout << varToken_->symbol();
}

bool VarNode::equals(SyntaxNode * node)
{
    VarNode * vNode = dynamic_cast<VarNode *>(node);
    
    return ((vNode != 0) && (varToken_->symbol() == vNode->varToken().symbol()));
}

bool VarNode::occur_check(SyntaxNode * var)
{
    return equals(var);
}

const Token & VarNode::varToken() const
{
    return *varToken_;
}

Token & VarNode::varToken()
{
    return *varToken_;
}

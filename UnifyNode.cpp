#include "UnifyNode.h"
#include "TermNode.h"

#include <iostream>
using std::cout;
using std::endl;

UnifyNode::UnifyNode(TermNode * leftTerm, TermNode * rightTerm) :
    SyntaxNode(), leftTerm_(leftTerm), rightTerm_(rightTerm)
{
}

UnifyNode::UnifyNode(const UnifyNode & u) :
    SyntaxNode(), leftTerm_(new TermNode(u.leftTerm())),
    rightTerm_(new TermNode(u.rightTerm()))
{
}

UnifyNode::~UnifyNode()
{
    if (leftTerm_ != 0) {
        delete leftTerm_;
    }
    if (rightTerm_ != 0) {
        delete rightTerm_;
    }
}

void UnifyNode::printNode()
{
    leftTerm_->printNode();
    cout << " = ";
    rightTerm_->printNode();
    cout << endl;
}

void UnifyNode::computeArity()
{
    leftTerm_->computeArity();
    rightTerm_->computeArity();
}

bool UnifyNode::equals(SyntaxNode * node)
{
    UnifyNode * uNode = dynamic_cast<UnifyNode *>(node);
    
    return ((uNode != 0) && (leftTerm_->equals(&uNode->leftTerm())) &&
            (rightTerm_->equals(&uNode->rightTerm())));
}

const TermNode & UnifyNode::leftTerm() const
{
    return *leftTerm_;
}

TermNode & UnifyNode::leftTerm()
{
    return *leftTerm_;
}

const TermNode & UnifyNode::rightTerm() const
{
    return *rightTerm_;
}

TermNode & UnifyNode::rightTerm()
{
    return *rightTerm_;
}

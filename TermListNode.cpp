#include "TermListNode.h"
#include "TermNode.h"

#include <iostream>
using std::cout;
using std::endl;

TermListNode::TermListNode(TermNode * term, TermListNode * next) :
    SyntaxNode(), term_(term), next_(next)
{
}

TermListNode::TermListNode(const TermListNode & l) :
    SyntaxNode(), term_(new TermNode(l.term())),
    next_(0)
{
    if (l.next_ != 0) {
        next_ = new TermListNode(*l.next_);
    }
}

TermListNode::~TermListNode()
{
    if (next_ != 0) {
        delete next_;
    }
    if (term_ != 0) {
        delete term_;
    }
}

void TermListNode::printNode()
{
    term_->printNode();
    if (next_ != 0) {
        cout << ", ";
        next_->printNode();
    }
}

void TermListNode::computeArity()
{
    term_->computeArity();
    if (next_ != 0) {
        next_->computeArity();
    }
}

bool TermListNode::equals(SyntaxNode * node)
{
    TermListNode * lNode = dynamic_cast<TermListNode *>(node);
    bool ok = (lNode != 0);
    
    if (ok) {
        if (next_ != 0) {
            ok = ((term_->equals(&lNode->term())) && (next_->equals(lNode->next())));
        } else {
            ok = (term_->equals(&lNode->term()));
        }
    }
    
    return ok;
}

bool TermListNode::occur_check(SyntaxNode * var)
{
    bool occurCheckFlag;
    
    if (next_ != 0) {
        occurCheckFlag = (term_->occur_check(var)) || (next_->occur_check(var));
    } else {
        occurCheckFlag = term_->occur_check(var);
    }
    
    return occurCheckFlag;
}

void TermListNode::replace(SyntaxNode * var, SyntaxNode * data)
{
    term_->replace(var, data);
    if (next_ != 0) {
        next_->replace(var, data);
    }
}

const TermNode & TermListNode::term() const
{
    return *term_;
}

TermNode & TermListNode::term()
{
    return *term_;
}

const TermListNode * TermListNode::next() const
{
    return next_;
}

TermListNode * TermListNode::next()
{
    return next_;
}

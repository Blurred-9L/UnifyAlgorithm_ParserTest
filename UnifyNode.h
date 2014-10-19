#ifndef UNIFY_NODE_H
#define UNIFY_NODE_H

#include "SyntaxNode.h"

class TermNode;

/**
 *  @class  UnifyNode
 */
class UnifyNode : public SyntaxNode {
private:
    ///
    TermNode * leftTerm_;
    ///
    TermNode * rightTerm_;
    
public:
    ///
    UnifyNode(TermNode * leftTerm, TermNode * rightTerm);
    ///
    UnifyNode(const UnifyNode & u);
    ///
    virtual ~UnifyNode();
    ///
    virtual void printNode();
    ///
    virtual void computeArity();
    ///
    virtual bool equals(SyntaxNode * node);
    ///
    const TermNode & leftTerm() const;
    ///
    TermNode & leftTerm();
    ///
    const TermNode & rightTerm() const;
    ///
    TermNode & rightTerm();
};

#endif /// NOT UNIFY_NODE_H

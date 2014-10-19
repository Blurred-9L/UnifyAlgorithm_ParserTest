#ifndef TERM_LIST_NODE_H
#define TERM_LIST_NODE_H

#include "SyntaxNode.h"

class TermNode;

/**
 *  @class  TermListNode
 */
class TermListNode : public SyntaxNode {
private:
    ///
    TermNode * term_;
    ///
    TermListNode * next_;
    
public:
    ///
    TermListNode(TermNode * term, TermListNode * next);
    ///
    TermListNode(const TermListNode & l);
    ///
    virtual ~TermListNode();
    ///
    virtual void printNode();
    ///
    virtual void computeArity();
    ///
    virtual bool equals(SyntaxNode * node);
    ///
    virtual bool occur_check(SyntaxNode * var);
    ///
    virtual void replace(SyntaxNode * var, SyntaxNode * data);
    ///
    const TermNode & term() const;
    ///
    TermNode & term();
    ///
    const TermListNode * next() const;
    ///
    TermListNode * next();
};

#endif /// NOT TERM_LIST_NODE_H

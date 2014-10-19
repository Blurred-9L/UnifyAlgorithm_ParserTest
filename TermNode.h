#ifndef TERM_NODE_H
#define TERM_NODE_H

#include "SyntaxNode.h"

/**
 *  @class  TermNode
 */
class TermNode : public SyntaxNode {
private:
    ///
    SyntaxNode * data_;
    
public:
    ///
    TermNode(SyntaxNode * data);
    ///
    TermNode(const TermNode & t);
    ///
    virtual ~TermNode();
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
    const SyntaxNode & data() const;
    ///
    SyntaxNode & data();
    ///
    static bool isVariable(SyntaxNode * node);
    ///
    static bool isConstant(SyntaxNode * node);
    ///
    static bool isInteger(SyntaxNode * node);
    ///
    static bool isFloat(SyntaxNode * node);
    ///
    static bool isSymbol(SyntaxNode * node);
    ///
    static bool isFormula(SyntaxNode * node);
};

#endif /// NOT TERM_NODE_H

#ifndef SYNTAX_NODE_H
#define SYNTAX_NODE_H

/**
 *  @class  SyntaxNode
 */
class SyntaxNode {
public:
    ///
    SyntaxNode();
    ///
    virtual ~SyntaxNode();
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
};

#endif /// NOT SYNTAX_NODE_H

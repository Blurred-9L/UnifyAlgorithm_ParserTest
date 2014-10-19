#ifndef FORMULA_NODE_H
#define FORMULA_NODE_H

#include "SyntaxNode.h"

class SymbolNode;
class TermListNode;

/**
 *  @class FormulaNode
 */
class FormulaNode : public SyntaxNode {
private:
    ///
    SymbolNode * symbol_;
    ///
    TermListNode * terms_;
    ///
    int arity_;
    
public:
    ///
    FormulaNode(SymbolNode * symbol, TermListNode * terms);
    ///
    FormulaNode(const FormulaNode & f);
    ///
    virtual ~FormulaNode();
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
    const SymbolNode & symbol() const;
    ///
    SymbolNode & symbol();
    ///
    const TermListNode * terms() const;
    ///
    TermListNode * terms();
    ///
    int arity() const;
};

#endif /// NOT FORMULA_NODE_H

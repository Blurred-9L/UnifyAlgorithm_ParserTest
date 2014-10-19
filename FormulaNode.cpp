#include "FormulaNode.h"
#include "SymbolNode.h"
#include "TermListNode.h"

#include <iostream>
using std::cout;
using std::endl;

FormulaNode::FormulaNode(SymbolNode * symbol, TermListNode * terms) :
    SyntaxNode(), symbol_(symbol), terms_(terms), arity_(0)
{
}

FormulaNode::FormulaNode(const FormulaNode & f) :
    SyntaxNode(), symbol_(new SymbolNode(f.symbol())), terms_(0),
    arity_(f.arity_)
{
    if (f.terms_ != 0) {
        terms_ = new TermListNode(*f.terms_);
    }
}

FormulaNode::~FormulaNode()
{
    if (symbol_ != 0) {
        delete symbol_;
    }
    if (terms_ != 0) {
        delete terms_;
    }
}

void FormulaNode::printNode()
{
    symbol_->printNode();
    cout << "(";
    if (terms_ != 0) {
        terms_->printNode();
    }
    cout << ")";
}

void FormulaNode::computeArity()
{
    TermListNode * iterator = terms_;
    
    terms_->computeArity();
    arity_ = 0;
    while (iterator != 0) {
        arity_ += 1;
        iterator = iterator->next();
    }
}

bool FormulaNode::equals(SyntaxNode * node)
{
    FormulaNode * fNode = dynamic_cast<FormulaNode *>(node);
    bool ok = (fNode != 0);
    
    if (ok) {
        if (terms_ != 0) {
            ok = (symbol_->equals(&fNode->symbol()) && arity_ == fNode->arity() && terms_->equals(fNode->terms()));
        } else {
            ok = (symbol_->equals(&fNode->symbol()) && arity_ == fNode->arity());
        }
    }
    
    return ok;
}

bool FormulaNode::occur_check(SyntaxNode * var)
{
    bool occurCheckFlag;
    
    if (terms_ != 0) {
        occurCheckFlag = terms_->occur_check(var);
    } else {
        occurCheckFlag = false;
    }
    
    return occurCheckFlag;
}

void FormulaNode::replace(SyntaxNode * var, SyntaxNode * data)
{
    if (terms_ != 0) {
        terms_->replace(var, data);
    }
}

const SymbolNode & FormulaNode::symbol() const
{
    return *symbol_;
}

SymbolNode & FormulaNode::symbol()
{
    return *symbol_;
}

const TermListNode * FormulaNode::terms() const
{
    return terms_;
}

TermListNode * FormulaNode::terms()
{
    return terms_;
}

int FormulaNode::arity() const
{
    return arity_;
}

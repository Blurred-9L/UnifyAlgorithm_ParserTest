#include "TermNode.h"
#include "VarNode.h"
#include "IntegerNode.h"
#include "FloatNode.h"
#include "SymbolNode.h"
#include "FormulaNode.h"

TermNode::TermNode(SyntaxNode * data) :
    SyntaxNode(), data_(data)
{
}

TermNode::TermNode(const TermNode & t) :
    SyntaxNode(), data_(0)
{
    if (isVariable(t.data_)) {
        data_ = new VarNode(*dynamic_cast<VarNode *>(t.data_));
    } else if (isFormula(t.data_)) {
        data_ = new FormulaNode(*dynamic_cast<FormulaNode *>(t.data_));
    } else if (isInteger(t.data_)) {
        data_ = new IntegerNode(*dynamic_cast<IntegerNode *>(t.data_));
    } else if (isFloat(t.data_)) {
        data_ = new FloatNode(*dynamic_cast<FloatNode *>(t.data_));
    } else if (isSymbol(t.data_)) {
        data_ = new SymbolNode(*dynamic_cast<SymbolNode *>(t.data_));
    }
}

TermNode::~TermNode()
{
    if (data_ != 0) {
        delete data_;
    }
}

void TermNode::printNode()
{
    data_->printNode();
}

void TermNode::computeArity()
{
    data_->computeArity();
}

bool TermNode::equals(SyntaxNode * node)
{
    TermNode * tNode = dynamic_cast<TermNode *>(node);
    
    return ((tNode != 0) && (data_->equals(&tNode->data())));
}

bool TermNode::occur_check(SyntaxNode * var)
{
    return data_->occur_check(var);
}

void TermNode::replace(SyntaxNode * var, SyntaxNode * data)
{
    if (data_->equals(var)) {
        if (isVariable(data)) {
            data_ = new VarNode(*dynamic_cast<VarNode *>(data));
        } else if (isFormula(data)) {
            data_ = new FormulaNode(*dynamic_cast<FormulaNode *>(data));
        } else if (isInteger(data)) {
            data_ = new IntegerNode(*dynamic_cast<IntegerNode *>(data));
        } else if (isFloat(data)) {
            data_ = new FloatNode(*dynamic_cast<FloatNode *>(data));
        } else if (isSymbol(data)) {
            data_ = new SymbolNode(*dynamic_cast<SymbolNode *>(data));
        }
    } else {
        data_->replace(var, data);
    }
}

const SyntaxNode & TermNode::data() const
{
    return *data_;
}

SyntaxNode & TermNode::data()
{
    return *data_;
}

bool TermNode::isVariable(SyntaxNode * node)
{
    return dynamic_cast<VarNode *>(node) != 0;
}

bool TermNode::isConstant(SyntaxNode * node)
{
    return ((isInteger(node)) || (isFloat(node)) || (isSymbol(node)));
}

bool TermNode::isInteger(SyntaxNode * node)
{
    return dynamic_cast<IntegerNode *>(node) != 0;
}

bool TermNode::isFloat(SyntaxNode * node)
{
    return dynamic_cast<FloatNode *>(node) != 0;
}

bool TermNode::isSymbol(SyntaxNode * node)
{
    return dynamic_cast<SymbolNode *>(node) != 0;
}

bool TermNode::isFormula(SyntaxNode * node)
{
    return dynamic_cast<FormulaNode *>(node) != 0;
}


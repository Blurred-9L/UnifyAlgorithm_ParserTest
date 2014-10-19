#include "SyntaxNode.h"

SyntaxNode::SyntaxNode()
{
}

SyntaxNode::~SyntaxNode()
{
}

void SyntaxNode::printNode()
{
}

void SyntaxNode::computeArity()
{
}

bool SyntaxNode::equals(SyntaxNode * node)
{
    return this == node;
}

bool SyntaxNode::occur_check(SyntaxNode * var)
{
    return false;
}

void SyntaxNode::replace(SyntaxNode * var, SyntaxNode * data)
{
}

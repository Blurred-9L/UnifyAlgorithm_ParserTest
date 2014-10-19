#ifndef VAR_NODE_H
#define VAR_NODE_h

#include "SyntaxNode.h"

class Token;

/**
 *  @class  VarNode
 */
class VarNode : public SyntaxNode {
private:
    ///
    Token * varToken_;
    
public:
    ///
    VarNode(Token * varToken);
    ///
    VarNode(const VarNode & v);
    ///
    virtual ~VarNode();
    ///
    virtual void printNode();
    ///
    virtual bool equals(SyntaxNode * node);
    ///
    virtual bool occur_check(SyntaxNode * var);
    ///
    const Token & varToken() const;
    ///
    Token & varToken();
};

#endif /// NOT VAR_NODE_H

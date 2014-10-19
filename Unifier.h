#ifndef UNIFIER_H
#define UNIFIER_H

#include <string>
using std::string;
#include <utility>
using std::pair;
#include <vector>
using std::vector;

class UnifyParser;
class TermNode;
class SyntaxNode;
class TermListNode;

/**
 *  @class  Unifier
 */
class Unifier {
private:
    ///
    UnifyParser * parser_;
    ///
    vector<pair<SyntaxNode *, SyntaxNode *> *> pairs;
    
    ///
    bool unification(TermNode & left, TermNode & right);
    ///
    pair<SyntaxNode *, SyntaxNode *> * firstDiffPair(TermListNode * left, TermListNode * right);
    ///
    pair<SyntaxNode *, SyntaxNode *> * firstDiffPair(TermNode & left, TermNode & right);

public:
    ///
    Unifier();
    ///
    ~Unifier();
    ///
    const UnifyParser & parser() const;
    ///
    UnifyParser & parser();
    ///
    bool unify(const string & input);
};

#endif /// NOT UNIFIER_H

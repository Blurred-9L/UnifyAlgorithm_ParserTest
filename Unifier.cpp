#include "Unifier.h"

#include "UnifyParser.h"
#include "UnifyParserTable.h"
#include "UnifyAutomata.h"
#include "KeywordSet.h"
#include "Tokenizer.h"
#include "SyntaxNode.h"

#include "UnifyNode.h"
#include "TermNode.h"
#include "TermListNode.h"
#include "FormulaNode.h"
#include "SymbolNode.h"
#include "VarNode.h"
#include "IntegerNode.h"
#include "FloatNode.h"

#include <iostream>
using std::cout;
using std::endl;

///
static void cleanPairs(vector<pair<SyntaxNode *, SyntaxNode *> *> & pairs);
///
static void showPairs(vector<pair<SyntaxNode *, SyntaxNode *> *> & pairs);
///
static void showErrorType(int type);

Unifier::Unifier() :
    parser_(0)
{
    parser_ = new UnifyParser(new UnifyParserTable(),
                              new Tokenizer(new UnifyAutomata(), new KeywordSet(), 0));
}

Unifier::~Unifier()
{
    if (parser_ != 0) {
        delete parser_;
    }
}
const UnifyParser & Unifier::parser() const
{
    return *parser_;
}

UnifyParser & Unifier::parser()
{
    return *parser_;
}

bool Unifier::unify(const string & input)
{
    bool parseOk;
    bool ok = false;
    SyntaxNode * root;
    UnifyNode * uRoot;
    
    parseOk = parser_->parse(input);
    if (parseOk) {
        root = parser_->getSyntaxTreeRoot();
        uRoot = dynamic_cast<UnifyNode *>(root);
        root->computeArity();
        ok = unification(uRoot->leftTerm(), uRoot->rightTerm());
        delete root;
    } else {
        cout << "Syntax error!" << endl;
    }
    
    return ok;
}

/////////////
// Private //
/////////////

bool Unifier::unification(TermNode & left, TermNode & right)
{
    bool done = false;
    bool error = false;
    bool ok;
    SyntaxNode * variable;
    SyntaxNode * data;
    pair<SyntaxNode *, SyntaxNode *> * fdp;
    int errorType = 0;
    
    while (!done && !error) {
        fdp = firstDiffPair(left, right);
        if (fdp == 0) {
            done = true;
        } else if (TermNode::isVariable(fdp->first)) {
            variable = fdp->first;
            data = fdp->second;
            error = data->occur_check(variable);
            if (!error) {
                left.replace(variable, data);
                right.replace(variable, data);
                pairs.push_back(fdp);
            } else {
                errorType = 1;
            }
        } else if (TermNode::isVariable(fdp->second)) {
            variable = fdp->second;
            data = fdp->first;
            error = data->occur_check(variable);
            if (!error) {
                left.replace(variable, data);
                right.replace(variable, data);
                pairs.push_back(fdp);
            } else {
                errorType = 1;
            }
        } else {
            error = true;
            errorType = 2;
        }
    }
    
    ok = (!error && done);
    if (error) {
        showErrorType(errorType);
        left.printNode();
        cout << " != ";
        right.printNode();
        cout << endl;
        if (errorType == 2) {
            cout << "Last FDP: (";
            fdp->first->printNode();
            cout << ", ";
            fdp->second->printNode();
            cout << ") did not contain a variable." << endl;
        }
    } else {
        showPairs(pairs);
    }
    cleanPairs(pairs);
    
    return ok;
}

pair<SyntaxNode *, SyntaxNode *> * Unifier::firstDiffPair(TermListNode * left, TermListNode * right)
{
    TermListNode * iLeft;
    TermListNode * iRight;
    bool found = false;
    pair<SyntaxNode *, SyntaxNode *> * p;
    
    iLeft = left;
    iRight = right;
    while (iLeft != 0 && iRight != 0 && !found) {
        p = firstDiffPair(iLeft->term(), iRight->term());
        if (p != 0) {
            found = true;
        } else {
            iLeft = iLeft->next();
            iRight = iRight->next();
        }
    }
    
    return p;
}

pair<SyntaxNode *, SyntaxNode *> * Unifier::firstDiffPair(TermNode & left, TermNode & right)
{
    SyntaxNode * leftData = &left.data();
    SyntaxNode * rightData = &right.data();
    FormulaNode * leftF;
    FormulaNode * rightF;
    TermListNode * leftTerms;
    TermListNode * rightTerms;
    
    if (TermNode::isFormula(leftData) != 0 && TermNode::isFormula(rightData) != 0) {
        leftF = dynamic_cast<FormulaNode *>(leftData);
        rightF = dynamic_cast<FormulaNode *>(rightData);
        if (!leftF->symbol().equals(&rightF->symbol())) {
            return new pair<SyntaxNode *, SyntaxNode *>(leftF, rightF);
        } else if (leftF->arity() != rightF->arity()) {
            return new pair<SyntaxNode *, SyntaxNode *>(leftF, rightF);
        } else {
            return firstDiffPair(leftF->terms(), rightF->terms());
        }
    } else if (!leftData->equals(rightData)) {
        return new pair<SyntaxNode *, SyntaxNode *>(leftData, rightData);
    } else {
        return 0;
    }
}

///////////////
// Functions //
///////////////

void cleanPairs(vector<pair<SyntaxNode *, SyntaxNode *> *> & pairs)
{
    unsigned size = pairs.size();
    
    for (unsigned i = 0; i < size; i++) {
        if (TermNode::isVariable(pairs[i]->first)) {
            delete pairs[i]->first;
        } else {
            delete pairs[i]->second;
        }
        delete pairs[i];
        pairs[i] = 0;
    }
    pairs.clear();
}

void showPairs(vector<pair<SyntaxNode *, SyntaxNode *> *> & pairs)
{
    unsigned size = pairs.size();
    
    for (unsigned i = 0; i < size; i++) {
        if (TermNode::isVariable(pairs[i]->first)) {
            pairs[i]->first->printNode();
            cout << " = ";
            pairs[i]->second->printNode();
        } else {
            pairs[i]->second->printNode();
            cout << " = ";
            pairs[i]->first->printNode();
        }
        cout << endl;
    }
}

void showErrorType(int type)
{
    switch (type) {
    case 1:
        cout << "Occur check error!" << endl;
        break;
    case 2:
        cout << "Terms can't be unified!" << endl;
        break;
    }
}

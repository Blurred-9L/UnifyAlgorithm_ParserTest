#ifndef ABSTRACT_AUTOMATA_H
#define ABSTRACT_AUTOMATA_H

#include <string>
using std::string;

/**
 *  @class  AbstractAutomata
 */
class AbstractAutomata {
protected:
    ///
    int ** transitions;
    ///
    unsigned nStates_;
    ///
    unsigned nInputs_;
    ///
    unsigned nTerminalStates_;

public:
    ///
    AbstractAutomata();
    ///
    virtual ~AbstractAutomata();
    ///
    bool loadMatrix(const char * filename);
    ///
    unsigned nStates() const;
    ///
    unsigned nInputs() const;
    ///
    unsigned nTerminalStates() const;
    ///
    virtual int nextState(int state, char input) const = 0;
    ///
    virtual bool isAcceptState(int state) const = 0;
    ///
    virtual bool includeNextChar(int state, const string & line, int charIdx) const = 0;
    ///
    virtual int getTokenType(int state) = 0;
};

#endif /// NOT ABSTRACT_AUTOMATA_H

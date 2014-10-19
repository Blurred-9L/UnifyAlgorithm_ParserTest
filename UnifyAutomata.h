#ifndef UNIFY_AUTOMATA_H
#define UNIFY_AUTOMATA_H

#include "AbstractAutomata.h"

/**
 *  @class  UnifyAutomata
 */
class UnifyAutomata : public AbstractAutomata {
public:
    /**
     *  @enum   InputType
     */
    enum InputType {
        MIN_LETTER,
        CAP_LETTER,
        DIGIT,
        UNDERSCORE,
        POINT,
        L_PAR,
        R_PAR,
        COMMA,
        EQUALS,
        WHITESPACE
    };
    
    /**
     *  @enum   TokenType
     */
    enum TokenType {
        VARIABLE,
        SYMBOL,
        INT_CONST,
        FLOAT_CONST,
        PARENTHESIS_L,
        PARENTHESIS_R,
        COMMA_TOKEN,
        UNIFIER,
        END_OF_INPUT
    };
    
    ///
    UnifyAutomata();
    ///
    virtual ~UnifyAutomata();
    ///
    virtual int nextState(int state, char input) const;
    ///
    virtual bool isAcceptState(int state) const;
    ///
    virtual bool includeNextChar(int state, const string & line, int charIdx) const;
    ///
    virtual int getTokenType(int state);
};

#endif /// NOT UNIFY_AUTOMATA_H

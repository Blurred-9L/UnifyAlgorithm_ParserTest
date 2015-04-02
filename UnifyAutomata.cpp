#include "UnifyAutomata.h"

#include <cctype>
#include <algorithm>
using std::binary_search;

UnifyAutomata::UnifyAutomata(const char * filename) :
    AbstractAutomata(filename)
{
}

UnifyAutomata::~UnifyAutomata()
{
}

int UnifyAutomata::nextState(int state, char input) const
{
    int nextState = -1;
    
    switch (input) {
    case '_':
        nextState = transitions[state][UNDERSCORE];
        break;
    case '(':
        nextState = transitions[state][L_PAR];
        break;
    case ')':
        nextState = transitions[state][R_PAR];
        break;
    case '=':
        nextState = transitions[state][EQUALS];
        break;
    case '.':
        nextState = transitions[state][POINT];
        break;
    case ',':
        nextState = transitions[state][COMMA];
        break;
    default:
        if (isupper(input)) {
            nextState = transitions[state][CAP_LETTER];
        } else if (islower(input)) {
            nextState = transitions[state][MIN_LETTER];
        } else if (isdigit(input)) {
            nextState = transitions[state][DIGIT];
        } else if (isspace(input)) {
            nextState = transitions[state][WHITESPACE];
        }
        break;
    }
    
    return nextState;
}

bool UnifyAutomata::isAcceptState(int state) const
{
    int acceptedStates[] = {1, 2, 3, 5, 6, 7, 8, 9};
    
    return binary_search(acceptedStates, acceptedStates + nTerminalStates_, state);
}

int UnifyAutomata::getTokenType(int state)
{
    int type = -1;
    
    switch (state) {
    case 1:
        type = VARIABLE;
        break;
    case 2:
        type = SYMBOL;
        break;
    case 3:
        type = INT_CONST;
        break;
    case 5:
        type = FLOAT_CONST;
        break;
    case 6:
        type = PARENTHESIS_L;
        break;
    case 7:
        type = PARENTHESIS_R;
        break;
    case 8:
        type = COMMA_TOKEN;
        break;
    case 9:
        type = UNIFIER;
        break;
    }
    
    return type;
}

const char * UnifyAutomata::getTokenName(int tokenType)
{
    const char * names[] = {"Variable", "Symbol", "Integer", "Float", "Left Parenthesis", "Right Parenthesis",
                            "Comma", "Unify Operator", "EOI"};
                            
    return names[tokenType];
}

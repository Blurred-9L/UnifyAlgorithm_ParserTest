/**
 *  @author Blurred-9L
 *  @file   Tokenizer.cpp
 */

#include "Tokenizer.h"
#include "AbstractAutomata.h"
#include "KeywordSet.h"

#include "Token.h"
#include "LineFileReader.h"

/**
 *  @details    Constructs a Tokenizer object. The object constructed
 *              does not have a set automata, keyword set or line reader,
 *              so the user should remember to set them before calling
 *              getToken().
 */
Tokenizer::Tokenizer() :
    automata_(0), keywords_(0), lineReader_(0), line_(), charIdx(-1),
    tokenStartIndex(-1)
{
}

/**
 *  @details    Constructs a Tokenizer object with the given automata,
 *              keyword set and line reader.
 *
 *  @param[in]  automata        The automata to use. Should be dynamically
 *                              allocated.
 *  @param[in]  keywords        The keyword set to use. Should be dynamically
 *                              allocated.
 *  @param[in]  lineReader      The lineReader set to use. Should be dynamically
 *                              allocated.
 */
Tokenizer::Tokenizer(AbstractAutomata * automata, KeywordSet * keywords,
                     LineFileReader * lineReader) :
    automata_(automata), keywords_(keywords), lineReader_(lineReader),
    line_(), charIdx(-1)
{
}

/**
 *  @details    Destroys the Tokenizer object.
 */
Tokenizer::~Tokenizer()
{
    if (automata_ != 0) {
        delete automata_;
    }
    if (keywords_ != 0) {
        delete keywords_;
    }
    if (lineReader_ != 0) {
        delete lineReader_;
    }
}

/**
 *  @details    Gets the automata attribute from the Tokenizer.
 *
 *  @return     A constant reference to the automata attribute.
 */
const AbstractAutomata & Tokenizer::automata() const
{
    return *automata_;
}

/**
 *  @details    Gets the automata attribute from the Tokenizer.
 *
 *  @return     A reference to the automata attribute.
 */
AbstractAutomata & Tokenizer::automata()
{
    return *automata_;
}

/**
 *  @details    Gets the keywords attribute from the Tokenizer.
 *
 *  @return     A constant reference to the keywords attribute.
 */
const KeywordSet & Tokenizer::keywords() const
{
    return *keywords_;
}

/**
 *  @details    Gets the keywords attribute from the Tokenizer.
 *
 *  @return     A reference to the keywords attribute.
 */
KeywordSet & Tokenizer::keywords()
{
    return *keywords_;
}

/**
 *  @details    Gets the lineReader attribute from the Tokenizer.
 *
 *  @return     A constant pointer to the lineReader attribute.
 */
const LineFileReader * Tokenizer::lineReader() const
{
    return lineReader_;
}

/**
 *  @details    Gets the lineReader attribute from the Tokenizer.
 *
 *  @return     A reference pointer to the lineReader attribute.
 */
LineFileReader * Tokenizer::lineReader()
{
    return lineReader_;
}

/**
 *  @details    Sets the automata to be used when tokenizing
 *              the given input string. The automata passed
 *              should be dynamically allocated. If a previous
 *              automata had been set, it will be deleted.
 *
 *  @param[in]  automata        The automata to use.
 */
void Tokenizer::setAutomata(AbstractAutomata * automata)
{
    if (automata != 0) {
        if (automata_ != 0) {
            delete automata_;
        }
        automata_ = automata;
    }
}

/**
 *  @details    Sets the keyword set to be used when tokenizing
 *              the given input string. The keyword set passed
 *              should have been dynamically allocated. If a
 *              previous keyword set had been set, it will be
 *              deleted.
 *
 *  @param[in]  keywords        The keyword set to use.
 */
void Tokenizer::setKeywords(KeywordSet * keywords)
{
    if (keywords != 0) {
        if (keywords_ != 0) {
            delete keywords_;
        }
        keywords_ = keywords;
    }
}

/**
 *  @details    Sets the line reader to be used when this tokenizer
 *              consumes a line. The lineReader passed should have
 *              been dynamically allocated. If a previous line reader
 *              had been set, it will be deleted. Since the line reader
 *              is not strictly necessary for the Tokenizer to
 *              function properly, it can be set to a 0 value.
 *
 *  @param[in]  lineReader      The lineReader to use.
 */
void Tokenizer::setLineReader(LineFileReader * lineReader)
{
    if (lineReader_ != 0) {
        delete lineReader_;
    }
    lineReader_ = lineReader;
}

/**
 *  @details    Sets the line to use when tokenizing and also
 *              resets the index used when iterating over it.
 *
 *  @param[in]  line            The line to be tokenized.
 */
void Tokenizer::setLine(const string & line)
{
    line_ = line;
    charIdx = 0;
}

/**
 *  @details    Gets the next token from the given input string.
 *              The token returned will be dynamically allocated,
 *              so one should remember to deallocate it later.
 *
 *  @return     The token found or 0 if no more tokens can be
 *              extracted.
 */
Token * Tokenizer::getToken()
{
    Token * token = 0;
    string symbol;
    int lastState;
    
    if (lineReader_ != 0) {
        while (line_.empty() && lineReader_->hasNext()) {
            lineReader_->sendNextLine(*this);
        }
    }
    
    if ((charIdx < line_.length()) && (automata_ != 0) && (keywords_ != 0)) {
        lastState = getTokenString(symbol);
        if (keywords_->isKeyword(symbol)) {
            token = new Token(keywords_->getKeywordId(symbol), symbol);
        } else if (automata_->isAcceptState(lastState)) {
            token = new Token(automata_->getTokenType(lastState), symbol);
        }
    }
    
    return token;
}

/////////////
// Private //
/////////////

/**
 *  @details    Algorithm used to build the substring of the
 *              input string to be included on the next token.
 *
 *  @param[out]  symbol          The string on which to copy the token's symbol.
 *
 *  @return     Returns the state at which the algorithm stopped. If
 *              an error ocurred, -1 is returned. If the algorithm 
 *              stopped because the end of the string was reached
 *              before a full token was found, the last state is
 *              returned.
 */
int Tokenizer::getTokenString(string & symbol)
{
    int state = 0;
    unsigned lineLength = line_.length();
    bool done = false;
    bool error = false;
    bool gotFirstChar = false;
    
    while ((!done) && (!error) && (charIdx < lineLength)) {
        state = automata_->nextState(state, line_[charIdx]);
        if (state > 0) {
            if (!gotFirstChar) {
                gotFirstChar = true;
                tokenStartIndex = charIdx;
            }
            symbol.push_back(line_[charIdx]);
            if (automata_->isAcceptState(state)) {
                if (!automata_->includeNextChar(state, line_, charIdx)) {
                    done = true;
                }
            }
        } else if (state < 0) {
            error = true;
        }
        charIdx++;
    }
    
    if (error) {
        /// No implementation yet!
    } else if (!done) {
        /// no implementation yet!
    }
    
    return state;
}

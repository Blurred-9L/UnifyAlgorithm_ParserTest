#ifndef KEYWORD_SET_H
#define KEYWORD_SET_H

#include <string>
using std::string;

/**
 *  @class  KeywordSet
 */
class KeywordSet {
public:
    ///
    static const int INVALID_ID;

    ///
    KeywordSet();
    ///
    virtual ~KeywordSet();
    ///
    virtual bool isKeyword(const string & symbol) const;
    ///
    virtual int getKeywordId(const string & symbol) const;
};

#endif /// NOT KEYWORD_SET_H

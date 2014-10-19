#ifndef TOKEN_H
#define TOKEN_H

#include <string>
using std::string;

/**
 *  @class  Token
 */
class Token {
private:
    ///
    int type_;
    ///
    string symbol_;
    
public:
    ///
    Token(int type, const string & symbol);
    ///
    int type() const;
    ///
    const string & symbol() const;
    ///
    string & symbol();
    ///
    void setType(int type);
    ///
    void setSymbol(const string & symbol);
};

#endif /// NOT TOKEN_H

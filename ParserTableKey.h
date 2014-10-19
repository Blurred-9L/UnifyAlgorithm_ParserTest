#ifndef PARSER_TABLE_KEY_H
#define PARSER_TABLE_KEY_H

/**
 *  @class  ParserTableKey
 */
class ParserTableKey {
private:
    ///
    int state_;
    ///
    int tokenType_;

public:
    ///
    ParserTableKey();
    ///
    ParserTableKey(int state, int tokenType);
    ///
    int state() const;
    ///
    int tokenType() const;
    ///
    void setState(int state);
    ///
    void setTokenType(int tokenType);
};

#endif /// NOT PARSER_TABLE_KEY_H

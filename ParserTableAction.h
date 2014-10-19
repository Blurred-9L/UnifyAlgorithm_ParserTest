#ifndef PARSER_TABLE_ACTION_H
#define PARSER_TABLE_ACTION_H

/**
 *  @class  ParserTableAction
 */
class ParserTableAction {
private:
    ///
    int type_;
    ///
    int value_;

public:
    ///
    ParserTableAction();
    ///
    ParserTableAction(int type, int value);
    ///
    int type() const;
    ///
    int value() const;
    ///
    void setType(int type);
    ///
    void setValue(int value);
};

#endif /// NOT PARSER_TABLE_ACTION_H

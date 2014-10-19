#ifndef PARSER_TABLE_H
#define PARSER_TABLE_H

class ParserTableKey;
class ParserTableAction;

/**
 *  @class  ParserTable
 */
class ParserTable {
protected:
    ///
    virtual void fillTable() = 0;
    
public:
    /**
     *  @enum   ActionType
     */
    enum ActionType {
        SHIFT,
        REDUCE,
        CHANGE,
        ACCEPT
    };

    ///
    ParserTable();
    ///
    virtual bool hasKey(const ParserTableKey & key) const = 0;
    ///
    virtual ParserTableAction * getAction(const ParserTableKey & key) const = 0;
};

#endif /// NOT PARSER_TABLE_H

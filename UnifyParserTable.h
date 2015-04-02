#ifndef UNIFY_PARSER_TABLE_H
#define UNIFY_PARSER_TABLE_H

#include "BlurParser/Parser/ParserTable.h"

#include <map>
using std::map;
using std::pair;

/**
 *  @class  UnifyParserTable
 */
class UnifyParserTable : public ParserTable {
private:
    ///
    map< pair<int, int>, pair<int, int> > lrTable;
    
protected:
    ///
    virtual void fillTable();
    
public:
    /**
     *  @enum   NonTerminalType
     */
    enum NonTerminalType {
        UNIFICATION = 1000,
        TERM,
        ATOMIC_FORMULA,
        TERM_LIST
    };

    ///
    UnifyParserTable();
    ///
    virtual bool hasKey(const ParserTableKey & key) const;
    ///
    virtual ParserTableAction * getAction(const ParserTableKey & key) const;
    ///
    virtual int getRuleLength(int ruleNumber);
    ///
    virtual int getNonTerminalType(int ruleNumber);
};

#endif /// UNIFY_PARSER_TABLE_H

#include "UnifyParserTable.h"
#include "BlurParser/Parser/ParserTableKey.h"
#include "BlurParser/Parser/ParserTableAction.h"
#include "UnifyAutomata.h"

using std::make_pair;

UnifyParserTable::UnifyParserTable() :
    ParserTable()
{
    fillTable();
}

bool UnifyParserTable::hasKey(const ParserTableKey & key) const
{
    return lrTable.count(make_pair(key.state(), key.tokenType()));
}

ParserTableAction * UnifyParserTable::getAction(const ParserTableKey & key) const
{
    map< pair<int, int>, pair<int, int> >::const_iterator value;
    pair<int, int> keyPair = make_pair(key.state(), key.tokenType());
    ParserTableAction * action = 0;
    
    value = lrTable.find(keyPair);
    if (value != lrTable.end()) {
        action = new ParserTableAction(value->second.first, value->second.second);
    }
    
    return action;
}

int UnifyParserTable::getRuleLength(int ruleNumber)
{
    int popTimes[] = {0, 3, 1, 1, 1, 1, 1, 3, 4, 1, 3};
    
    return popTimes[ruleNumber];
}

int UnifyParserTable::getNonTerminalType(int ruleNumber)
{
    int nonTermType;
    
    switch (ruleNumber) {
        case 1:
            nonTermType = UnifyParserTable::UNIFICATION;
            break;
        case 2: case 3: case 4: case 5: case 6:
            nonTermType = UnifyParserTable::TERM;
            break;
        case 7: case 8:
            nonTermType = UnifyParserTable::ATOMIC_FORMULA;
            break;
        case 9: case 10:
            nonTermType = UnifyParserTable::TERM_LIST;
            break;
    }
    
    return nonTermType;
}

///////////////
// Protected //
///////////////

void UnifyParserTable::fillTable()
{
    lrTable.insert(make_pair(make_pair(0, UnifyAutomata::VARIABLE), make_pair(ParserTable::SHIFT, 3)));
    lrTable.insert(make_pair(make_pair(0, UnifyAutomata::SYMBOL), make_pair(ParserTable::SHIFT, 4)));
    lrTable.insert(make_pair(make_pair(0, UnifyAutomata::INT_CONST), make_pair(ParserTable::SHIFT, 5)));
    lrTable.insert(make_pair(make_pair(0, UnifyAutomata::FLOAT_CONST), make_pair(ParserTable::SHIFT, 6)));
    lrTable.insert(make_pair(make_pair(0, UNIFICATION), make_pair(ParserTable::CHANGE, 1)));
    lrTable.insert(make_pair(make_pair(0, TERM), make_pair(ParserTable::CHANGE, 2)));
    lrTable.insert(make_pair(make_pair(0, ATOMIC_FORMULA), make_pair(ParserTable::CHANGE, 7)));
    
    lrTable.insert(make_pair(make_pair(1, UnifyAutomata::END_OF_INPUT), make_pair(ParserTable::ACCEPT, 0)));
    
    lrTable.insert(make_pair(make_pair(2, UnifyAutomata::UNIFIER), make_pair(ParserTable::SHIFT, 8)));
    
    lrTable.insert(make_pair(make_pair(3, UnifyAutomata::UNIFIER), make_pair(ParserTable::REDUCE, 2)));
    lrTable.insert(make_pair(make_pair(3, UnifyAutomata::PARENTHESIS_R), make_pair(ParserTable::REDUCE, 2)));
    lrTable.insert(make_pair(make_pair(3, UnifyAutomata::COMMA_TOKEN), make_pair(ParserTable::REDUCE, 2)));
    lrTable.insert(make_pair(make_pair(3, UnifyAutomata::END_OF_INPUT), make_pair(ParserTable::REDUCE, 2)));
    
    lrTable.insert(make_pair(make_pair(4, UnifyAutomata::UNIFIER), make_pair(ParserTable::REDUCE, 3)));
    lrTable.insert(make_pair(make_pair(4, UnifyAutomata::PARENTHESIS_L), make_pair(ParserTable::SHIFT, 9)));
    lrTable.insert(make_pair(make_pair(4, UnifyAutomata::PARENTHESIS_R), make_pair(ParserTable::REDUCE, 3)));
    lrTable.insert(make_pair(make_pair(4 ,UnifyAutomata::COMMA_TOKEN), make_pair(ParserTable::REDUCE, 3)));
    lrTable.insert(make_pair(make_pair(4, UnifyAutomata::END_OF_INPUT), make_pair(ParserTable::REDUCE, 3)));
    
    lrTable.insert(make_pair(make_pair(5, UnifyAutomata::UNIFIER), make_pair(ParserTable::REDUCE, 4)));
    lrTable.insert(make_pair(make_pair(5, UnifyAutomata::PARENTHESIS_R), make_pair(ParserTable::REDUCE, 4)));
    lrTable.insert(make_pair(make_pair(5, UnifyAutomata::COMMA_TOKEN), make_pair(ParserTable::REDUCE, 4)));
    lrTable.insert(make_pair(make_pair(5, UnifyAutomata::END_OF_INPUT), make_pair(ParserTable::REDUCE, 4)));
    
    lrTable.insert(make_pair(make_pair(6, UnifyAutomata::UNIFIER), make_pair(ParserTable::REDUCE, 5)));
    lrTable.insert(make_pair(make_pair(6, UnifyAutomata::PARENTHESIS_R), make_pair(ParserTable::REDUCE, 5)));
    lrTable.insert(make_pair(make_pair(6, UnifyAutomata::COMMA_TOKEN), make_pair(ParserTable::REDUCE, 5)));
    lrTable.insert(make_pair(make_pair(6, UnifyAutomata::END_OF_INPUT), make_pair(ParserTable::REDUCE, 5)));
    
    lrTable.insert(make_pair(make_pair(7, UnifyAutomata::UNIFIER), make_pair(ParserTable::REDUCE, 6)));
    lrTable.insert(make_pair(make_pair(7, UnifyAutomata::PARENTHESIS_R), make_pair(ParserTable::REDUCE, 6)));
    lrTable.insert(make_pair(make_pair(7, UnifyAutomata::COMMA_TOKEN), make_pair(ParserTable::REDUCE, 6)));
    lrTable.insert(make_pair(make_pair(7, UnifyAutomata::END_OF_INPUT), make_pair(ParserTable::REDUCE, 6)));
    
    lrTable.insert(make_pair(make_pair(8, UnifyAutomata::VARIABLE), make_pair(ParserTable::SHIFT, 3)));
    lrTable.insert(make_pair(make_pair(8, UnifyAutomata::SYMBOL), make_pair(ParserTable::SHIFT, 4)));
    lrTable.insert(make_pair(make_pair(8, UnifyAutomata::INT_CONST), make_pair(ParserTable::SHIFT, 5)));
    lrTable.insert(make_pair(make_pair(8, UnifyAutomata::FLOAT_CONST), make_pair(ParserTable::SHIFT, 6)));
    lrTable.insert(make_pair(make_pair(8, UnifyParserTable::TERM), make_pair(ParserTable::CHANGE, 10)));
    lrTable.insert(make_pair(make_pair(8, UnifyParserTable::ATOMIC_FORMULA), make_pair(ParserTable::CHANGE, 7)));
    
    lrTable.insert(make_pair(make_pair(9, UnifyAutomata::VARIABLE), make_pair(ParserTable::SHIFT, 3)));
    lrTable.insert(make_pair(make_pair(9, UnifyAutomata::SYMBOL), make_pair(ParserTable::SHIFT, 4)));
    lrTable.insert(make_pair(make_pair(9, UnifyAutomata::INT_CONST), make_pair(ParserTable::SHIFT, 5)));
    lrTable.insert(make_pair(make_pair(9, UnifyAutomata::FLOAT_CONST), make_pair(ParserTable::SHIFT, 6)));
    lrTable.insert(make_pair(make_pair(9, UnifyAutomata::PARENTHESIS_R), make_pair(ParserTable::REDUCE, 11)));
    lrTable.insert(make_pair(make_pair(9, UnifyParserTable::TERM), make_pair(ParserTable::CHANGE, 13)));
    lrTable.insert(make_pair(make_pair(9, UnifyParserTable::ATOMIC_FORMULA), make_pair(ParserTable::CHANGE, 7)));
    lrTable.insert(make_pair(make_pair(9, UnifyParserTable::TERM_LIST), make_pair(ParserTable::CHANGE, 12)));
    
    lrTable.insert(make_pair(make_pair(10, UnifyAutomata::END_OF_INPUT), make_pair(ParserTable::REDUCE, 1)));
    
    lrTable.insert(make_pair(make_pair(11, UnifyAutomata::UNIFIER), make_pair(ParserTable::REDUCE, 7)));
    lrTable.insert(make_pair(make_pair(11, UnifyAutomata::PARENTHESIS_R), make_pair(ParserTable::REDUCE, 7)));
    lrTable.insert(make_pair(make_pair(11, UnifyAutomata::COMMA_TOKEN), make_pair(ParserTable::REDUCE, 7)));
    lrTable.insert(make_pair(make_pair(11, UnifyAutomata::END_OF_INPUT), make_pair(ParserTable::REDUCE, 7)));
    
    lrTable.insert(make_pair(make_pair(12, UnifyAutomata::PARENTHESIS_R), make_pair(ParserTable::SHIFT, 14)));

    lrTable.insert(make_pair(make_pair(13, UnifyAutomata::PARENTHESIS_R), make_pair(ParserTable::REDUCE, 9)));
    lrTable.insert(make_pair(make_pair(13, UnifyAutomata::COMMA_TOKEN), make_pair(ParserTable::SHIFT, 15)));
    
    lrTable.insert(make_pair(make_pair(14, UnifyAutomata::UNIFIER), make_pair(ParserTable::REDUCE, 8)));
    lrTable.insert(make_pair(make_pair(14, UnifyAutomata::PARENTHESIS_R), make_pair(ParserTable::REDUCE, 8)));
    lrTable.insert(make_pair(make_pair(14, UnifyAutomata::COMMA_TOKEN), make_pair(ParserTable::REDUCE, 8)));
    lrTable.insert(make_pair(make_pair(14, UnifyAutomata::END_OF_INPUT), make_pair(ParserTable::REDUCE, 8)));    
    
    lrTable.insert(make_pair(make_pair(15, UnifyAutomata::VARIABLE), make_pair(ParserTable::SHIFT, 3)));
    lrTable.insert(make_pair(make_pair(15, UnifyAutomata::SYMBOL), make_pair(ParserTable::SHIFT, 4)));
    lrTable.insert(make_pair(make_pair(15, UnifyAutomata::INT_CONST), make_pair(ParserTable::SHIFT, 5)));
    lrTable.insert(make_pair(make_pair(15, UnifyAutomata::FLOAT_CONST), make_pair(ParserTable::SHIFT, 6)));
    lrTable.insert(make_pair(make_pair(15, UnifyParserTable::TERM), make_pair(ParserTable::CHANGE, 13)));
    lrTable.insert(make_pair(make_pair(15, UnifyParserTable::ATOMIC_FORMULA), make_pair(ParserTable::CHANGE, 7)));
    lrTable.insert(make_pair(make_pair(15, UnifyParserTable::TERM_LIST), make_pair(ParserTable::CHANGE, 16)));
    
    lrTable.insert(make_pair(make_pair(16, UnifyAutomata::PARENTHESIS_R), make_pair(ParserTable::REDUCE, 10)));
}

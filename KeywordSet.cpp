#include "KeywordSet.h"

const int KeywordSet::INVALID_ID = -1;

KeywordSet::KeywordSet()
{
}

KeywordSet::~KeywordSet()
{
}

bool KeywordSet::isKeyword(const string & symbol) const
{
    return false;
}

int KeywordSet::getKeywordId(const string & symbol) const
{
    return INVALID_ID;
}

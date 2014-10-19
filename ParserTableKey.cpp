#include "ParserTableKey.h"

ParserTableKey::ParserTableKey() :
    state_(-1), tokenType_(-1)
{
}

ParserTableKey::ParserTableKey(int state, int tokenType) :
    state_(state), tokenType_(tokenType)
{
}

int ParserTableKey::state() const
{
    return state_;
}

int ParserTableKey::tokenType() const
{
    return tokenType_;
}

void ParserTableKey::setState(int state)
{
    state_ = state;
}

void ParserTableKey::setTokenType(int tokenType)
{
    tokenType_ = tokenType;
}

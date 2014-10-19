#include "Token.h"

Token::Token(int type, const string & symbol) :
    type_(type), symbol_(symbol)
{
}

int Token::type() const
{
    return type_;
}

const string & Token::symbol() const
{
    return symbol_;
}

string & Token::symbol()
{
    return symbol_;
}

void Token::setType(int type)
{
    type_ = type;
}

void Token::setSymbol(const string & symbol)
{
    symbol_ = symbol;
}

#include "ParserTableAction.h"

ParserTableAction::ParserTableAction() :
    type_(-1), value_(-1)
{
}

ParserTableAction::ParserTableAction(int type, int value) :
    type_(type), value_(value)
{
}

int ParserTableAction::type() const
{
    return type_;
}

int ParserTableAction::value() const
{
    return value_;
}

void ParserTableAction::setType(int type)
{
    type_ = type;
}

void ParserTableAction::setValue(int value)
{
    value_ = value;
}

//filename: Symbol.cpp
//author: Rolf

#include "Symbol.h"

Symbol::Symbol(const string& _name, Identifier::IdentifierType type, const string& _description /*= ""*/)
	: Component(_name, type, _description), isConstSymbol(false), visibility(PUBLIC)
{

}


void Symbol::setConst(bool c) {
	isConstSymbol = c;
}

void Symbol::setVisibility(Visibility v) {
	visibility = v;
}

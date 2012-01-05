//filename: Parameter.cpp
//author: Rolf
//revision by: Mathieu Morainville

#include "Parameter.h"

Parameter::Parameter(const string& _type, const string& _name, const string& _description /*= ""*/)
	: identifier(_name, Identifier::VARIABLE, _description), type(_type)
{}

Parameter::~Parameter() {}

void Parameter::setDescription(const string& _description) {
	identifier.setDescription(_description);
}

bool Parameter::operator==(const Parameter& p) const {
	//eigentlich Identifier vergleichen
	return (getName() == p.getName() && getType() == p.getType());
}

bool Parameter::operator!=(const Parameter& p) const {
	return ! (*this == p);
}

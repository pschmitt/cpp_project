//filename: Parameter.cpp
//author: Rolf

#include "Parameter.h"

Parameter::Parameter(const string& _type, const string& _name, const string& _description /*= ""*/)
	: identifier(_name, Identifier::VARIABLE, _description), type(_type)
{

}

Parameter::~Parameter() {}

void Parameter::setDescription(const string& _description) {
	identifier.setDescription(_description);
}

/* type ist const
void Parameter::setType(const string& _type) {
	if (_type.empty()) {
		//exception
	} else {
		type = _type;
	}
}
*/

bool Parameter::operator==(const Parameter& p) const {
	//eigentlich Identifier vergleichen
	return (getName() == p.getName() && getType() == p.getType());//ohne description
}

bool Parameter::operator!=(const Parameter& p) const {
	return ! (*this == p);
}

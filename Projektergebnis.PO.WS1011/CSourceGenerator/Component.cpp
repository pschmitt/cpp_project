//filename: Component.cpp
//author: Rolf

#include "Component.h"

Component::Component(const string& _name, Identifier::IdentifierType type, const string& _description /* = "" */)
	: identifier(_name, type, _description)
{

}

/* Identifer ist const
void Component::setDescription(const string& _description) {	
	if (_description.empty()) {
		//exception
	} else {
		identifier.setDescription(_description);
	}
	
}
*/

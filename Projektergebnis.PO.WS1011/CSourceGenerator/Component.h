//filename: Component.h
//author: Rolf

#ifndef _COMPONENT_H_INCLUDED
#define _COMPONENT_H_INCLUDED

#include <string>
#include "Identifier.h"

using namespace std;

class Component {

	public:
		
		/* Funktionsdeklarationen */
		virtual ~Component() {};
		// fuer .c:
		virtual void writeDefinitionTo(ostream& out) const = 0;
		// fuer .h:
		virtual void writeDeclarationTo(ostream& out) const = 0;
	
		/* Getters */
		Identifier getIdentifier() const { return identifier; }//noetig ???
		string getName() const { return identifier.getName(); }
		string getDescription() const { return identifier.getDescription(); }
	
		/* Setters */
		//void setDescription(const string& _description); -> unnoetig, Identifer ist const, und das ist auch gut so [ausser bei Wiederverwendung :( ]

	protected:
		/* Component ist abstrakt */
		Component(const string& _name, Identifier::IdentifierType type, const string& _description = "");
	
	private:
		const Identifier identifier;
};

#endif //_COMPONENT_H_INCLUDED

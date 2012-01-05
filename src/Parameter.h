//filename: Parameter.h
//author: Rolf
//revision by: Mathieu Morainville

#ifndef _PARAMETER_H_INCLUDED
#define _PARAMETER_H_INCLUDED

#include <string>
#include "Identifier.h"

/*
Ein Parameter hat einen Namen und eine Beschreibung (-> Identifier).
Hinzu kommt der Typ.

In der Zukunft koennte man versuchen, die Parameter weiter zu spezialisieren.
D.h. Aufteilen und "normale Parameter" und Pointer, Referenzen, Funktionspointer.
*/

class Parameter {

	public:
		Parameter(const string& _type, const string& _name, const string& _description = "");
		virtual ~Parameter();
		
		/* Getters */
		string getType() const { return type; }
		string getName() const { return identifier.getName(); }
		string getDescription() const { return  identifier.getDescription(); }
		
		/* Setters */
		void setDescription(const string& _description);
		
		bool operator==(const Parameter& p) const;
		bool operator!=(const Parameter& p) const;

	private:
		Identifier identifier;
		const string type;

};

#endif //_PARAMETER_H_INCLUDED

//filename: Variable.h
// Author : Tenguemne Frantz

#ifndef _VARIABLE_H_INCLUDED_
#define _VARIABLE_H_INCLUDED_

#include "Object.h"
#include <string>

using namespace std;

class Variable: public Object{
	public:
	
		/*
		Variable(const string& name, Identifier::IdentifierType type, const string& typeObject, const string& value = "", 
		         Visibility visibility = Component::PUBLIC
		        );
				*/
		Variable(const string& name, const string& typeObject, const string& value = "", 
		 Visibility visibility = Component::PUBLIC
		);
		~Variable();
		void writeDefinitionTo (ostream& out) const;
		void writeDeclarationTo(ostream& out) const;
};
#endif //_VARIABLE_H_INCLUDED_
//filename: Variable.h
// Author : Tenguemne Frantz

#ifndef _VARIABLE_H_INCLUDED_
#define _VARIABLE_H_INCLUDED_

#include "Object.h"
#include <string>

using namespace std;

class Variable: public Object{
	public:
	
		Variable(const string& name, const string& typeObject, const string& value = "", 
		 Visibility visibility = Component::PUBLIC
		);
		~Variable();
		string writeDefinitionTo () const;
		string writeDeclarationTo() const;
};
#endif //_VARIABLE_H_INCLUDED_
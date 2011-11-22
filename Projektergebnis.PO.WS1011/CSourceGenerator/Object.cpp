// Filename Object.cpp
// author : Nicolas
#include "Object.h"
#include <string>
#include <iostream>

Object::Object(const string& _name, const string& _type) 
    : Symbol(_name, Identifier::VARIABLE), type(_type), value("")
{
}

Object::Object(const string& _name, const string& _type, const string& _value /*= ""*/)
	: Symbol(_name, Identifier::VARIABLE), type(_type), value(_value)
{
}

Object::Object(const string& _name, const string& _type, Visibility v)
	: Symbol(_name, Identifier::VARIABLE), type(_type)
{  
	setVisibility(v);
}


Object::Object(const string& _name, const string& _type, const string& _value, Visibility v)
    : Symbol (_name, Identifier::VARIABLE), type(_type), value(_value)
{  
 setVisibility(v);
}

void Object::writeDefinitionTo(ostream& out) const {
	if (isConst()) {
		out << "static const ";
	} else if (isPrivate()) {
		cout << "static " ;
	}
      out << type << " " << getName();
     if (!value.empty()) {
        out  << " = " << value;                  
     }
     out << ";"  << endl; 
       
}
		    
            
void Object::writeDeclarationTo(ostream& out) const {
	if ( ! isPrivate()) {
		if (isConst()) {
		out << "static const ";
		} else {
		out << "extern ";
		}
		out << type << " " << getName();
	    
	     out << ";" << endl;
	}
}
    

/*
bool Function::isConst() const 
{
	return _const;
}

bool Function::isStatic() const 
{
	return _static;
}
*/


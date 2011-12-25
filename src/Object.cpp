// Filename Object.cpp
// author : Frantz Tenguemne
#include "Object.h"
#include <string>

Object::Object(const string& name, Identifier::IdentifierType type, const string& typeObject, const string& value, 
			  Visibility visibility, bool isConst
			  )
: Component(name, type, visibility, isConst), typeObject(typeObject), value(value)
{

}

Object::~Object(){}

const string& Object::getValue() const{
	return value;
}
const string& Object::getTypeObject() const{
	return typeObject;
}
/*
utiliser la classe stringstream pour concatener le resultat au lieu de faire l'addition 
const string& Object::toString() const{
	string ausgabe("");
	if(!value.empty())
		return string("static " + typeObject + " " + getName() + " = " + value + ";" + endl);
	else
		return string("static " + typeObject + " " + getName() + ";" + endl); 
}
*/



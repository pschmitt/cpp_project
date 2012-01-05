//filename: enumeration.cpp
#include "enumeration.h"
Enumeration::Enumeration(const string& name, const string& _description): Component(name, Identifier::ENUM, Component::PUBLIC,false,_description)
{
}

void Enumeration::add(const string& name, const string& wert)
{
     string maj_name=Enumeration::toUpper(name);
     enumeration.insert( map<string, string>::value_type( maj_name, wert) );
}

string Enumeration::writeDeclarationTo() const 
{
    string returnString="typedef enum {";
    for(map<string, string>::const_iterator it = enumeration.begin(); it != enumeration.end(); ++it)
    {
		returnString +=" "+(*it).first+" = "+(*it).second+", ";
    }
	returnString+="} "+getName()+";";
	return returnString;
}

string Enumeration::writeDefinitionTo() const {
	return "noDefinition";
}


string Enumeration::toUpper (const string& str) {
	string myString(str);//schneller -> Kopierkonstruktor
	int len = myString.length();
	for (int i = 0; i < len; i++) {
		if (myString[i] >= 'a' && myString[i] <= 'z') {
			myString[i] = myString[i] + 'A' - 'a';		
		}
	}
	
	return myString;
}

/*virtual*/Enumeration::~Enumeration() {}

//filename: enumeration.cpp
#include "enumeration.h"
Enumeration::Enumeration(const string& name): Component(name, Identifier::ENUM)
{
}

void Enumeration::add(const string& name, const string& wert)
{
     string maj_name=Enumeration::toUpper(name);
     enumeration.insert( map<string, string>::value_type( maj_name, wert) );
}

void Enumeration::writeDeclarationTo(ostream& out) const 
{
    out << "typedef enum" << "\n" << "{\n";
    for(map<string, string>::const_iterator it = enumeration.begin(); it != enumeration.end(); ++it)
     {
        out << "\t" << (*it).first << "=" << (*it).second << "," << endl;       
     }
     out << "}" << getName() << ";";
}

void Enumeration::writeDefinitionTo(ostream& out) const {
	out << "typedef enum " << Component::getName() << endl;
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

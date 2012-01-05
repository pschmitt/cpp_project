//file name Structur.cpp
//author: Hicham & Gorlt

#include "Structur.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/*
  Konstruktur der Struktur hat name der struktur als parameter
 */
		
   Structur::Structur(const string& nameStructur) : Component(nameStructur, Identifier::STRUCT)
   {
      // this->name = nameStructur;
    }

/*
   diese Funktion ermoeglicht das hinzufuegen von neue componenten des Struktur.
   sie hat zwei parametr von type String name ist name der component und type ist type der component
    
 */
     void Structur::addComponent(const string& name, const string& type)
     {
        structurComponent.insert( map<string, string>::value_type( name, type) );
      }

   
   
   /*
   Die Methode toString schreibt eine structur von der angegebne name und angegebne componenten.
 */
string Structur::writeDeclarationTo() const {
     string returnString="struct {\n";
    for(map<string, string>::const_iterator it = structurComponent.begin(); it != structurComponent.end(); ++it)
    {
		returnString +=" "+(*it).second+" "+(*it).first+"; \n";
    }
	returnString+="} "+getName()+";";
	return returnString; 
}

string Structur::writeDefinitionTo() const {
	return "noDefinition";
}


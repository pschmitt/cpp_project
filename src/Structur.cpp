//file name Structur.cpp
//author: Hicham

#include "Structur.h"
#include<iostream>
#include<string>
#include <sstream>

using namespace std;

/*
  Konstruktur der Struktur hat name der struktur als parameter
 */
									   //eigentlich Identifier::STRUCT	
   Structur::Structur(const string& nameStructur) : Component(nameStructur, Identifier::TYPE)
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
void Structur::writeDeclarationTo(ostream& out) const {
out << "typedef enum" << "\n" << "{\n";
    for(map<string, string>::const_iterator it = structurComponent.begin(); it != structurComponent.end(); ++it)
     {
        out << "\t" << (*it).second<< " " << (*it).first <<"," << endl;       
     }
     out<<"}"<< getName() <<";";
    //cout << fichier.str() << endl;   
}  

void Structur::writeDefinitionTo(ostream& out) const {
	out << "rien " << endl;
}






//author: Hicham

#include "Enumeration.h"
#include<iostream>
#include<string>
#include <sstream>

using namespace std;

/*
   Enumeration Konstruktur 
 */									//eigentlich Identifier::ENUM	
 Enumeration::Enumeration(const string& nameEnumator) : Component(nameEnumator, Identifier::TYPE)
{
  // this->name = nameEnumator;
 
 }
void Enumeration::toUpper (const string& str ,string& maj) {
	//string myString(str);//schneller -> Kopierkonstruktor
	maj = str;
	int len = maj.length();
	for (int i = 0; i < len; i++) {//oder str.length
		if (maj[i] >= 'a' && maj[i] <= 'z') {
			maj[i] = maj[i] + 'A' - 'a';		
		}
	}
	
	//return myString;
}

/*
   Die Methode add ermoeglicht das Hinzufügen von von enumeratoren.
   sie hat zwei parameter parametre name der enumertaor und wert sein Wert. 
 */
void Enumeration::add(const string& name, const string& wert)
{
  string maj="";
  string& maj2 = maj;
  Enumeration::toUpper(name, maj2);
  enumeratoren.insert( map<string, string>::value_type( maj2, wert) );

}

/*
      Die Methode writeDeclarationTo schreibt eine Enumerator von der angegebne name und angegebne enumuratoren.
 */
void Enumeration::writeDeclarationTo(ostream& out) const {
out << "typedef enum" << "\n" << "{\n";
    for(map<string, string>::const_iterator it = enumeratoren.begin(); it != enumeratoren.end(); ++it)
     {
        out << "\t" << (*it).first<< "=" << (*it).second <<"," << endl;       
     }
     out<<"}"<< getName() <<";";
    //cout << fichier.str() << endl;   
}


void Enumeration::writeDefinitionTo(ostream& out) const {
	out << "rien " << endl;
}




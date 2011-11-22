//filename Enumeration.h
//author: Hicham
#ifndef _ENUMERATION_H_INCLUDED
#define _ENUMERATION_H_INCLUDED
#include <string>
#include <map>
#include "Component.h"
using namespace std;

class Enumeration : public Component
{
  public: Enumeration(const string& nameEnumator);
  
  		void writeDefinitionTo(ostream& out) const;
		void writeDeclarationTo(ostream& out) const;
 
 void toUpper (const string& str ,string& maj);
  map<string, string> enumeratoren;
  void add(const string& name, const string& wert);      

 

};
#endif

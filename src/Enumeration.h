//filename: enumeration.h
#ifndef ENUMERATION_H_INCLUDED
#define ENUMERATION_H_INCLUDED

#include "component.h"
#include <iostream>
#include <string>
#include <map>
using std::string;
class Enumeration : public Component
{
public:
      Enumeration(const string& name);
      string toUpper(const string& str);
      void add(const string& name, const string& wert);
      map<string, string> enumeration;
      void writeDeclarationTo(ostream& out)const;
      void writeDefinitionTo(ostream& out)const;
      ~Enumeration();
      
};
#endif

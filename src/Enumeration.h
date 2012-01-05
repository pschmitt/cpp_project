//filename: enumeration.h
#ifndef ENUMERATION_H_INCLUDED
#define ENUMERATION_H_INCLUDED

#include "Component.h"
#include <iostream>
#include <string>
#include <map>
using std::string;
class Enumeration : public Component
{
public:
      Enumeration(const string& name, const string& _description);
      string toUpper(const string& str);
      void add(const string& name, const string& wert);
      map<string, string> enumeration;
      string writeDeclarationTo()const;
      string writeDefinitionTo()const;
      virtual ~Enumeration();
};
#endif

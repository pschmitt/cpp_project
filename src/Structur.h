//filename structur.h
//author: Hicham & Gorlt
#ifndef _STRUCTUR_H_INCLUDED
#define _STRUCTUR_H_INCLUDED
#include <string>
#include <map>
#include "Component.h"
using namespace std;

/*
 * Klasse structur. 
 */
class Structur : public Component
{
  public: Structur(const string& nameStructur);
  void writeDefinitionTo(ostream& out) const;
  void writeDeclarationTo(ostream& out) const;
  map<string, string> structurComponent;
  void addComponent(const string& name, const string& type);      

  string toString() const;

};
#endif

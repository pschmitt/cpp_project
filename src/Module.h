/*
 * Module.h
 *
 * 		Author: Leonnel Fonkwe
 * Revision by: Philipp Schmitt
 *
 */

#ifndef _MODULE_H_INCLUDED_
#define _MODULE_H_INCLUDED_
#include <string>
#include <list>
#include "Component.h"
#include "Identifier.h"

using namespace std;

class Exception {
};

class Module {
public:
	Module(const string& _name, const string& _description = "");
	void readArgsFromUser();
	void generateHFile() const;
	void addComponent(const Component& comp);
	void generateCFile() const;
	void generate() const;
	string getName() const {
		return module_name.getName();
	}
	// void  add_symbol()const;
private:
	Identifier module_name;
	list<const Component*> components;

};

#endif //_MODULE_H_INCLUDED_ 

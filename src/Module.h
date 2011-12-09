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
#include "Identifier.h"
#include "Component.h"

using namespace std;

class Exception {
};

class Module {
public:
	Module(const string& _name, const string& _description = "");
	void readArgsFromUser();
	void addComponent(const Component& comp);
	void generate() const;
	Identifier get_module_id() const;
	// void  add_symbol()const;
private:
	Identifier module_id;
	list<const Component*> component_list;
	void generateCFile() const;
	void generateHFile() const;

};

#endif //_MODULE_H_INCLUDED_ 

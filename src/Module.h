/*
 * Module.h
 *
 * 		Author: Leonnel Fonkwe
 * Revision by: Philipp Schmitt
 *
 */

#ifndef _MODULE_H_INCLUDED_
#define _MODULE_H_INCLUDED_

#include <list>
#include <string>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include <boost/filesystem.hpp>
#include "Identifier.h"
#include "Component.h"

using namespace std;

class Module {
public:
	Module(const string& _name, const string& _description = "");
	void add_component(const Component& comp);
	void generate(const boost::filesystem::path& destPath) const;
	Identifier get_module_id() const;
private:
	Identifier module_id;
	list<const Component*> component_list;
	void generate_c_file(const boost::filesystem::path& destPath) const;
	void generate_h_file(const boost::filesystem::path& destPath) const;

};

#endif //_MODULE_H_INCLUDED_ 

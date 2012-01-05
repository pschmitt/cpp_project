// Filename: Library.cpp
// Creator: Montagnoni Thomas
// Date: 23/12/2011
// version: 0.1

#include "Library.h"
using namespace std;

//Project got a name & a description
Library::Library(const string& name, const string& description) : project_id(name, Identifier::PROJECT, description) { }

//Add a modul to a Project
void Library::add_module(Module& m) {
	module_list.push_back(&m);
}

//Generate the directory for Library
void Library::generate(const path& destpath) throw (ProjectException) {
	list<Module*>::iterator it;
	string list_dir[4] = { "test", "src", "build", "doc" };
	int taille_list = 4;
	for (int i =0; i < taille_list; i++) {
		create_directories(destpath / project_id.getName() / list_dir[i]);
		if (module_list.size() != 0) {
			for (it = module_list.begin(); it != module_list.end(); it++) {
					(*it)->generate(destpath / project_id.getName() / list_dir[i]);
			}
		}
	}
}

//Get the Project informations
Identifier Library::get_project_id() const {
	return project_id;
}

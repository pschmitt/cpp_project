// Filename: Library.cpp
// Creator: Montagnoni Thomas
// Date: 23/12/2011
// version: 0.1

#include "Library.h"
using namespace std;

//Project got a name & a description
Library::Library(const string& name, const string& description) : project_id(name, description) { }

//Add a modul to a Project
void Program::add_module(Module& m) {
	module_list.push_back(&m);
}

//Generate the directory for Library
void Library::generate(const path& destpath) throw (LibraryException) {
	if (!create_directory(destpath.project_id.getName())) {
		throw LibraryException();
	}
	String list_dir[] = { "test", "src", "build", "doc" };
	int taille_list = list_dir.length();
	for (int i =0; i < taille_list; i++) {
		create_directory(destpath + list_dir[i]);
		if (module_list.size() != 0) {
			for (it = module_list.begin(); it != module_list.end(); it++) {
					(*it)->generate(destpath + list_dir[i]);
			}
		}
	}
}

//Get the Project informations
Identifier Library::get_project() const {
	return project_id;
}

//Tostring for project informations
ostream& operator<<(ostream& out, Project& project) {
	out << project.get_project();
	return out;
}
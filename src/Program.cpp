// Filename: Program.cpp
// Creator: Montagnoni Thomas
// Date: 26/12/2011
// Version: 0.1

#include "Program.h"
using namespace std;

//Project got a name & a description
Program::Program(const string& name, const string& description) : project_id(name, Identifier::PROJECT, description) {
}

//Add a modul to a Project
void Program::add_module(Module& m) {
	module_list.push_back(&m);
}

//Generate the directory
void Program::generate(const boost::filesystem::path& destpath) throw (ProjectException) {
	if (!boost::filesystem::create_directories(destpath / project_id.getName() / "src")) {
		throw ProjectException();
	}
	//boost::filesystem::create_directory(destpath / project_id.getName());
	list<Module*>::iterator it;
	if (module_list.size() != 0) {
		for (it = module_list.begin(); it != module_list.end(); it++) {
				(*it)->generate(destpath / project_id.getName() / "src");
		}
	}
}

//Get the Project informations
Identifier Program::get_project_id() const {
	return project_id;
}

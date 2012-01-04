// Filename: Program.cpp
// Creator: Montagnoni Thomas
// Date: 26/12/2011
// Version: 0.1

#include "Program.h"
using namespace std;

//Project got a name & a description
Program::Program(const string& name, const string& description) : project_id(name, description) {
}

//Add a modul to a Project
void Program::add_module(Module& m) {
	module_list.push_back(&m);
}

//Generate the directory
void Project::generate(const path& destpath) throw (ProjectException) {
	if (!create_directory(destpath.project_id.getName())) {
		throw ProgramException();
	}
	create_directory(destpath + "/src");
	if (module_list.size() != 0) {
		for (it = module_list.begin(); it != module_list.end(); it++) {
				(*it)->generate(destpath + "/src");
		}
	}
}

//Get the Project informations
Identifier Program::get_project() const {
	return project_id;
}

//Tostring for project informations
ostream& operator<<(ostream& out, Project& project) {
	out << project.get_project();
	return out;
}
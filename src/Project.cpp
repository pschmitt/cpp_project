// Filename: Project.cpp
// Firstversion by Philipp
// Creator: Montagnoni Thomas
// Date: 23/12/2011
// version 0.1

#include "Project.h"

using namespace std;

//Project got a name & a description
Project::Project(const string& name, const string& description) :
	project_id(name, description) {
}

//Add a modul to a Project
void Project::add_modul(Modul& m) {
	modul_list.push_back(&m);
}

//Generate the directory
void Project::generate(const path& destpath) throw (ProjectException) {
	if (!create_directories(destpath.project_id.getName())) {
		return ProjectException();
	}
}

//Get the Project informations
Identifier Project::get_project() const {
	return project_id;
}

//Tostring for project informations
ostream& operator<<(ostream& out, Project& project) {
	out << project.get_project();
	return out;
}
  

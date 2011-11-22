// Mbeunzoueuh Gasparri
// filename Workspace.c++
#include"Workspace.h"
#include "WorkspaceException.h"

Workspace::Workspace(Identifier workspaceName) :
		workspaceName((std::string) workspaceName) {
	//projectList=NULL;
}

void Workspace::addProject(Project& p) {
	projectList.push_back(&p);
}

void Workspace::generate() throw (WorkspaceException) {
	std::string str = "\\";
	const char* c;
	// Check whether directory already exists
	str = str + workspaceName;
	c = str.c_str();
	if (_mkdir(c) == 0) {
		// test ob es project gibt
		if (projectList.size() != 0) {
			for (it = projectList.begin(); it != projectList.end(); it++)
				(*it)->generate(str);
		}
	} else
		throw WorkspaceException();
}

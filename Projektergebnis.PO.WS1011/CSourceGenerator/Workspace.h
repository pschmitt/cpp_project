// Mbeunzoueuh Gasparri
// Workspace.h
#ifndef WORKSPACE_H_INCLUDED
#define WORKSPACE_H_INCLUDED

#include "Project.h"
#include "WorkspaceException.h"

class Workspace {
public:
	Workspace(Identifier workspaceName);
	void addProject(Project& p);
	void generate() throw (WorkspaceException);
private:
	list<Project*> projectList;
	Identifier workspaceName;
	list<Project*>::iterator it;
	// TODO Directory: ws_root_dir
};

#endif

/*
 * Workspace.h
 *
 * 		Author: Mbeunzoueuh Gasparri
 * Revision by: Philipp Schmitt
 *
 */

#ifndef WORKSPACE_H_INCLUDED
#define WORKSPACE_H_INCLUDED

#include <list>
#include <string>
#include <boost/filesystem.hpp>
#include "Identifier.h"
#include "Project.h"
#include "WorkspaceException.h"

// TODO remove using directives
using std::string;
using namespace boost::filesystem;

// TODO exception hierarchy
class Workspace {
public:
	Workspace(const string& _ws_name, const path& _ws_dir = current_path(),
			const string& _ws_description = "");
	void add_project(Project& p);
	void generate() throw (WorkspaceException);
	Identifier get_ws_id() const;
	string get_proj_list();
	path get_ws_dir() const;
private:
	list<Project*> project_list;
	Identifier ws_id;
	path ws_dir;
};

ostream& operator<<(ostream& out, Workspace& ws);

#endif

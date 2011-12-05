/*
 * Workspace.cpp
 *
 * 		Author: Mbeunzoueuh Gasparri
 * Revision by: Philipp Schmitt
 *
 */

#include"Workspace.h"

Workspace::Workspace(const string& _ws_id, const path& _ws_dir, const string& _ws_description):
		ws_id(_ws_id, Identifier::WORKSPACE, _ws_description) {
	ws_dir = _ws_dir / ws_id.getName();
}

void Workspace::add_project(Project& p) {
	project_list.push_back(&p);
}

void Workspace::generate() throw (WorkspaceException) {
	list<Project*>::iterator it;
	string str = "\\";
	const char* c;
	str = str + ws_id.getName();
	c = str.c_str();

	if (create_directory(c)) {
		// teste ob es Projekte gibt
		if (project_list.size() != 0) {
			for (it = project_list.begin(); it != project_list.end(); it++)
				(*it)->generate(str);
		}
	} else
		throw WorkspaceException();
}

Identifier Workspace::get_ws_id() const {
	return ws_id;
}

string Workspace::get_proj_list() {
	string ws_str;
	list<Project*>::iterator it;
	if (project_list.size() != 0) {
		for (it = project_list.begin(); it != project_list.end(); it++)
			ws_str += "->" + (*it)->get_project_id().getName();
	}
	return ws_str;
}

path Workspace::get_ws_dir() const {
	return ws_dir;
}

ostream& operator<<(ostream& out, Workspace& ws) {
	out << ws.get_ws_id().getName();
	out << " (" << ws.get_ws_dir() << ")" << endl;
	out << ws.get_proj_list() << endl;
	return out;
}

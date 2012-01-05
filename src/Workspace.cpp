/*
 * Workspace.cpp
 *
 * 		Author: Mbeunzoueuh Gasparri
 * Revision by: Philipp Schmitt
 *
 */

#include"Workspace.h"

/*
 * Constructor
 *
 * @param _wd_id Identifier (name)
 * @param _wd_dir path of ws (defaults to current dir)
 * @param _ws_description Description - optional
 */
Workspace::Workspace(const string& _ws_id, const path& _ws_dir, const string& _ws_description /* = "" */):
		ws_id(_ws_id, Identifier::WORKSPACE, _ws_description) {
	ws_dir = _ws_dir / ws_id.getName();
}

/**
 * add_project
 *
 * @param p Project to add
 */
void Workspace::add_project(Project& p) {
	project_list.push_back(&p);
}

/**
 * generate - Creates the WS dir
 */
void Workspace::generate() throw (WorkspaceException) {
	list<Project*>::iterator it;

	if (create_directory(ws_dir)) {
		// teste ob es Projekte gibt
		if (project_list.size() != 0) {
			for (it = project_list.begin(); it != project_list.end(); it++)
				(*it)->generate(ws_dir);
		}
	} else
		throw WorkspaceException();
}

/**
 * get_ws_id
 *
 * @return ws_id
 */
Identifier Workspace::get_ws_id() const {
	return ws_id;
}

/**
 * get_proj_list
 *
 * @return String representation of WS
 */
string Workspace::get_proj_list() {
	string ws_str;
	list<Project*>::iterator it;
	if (project_list.size() != 0) {
		for (it = project_list.begin(); it != project_list.end(); it++)
			ws_str += "->" + (*it)->get_project_id().getName();
	}
	return ws_str;
}

/**
 * get_ws_dir
 *
 * @return ws_dir
 */
path Workspace::get_ws_dir() const {
	return ws_dir;
}

/**
 * operator overloading (output)
 */
ostream& operator<<(ostream& out, Workspace& ws) {
	out << ws.get_ws_id().getName();
	out << " (" << ws.get_ws_dir() << ")" << endl;
	out << ws.get_proj_list() << endl;
	return out;
}

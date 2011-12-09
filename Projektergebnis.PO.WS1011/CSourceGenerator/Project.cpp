/*
 * Project.cpp
 *
 * 		Author: Mbeunzoueuh Gasparri
 * Revision by: Philipp Schmitt
 *
 */

#include"Project.h"

Project::Project(const string& _project_id,
		const string& _proj_description) :
		project_id(_project_id, Identifier::PROJECT, _proj_description) {
}

void Project::add_modul(Modul& m) {
	modul_list.push_back(&m);
}

void Project::generate(const path& workspace_dir)
		throw (ProjectException) {
	//project_dir = workspaceDirectory + "\\" + project_name;
	// Check if directory already exists
	//if (create_directory(workspaceDirectory.c_str()) == 0) {
	/* if(modulList.size()!=0){
	 for (list<Modul>::iterator it= modulList.begin() ; it != modulList.end(); it++ ){
	 (*it).generate();
	 }
	 }*/
	//} else {
	//	throw ProjectException();
	//}
	if (!create_directories(workspace_dir / project_id.getName()))
		throw ProjectException();
}

Identifier Project::get_project_id() const {
	return project_id;
}

ostream& operator<<(ostream& out, Project& proj) {
	out << proj.get_project_id().getName();
	return out;
}

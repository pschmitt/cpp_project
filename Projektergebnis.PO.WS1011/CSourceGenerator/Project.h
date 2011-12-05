/*
 * Project.h
 *
 * 		Author: Mbeunzoueuh Gasparri
 * Revision by: Philipp Schmitt
 *
 */

#ifndef PROJECT_H_INCLUDED
#define PROJECT_H_INCLUDED
#include <list>
#include <string>
#include <boost/filesystem.hpp>
#include "Identifier.h"
#include "ProjectException.h"

// TODO remove using directives
using std::string;
using namespace boost::filesystem;

#ifndef RELEASE
	typedef string Modul;
#else
	#include "Modul.h"
#endif

class Project {
public:
	Project(const string& project_id, const string& _proj_description = "");
	void add_modul(Modul& m);
	void generate(const string& workspaceDirectory) throw (ProjectException);
	Identifier get_project_id() const;
private:
	// why was that protected ?
	list<Modul*> modul_list;
	Identifier project_id;
	/*path*/
	string project_dir;
};

ostream& operator<<(ostream& out, Project& proj);

#endif

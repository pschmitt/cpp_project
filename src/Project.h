// Filename: Project.h
// Firstversion by Philipp
// Creator: Montagnoni Thomas
// Date: 23/12/2011
// version: 0.1

#ifndef PROJECT_H_INCLUDED
#define PROJECT_H_INCLUDED

#include <list>
#include <string>

#include <Identifier.h>
#include <ProjectException.h>
// Boost permet de rendre le code portable
#include <boost/filesystem.hpp> 
using namespace std;

class Project {
	public:
		Project(const string& name, const string& description= "");
		void add_modul(Modul& m);
		void create(const boost::filesystem::path& destPath) throw (ProjectException);
		Identifier get_project() const;
	private:
		list<Modul*> modul_list;
		Identifier name;
};

ostream& operator<<(ostream& out, Project& project);
#endif

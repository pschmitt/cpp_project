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
		// Virtual car seulement utilisé par les fils (Program et Library)
		virtual Project(const string& name, const string& description= "") = 0;
		virtual void add_module(Module& m) = 0;
		virtual void generate(const boost::filesystem::path& destPath) throw (ProjectException) = 0;
		virtual Identifier get_project() const = 0;
	private:
		list<Module*> module_list;
		Identifier name;
};

ostream& operator<<(ostream& out, Project& project);
#endif

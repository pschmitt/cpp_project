// Filename: Project.h
// Firstversion by Philipp
// Creator: Montagnoni Thomas
// Date: 23/12/2011
// version: 0.1

#ifndef PROJECT_H_INCLUDED
#define PROJECT_H_INCLUDED

#include <list>
#include <string>
#include <Module.h>
#include <Identifier.h>
#include <ProjectException.h>
// Boost permet de rendre le code portable
#include <boost/filesystem.hpp> 

using namespace std;

class Project {
public:
	// Virtual car seulement utilis� par les fils (Program et Library)
	virtual void add_module(Module& m)= 0;
	virtual void generate(const boost::filesystem::path& destPath)
			throw (ProjectException) = 0;
	virtual Identifier get_project_id() const = 0;

};
#endif

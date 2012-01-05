// Filename: Library.h
// Creator: Montagnoni Thomas
// Date: 23/12/2011
// version: 0.1

#ifndef _LIBRARY_H_INCLUDED_
#define _LIBRARY_H_INCLUDED_

#include <boost/filesystem.hpp>
#include "Project.h" //H�ritage de Project
#include "LibraryException.h"
#include <string>

using namespace boost::filesystem;

class Library: virtual public Project { //h�rite de project
	public:
		Library(const string& name, const string& description= "");
		void add_module(Module& m);
		void generate(const path& destPath) throw (ProjectException);
		Identifier get_project_id() const;
	private:
		list<Module*> module_list;
		Identifier project_id;
};
#endif

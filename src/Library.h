// Filename: Library.h
// Creator: Montagnoni Thomas
// Date: 23/12/2011
// version: 0.1

#ifndef _LIBRARY_H_INCLUDED_
#define _LIBRARY_H_INCLUDED_

#include "Project.h" //Héritage de Project
#include "LibraryException.h"

class Library: public Project { //hérite de project
	public:
		Library(Identifier projectName);
		const string& getDirectory(); //Get the Directory Name
		virtual void generate(const boost::filesystem::path& destPath) throw (LibraryException);
};
#endif
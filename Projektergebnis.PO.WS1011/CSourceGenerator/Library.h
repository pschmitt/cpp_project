// Mbeunzoueuh Gasparri
//filename Library.h
#ifndef _LIBRARY_H_INCLUDED_
#define _LIBRARY_H_INCLUDED_
#include"Project.h"
#include"LibraryException.h"
class Library : public Project
{
	public:
		Library(Identifier projectName);
		virtual void generate(const string& workspaceDirectory);
		
};
#endif
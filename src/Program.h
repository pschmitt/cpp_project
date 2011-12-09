/*
 * Program.h
 *
 * 		Author: Mbeunzoueuh Gasparri
 * Revision by: Philipp Schmitt
 *
 */

#ifndef _PROGRAM_H_INCLUDED_
#define _PROGRAM_H_INCLUDED_
#include "Project.h"
#include "ProgramException.h"

typedef string Identifier; // #include"Identifier.h"
typedef string Modul; 	   // #include"Modul.h"

class Program: public Project {
public:
	Program(Identifier projectName);
	virtual void generate(const string& workspaceDirectory)
			throw (ProgrammException);
};
#endif

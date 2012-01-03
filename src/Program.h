// Filename: Program.h
// Creator: Montagnoni Thomas
// Date: 26/12/2011
// Version: 0.1

#ifndef _PROGRAM_H_INCLUDED_
#define _PROGRAM_H_INCLUDED_

#include "Project.h" //Include car il y'a un héritage
#include "Identifier.h" //Include pour verifier la variable courante
#include "Modul.h" //Include Modul car utilisé par Programm

class Program : public Project { //Program hérite de projet
	public:
		Program(const Identifier& name);
		virtual ~Program();
		const string& getDirectory(); //Get the Directory Name
		virtual void generate(const boost::filesystem::path& destPath) throw (ProgramException);
};
#endif

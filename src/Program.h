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
	private:
		list<Module*> module_list;
		Identifier name;
};
#endif

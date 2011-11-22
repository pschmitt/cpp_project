// Mbeunzoueuh Gasparri
//filename Programm.h
#ifndef _PROGRAM_H_INCLUDED_
#define _PROGRAM_H_INCLUDED_
#include"Project.h"
#include "ProgrammException.h"
typedef string Identifier;// #include"Identifier.h"
typedef string Modul;// #include"Modul.h"

class Programm : public Project{
	public:
		Programm(Identifier projectName);
		virtual void generate(const string& workspaceDirectory)throw (ProgrammException);
		
};
#endif
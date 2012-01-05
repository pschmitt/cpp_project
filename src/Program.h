// Filename: Program.h
// Creator: Montagnoni Thomas
// Date: 26/12/2011
// Version: 0.1

#ifndef _PROGRAM_H_INCLUDED_
#define _PROGRAM_H_INCLUDED_

#include "Project.h" //Include car il y'a un héritage
#include "Identifier.h" //Include pour verifier la variable courante
#include "Module.h" //Include Modul car utilisé par Programm

class Program : virtual public Project { //Program hérite de projet
	public:
		Program(const string& name, const string& description= "");
		void add_module(Module& m);
		void generate(const boost::filesystem::path& destPath) throw (ProjectException);
		Identifier get_project_id() const;
	private:
		list<Module*> module_list;
		Identifier project_id;
};
#endif

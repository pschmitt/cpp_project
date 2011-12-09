/*
 * Program.cpp
 *
 * 		Author: Mbeunzoueuh Gasparri
 * Revision by: Philipp Schmitt
 *
 */

#include"Program.h"
Program::Program(Identifier projectName) :
		Project(projectName) {
	//modulList=NULL;
}

void Program::generate(const string& workspaceDirectory)
		throw (ProgrammException) {

	Project::generate(workspaceDirectory);

	std::string srcDir = projectDir + "\\src";
	if (_mkdir(srcDir.c_str()) == 0) {
		//modul
	} else {
		throw "umnoglich! src Directorie zuerzeugen weil es schon vorhanden ist";
	}
}

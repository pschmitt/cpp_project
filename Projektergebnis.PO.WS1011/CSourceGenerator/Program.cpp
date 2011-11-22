// Mbeunzoueuh Gasparri
// filename Programm.cpp
#include"Program.h"
Programm::Programm(Identifier projectName) :
		Project(projectName) {
	//modulList=NULL;
}

void Programm::generate(const string& workspaceDirectory)
		throw (ProgrammException) {

	Project::generate(workspaceDirectory);

	std::string srcDir = projectDir + "\\src";
	if (_mkdir(srcDir.c_str()) == 0) {
		//modul

	} else {
		throw "umnoglich! src Directorie zuerzeugen weil es schon vorhanden ist";
	}
}

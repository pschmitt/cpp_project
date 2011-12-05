/*
 * Library.cpp
 *
 * 		Author: Mbeunzoueuh Gasparri
 * Revision by: Philipp Schmitt
 *
 */

#include "Library.h"
Library::Library(Identifier projectName) :
		Project(projectName) {
	//modulList=NULL;
}

void Library::generate(const string& workspaceDirectory)
		throw (LibraryException) {

	// �berpr�fung ob der Ordner schon vorhanden ist.
	Project::generate(workspaceDirectory);

	std::string srcDir = projectDir + "\\src";
	if (_mkdir(srcDir.c_str()) == 0) {
		//modulo
	} else {
		throw "umnoglich! src Directorie zuerzeugen weil es schon vorhanden ist";
	}
	std::string docDir = projectDir + "\\doc";
	if (_mkdir(docDir.c_str()) == 0) {
		//modul
	} else {
		throw "umnoglich ! doc Directorie zuerzeugen weil es schon vorhanden ist";
	}
	std::string sampleDir = projectDir + "\\sample";
	if (_mkdir(sampleDir.c_str()) == 0) {
		//modul
	} else {
		throw "umnoglich! sample Directorie zuerzeugen weil es schon vorhanden ist";
	}
	std::string testDir = projectDir + "\\test";
	if (_mkdir(testDir.c_str()) == 0) {
		//modul
	} else {
		throw "umnoglich!  test Directorie zuerzeugen weil es schon vorhanden ist";
	}

}

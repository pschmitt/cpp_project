// Mbeunzoueuh Gasparri
//filename Project.c++
#include"Project.h"

Project::Project(const string& projectName, const string& projectDescription) :
		_projectName(projectName) {
	//modulList=NULL;
}

void Project::add(Modul m) {
	modulList.push_back(m);
}

void Project::generate(const string& workspaceDirectory)
		throw (ProjectException) {
	projectDir = workspaceDirectory + "\\" + _projectName;
	// �berpr�fung ob der Ordner schon Vvorhanden ist.
	if (_mkdir(projectDir.c_str()) == 0) {
		/* if(modulList.size()!=0){
		 	 for (list<Modul>::iterator it= modulList.begin() ; it != modulList.end(); it++ ){
		 	 	 (*it).generate();
		 	 }
		 }*/
	} else {
		throw ProjectException();
	}
}

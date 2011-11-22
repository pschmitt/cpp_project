// Mbeunzoueuh Gasparri
//Project.h
#ifndef PROJECT_H_INCLUDED
#define PROJECT_H_INCLUDED
#include<string>
#include<list>
/*#include <direct.h>*/
#include "ProjectException.h"

using namespace std;

typedef string Identifier; // #include"Identifier.h"
typedef string Modul; // #include"Modul.h"

class Project {
public:
	Project(const string& projectName, const string& projectDescription = "");
	void add(Modul m);
	virtual void generate(const string& workspaceDirectory)
			throw (ProjectException);
protected:
	list<Modul> modulList;
	Identifier _projectName;
	string projectDir;
};

#endif

#include"Library.h"
#include"Program.h"
#include"Project.h"
#include"Workspace.h"
#include "WorkspaceException.h"
#include "ProjectException.h"
int main()
{
	cout << "begin main unit test function ..." << endl;	
	try{
		Programm p("CylinderApplication");
		Modul cylinderIO("cylinderIO");
		p.add(cylinderIO);
	
	
	
		Library l("Libray");
		Modul cylinder("cylinder");
		Modul circle("circle");
		l.add(cylinder);
		l.add(circle);
	
		Workspace ws("Workspace");
		ws.addProject(p);
		ws.addProject(l);
	
		ws.generate();
	}catch(const WorkspaceException& e){
		cout<<e.handlung()<<endl;
	}catch(const ProjectException& e){
		cout<<e.handlung()<<endl;
	}catch(const char* t){
		cout<<t<<endl;
	}
	cout << "Test1 Workspace schon da fehler..." << endl;
	try{
		
	
		Workspace ws("Workspacetest");
		ws.generate();
		}catch(const WorkspaceException& e){
		cout<< "OK "<<endl;
	}
	cout << "Test2 Program creation ..." << endl;
	try{
		
	
		Workspace ws("Workspacetest");
		Programm p("CylinderApplicationtest");
		ws.addProject(p);
		p.generate("Workspacetest");
		}catch(const ProjectException& e){
		cout<< "OK "<<endl;
	}
		cout << "Test2 Program creation schon da fehler ..." << endl;
	try{
		
	
		Workspace ws("Workspacetest");
		Programm p("CylinderApplicationtest");
		ws.addProject(p);
		p.generate("Workspacetest");
		}catch(const ProjectException& e){
		cout<< "OK "<<endl;
	}
	cout << "Test3 Library creation  ..." << endl;
	try{
		
	
		Workspace ws("Workspacetest");
		Library l("Libraytest");
		ws.addProject(l);
		l.generate("Workspacetest");
		}catch(const ProjectException& e){
		cout<< "OK "<<endl;
	}
	cout << "Test4 Library creation schon da fehler  ..." << endl;
	try{
		
	
		Workspace ws("Workspacetest");
		Library l("Libraytest");
		ws.addProject(l);
		l.generate("Workspacetest");
		}catch(const ProjectException& e){
		cout<< "OK "<<endl;
	}
	int i=1+1;	
		
	return 0;
}
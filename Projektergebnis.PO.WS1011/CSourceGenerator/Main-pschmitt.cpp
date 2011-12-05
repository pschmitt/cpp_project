/*
 * Main.cpp
 *
 *  Created on: Nov 17, 2011
 *      Author: pschmitt
 */

#include <iostream>
#include <string>
#include <boost/filesystem.hpp>

// Testing
typedef std::string Modul;

#include "Identifier.h"
#include "Project.h"
#include "Workspace.h"

// using namespace boost::filesystem;
using namespace std;

int main() {
	try {
		Workspace ws = Workspace("Wss", "/tmp");
		Project p1 = Project("Proj");
		Project p2 = Project("proj2");
		Project p3 = Project("proj3");

		ws.add_project(p1);
		ws.add_project(p2);
		ws.add_project(p3);
		cout << ws << endl << endl;

		path p = ws.get_ws_dir();
		cout << "wow";
		create_directory(p);
		cout << p << endl << exists(p.parent_path()) << endl << p.native();

	} catch (ProjectException& err) {
		cout << err.what() << endl;
	} catch (WorkspaceException& err) {
		cout << err.what() << endl;
	// thrown by Identifier
	} catch (const string& err) {
		cout << err << endl;
	} catch (...) {
		cout << "Whaa ? Unknown error" << endl;
	}
	return 0;
}

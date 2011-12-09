/*
 * main_pschmitt.cpp
 *
 *  Created on: Nov 17, 2011
 *      Author: pschmitt
 */

#include <iostream>
#include <string>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string.hpp> // toUpper case !
#include "Identifier.h"
#include "Project.h"
#include "Workspace.h"

// using namespace boost::filesystem;
using namespace std;

int main() {
	try {
		// clean up !
		boost::filesystem::remove_all("/tmp/Ws");

		Workspace ws = Workspace("Ws", "/tmp");
		Project p1 = Project("Proj");
		Project p2 = Project("proj2");
		Project p3 = Project("proj3");
		Project p4 = Project("project4");

		ws.add_project(p1);
		ws.add_project(p2);
		ws.add_project(p3);
		ws.add_project(p4);
		cout << ws << endl << endl;
		ws.generate();

		// test
		string lc = "lowercase";
		std::transform(lc.begin(), lc.end(),lc.begin(), ::toupper);
		cout << lc << endl;
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

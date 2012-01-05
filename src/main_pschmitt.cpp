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
#include "Module.h"
#include "Function.h"
#include "Program.h"
#include "Workspace.h"
#include "Library.h"
#include "Variable.h"

// using namespace boost::filesystem;
using namespace std;

int main() {
	try {
		// clean up !
		boost::filesystem::remove_all("/tmp/Ws");

		// instanciate a WS, some Programs, Libraries etc.
		Workspace ws = Workspace("Ws", "/tmp");
		Program p1 = Program("Proj");
		Program p2 = Program("proj2");
		Program p3 = Program("proj3");
		Program p4 = Program("project4");
		Library lib1 = Library("Lib1");
		Library lib2 = Library("lib2");
		Module m1 = Module("m1");
		Module m2 = Module("m2");
		Variable v1 = Variable("v1", "int");
		Function f1 = Function("f1", "description");

		// Mix them together
		m1.add_component(v1);
		m1.add_component(f1);
		p1.add_module(m1);
		p1.add_module(m2);
		ws.add_project(p1);
		ws.add_project(p2);
		ws.add_project(p3);
		ws.add_project(p4);
		ws.add_project(lib1);
		ws.add_project(lib2);

		// look at em
		cout << ws << endl << endl;

		// Crete the WS
		ws.generate();
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

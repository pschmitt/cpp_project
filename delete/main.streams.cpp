//filename: Main.cpp
//author: Rolf

#include <iostream>
#include <sstream>
#include <string>

#include "Function.h"
#include "Streams.h"//hat auch Functions.h; nur der Klarheit halber



//#define EXAMPLE_FUNCTION_MAIN
#ifdef EXAMPLE_FUNCTION_MAIN
int main (int argc, char** argv) {
	using namespace std;
	cout << "begin main example functions ..." << endl << endl;	
	
	// Function f1
	Function f("myTestFunctionF1", "Das ist die Testbeschreibung der Funktion");
	f.setConst(true);
	f.addParameter("x", "int");
	f.addParameter("c", "char");
	Parameter p("int", "i");
	p.setDescription("Das ist eine Integer-Variable");
	f.addParameter(p);	
	f.setReturnType("char*", "Diese Funktion gibt das zurueck");

	DeclarationStream decS;
	DefinitionStream defS;
	DoxygenDefinitionStream doxyS;

	decS << f;
	defS << f;
	doxyS << f;

	cout << "Function f1: " << endl << endl;

	cout << "declaration (.h):" << endl << "----------------" << endl;
	cout << decS << endl;
	
	cout << "definition (.c):" << endl << "----------------" << endl;
	cout << defS << endl;

	cout << "definition with Doxygen (.c):" << endl << "-----------------------------" << endl;
	cout << doxyS;
	
	cout << endl << "#################################################" << endl;
	
	Function f2("function2");
	f2.setConst(false);
	f2.setVisibility(Symbol::PRIVATE);
	f2.addParameter("c", "char");
	Parameter p2("double", "d");
	p2.setDescription("Das ist eine Gleitkommazahl");
	f2.addParameter(p);	
	f2.setReturnType("char*", "Diese Funktion gibt das zurueck");
	
	decS << f2;
	defS << f2;
	doxyS << f2;

	cout << "Function f2: " << endl << endl;
		
	cout << "declaration (.h):" << endl << "----------------" << endl;
	cout << decS << endl;
	
	cout << "definition (.c):" << endl << "----------------" << endl;
	cout << defS << endl;

	cout << "definition with Doxygen (.c):" << endl << "-----------------------------" << endl;
	cout << doxyS;
	
	cout << endl << "#################################################" << endl;
	
	Function f3("function3");
	
	decS << f3;
	defS << f3;
	doxyS << f3;

	cout << "Function f3: " << endl << endl;
		
	cout << "declaration (.h):" << endl << "----------------" << endl;
	cout << decS << endl;
	
	cout << "definition (.c):" << endl << "----------------" << endl;
	cout << defS << endl;

	cout << "definition with Doxygen (.c):" << endl << "-----------------------------" << endl;
	cout << doxyS;
	
	cout << endl << " ... end main example functions" << endl;
}
#endif //EXAMPLE_FUNCTION_MAIN


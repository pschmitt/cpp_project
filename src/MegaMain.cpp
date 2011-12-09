//filename: MegaMain.cpp
//author: Rolf

#include <iostream>
//#include <sstream>
#include <string>

#include "Function.h"
#include "Object.h"
#include "Enumeration.h"
#include "Structur.h"
#include "module.h"
//#include "Streams.h"//hat auch Functions.h; nur der Klarheit halber



#define MEGA_MAIN
#ifdef MEGA_MAIN
int main (int argc, char** argv) {
	using namespace std;
	try {
		cout << "begin mega main" << endl << endl;
	
	
		Module m("Amy_modul");
		Function f1("help");
		f1.setVisibility(Symbol::PRIVATE);
		Function f2("interface");
		f2.setReturnType("int");
		m.addComponent(f1);
		m.addComponent(f2);

		Object v1("global", "int");
		Object v2("konst", "int", "2");
		Object v3("intern", "int", Symbol::PRIVATE);
		Object v4("internkonst", "int", "3", Symbol::PRIVATE);
		m.addComponent(v1);
		m.addComponent(v2);
		m.addComponent(v3);
		m.addComponent(v4);

		Enumeration e("Himmelsrichtung");
		e.add("NORDEN", "1");
		e.add("SUEDEN", "2");
		e.add("WESTEN", "3");
		e.add("OSTEN", "4");

		Structur s("Zylinder");
		s.addComponent("hoehe", "double");
		s.addComponent("radius", "double");


		m.generateCFile();
		cout << "generated " << m.getName() << ".c" << endl;
		m.generateHFile();
		cout << "generated " << m.getName() << ".h" << endl;

	} catch (std::string& s) {
		cout << "caught exception: " << s << endl;
	} catch (...) {
		cout << "caught unknown exception." << endl;
	}
	cout << endl << " ... end mega main" << endl;
}
#endif //EXAMPLE_FUNCTION_MAIN


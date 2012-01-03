//filename: Function.cpp
//author: Rolf
//revision by: Mathieu Morainville

#include "Function.h"
#include <sstream>

Function::Function (const string& _name, const string& _description /*= ""*/)
	: Component(_name, Identifier::VARIABLE, Component::PUBLIC, false, _description), returnData("void", "")
{}

//Destructor
Function::~Function() {}

/*
Fuegt einen neuen Parameter hinzu.
Der Parameter wird kopiert.
*/
void Function::addParameter(const Parameter& p, int pos /*= 0*/) {
	/*
	TODO: irgendwie noch die Gueltigkeit des Namens (macht eigtl. Identifier) UND des Typs testen
	*/
	parameterList.push_back(p);//kopiert ...
}

/*
Fuegt einen neuen Parameter hinzu.
Der Parameter wird kopiert.
*/
void Function::addParameter(const string& _identifier, const string& _type, const string& _description /*= ""*/) {
	Parameter p(_identifier, _type, _description);
	addParameter(p);
}

/*
Gibt einen bestimmten Parameter zurueck.
Wirft Ausnahmen, falls 1) keine Parameter oder 2) ungueltiger Index
*/
const Parameter& Function::getParamAtIndex(const int index) const throw (const char*) {
	if (parameterList.empty()) {
		throw "There are no parameters for this function!";
	} else if ((index < 0) || (index > (parameterList.size() - 1))) {
		throw "Index out of bound!";
	} else {	
		;
		list<Parameter>::const_iterator it = parameterList.begin();
		for (int i = 0; i < index; i++) {
			it++;
		}
		return *it;
	}
}

/*
Setzt den Rueckgabewert und dessen Beschreibung.
Wirft eine Ausahme, falls der Wert leer ist
*/
void Function::setReturnType(const string& returnType, const string& _text /*= ""*/) throw (const char*) {
	if (returnType.empty()) {
		throw ("Return type cannot be empty!");
	} else {
		returnData.returnType = returnType;
		returnData.returnTypeDescription = _text;
	}
	
}

/*
Schreibt die Funktionssignatur und den Rueckgabewert in den Stream.
writeSignatureAndReturnTypeTo() ist nur eine Hilfsfunktion um die eigentliche
Funktionsdefinition bzw. Funktionsdeklaration zu erstellen.
*/
void Function::writeSignatureAndReturnTypeTo(ostream& out) const {
	out << returnData.returnType;
	out << ' ' << getName();
	out << "(";
	for (list<Parameter>::const_iterator it = parameterList.begin(); it != parameterList.end(); it++) {
		out << it->getType() << ' ' << it->getName();
		out << ", ";
	}
	//letztes Komma rausschmeissen (hoffentlich besser als if-Konditition in der Schleife ?)
	if (numParams() != 0) {
		long pos = out.tellp();
		out.seekp(pos - 2);
	}
	
	out << ")";	
	if (getConst() == true) { out << " const"; } //if (isConst()) { out << " const"; }
}

/*
Schreibt die Funktionsdefinition (.c) in den Stream
*/
void Function::writeDefinitionTo(ostream& out) const {
	writeSignatureAndReturnTypeTo(out);
	out << endl << '{' << endl << endl << '}' << endl;
}

/*
Schreibt die Funktionsdeklaration (.h) in den Stream
Fragt sich noch, wie reagiert werden soll, wenn die Funktion nicht oeffentlich ist
*/
void Function::writeDeclarationTo(ostream& out) const {
	/*if (isPrivate()) {
		//exception ??
		//hier stimmt auch etwas nicht, wenn man nichts in den stream schreibt, dann gibt's Probleme
		out << "// " << getName() << "() is private" << endl;
	} else {*/
		writeSignatureAndReturnTypeTo(out);
		out << ";" << endl;
	//}
}

/* convenience */
void Function::writeSignatureAndReturnTypeTo(string& str) const {
	stringstream ss;
	writeSignatureAndReturnTypeTo(ss);
	str = ss.str();
}

/* convenience */
void Function::writeDefinitionTo(string& str) const {
	stringstream ss;
	writeDefinitionTo(ss);
	str = ss.str();
}

/* convenience */
void Function::writeDeclarationTo(string& str) const {
	stringstream ss;
	writeDeclarationTo(ss);
	str = ss.str();
}





//#define UNIT_TEST_FUNCTION
//#ifdef UNIT_TEST_FUNCTION
int main (int argc, char** argv) {
	cout << "begin main unit test function ..." << endl;	
	try {
		Function f1("f1", "Dies ist die Funktion f1");
		f1.setReturnType("int", "Die Summer der Parameter");
	
		Function f2("f2", "Dies ist die Funktion f2");
		f2.setReturnType("bool", "Ja oder Nein :)");
		Parameter p1("const string&", "str");
		p1.setDescription("Ein konstanter String");
		Parameter p2("int", "i");
		p2.setDescription("Das ist eine Integer-Variable");
		Parameter p3("char*", "x");
		p3.setDescription("Ein Char-Pointer");
		f2.addParameter(p1);
		f2.addParameter(p2);
		f2.addParameter(p3);
		
		f1.addParameter(p1);
		
		f1.writeDefinitionTo(cout);
		f2.writeDefinitionTo(cout);
	
		// TEST01
		f1.setConst(true);
		if (f1.getConst() == true) {
			cout << "TEST01 OK" << endl;
		} else {
			cout << "TEST01 FAILED!!!" << endl << "isConst() failed" << endl;
		}
	
		// TEST02
		f1.addParameter("int", "i");
		f1.addParameter("int", "j");
		if (f1.numParams() == 2) {
			cout << "TEST02 OK" << endl;
		} else {
			cout << "TEST02 FAILED!!!" << " numParams() OR addParameter() failed" << endl;
		}
	
		// TEST03
		f1.setVisibility(Component::PRIVATE);
		if (f1.isStatic()) {
			cout << "TEST03 OK" << endl;
		} else {
			cout << "TEST03 FAILED!!!" << " isStatic() with private function failed" << endl;
		}
	
		// TEST04
		Function f3("f3");
		try {
			f3.getParamAtIndex(0);
			cout << "TEST04_0 FAILELD!!!" << " getParamAtIndex() with empty parameter list failed" << endl;
		} catch (const char* msg) {
			cout << "TEST04_0 OK" << endl;
		}
		Parameter p4("const string&", "str");
		f3.addParameter(p4);
		if (f3.getParamAtIndex(0) == p4) {
			cout << "TEST04_1 OK" << endl;
		} else {
			cout << "TEST04_1 FAILED!!!" << " getParamAtIndex() || addParameter failed, returned parameter not equal to the original" << endl;
		}
		try {
			f3.getParamAtIndex(1);
			cout << "TEST04_2 FAILELD!!!" << " getParamAtIndex() with out of bound index failed" << endl;
		} catch (const char* msg) {
			cout << "TEST04_2 OK" << endl;
		}
	
		// TEST05
		try {
			f3.setReturnType("");
			cout << "TEST05 FAILELD!!!" << " setReturnType() with an empty returnType failed" << endl;
		} catch (const char* msg) {
			cout << "TEST05 OK" << endl;
		}
	
		// TEST06
		Parameter p5("double", "d");
		f1.addParameter(p5, 1);
		if (f1.getParamAtIndex(1) != p5) {
			cout << "TEST06 FAILED!!!" << " addParameter() with predefined position failed" << endl;;
		} else {
			cout << "TEST06 OK" << endl;
		}
	
	} catch (const char* msg) {
		cout << "Unknown error in unit test: " << msg << endl;
	} catch (...) {
		cout << "Unknown error in unit test" << endl;
	}
	
	cout << "... end main unit test function" << endl;
}
//#endif

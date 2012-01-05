/*
 * Module.cpp
 *
 * dieses Programme nimmt ein name von ein Identifier/user und generate ein c_ und h_programme
 *
 * 		Author: Leonnel Fonkwe
 * Revision by: Philipp Schmitt
 *
 */

#include <fstream>
#include "Module.h"

Module::Module(const string& _name, const string& _description /* = "" */) :
		module_id(_name, Identifier::MODUL, _description) {
}

Identifier Module::get_module_id() const {
	return module_id;
}

// diese Methode generiert de C File
void Module::generateCFile() const {
	string varmaj = module_id.getName(); // variable parametre
	boost::to_upper(varmaj);

	string name_c = module_id.getName();
	name_c.append(".c");
	std::ofstream c_File(name_c.c_str());
	c_File << "// filename: " << name_c << endl << endl << "#include \""
			<< module_id.getName() << ".h" << "\"" << endl << endl;
	c_File << "/* Definitionen */" << endl;

	list<Component*>::iterator it;
	for (it = component_list.begin(); it != component_list.end(); it++) // parcourt de la liste component
		it->writeDefinitionTo(c_File);

	c_File << "//#define UNIT_TEST_" << varmaj << endl;
	c_File << "#ifdef UNIT_TEST_" << varmaj << endl;
	c_File << "int main (int argc, char** argv) { " << endl;
	c_File << "int errorCount = 0; " << endl;
	c_File << "/* test cases */" << endl;
	c_File << "return errorCount;" << endl;
	c_File << "}" << endl;
	c_File << "#endif" << endl;
}

//diese Methode generiert de H file
void Module::generateHFile() const {
	string varmaj = module_id.getName();
	string descript = module_id.getDescription();
	boost::to_upper(varmaj);
	string name_h = module_id.getName();
	name_h.append(".h");
	string sentrydefine = string("_") + varmaj + "_H_";
	std::ofstream hFile(name_h.c_str());
	hFile << "/* filename: " << name_h << " */" << endl
			<< endl
			//afficher la description ici
			<< "//" << descript << endl << endl << "#ifndef " << sentrydefine
			<< endl << "#define " << sentrydefine << endl << endl
			<< "/* Deklarationen */" << endl << endl;

	list<const Component*>::const_iterator it;
	for (it = component_list.begin(); it != component_list.end(); it++) { // parcour de la liste component
		//it->writeDeclarationTo(hFile);
	}

	hFile << "#endif /* " << sentrydefine << " */" << endl;
}

void Module::generate(const boost::filesystem::path& destPath) const {
	generateHFile();
	generateCFile();
}

void Module::addComponent(const Component& comp) {
	component_list.push_back(&comp);
}


/*
 * Module.cpp
 *
 * dieses Programme nimmt ein name von ein Identifier/user und generate ein c_ und h_programme
 *
 * 		Author: Leonnel Fonkwe
 * Revision by: Philipp Schmitt
 *
 */

#include "Module.h"

Module::Module(const string& _name, const string& _description /* = "" */) :
		module_id(_name, Identifier::MODUL, _description) {
}

Identifier Module::get_module_id() const {
	return module_id;
}

// diese Methode generiert de C File
void Module::generateCFile(const boost::filesystem::path& destPath) const {
	string varmaj = module_id.getName(); // variable parametre
	boost::to_upper(varmaj);
	string name_c = module_id.getName() + ".c";
	boost::filesystem::path p = destPath / name_c;

	std::ofstream c_File(p.string().c_str());

	c_File << "// filename: " << name_c << endl << endl << "#include \""
			<< module_id.getName() << ".h" << "\"" << endl << endl;
	c_File << "/* Definitionen */" << endl;

	list<const Component*>::const_iterator it;
	if (component_list.size() != 0) {
		for (it = component_list.begin(); it != component_list.end(); it++) // parcourt de la liste component
			c_File << (*it)->writeDefinitionTo(); //it->writeDefinitionTo(c_File);
	}

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
void Module::generateHFile(const boost::filesystem::path& destPath) const {
	string name_h = module_id.getName() + ".h";
	boost::filesystem::path p = destPath / name_h;

	string varmaj = module_id.getName();
	boost::to_upper(varmaj);
	string descript = module_id.getDescription();

	name_h.append(module_id.getName());
	name_h.append(".h");
	string sentrydefine = string("_") + varmaj + "_H_";
	std::ofstream hFile(p.string().c_str());
	hFile << "/* filename: " << name_h << " */" << endl
			<< endl
			//afficher la description ici
			<< "//" << descript << endl << endl << "#ifndef " << sentrydefine
			<< endl << "#define " << sentrydefine << endl << endl
			<< "/* Deklarationen */" << endl << endl;

	list<const Component*>::const_iterator it;
	for (it = component_list.begin(); it != component_list.end(); it++) { // parcour de la liste component
		hFile << (*it)->writeDeclarationTo();
	}

	hFile << "#endif /* " << sentrydefine << " */" << endl;
}

void Module::generate(const boost::filesystem::path& destPath) const {
	generateHFile(destPath);
	generateCFile(destPath);
}

void Module::addComponent(const Component& comp) {
	component_list.push_back(&comp);
}


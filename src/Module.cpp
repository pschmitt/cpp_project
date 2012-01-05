/*
 * Module.cpp
 *
 * Dieses Program verwaltet Componenten und schreibt die Header- und C-Files.
 *
 * 		Author: Leonnel Fonkwe
 * Revision by: Philipp Schmitt
 *
 */

#include "Module.h"

/**
 * Constructor
 */
Module::Module(const string& _name, const string& _description /* = "" */) :
		module_id(_name, Identifier::MODUL, _description) {
}

/**
 * get_module_id
 *
 * @return module_id
 */
Identifier Module::get_module_id() const {
	return module_id;
}

/**
 * add_component
 *
 * @param comp Component to add
 */
void Module::add_component(const Component& comp) {
	component_list.push_back(&comp);
}

/**
 * generate
 *
 * @param dest_path - Path where file is going to be created
 */
void Module::generate(const boost::filesystem::path& dest_path) const {
	generate_h_file(dest_path);
	generate_c_file(dest_path);
}

/**
 * generate_h_file - Generates the C file
 *
 * @param dest_path - Path where file is going to be created
 */
void Module::generate_h_file(const boost::filesystem::path& dest_path) const {
	string filename = module_id.getName() + ".h";
	boost::filesystem::path p = dest_path / filename;

	string varmaj = module_id.getName();
	boost::to_upper(varmaj);
	string description = module_id.getDescription();

	filename.append(module_id.getName());
	filename.append(".h");
	string sentrydefine = string("_") + varmaj + "_H_";
	std::ofstream hFile(p.string().c_str());
	hFile << "// filename: " << filename << endl << endl
		  << "//" << description << endl << endl
		  << "#ifndef " << sentrydefine << endl
		  << "#define "	<< sentrydefine << endl << endl
		  << "/* Deklarationen */" << endl << endl;

	list<const Component*>::const_iterator it;
	for (it = component_list.begin(); it != component_list.end(); it++) { // parcour de la liste component
		hFile << (*it)->writeDeclarationTo();
	}

	hFile << "#endif /* " << sentrydefine << " */" << endl;
}

/**
 * generate_c_file - Generates the C file
 *
 * @param dest_path - Path where file is going to be created
 */
void Module::generate_c_file(const boost::filesystem::path& dest_path) const {
	string varmaj = module_id.getName(); // variable parametre
	boost::to_upper(varmaj); // transform  to UC
	string filename = module_id.getName() + ".c";
	boost::filesystem::path p = dest_path / filename;

	std::ofstream c_File(p.string().c_str());

	c_File << "// filename: " << filename << endl << endl
		   << "#include \"" << module_id.getName() << ".h" << "\"" << endl << endl
		   << "/* Definitionen */" << endl;

	list<const Component*>::const_iterator it;
	if (component_list.size() != 0) {
		for (it = component_list.begin(); it != component_list.end(); it++) // parcourt de la liste component
			c_File << (*it)->writeDefinitionTo(); //it->writeDefinitionTo(c_File);
	}

	c_File << "//#define UNIT_TEST_" << varmaj << endl
		   << "#ifdef UNIT_TEST_" << varmaj << endl
		   << "int main (int argc, char** argv) { " << endl
		   << "int errorCount = 0; " << endl
		   << "/* test cases */" << endl
		   << "return errorCount;" << endl
		   << "}" << endl
		   << "#endif" << endl;
}

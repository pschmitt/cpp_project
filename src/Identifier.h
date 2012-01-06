// Filename Identifier.h;
// Auteur : LENHOF K�vin
// Frantz Koagne Tenguemne
#ifndef _IDENTIFIER_H_INCLUDED_
#define _IDENTIFIER_H_INCLUDED_

#include <string>
using namespace std;

class Identifier {

	/* Funktionsdeklaration */
public:

	enum IdentifierType {
		VARIABLE,
		CONSTANT,
		ENUM,
		CLASS,
		STRUCT,
		FUNCTION,
		PARAMETER,
		WORKSPACE,
		PROJECT,
		MODUL,
		UNKNOWN
	};

	Identifier(const string& name, IdentifierType type = UNKNOWN,
			const string& _description = "") throw (std::string);

	const string& getName() const {
		return name;
	}
	const string& getDescription() const {
		return description;
	}
	void setDescription(const string& description) {
		this->description = description;
	}
	/* Konstantendeklaration */

	/* Variabledeklaration */
private:
	string name;
	string description;
	//creer une classe avec ces fctions

	static bool isDigit(char c);
	static bool isLowerCase(char c);
	static bool isUpperCase(char c);
	static bool isUnderscore(char c);
	static bool nonFirstLetter(char c);
	static bool isConstantName(const string& name);

	static bool isVariableName(const string& name);
	static bool isClassName(const string& name);
	static bool isEnumName(const string& name);
	static bool isStructName(const string& name);
	static bool isFunctionName(const string& name);
	static bool isParameterName(const string& name);
	static bool isWorkspaceName(const string& name);
	static bool isProjectName(const string& name);
	static bool isModulName(const string& name);
	static bool check(const string& name, bool(*f)(char), bool(*g)(char));
};

#endif // #ifndef _IDENTIFIER_H_INCLUDED_

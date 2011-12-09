// Filename identifier.cpp;

/*
 Autor:  -LENHOF Kevin WS 2010/2011
 -Tenguemne Frantz WS 2011/2012

 */

#include "Identifier.h"
#include <iostream> 
#include <string>

// Constructeur
Identifier::Identifier(const string& name, IdentifierType type,
		const string& description) throw (std::string) :
		name(name), description(description) {

	if (name.empty()) {
		throw std::string("ERROR : Leer Name !");
	} else {

		switch (type) {
		case VARIABLE:
			if (!isVariableName(name)) {
				throw std::string(name + " : ERROR : Kein Variablename !");
			}
			break;

		case CONSTANT:
			if (!isConstantName(name)) {
				throw std::string(name + " ERROR : Kein Konstantenname");
				;
			}
			break;

		case ENUM:
			if (!isEnumName(name)) {
				throw std::string(name + " ERROR : Kein Enumname !");
				;
			}
			break;
		case CLASS:
			if (!isEnumName(name)) {
				throw std::string(name + " ERROR : Kein Klassenname !");
				;
			}
			break;
		case STRUCT:
			if (!isEnumName(name)) {
				throw std::string(name + " ERROR : Kein Strukturenname !");
				;
			}
			break;

		case FUNCTION:
			if (!isFunctionName(name)) {
				throw std::string(name + " ERROR : Kein Functionname !");
			}
			break;
		case PARAMETER:
			if (!isParameterName(name)) {
				throw std::string(name + " ERROR : Kein Parametername !");
			}
			break;

		case WORKSPACE:
			if (!isWorkspaceName(name)) {
				throw std::string(name + " ERROR : Kein Workspacename !");
			}
			break;
		case PROJECT:
			if (!isProjectName(name)) {
				throw std::string(name + " ERROR : Kein Projectname !");
			}
			break;
		case MODUL:
			if (!isModulName(name)) {
				throw std::string(name + " ERROR : Kein Modulename !");
			}
			break;

		case UNKNOWN:
			throw std::string(
					" ERROR : Sie mussen ein Typ mit die Name geben !!");
			break;
		}
	}
}

// Methode qui verifie si un caractere est un chiffre.
bool Identifier::isDigit(char c) {
	return (c >= '0' && c <= '9');
}

// Methode qui verifie si un caractere est une lettre minuscule.
bool Identifier::isLowerCase(char c) {
	return (c >= 'a' && c <= 'z');
}

// Methode qui verifie si un caractere est une lettre majuscule.
bool Identifier::isUpperCase(char c) {
	return (c >= 'A' && c <= 'Z');
}

// Methode qui verifie si un caractere est un underscore.
bool Identifier::isUnderscore(char c) {
	return (c == '_');
}
/*la fonction nonFirstLetter verifie si le caract�re c pass� en param�tre est soit
 une lettre miniscule(a-z), soit une lettre majuscule(A-Z), soit un chiffre(0-9), soit le tiret du bas(_)
 retun vrai si c'est le cas et faux sinon
 */
bool Identifier::nonFirstLetter(char c) {
	//le caractere c est-il une lettre miniscule(a-z), majuscule(A-Z), un chiffre(0-9), le tiret du bas(_)
	if ((!isLowerCase(c)) && (!isUnderscore(c)) && (!isDigit(c))
			&& (!isUpperCase(c))) {
		return false;
	}

	return true;
}

// Methode pour identifier si une chaine de caract�re peut �tre ou non un nom de constante.
bool Identifier::isConstantName(const string& name) {
	return check(name, isUpperCase, isUpperCase);

}

/*class VariableChecker : public Checker

 isVariableName(VarialbeChecker());*/
// Methode pour identifier si une chaine de caract�re peut �tre ou non un nom de variable.
//bool Identifier::isVariableName(const string& name, Checker& check) const
bool Identifier::isVariableName(const string& name) {
	return check(name, isLowerCase, nonFirstLetter);
}

//neu fction
bool Identifier::check(const string& name, bool(*f)(char), bool(*g)(char)) {
	bool correct = true;
	if (name.size() == 0) {
		return false;
	}

	char c = '\0';
	int i = 0;

	while ((c = name[i]) != '\0') {
		if (i == 0) {
			if (!f(c)) {
				correct = false;
				break;
			}
		} else {
			if (!g(c)) {
				correct = false;
				break;
			}
		}
		i++;
	}
	return correct;
}

// Methode pour identifier si une chaine de caract�re peut �tre ou non un nom de classe.
bool Identifier::isClassName(const string& name) {
	return check(name, isUpperCase, nonFirstLetter);
}

// Methode pour identifier si une chaine de caract�re peut �tre ou non un nom d'enum.
bool Identifier::isEnumName(const string& name) {
	return isClassName(name);
}

// Methode pour identifier si une chaine de caract�re peut �tre ou non un nom de structure.
bool Identifier::isStructName(const string& name) {
	return isClassName(name);
}

// Methode pour identifier si une chaine de caract�re peut �tre ou non un nom de fonction.
bool Identifier::isFunctionName(const string& name) {
	return isVariableName(name);
}
/*la methode isParameterName verifie si une chaine de caract�re pass�e en param�tre est ou non un nom de param�tre
 return true si la chaine name est un nom de param�tre et false le cas contraire
 */
bool Identifier::isParameterName(const string &name) {
	return isVariableName(name);
}

/*la methode isWorkspaceName verifie si une chaine de caract�re pass�e en param�tre est ou non un nom de Workspace
 return true si la chaine name est un nom de Workspace et false le cas contraire
 */
bool Identifier::isWorkspaceName(const string& name) {
	if (isVariableName(name) || isClassName(name)) {
		return true;
	}
	return false;
}

/*la methode isProjectName verifie si une chaine de caract�re pass�e en param�tre est ou non un nom de projet
 return true si la chaine name est un nom de projet et false le cas contraire
 */
bool Identifier::isProjectName(const string& name) {
	if (isVariableName(name) || isClassName(name)) {
		return true;
	}
	return false;
}

/*la methode isModulName verifie si une chaine de caract�re pass�e en param�tre est ou non un nom de module
 return true si la chaine name est un nom de module et false le cas contraire
 */
bool Identifier::isModulName(const string& name) {
	if (isVariableName(name) || isClassName(name)) {
		return true;
	}
	return false;
}

//#define UNIT_TEST_IDENTIFIER_CPP
#ifdef UNIT_TEST_IDENTIFIER

using namespace std;
int main() // Function Main mit allen Test.
{

	try {
		Identifier monIdentifier("verognZn8jg", Identifier::CONSTANT);
		cout << "TEST01 CONSTANT OK !" << endl;
	} catch (std::string s) {
		cout << "TEST01 CONSTANT ERROR!" << "(" << s << ")" << endl;
	}

	try {
		Identifier monIdentifier("KUAA", Identifier::CONSTANT);
		cout << "TEST02 CONSTANT OK!" << endl;
	} catch (std::string s) {
		cout << "TEST02 CONSTANT ERROR!" << "(" << s << ")" << endl;
	}

	try {
		Identifier monIdentifier("", Identifier::CONSTANT);
		cout << "TEST03 CONSTANT OK!" << endl;
	} catch (std::string s) {
		cout << "TEST03 CONSTANT ERROR!" << "(" << s << ")" << endl;
	}

	try {
		Identifier monIdentifier("verognZn8jg", Identifier::VARIABLE);
		cout << "TEST01 VARIABLE OK!" << endl;
	} catch (std::string s) {
		cout << "TEST01 VARIABLE ERROR!" << "(" << s << ")" << endl;
	}

	try {
		Identifier monIdentifier("__okfgPPl12m", Identifier::VARIABLE);
		cout << "TEST02 VARIABLE OK!" << endl;
	} catch (std::string s) {
		cout << "TEST02 VARIABLE ERROR!" << "(" << s << ")" << endl;
	}
	try {
		Identifier monIdentifier("vRAIABLE2", Identifier::VARIABLE);
		cout << "TEST03 VARIABLE OK !" << endl;
	} catch (std::string s) {
		cout << "TEST03 VARIABLE ERROR!" << "(" << s << ")" << endl;
	}
	try {
		Identifier monIdentifier("Onkieml", Identifier::ENUM);
		cout << "TEST01 ENUM OK!" << endl;
	} catch (std::string s) {
		cout << "TEST01 ENUM ERROR!" << "(" << s << ")" << endl;
	}

	try {
		Identifier monIdentifier("student", Identifier::CLASS);
		cout << "TEST01 CLASS OK!" << endl;
	} catch (std::string s) {
		cout << "TEST01 CLASS ERROR!" << "(" << s << ")" << endl;
	}
	try {
		Identifier monIdentifier("Dreiecker", Identifier::CLASS);
		cout << "TEST02 CLASS OK!" << endl;
	} catch (std::string s) {
		cout << "TEST02 CLASS ERROR!" << "(" << s << ")" << endl;
	}
	try {
		Identifier monIdentifier("=MAMMAMIA", Identifier::FUNCTION);
		cout << "TEST01 FUNCTION OK!" << endl;
	} catch (std::string s) {
		cout << "TEST01 FUNCTION ERROR!" << "(" << s << ")" << endl;
	}
	try {
		Identifier monIdentifier("manger", Identifier::FUNCTION);
		cout << "TEST02 FUNCTION OK!" << endl;
	} catch (std::string s) {
		cout << "TEST02 FUNCTION ERROR!" << "(" << s << ")" << endl;
	}

	try {
		Identifier monIdentifier("dreieckerWorkspace", Identifier::WORKSPACE);
		cout << "TEST01 WORKSPACE OK !" << endl;
	} catch (std::string s) {
		cout << "TEST01 WORKSPACE ERROR!" << "(" << s << ")" << endl;
	}

	try {
		Identifier monIdentifier("_-_-_-_-ppp8", Identifier::WORKSPACE);
		cout << "TEST02 WORKSPACE OK !" << endl;
	} catch (std::string s) {
		cout << "TEST02 WORKSPACE ERROR!" << "(" << s << ")" << endl;
	}
	try {
		Identifier monIdentifier("binaire Baueme", Identifier::PROJECT);
		cout << "TEST01 PROJECT OK !" << endl;
	} catch (std::string s) {
		cout << "TEST01 PROJECT ERROR!" << "(" << s << ")" << endl;
	}
	try {
		Identifier monIdentifier("ApplicationGraphique", Identifier::PROJECT);
		cout << "TEST02 PROJECT OK !" << endl;
	} catch (std::string s) {
		cout << "TEST02 PROJECT ERROR!" << "(" << s << ")" << endl;
	}
	try {
		Identifier monIdentifier("inputOutput", Identifier::MODUL);
		cout << "TEST01 MODUL OK !" << endl;
	} catch (std::string s) {
		cout << "TEST01 MODUL ERROR!" << "(" << s << ")" << endl;
	}
	try {
		Identifier monIdentifier("module de-fonctions", Identifier::MODUL);
		cout << "TEST02 MODUL OK !" << endl;
	} catch (std::string s) {
		cout << "TEST02 MODUL ERROR!" << "(" << s << ")" << endl;
	}
	try {
		Identifier monIdentifier("_POKEMONATTRAPEZlestous!", Identifier::UNKNOWN);
		cout << "TEST01 UNKNOWN OK !" << endl;
	} catch (std::string s) {
		cout << "TEST01 UNKNOWN ERROR!" << "(" << s << ")" << endl;
	}

	try {
		Identifier monIdentifier("POki_ijkO", Identifier::UNKNOWN);
		cout << "TEST02 UNKNOWN OK !" << endl;
	} catch (std::string s) {
		cout << "TEST02 UNKNOWN ERROR!" << "(" << s << ")" << endl;
	}

//system("pause");
	return 0;
}
#endif

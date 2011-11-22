// Filename Identifier.h;
// Auteur : LENHOF Kévin
#ifndef _IDENTIFIER_H_INCLUDED_
#define _IDENTIFIER_H_INCLUDED_

#include <string>

using namespace std;



class Identifier 
{

/* Funktionsdeklaration */
public:
   

  enum IdentifierType { VARIABLE, CONSTANT, TYPE, FUNCTION, DIRECTORY, UNKNOWN};
  Identifier (const string& name, IdentifierType type = UNKNOWN, const string& _description = "") ;
  
	string getName() const { return name; }
	string getDescription() const { return description; }
	void setDescription(const string& _description) { description = _description; }
/* Konstantendeklaration */
  
  
/* Variabledeklaration */
  private:
          string name; 
          string description;
           
          bool isDigit(char c) const;
          bool isLowerCase(char c) const;
          bool isUpperCase(char c) const;
          bool isUnderscore(char c) const; 
          
          bool isConstantName (const string& name) const;
          bool isVariableName (const string& name) const;
          bool isClassName(const string& name) const;
          bool isEnumName(const string& name) const;
          bool isStructName(const string& name) const;
          bool isFunctionName(const string& name) const;
          bool isDirectoryName(const string& name) const;
   
  
  
};  


  
 #endif // #ifndef _IDENTIFIER_H_INCLUDED_


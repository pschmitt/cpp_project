// Filename identifier.cpp;
// Auteur : LENHOF Kevin

#include "Identifier.h"
#include <iostream> 
#include <string>


// Constructeur
Identifier::Identifier (const string& _name, IdentifierType type, const string& _description)
	: name(_name), description(_description)
{ 
                       
  if (name.size() == 0)
  {
     throw std::string("ERROR : Leer Name !");
  }  
  else
  {
      
          switch (type)
          {
                 case VARIABLE :
                      if (!isVariableName(name))
                      {
                          throw std::string(name + " : ERROR : Kein Variablename !");
                      }
                      break;
                      
                 case CONSTANT :
                      if (!isConstantName(name))
                      {
                          throw std::string(name + " ERROR : Kein Konstantenname");;
                      }
                      break;
                      
                 case TYPE :
                      if (!isEnumName(name)) 
                      {
                          throw std::string(name + " ERROR : Kein Enumname !");;
                      }
                      break;
                      
                 case FUNCTION :
                      if (!isFunctionName(name)) 
                      {
                          throw std::string(name + " ERROR : Kein Functionname !");
                      }
                      break;
                 
                 case DIRECTORY :
                      if (!isDirectoryName(name)) 
                      {
                          throw std::string(name + " ERROR : Kein Directoryname !");
                      }
                      break;
                 
                 case UNKNOWN :
                          throw std::string(" ERROR : Sie mussen ein Typ mit die Name geben !!");
                      break;
          }
  }
}



// Methode qui verifie si un caractere est un chiffre.
bool Identifier::isDigit(char c) const
{
	return (c >= '0' && c <= '9');    
}

// Methode qui verifie si un caractere est une lettre minuscule.
bool Identifier::isLowerCase(char c) const
{
    return (c >= 'a' && c <= 'z'); 
}

// Methode qui verifie si un caractere est une lettre majuscule.
bool Identifier::isUpperCase(char c) const
{
     return (c >= 'A' && c <= 'Z');
} 

// Methode qui verifie si un caractere est un underscore.
bool Identifier::isUnderscore (char c) const
{
     return (c == '_');    
}     

// Methode pour identifier si une chaine de caractère peut être ou non un nom de constante.
bool Identifier::isConstantName(const string& name) const
{
  bool correct = true;
  if (name.size() == 0)
  {
    return false;
  }
  
  char c = '\0';
  int i = 0;

  while ((c = name[i]) != '\0')
  {
    
         if (!isUpperCase(c))
            {
                correct = false;			
                break;
            }	
   
   i++; 
  }
  return correct;
}

// Methode pour identifier si une chaine de caractère peut être ou non un nom de variable.

bool Identifier::isVariableName(const string& name) const
{
  bool correct = true;
  if (name.size()== 0)
  {
    return false;
  }
  
  char c = '\0';
  int i = 0;

  while ((c = name[i]) != '\0')
  {
    if (i == 0)
      {
         if (!isLowerCase(c))
            {
                correct = false;			
                break;
            }
      }	
    else 			 
      {
             
	     if ((!isLowerCase(c)) && (!isUnderscore(c)) && (!isDigit(c)) && (!isUpperCase(c)))
		    {
			    correct = false;
				break;
	        }	   
      }
   i++; 
  }
  return correct;
}


// Methode pour identifier si une chaine de caractère peut être ou non un nom de classe.
bool Identifier::isClassName(const string& name) const
{
  bool correct = true;
  if (name.size() == 0)
  {
    return false;
  }
  
  char c = '\0';
  int i = 0;

  while ((c = name[i]) != '\0')
  {
    if (i == 0)
      {
         if (!isUpperCase(c))
            {
                correct = false;			
                break;
            }	
      }
    else 			 
      {
	     if (!isLowerCase(c) && !isUnderscore(c) && !isDigit(c))
		    {
			    correct = false;
				break;
	        }	    
      }
   i++; 
  }
  return correct;
}

// Methode pour identifier si une chaine de caractère peut être ou non un nom d'enum.
bool Identifier::isEnumName(const string& name) const
{
  return isClassName(name);
} 

// Methode pour identifier si une chaine de caractère peut être ou non un nom de structure.
bool Identifier::isStructName(const string& name) const
{
  bool correct = true;
  if (name.size() == 0)
  {
    return false;
  }
  
  char c = '\0';
  int i = 0;

  while ((c = name[i]) != '\0')
  {
    if (i == 0)
      {
         if (!((c >= 'A') && (c <= 'Z')))
            {
                correct = false;			
                break;
            }	
      }
    else 			 
      {
	     if (!isLowerCase(c) && !isUnderscore(c) && !isDigit(c) && !isUpperCase(c))
		    {
			    correct = false;
				break;
	        }	    
      }
   i++; 
  }
  return correct;
}

// Methode pour identifier si une chaine de caractère peut être ou non un nom de fonction.
bool Identifier::isFunctionName(const string& name) const
{
  return isVariableName(name);
}


// Methode pour identifier si une chaine de caractère peut être ou non un nom de directory.
bool Identifier::isDirectoryName(const string &name) const
{
  return isVariableName(name);
}

//#define UNIT_TEST_IDENTIFIER_CPP
#ifdef UNIT_TEST_IDENTIFIER_CPP
using namespace std;
int main()  // Function Main mit allen Test.
{
    
    
      try  {
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
       Identifier monIdentifier("Onkieml", Identifier::TYPE);
       cout << "TEST01 ENUM OK!" << endl;
       } catch (std::string s) {
               cout << "TEST01 ENUM ERROR!" << "(" << s << ")" << endl;
               } 
               
       try {
       Identifier monIdentifier("LEONNELFONKWE", Identifier::TYPE);
       cout << "TEST02 ENUM OK!" << endl;
       } catch (std::string s) {
               cout << "TEST01 ENUM ERROR!" << "(" << s << ")" << endl;
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
               
       try  {
            Identifier monIdentifier("bureau", Identifier::DIRECTORY);
            cout << "TEST01 DIRECTORY OK !" << endl;
           } catch (std::string s) {
             cout << "TEST01 DIRECTORY ERROR!" << "(" << s << ")" << endl;
           } 
           
       try  {
            Identifier monIdentifier("_-_-_-_-ppp8", Identifier::DIRECTORY);
            cout << "TEST02 DIRECTORY OK !" << endl;
           } catch (std::string s) {
             cout << "TEST02 DIRECTORY ERROR!" << "(" << s << ")" << endl;
           } 
           
       try  {
            Identifier monIdentifier("_POKEMONATTRAPEZlestous!", Identifier::UNKNOWN);
            cout << "TEST01 UNKNOWN OK !" << endl;
           } catch (std::string s) {
             cout << "TEST01 UNKNOWN ERROR!" << "(" << s << ")" << endl;
           } 
           
       try  {
            Identifier monIdentifier("POki_ijkO", Identifier::UNKNOWN);
            cout << "TEST02 UNKNOWN OK !" << endl;
           } catch (std::string s) {
             cout << "TEST02 UNKNOWN ERROR!" << "(" << s << ")" << endl;
           } 
       
      
  

//system("pause");
   return 0;
}
#endif

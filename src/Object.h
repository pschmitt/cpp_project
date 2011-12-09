// Filename Object.h
// author : Nicolas
#ifndef _OBJECT_H_INCLUDED_
#define _OBJECT_H_INCLUDED_

#include "Symbol.h"
#include <string>

using namespace std;

#include "Identifier.h"

class Object : public Symbol 
{
      // Funktionsdeklarationen
      public:
             Object(const string& _name, const string& _type);
             Object(const string& _name, const string& _type, const string& _value);
             Object(const string& _name, const string& _type, Visibility v);
             Object(const string& _name, const string& _type, const string& _value, Visibility v);
              
             void writeDefinitionTo (ostream& out) const;
		     void writeDeclarationTo(ostream& out) const;
		    
		     
            // bool isConst() const;
		    // bool isStatic() const;
		     
       // Private Variable
       private:
               string type;
               string value;
               
                bool isKonstantType (const string& type) const;
                bool isGlobalType (const string& type) const;
                bool isInternType (const string& type) const;
      
               // bool _static;
               // bool _const;
               
};

#endif //_OBJECT_H_INCLUDED_

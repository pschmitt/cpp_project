// Filename Object.h
// author : Frantz Tenguemne
#ifndef _OBJECT_H_INCLUDED_
#define _OBJECT_H_INCLUDED_

#include "Component.h"
#include <string>
#include "Identifier.h" //a eventuelement supprimer
using namespace std;

class Object : public Component 
{
      // Funktionsdeklarationen
	public:
		 
		Object(const string& name, Identifier::IdentifierType type, const string& typeObject, const string& value = "",
		       Visibility visibility = Component::PUBLIC, bool isConst = false
			  );
			
		virtual ~Object();      
		virtual void writeDefinitionTo (ostream& out) const = 0;
		virtual void writeDeclarationTo(ostream& out) const = 0;
		const string& getValue() const;
		const string& getTypeObject() const;	
		//const string& toString() const;
       // protected Variable
	protected:
		string typeObject; //qui est let ype de l'object par ex int, double,...  
		string value;
};

#endif //_OBJECT_H_INCLUDED_

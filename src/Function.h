//filename: Function.h
//author: Rolf
//revision by: Mathieu Morainville

#ifndef _FUNCTION_H_INCLUDED_
#define _FUNCTION_H_INCLUDED_

#include <iostream>
#include <list>
#include <string>

#include "Component.h"
#include "Parameter.h"

class Function : public Component {

	public:
		/* Funktionsdeklarationen */
		Function(const string& _identifier, const string& _description = "");
		virtual ~Function();
		
		/* Getters */
		string getReturnType() const { return returnData.returnType; }
		string getReturnTypeDescription() const { return returnData.returnTypeDescription; }
		bool isStatic() const { return (getVisibility() == PRIVATE); }
		const Parameter& getParamAtIndex(const int index) const throw(const char*);
		int numParams() const { return parameterList.size(); }
		const std::list<Parameter>& getParameterList() const { return parameterList; }

		/* Parameter */
		void addParameter(const Parameter& p, int pos = 0);
		void addParameter(const string& _identifier, const string& _type, const string& _description = "");
		
		/* Setters */
		void setReturnType(const string& returnType, const string& _text = "") throw (const char*);
		
		/* toString() Methoden */
		string writeDefinitionTo() const;
		string writeDeclarationTo() const;
	
	private:
		/* private Variablen */
		struct rd {
			//fuer Initialisirungs-Liste von Function-Ctor
			rd(const string& s1, const string& s2) : returnType(s1), returnTypeDescription(s2) {}
			string returnType;
			string returnTypeDescription;
		} returnData;
		list<Parameter> parameterList;

		/* private Funktionen */	
		string writeSignatureAndReturnTypeTo() const;
};

#endif // _FUNCTION_H_INCLUDED_

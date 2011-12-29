//filename: Function.h
//author: Rolf
//revision by: Mathieu Morainville

#ifndef _FUNCTION_H_INCLUDED_
#define _FUNCTION_H_INCLUDED_

#include <iostream>
#include <list>

#include "Symbol.h"
#include "Parameter.h"

class Function : public Symbol {

	public:
		/* Funktionsdeklarationen */
		Function(const string& _identifier, const string& _description = "");
		virtual ~Function();
		
		/* Getters */
		string getReturnType() const { return returnData.returnType; }
		string getReturnTypeDescription() const { return returnData.returnTypeDescription; }
		bool isStatic() const { return isPrivate(); }
		const Parameter& getParamAtIndex(const int index) const throw(const char*);
		int numParams() const { return parameterList.size(); }
		const std::list<Parameter>& getParameterList() const { return parameterList; }

		/* Parameter */
		void addParameter(const Parameter& p, int pos = 0);//Pos. atm nicht eingebaut
		void addParameter(const string& _identifier, const string& _type, const string& _description = "");
		
		/* Setters */
		void setReturnType(const string& returnType, const string& _text = "") throw (const char*);

		/* Ausgabe */
		void writeDefinitionTo(ostream& out) const;
		void writeDeclarationTo(ostream& out) const;
		
		/* fuer den Fall der Faelle - convenience */
		void writeDefinitionTo(string& str) const;
		void writeDeclarationTo(string& str) const;
	
	private:
		/* private Variablen */
		struct rd {
			//fuer Initialisirungs-Liste von Function-Ctor
			rd(const string& s1, const string& s2) : returnType(s1), returnTypeDescription(s2) {}
			string returnTypeDescription;
			string returnType;
		} returnData;
		list<Parameter> parameterList;

		/* private Funktionen */	
		void writeSignatureAndReturnTypeTo(ostream& out) const;
		void writeSignatureAndReturnTypeTo(string& str) const;
};

#endif // _FUNCTION_H_INCLUDED_

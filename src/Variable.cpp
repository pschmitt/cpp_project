//filename: Variable.cpp
// Author : Tenguemne Frantz

#include "Object.h"
#include "Variable.h"
#include <string>
#include <iostream>

using namespace std;
				   
Variable::Variable(const string& name, const string& typeObject, const string& value,
                   Visibility visibility): Object( name, Identifier::VARIABLE, typeObject, value, visibility, false) {}

Variable::~Variable(){}

string Variable::writeDefinitionTo() const {
	string str;
	if(getVisibility() == Component::PUBLIC){
		if(!value.empty())
			str += typeObject + " " + getName() + " = " + value + ";" + "\n"; 
		else
			str += typeObject + " " + getName() + ";" + "\n"; 
	}
	else{
		if(getVisibility() == Component::PRIVATE){
			if(!value.empty())
				str += "static " + typeObject + " " + getName() + " = " + value + ";" + "\n";
			else
				str += "static " + typeObject + " " + getName() + ";" + "\n";
		}
	}
    return str;   
}
		    
            
string Variable::writeDeclarationTo() const {
	string str;
	if(getVisibility() == Component::PUBLIC){
		str += "extern " + typeObject + " " + getName() + ";\n";
	}
	return str;
}
/* main pour tester la classe Variable */
/*
int main(){
	cout << "Begin main.." << endl << endl;
	try{
		cout << "global variable v1 definition "<<endl;
		Variable v1("global", "int", "0"); 
		cout << v1.writeDeclarationTo();
		cout << v1.writeDefinitionTo();
	}
	catch(std::string s){
		cout << "Error " << s << endl;
	}
	try{
		Variable v3("intern", "int", "1", Component::PRIVATE);
		cout << "static variable v3 declaration" << endl;
		cout << v3.writeDeclarationTo();
		cout << v3.writeDefinitionTo();
	}
	catch(std::string s){
		cout << "Error " << s << endl;
	}
	try{
		cout << "global variable v5 definition avec erreur" << endl;
		Variable v5("Global", "int", "0");
		cout << v5.writeDeclarationTo();
		cout << v5.writeDefinitionTo();
	}
	catch(std::string s){
		cout << "Error " << s << endl;
	}	 
	cout << endl << "End main..";
	
	return 0;
}
*/
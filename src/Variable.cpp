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

void Variable::writeDefinitionTo(ostream& out) const {
	
	if(getVisibility() == Component::PUBLIC){
		if(!value.empty())
			out << typeObject << " " << getName() << " = " << value << ";" << endl; 
		else
			out << typeObject << " " << getName() << ";" << endl; 
	}
	else{
		if(getVisibility() == Component::PRIVATE){
			if(!value.empty())
				out << "static " << typeObject << " " << getName() << " = " << value << ";" << endl; //ecrire une methode toString() pour afficher un object selon quil a le champ value="" ou non
			else
				out << "static " << typeObject << " " << getName() << ";" << endl; //ecrire une methode toString() pour afficher un object selon quil a le champ value="" ou non
		}
	}
       
}
		    
            
void Variable::writeDeclarationTo(ostream& out) const {
	
	if(getVisibility() == Component::PUBLIC){
		out << "extern " << typeObject << " " << getName() << ";" << endl;
	}
}
/* main pour tester la classe Variable
int main(){
	cout << "Begin main.." << endl << endl;
	try{
		cout << "global variable v1 definition "<<endl;
		Variable v1("global", "int", "0"); 
		v1.writeDeclarationTo(cout);
		v1.writeDefinitionTo(cout);
	}
	catch(std::string s){
		cout << "Error " << s << endl;
	}
	try{
		Variable v3("intern", "int", "1", Component::PRIVATE);
		cout << "static variable v3 declaration" << endl;
		v3.writeDeclarationTo(cout);
		v3.writeDefinitionTo(cout);
	}
	catch(std::string s){
		cout << "Error " << s << endl;
	}
	try{
		cout << "global variable v5 definition avec erreur" << endl;
		Variable v5("Global", "int", "0");
		v5.writeDeclarationTo(cout);
		v5.writeDefinitionTo(cout);
	}
	catch(std::string s){
		cout << "Error " << s << endl;
	}	 
	cout << endl << "End main..";
	
	return 0;
}
*/
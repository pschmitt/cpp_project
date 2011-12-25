//filename: Constant.cpp
// Author : Tenguemne Frantz

#include "Object.h"
#include "Constant.h"
#include <string>
#include <iostream>

using namespace std;
				   
Constant::Constant(const string& name, const string& typeObject, const string& value,
                   Visibility visibility): Object( name, Identifier::CONSTANT, typeObject, value, visibility, true) {}

Constant::~Constant(){}

void Constant::writeDefinitionTo(ostream& out) const {
	
	if(getVisibility() == Component::PRIVATE){
		out << "static const " << typeObject << " " << getName();
		if(!value.empty()){
			out << " = " << value;
		}
		out << ";" << endl; 
	}
       
}
		    
            
void Constant::writeDeclarationTo(ostream& out) const {
	if(getVisibility() == Component::PUBLIC){
		out << "static const " << typeObject << " " << getName();
		if(!value.empty()){
			out << " = " << value; 
		}
		out << ";" << endl; 
	}
}
/*  main pour tester la classe Constant
int main(){
	cout << "Begin main.." << endl << endl;
	try{
		Constant v1("KONST", "int", "2"); 
		cout << "Test 01 Konstante OK" << endl;
		cout << "declaration " << endl;
		v1.writeDeclarationTo(cout);
		cout << "definition " << endl;
		v1.writeDefinitionTo(cout);
	}
	catch(std::string s){
		cout << "Test 01 Error:" << s << endl;
	}
	try{
		Constant v2("AUSGABE", "string", "\"Hallo!\"", Component::PRIVATE);
		cout << "Test 02 Konstante OK" << endl;
		cout << "declaration " << endl;
		v2.writeDeclarationTo(cout);
		cout << "definition " << endl;
		v2.writeDefinitionTo(cout);
	}
	catch(std::string s){
		cout << "Test 02 Error: " << s << endl;
	}
	try{
		Constant v3("SIZe", "int", "10");
		cout << "Test 03 Konstante OK" << endl;
		cout << "declaration " << endl;
		v3.writeDeclarationTo(cout);
		cout << "definition " << endl;
		v3.writeDefinitionTo(cout);
	}
	catch(std::string s){
		cout << "Test 03 Error: " << s << endl;
	}	 
	try{
		Constant v4("ECHT", "boolean", "true", Component::PUBLIC);
		cout << "Test 04 Konstante OK" << endl;
		cout << "declaration " << endl;
		v4.writeDeclarationTo(cout);
		cout << "definition " << endl;
		v4.writeDefinitionTo(cout);
	}
	catch(std::string s){
		cout << "Test 04 Error: " << s << endl;
	}
	
	try{
		Constant v5("INTERN", "int", "3", Component::PRIVATE);
		cout << "Test 05 Konstante OK" << endl;
		cout << "declaration " << endl;
		v5.writeDeclarationTo(cout);
		cout << "definition " << endl;
		v5.writeDefinitionTo(cout);
	}
	catch(std::string s){
		cout << "Test 05 Error: " << s << endl;
	}
	cout << endl << "End main..";
	
	return 0;
} // end main
*/
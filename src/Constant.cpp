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

string Constant::writeDefinitionTo() const {
	string str;
	if(getVisibility() == Component::PRIVATE){
		str += "static const " + typeObject + " " + getName();
		if(!value.empty()){
			str += " = " + value;
		}
		str += ";\n"; 
	}
    return str;   
}
		    
            
string Constant::writeDeclarationTo() const {
	string str;
	if(getVisibility() == Component::PUBLIC){
		str += "static const " + typeObject + " " + getName();
		if(!value.empty()){
			str += " = " + value; 
		}
		str += ";\n"; 
	}
	return str;
}
/*  main pour tester la classe Constant */
/*
int main(){
	cout << "Begin main.." << endl << endl;
	try{
		Constant v1("KONST", "int", "2"); 
		cout << "Test 01 Konstante OK" << endl;
		cout << "declaration " << endl;
		cout << v1.writeDeclarationTo();
		cout << "definition " << endl;
		cout << v1.writeDefinitionTo();
	}
	catch(std::string s){
		cout << "Test 01 Error:" << s << endl;
	}
	try{
		Constant v2("AUSGABE", "string", "\"Hallo!\"", Component::PRIVATE);
		cout << "Test 02 Konstante OK" << endl;
		cout << "declaration " << endl;
		cout << v2.writeDeclarationTo();
		cout << "definition " << endl;
		cout << v2.writeDefinitionTo();
	}
	catch(std::string s){
		cout << "Test 02 Error: " << s << endl;
	}
	try{
		Constant v3("SIZe", "int", "10");
		cout << "Test 03 Konstante OK" << endl;
		cout << "declaration " << endl;
		cout << v3.writeDeclarationTo();
		cout << "definition " << endl;
		cout << v3.writeDefinitionTo();
	}
	catch(std::string s){
		cout << "Test 03 Error: " << s << endl;
	}	 
	try{
		Constant v4("ECHT", "boolean", "true", Component::PUBLIC);
		cout << "Test 04 Konstante OK" << endl;
		cout << "declaration " << endl;
		cout << v4.writeDeclarationTo();
		cout << "definition " << endl;
		cout << v4.writeDefinitionTo();
	}
	catch(std::string s){
		cout << "Test 04 Error: " << s << endl;
	}
	
	try{
		Constant v5("INTERN", "int", "3", Component::PRIVATE);
		cout << "Test 05 Konstante OK" << endl;
		cout << "declaration " << endl;
		cout << v5.writeDeclarationTo();
		cout << "definition " << endl;
		cout << v5.writeDefinitionTo();
	}
	catch(std::string s){
		cout << "Test 05 Error: " << s << endl;
	}
	cout << endl << "End main..";
	
	return 0;
} // end main

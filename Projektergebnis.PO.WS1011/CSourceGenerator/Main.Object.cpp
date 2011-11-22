// Filename Main.cpp
// author : Nicolas
#include <iostream>
#include "Object.h"


//#define UNIT_TEST_OBJECT
#ifdef UNIT_TEST_OBJECT
int main (int argc, char** argv) {
	using namespace std;
	cout << "Beginn main ..." << endl;
    
    	//public und const
    Object o1("meine_variable", "int", "1");
    o1.setConst(true);
    cout << "public und const o1:" << endl;
    o1.writeDeclarationTo(cout);
    o1.writeDefinitionTo(cout);
    cout << endl;
	//public und nicht const
    Object o2("meine_variable", "int", "2");
    o2.setConst(false);
    cout << "public und nicht const o2:" << endl;
    o2.writeDeclarationTo(cout);
    o2.writeDefinitionTo(cout);
 cout << endl;

	//private und const
    Object o3("meine_variable", "int", "3", Symbol::PRIVATE);
    o3.setConst(true);
    cout << "private und const o3:" << endl;    
    o3.writeDeclarationTo(cout);
    o3.writeDefinitionTo(cout);
    cout << endl;
    //private und nicht const
    Object o4("meine_variable", "int", "4", Symbol::PRIVATE);
    o4.setConst(false);
	cout << "private und nicht const o4:" << endl;
    o4.writeDeclarationTo(cout);
    o4.writeDefinitionTo(cout);
    
   
	cout << " ... Ende main" << endl;
	//system("pause");
}
#endif


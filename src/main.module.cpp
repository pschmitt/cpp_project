#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "module.h"

using namespace std;

//#define UNIT_TEST_MODUL
#ifdef UNIT_TEST_MODUL
int main(int argc, char *argv[])
{
  //Identifier ::Identifier id (" un nom qlql" ) ;
  //id.toString() ;
//	string module_name;
   Module m1("Mymodul");
	/*if (argc < 3) {
	m1.readArgsFromUser();
	}*/ /*else {
		module_name = argv[1];
		}*/
		
		
		
		
	 m1.generateModule();
	 //system ("PAUSE");
 return 0;
 
}

#endif

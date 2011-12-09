#include "Enumeration.h"
#include "Structur.h"
#include <iostream>
//#include <string>


using namespace std;

//#define UNIT_TEST_STRUC_ENUM
#ifdef UNIT_TEST_STRUC_ENUM
int main(int argc, char *argv[])
{

    try
    {
             
      Enumeration::Enumeration e("Himmelrichtung");
     
     e.add("norden","1");
     e.add("sueden","2");
     e.add("western","3");
     e.add("osten","4");
   // e.toString();
     cout<<endl;
  
  e.writeDeclarationTo(cout);
  
  Structur::Structur stru("Zylindre");

    stru.addComponent("hoehe","double");
    stru.addComponent("breite","double");
    stru.addComponent("area","double");
    stru.writeDeclarationTo(cout);//toString();
    } catch (std::string& s) {
    	cout << s << endl;
    
    }catch(...)
      {
            cout<<"un erreur";
            }
  
    cout<<endl<<endl<<endl;
    //system("PAUSE");
    return 0;
}
#endif

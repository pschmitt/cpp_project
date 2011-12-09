// Filename module.h
// leonnel Fonkwe

#ifndef _MODULE_H_INCLUDED_
#define _MODULE_H_INCLUDED_
#include <string>
#include <list>
#include "Component.h"


using namespace std;
//typedef string Identifier;//#include "Identifier.h"

class Exception {
      
      };



class Module{
              // public funktionnen
               	public :
                       Module(const string& _name, const string& _description = "");
                 void  readArgsFromUser();
                 void  generateHFile() const;
                 void  addComponent(const Component& comp);
                 void  generateCFile() const;
                 void  generateModule() const;
                 string getName() const { return module_name.getName(); }
                 // void  add_symbol()const;
                
                // private                       
               private :     
                           
                  Identifier module_name;
		          list<const Component*> components;
      
      
      };

#endif //_MODULE_H_INCLUDED_ 


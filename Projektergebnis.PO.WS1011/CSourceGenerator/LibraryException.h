// Mbeunzoueuh Gasparri
//filename LibraryException.h
#ifndef _LIBRARYEXCEPTION_H_INCLUDED_
#define _LIBRARYEXCEPTION_H_INCLUDED_
#include <iostream>
#include <string>
#include "ProjectException.h"

using namespace std;
class LibraryException : public ProjectException
{
	public: 

		 LibraryException() throw();
		  virtual const string handlung()const throw();
		  


		
};
#endif
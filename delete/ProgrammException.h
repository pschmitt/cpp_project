// Mbeunzoueuh Gasparri
//filename ProgrammException.h
#ifndef _PROGRAMMEXCEPTION_H_INCLUDED_
#define _PROGRAMMEXCEPTION_H_INCLUDED_
#include <iostream>
#include <string>

#include"ProjectException.h"

using namespace std;
class ProgrammException :public ProjectException
{
	public: 

		 ProgrammException() throw();
		  virtual const string handlung()const throw();
		  


		
};
#endif
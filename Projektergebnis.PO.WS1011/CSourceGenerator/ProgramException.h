/*
 * ProgramException.h
 *
 * 		Author: Mbeunzoueuh Gasparri
 * Revision by: Philipp Schmitt
 *
 */

#ifndef _PROGRAMMEXCEPTION_H_INCLUDED_
#define _PROGRAMMEXCEPTION_H_INCLUDED_
#include <iostream>
#include <string>

#include"ProjectException.h"

using namespace std;
class ProgrammException: public ProjectException {
public:

	ProgramException() throw ();
	virtual const string handlung() const throw ();

};
#endif

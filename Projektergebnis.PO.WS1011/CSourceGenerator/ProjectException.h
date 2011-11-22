// Mbeunzoueuh Gasparri
// filename ProjectException.h
#ifndef _PROJECTEXCEPTION_H_INCLUDED_
#define _PROJECTEXCEPTION_H_INCLUDED_
#include <iostream>
#include <string>

using namespace std;
class ProjectException {
public:
	ProjectException() throw ();
	virtual const string handlung() const throw ();
};
#endif

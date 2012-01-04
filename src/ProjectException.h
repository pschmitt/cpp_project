// Filename: ProjectException
// Creator: Montagnoni Thomas
// Date: 26/12/2011
// Version: 0.1

#ifndef _PROJECTEXCEPTION_H_INCLUDED_
#define _PROJECTEXCEPTION_H_INCLUDED_
#include <string>

using namespace std;

class ProjectException {
	public:
		ProjectException() throw ();
		virtual const string reason() const throw();
};
#endif

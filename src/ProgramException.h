// Filename: ProgramException.h
// Creator: Montagnoni Thomas
// Date: 26/12/2011
// Version: 0.1

#ifndef _PROGRAMEXCEPTION_H_INCLUDED_
#define _PROGRAMEXCEPTION_H_INCLUDED_
#include <string>

using namespace std;

class ProgramException {
	public:
		ProgramException() throw ();
		virtual const string reason() const throw();
};
#endif
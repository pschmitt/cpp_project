// Filename: LibraryException.h
// Creator: Montagnoni Thomas
// Date: 26/12/2011
// Version: 0.1

#ifndef _LIBRARYEXCEPTION_H_INCLUDED_
#define _LIBRARYEXCEPTION_H_INCLUDED_
#include <string>

using namespace std;

class LibraryException {
	public:
		LibraryException() throw ();
		virtual const string reason() const throw();
};
#endif
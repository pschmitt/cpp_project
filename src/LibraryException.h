/*
 * LibraryException.h
 *
 * 		Author: Mbeunzoueuh Gasparri
 * Revision by: Philipp Schmitt
 *
 */

#ifndef _LIBRARYEXCEPTION_H_INCLUDED_
#define _LIBRARYEXCEPTION_H_INCLUDED_
#include <string>
#include "ProjectException.h"

using namespace std;

class LibraryException: public ProjectException {
public:

	LibraryException() throw ();
	virtual const char* what() const throw ();

};
#endif

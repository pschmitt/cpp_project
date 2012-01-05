// filename: LibraryException.cpp
// Creator: Montagnoni Thomas
// Date: 26/12/2011
// Version: 0.1

#include "LibraryException.h"

LibraryException::LibraryException() throw() {}

const string LibraryException::reason() const throw() {
	return "The Directory can't be created: he already exists";
}

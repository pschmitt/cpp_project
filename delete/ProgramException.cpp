// filename: ProgramException.cpp
// Creator: Montagnoni Thomas
// Date: 26/12/2011
// Version: 0.1

#include "ProgramException.h"

ProgramException::ProgramException() throw() {};

const string ProgramException::reason() const throw() {
	return "The Directory can't be created: he already exists";
}

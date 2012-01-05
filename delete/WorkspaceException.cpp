// Mbeunzoueuh Gasparri
// filename WorkspaceException.cpp
#include"WorkspaceException.h"

WorkspaceException::WorkspaceException() throw () {
}

const string WorkspaceException::what() const throw () {
	return "Cannot create directory: already exists";
}

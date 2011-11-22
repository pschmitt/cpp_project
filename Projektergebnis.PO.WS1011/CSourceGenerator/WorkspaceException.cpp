// Mbeunzoueuh Gasparri
// filename WorkspaceException.cpp
#include"WorkspaceException.h"

WorkspaceException::WorkspaceException() throw () {
}
;

const string WorkspaceException::handlung() const throw () {
	return "Directory already exists";
}

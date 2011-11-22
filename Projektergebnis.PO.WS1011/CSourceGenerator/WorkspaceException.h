// Mbeunzoueuh Gasparri
// filename WorkspaceException.h
#ifndef _WORKSPACEEXCEPTION_H_INCLUDED_
#define _WORKSPACEEXCEPTION_H_INCLUDED_

#include <iostream>
#include <string>

using namespace std;

class WorkspaceException {
public:
	WorkspaceException() throw ();
	const string handlung() const throw ();
};
#endif

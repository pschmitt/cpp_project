// filename: ProjectException
// Creator: Montagnoni Thomas
// Date: 26/12/2011
// Version: 0.1

#include "ProjectException.h"

ProjectException::ProjectException() throw() {

}

const string ProjectException::what() const throw() {
	return "The Directory can't be created: he already exists";
}


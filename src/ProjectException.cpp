/*
 * ProjectException.cpp
 *
 * 		Author: Mbeunzoueuh Gasparri
 * Revision by: Philipp Schmitt
 *
 */

#include"ProjectException.h"

ProjectException::ProjectException() throw () {
}

const char* ProjectException::what() const throw () {
	return "Cannot create directory: already exists";
}

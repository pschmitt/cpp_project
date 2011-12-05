/*
 * ProjectException.h
 *
 * 		Author: Mbeunzoueuh Gasparri
 * Revision by: Philipp Schmitt
 *
 */

#ifndef _PROJECTEXCEPTION_H_INCLUDED_
#define _PROJECTEXCEPTION_H_INCLUDED_

using namespace std;

class ProjectException {
public:
	ProjectException() throw ();
	virtual const char* what() const throw ();
};
#endif

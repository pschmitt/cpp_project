// Mbeunzoueuh Gasparri
// filename ProjectException.c++
#include"ProjectException.h"

ProjectException::ProjectException() throw () {
}
;

const string ProjectException::handlung() const throw () {
	return "diese directory kann nicht erzeugt werden weil sie  schon vorhanden ist";
}

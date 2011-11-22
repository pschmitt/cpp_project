// Mbeunzoueuh Gasparri
//filename LibraryException.c++
#include"LibraryException.h"

LibraryException::LibraryException() throw() {
};

  const string LibraryException::handlung () const throw(){
		return "dieses Directory Library kann nicht erzeugt werden weil sie  schon vorhanden ist";

} 
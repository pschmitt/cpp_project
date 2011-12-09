// Mbeunzoueuh Gasparri
//filename ProgrammException.c++
#include"ProgrammException.h"

ProgrammException::ProgrammException() throw() {

};

  const string ProgrammException::handlung () const throw(){
		return "dieses Directory Library kann nicht erzeugt werden weil sie  schon vorhanden ist";

} 
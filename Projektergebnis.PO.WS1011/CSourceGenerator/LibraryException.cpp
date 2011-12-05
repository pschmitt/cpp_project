/*
 * LibraryException.cpp
 *
 * 		Author: Mbeunzoueuh Gasparri
 * Revision by: Philipp Schmitt
 *
 */

#include"LibraryException.h"

LibraryException::LibraryException() throw () {
}
;

const string LibraryException::what() const throw () {
	return "dieses Directory Library kann nicht erzeugt werden weil sie  schon vorhanden ist";

}

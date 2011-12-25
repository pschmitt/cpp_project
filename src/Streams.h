//filename: Streams.h
//author: Rolf

#ifndef _STREAMS_H_INCLUDED
#define _STREAMS_H_INCLUDED


#include <iostream>
#include <sstream>

#include "Function.h"

/*
Die hier vorgestellten Stream-Klassen sollen einen moeglichen Ansatz zu vereinfachten
Ausgabe von Quelltext mit und ohne Kommentaren (z.B. Doxygen) geben.

		stringstream
			|
		Stream (abstrakt)
		|		|
	DefinitionStream (.c)	DeclarationStream (.h)
		|
	DoxygenDefinitionStream

Mittels Ueberladen von Operatoren ist es moeglich, in die Ausgabe der Components
(Functions, ...) in die Streams umzuleiten. Der Stream kann dann je nach Belieben
zusaetzliche Kommentare (siehe DoxygenDefinitionStream) hinzufuegen. Dazu muss fuer
jede Komponenente der Operatoren << neu ueberladen werden.
Der Ansatz trennt Quelltext- und Quelltextkommentargenerierung sauber.

*/

class Stream : public stringstream {
	protected:
		Stream() {}
};
ostream& operator<<(ostream& out, Stream& s) {
	out << s.rdbuf();//schiebt den Pointer auch weiter *juhu*
	return out;
}

/* ... */

class DefinitionStream : public Stream { 
	public:
		virtual DefinitionStream& operator<<(const Component& c);
		/* ... */
};
DefinitionStream& DefinitionStream::operator<<(const Component& c) {
	c.writeDefinitionTo(*this);
	return *this;
}

/* ... */

class DoxygenDefinitionStream : public DefinitionStream {
	public:
		DoxygenDefinitionStream& operator<<(const Function& f);
		/* ... */
};
DoxygenDefinitionStream& DoxygenDefinitionStream::operator<<(const Function& f) {
	(*this) << "/*!" << endl;
	/*
	"Indicates that a comment block contains documentation for a function (either global or as a member of a class).
	 This command is only needed if a comment block is not placed in front (or behind) the function declaration or definition."
	 Quelle: http://www.stack.nl/~dimitri/doxygen/commands.html#cmdfn
	(*this) << "\t\\fn " << f.getReturnType() << ' ' << f.getName() << endl;
	*/
	if ( ! f.getDescription().empty()) {(*this) << "\t\\brief " << f.getDescription() << endl; }//hier noch \n ->' ' einbauen ...
	for (list<Parameter>::const_iterator it = (f.getParameterList()).begin(); it != (f.getParameterList()).end(); it++) {
		(*this) << "\t\\param " << it->getType() << ' ' << it->getName() << ' ' << it->getDescription() << endl;
	}
	(*this) << "\t\\return " << f.getReturnType(); if ( ! f.getReturnTypeDescription().empty()) { (*this) << " " << f.getReturnTypeDescription(); }
	(*this) << "" << endl; // ??? irgendetwas stimmt mit dem Ueberladen nocht nicht ganz
	(*this) << "*/" << endl;

	// Ausgabe Funktion, besser waere sowas wie: DefinitionStream::<< f
	f.writeDefinitionTo(*this);
	return *this;
}

/* ... */

class DeclarationStream : public Stream {
	public:
		virtual DeclarationStream& operator<<(const Component& c);
		/* ... */
};
DeclarationStream& DeclarationStream::operator<<(const Component& c) {
	c.writeDeclarationTo(*this);
	return *this;
}

/* ... */

#endif //_STREAMS_H_INCLUDED

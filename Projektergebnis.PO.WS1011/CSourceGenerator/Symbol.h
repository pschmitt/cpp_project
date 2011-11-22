//filename: Symbol.h
//author: Rolf

#ifndef _SYMBOL_H_INCLUDED
#define _SYMBOL_H_INCLUDED

#include "Component.h"

class Symbol : public Component {


	public:
		/* Visibility:
		Ein Symbol (Funktion/Variable) ist 'PUBLIC', wenn es
		in der Header-Datei deklariert ist (d.h. von aussen 
		sichtbar). 'PRIVATE' ist eine Hilfs-Funktion bzw.
		Hilfs-Variable, die nur im aktuellen Modul benoetigt
		wird (=nur in der C-Datei)		
		*/
		enum Visibility { PUBLIC = 0, PRIVATE = 1 };

		/* Funktionsdeklarationen */
		virtual ~Symbol() {};
		
		/* Getters */
		bool isConst() const { return isConstSymbol; }
		Visibility getVisibility() const { return visibility; }
		bool isPrivate() const { return (visibility == PRIVATE); }
		bool isPublic() const { return !isPrivate(); }
		
		/* Setters */
		void setConst(bool c);
		void setVisibility(Visibility v);
		
	protected:
		/* Symbol ist abstrakt */
		Symbol(const string& _name, Identifier::IdentifierType type, const string& _description = "");

	private:
		bool isConstSymbol;
		Visibility visibility;

};

#endif //_SYMBOL_H_INCLUDED

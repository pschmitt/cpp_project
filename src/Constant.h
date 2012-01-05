//filename: Constant.h
// Author : Tenguemne Frantz

#ifndef _CONSTANT_H_INCLUDED_
#define _CONSTANT_H_INCLUDED_

#include "Object.h"
#include <string>
using namespace std;
 /*! \class Constant
   * \brief classe representant une constante
   *
   *  La classe permet de créer un objet constant
   */

class Constant: public Object{
	public:
		/*!
		*  \brief Constructeur
		*
		*  Constructeur de la classe Constant
		*
		*  \param name : nom de la constante
		*   \param typeObject : type de donnée de la constante
		*   \param value : valuer affectée à la constante
		*   \param visibility : vaux private ou public 
		*/
		Constant(const string& name, const string& typeObject, const string& value = "", 
		 Visibility visibility = Component::PUBLIC
		);
		~Constant();
		string writeDefinitionTo () const;
		string writeDeclarationTo() const;
};
#endif //_CONSTANT_H_INCLUDED_
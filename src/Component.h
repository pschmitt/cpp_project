/*filename: component.h
  author: clement Gorlt
*/
#ifndef COMPONENT_H_INCLUDED
#define COMPONENT_H_INCLUDED

#include <string>
#include "Identifier.h"
using std::string;
class Component {
public:
       enum Visibility {PUBLIC, PROTECTED, PRIVATE};
       const string& getName() const;
       const string& getDescription() const;
       Visibility getVisibility()const;
       const bool getConst()const;
       void setDescription(const string& description);
       void setVisibility(Visibility newVisibility);
       void setConst(bool newConst);
       virtual ~Component();
protected:
       Component(const string& name, Identifier::IdentifierType type, Visibility visibility = PUBLIC, bool isConst = false, const string& description = "");
private:
        Identifier identifier;
		bool isConst;
        Visibility visibility;
};
#endif

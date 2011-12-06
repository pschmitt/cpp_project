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
       enum Visibility {PRIVATE, PUBLIC};
       const string& getName() const;
       const string& getDescription() const;
       Visibility getVisibility()const;
       void setDescription(const string& description);
       void setVisibility(Visibility newVisibility);
       virtual ~Component();
protected:
       Component(const string& name, Identifier::IdentifierType type,Visibility visibility = PUBLIC, const string& description = "");
private:
        Identifier identifier;
        Visibility visibility;
}
#endif

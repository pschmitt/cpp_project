/*filename: component.h
  author: clement Gorlt
*/
#include "component.h"

Component::Component(const string& name, Identifier::IdentifierType type, Visibility visibility,bool isConst, const string& description):identifier(name, type, description), isConst(isConst), visibility(visibility)
{
}
const string& Component::getName()const
{
    return identifier.getName();
}

const string& Component::getDescription()const
{
    return identifier.getDescription();
}

Component::Visibility Component::getVisibility()const
{
     return this->visibility;
}

const bool Component::getConst() const
{
      return this->isConst;
}

void Component::setVisibility(Visibility newVisibility)
{
     this->visibility=newVisibility;
}

void Component::setDescription(const string& description)
{
     identifier.setDescription(description);
}

void Component::setConst(bool newConst)
{
     this->isConst=newConst;
}

Component::~Component(){}

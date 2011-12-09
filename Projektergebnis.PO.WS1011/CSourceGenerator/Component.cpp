/*filename: component.h
  author: clement Gorlt
*/
#include "component.h"

Component::Component(const string& name, Identifier::IdentifierType type, Visibility visibility, const string& description):identifier(name, type, description), visibility(visibility)
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

void Component::setVisibility(Visibility newVisibility)
{
     this->visibility=newVisibility;
}

void Component::setDescription(const string& description)
{
     identifier.setDescription(description);
}

Component::~Component(){}

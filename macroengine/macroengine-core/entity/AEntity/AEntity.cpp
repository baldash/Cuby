/*
** AEntity.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/entity/AEntity/AEntity.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Wed Feb 14 23:47:28 2018 Sylvain CHAUGNY
*/

# include				"macroengine-core/log/log.hpp"
#include				"AEntity.hpp"

macroengine::entity::AEntity::AEntity() :
  Object("AEntity"),
  _properties_mask() {
}

macroengine::utl::BitMask		&macroengine::entity::AEntity::getMask() {
  return _properties_mask;
}

void					macroengine::entity::AEntity::dump() {
  Dump::display("==== AEntity ====");
  _properties_mask.dump();
  Dump::display("=================");
}

void					macroengine::entity::AEntity::addProperty(macroengine::property::e_property property) {
  _properties_mask += property;
}

void					macroengine::entity::AEntity::addSubProperty(macroengine::property::e_property prop, macroengine::property::e_subproperty sub) {
  _subproperties[prop] += sub;
}

void					macroengine::entity::AEntity::addSubProperties(macroengine::property::e_property prop, const macroengine::utl::BitMask &sub) {
  _subproperties[prop] = sub;
}

macroengine::entity::t_subproperties	&macroengine::entity::AEntity::getSubProperties() {
  return _subproperties;
}

//const macroengine::t_identifier		&macroengine::entity::AEntity::getIdentifier() const {
//  return Object::getIdentifier();
//}
//
//void					macroengine::entity::AEntity::setIdentifier(const macroengine::t_identifier &identifier) {
//  Object::setIdentifier(identifier);
//}

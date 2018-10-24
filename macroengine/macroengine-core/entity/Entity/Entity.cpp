/*
** Entity.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/entity/Entity/Entity.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Wed Feb 14 23:09:38 2018 Sylvain CHAUGNY
*/

# include					"macroengine-core/utl/strings.hpp"
# include					"macroengine-core/exception/BadPermissionException/BadPermissionException.hpp"
#include					"Entity.hpp"

macroengine::entity::Entity::Entity() :
  AEntity(),
  Collidable(),
  Drawable(),
  Movable(),
  Controllable(),
  Factory(),
  Scriptable(),
  _remove(false) {
  setClassName("Entity");
}

void						macroengine::entity::Entity::dump() {
}

macroengine::utl::BitMask			&macroengine::entity::Entity::getPermissions() {
  return getMask();
}

void						macroengine::entity::Entity::setClassName(std::string const &name) {
  Object::setClassName(name);
}

macroengine::entity::component::Collidable	&macroengine::entity::Entity::asCollidable() {
  if (getMask().contains(property::COLLIDABLE)) {
    return *this;
  }
  throw exception::BadPermissionException(Strings("core_entity_no_permission", getClassName(), std::string("COLLIDABLE")));
}

macroengine::entity::component::Drawable	&macroengine::entity::Entity::asDrawable() {
  if (getMask().contains(property::DRAWABLE)) {
    return *this;
  }
  throw exception::BadPermissionException(Strings("core_entity_no_permission", getClassName(), std::string("DRAWABLE")));
}

macroengine::entity::component::Movable		&macroengine::entity::Entity::asMovable() {
  if (getMask().contains(property::MOVABLE)) {
    return *this;
  }
  throw exception::BadPermissionException(Strings("core_entity_no_permission", getClassName(), std::string("MOVABLE")));
}

macroengine::entity::component::Controllable	&macroengine::entity::Entity::asControllable() {
  if (getMask().contains(property::CONTROLLABLE)) {
    return *this;
  }
  throw exception::BadPermissionException(Strings("core_entity_no_permission", getClassName(), std::string("CONTROLLABLE")));
}

macroengine::entity::component::Factory		&macroengine::entity::Entity::asFactory() {
  if (getMask().contains(property::FACTORY)) {
    return *this;
  }
  throw exception::BadPermissionException(Strings("core_entity_no_permission", getClassName(), std::string("FACTORY")));
}

macroengine::entity::component::Scriptable	&macroengine::entity::Entity::asScriptable() {
  if (getMask().contains(property::SCRIPTABLE)) {
    return *this;
  }
  throw exception::BadPermissionException(Strings("core_entity_no_permission", getClassName(), std::string("SCRIPTABLE")));
}

void						macroengine::entity::Entity::remove() {
  _remove = true;
}

bool						macroengine::entity::Entity::getRemove() {
  return _remove;
}

macroengine::utl::BitMask			&macroengine::entity::Entity::getPermissionProperties(macroengine::property::e_property prop) {
  return getSubProperties()[prop];
}

void						macroengine::entity::Entity::error(std::string const &str, int indentation) {
  Object::error(str, indentation);
}

void						macroengine::entity::Entity::warning(std::string const &str, int indentation) {
  Object::warning(str, indentation);
}

void						macroengine::entity::Entity::log(std::string const &str, int indentation) {
  Object::log(str, indentation);
}

void						macroengine::entity::Entity::setIdentifier(t_identifier const &identifier) {
  AEntity::setIdentifier(identifier);
}

const macroengine::t_identifier			&macroengine::entity::Entity::getIdentifier() const {
  return AEntity::getIdentifier();
}

std::string const				&macroengine::entity::Entity::getClassName() {
  return Object::getClassName();
}

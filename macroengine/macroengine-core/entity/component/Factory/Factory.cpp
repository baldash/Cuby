/*
** Factory.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/entity/component/Factory/Factory.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Mar 01 10:03:49 2018 Sylvain CHAUGNY
*/

# include					"macroengine-core/utl/macros/macros_attributes.hpp"
# include					"macroengine-core/utl/configuration.hpp"
# include					"macroengine-core/utl/strings.hpp"
# include					"macroengine-core/utl/exceptions.hpp"
#include					"Factory.hpp"

macroengine::entity::Entity			&macroengine::entity::component::Factory::addEntity(std::string const &str, macroengine::entity::Entity *ent) {
  t_identifier 					identifier;

  log(Strings("core_building_entity", str));
  identifier = findCreatedEntity(toIdentifier(str));
  if (identifier.id != -1) {
    warning(Strings("core_building_entity_already_exists", str));
  } else {
    identifier.name = str;
    identifier.id = EntityIDGenerator.newID();
    _created_entities[identifier] = configuration::t_built_entity(ent);
  }
  _created_entities[identifier]->setIdentifier(identifier);
  log(Strings("core_entity_id", _created_entities[identifier]->getIdentifier().id));
  log(Strings("core_success"));
  return *_created_entities[identifier];
}

macroengine::configuration::t_built_entities	&macroengine::entity::component::Factory::getCreatedEntities() {
  return _created_entities;
}

const macroengine::t_identifier			&macroengine::entity::component::Factory::findCreatedEntity(const macroengine::t_identifier &identifier) {
  if (identifier.filled()) {
    if (_created_entities.find(identifier) != _created_entities.end()) {
      return identifier;
    }
    return _null_identifier;
  }
  for (auto &&r: _created_entities) {
    if (identifier.id != -1) {
      if (r.first.id == identifier.id) {
	return r.first;
      }
    } else {
      if (r.first.name == identifier.name) {
	return r.first;
      }
    }
  }
  return _null_identifier;
}

macroengine::entity::Entity			&macroengine::entity::component::Factory::invoke(std::string const &) {
  macroengine::entity::Entity			*ptr = nullptr;

  return *dynamic_cast<macroengine::entity::Entity *>(ptr);
}

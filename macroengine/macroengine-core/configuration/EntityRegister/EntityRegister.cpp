/*
** EntityRegister.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/entity/register/EntityRegister/EntityRegister.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Feb 08 10:17:54 2018 Sylvain CHAUGNY
*/

# include					"macroengine-core/utl/strings.hpp"
# include					"macroengine-core/utl/configuration.hpp"
#include					"EntityRegister.hpp"

macroengine::configuration::EntityRegister::EntityRegister() :
  Object("EntityRegister") {
}

void						macroengine::configuration::EntityRegister::dump() {
}

int						macroengine::configuration::EntityRegister::add(std::string const &name, t_builder builder) {
  t_identifier 					identifier;

  log(Strings("core_registering_entity", name));
  if (findRegisteredEntity(toIdentifier(name)).id != -1) {
    error(Strings("core_fail_registering_entity", name));
    return 1;
  }
  identifier.id = EntityIDGenerator.newID();
  identifier.name = name;
  _register[identifier] = builder;
  log(Strings("core_success"));
  return 0;
}

int						macroengine::configuration::EntityRegister::enableAtLaunch(const std::string &name) {
  t_identifier 					identifier;

  log(Strings("core_enabling_entity_at_launch", name));
  identifier = findRegisteredEntity(toIdentifier(name));
  if (identifier.id != -1) {
    _enabled_at_launch[identifier] = true;
    log(Strings("core_success"));
    return 0;
  }
  error(Strings("core_fail_enabling_entity_at_launch", name));
  return 1;
}

int						macroengine::configuration::EntityRegister::buildEntities() {
  for (auto &&registered: _register) {
    if (build(registered.first)) {
      return 1;
    }
  }
  return 0;
}

int						macroengine::configuration::EntityRegister::configure() {
  return buildEntities();
}

macroengine::configuration::t_built_entity	&macroengine::configuration::EntityRegister::get(t_identifier const &identifier) {
  if (identifier.id != -1) {
    return get(identifier.id);
  } else {
    return get(identifier.name);
  }
}

int						macroengine::configuration::EntityRegister::build(const macroengine::t_identifier &identifier) {
  if (identifier.id != -1) {
    return build(identifier.id);
  } else {
    return build(identifier.name);
  }
}

macroengine::configuration::t_built_entities	&macroengine::configuration::EntityRegister::getAll() {
  return _built_entities;
}

const macroengine::t_identifier			&macroengine::configuration::EntityRegister::findRegisteredEntity(t_identifier const &identifier) {
  if (identifier.filled()) {
    if (_register.find(identifier) != _register.end()) {
      return identifier;
    }
    return _null_identifier;
  }
  for (auto &&r: _register) {
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

const macroengine::t_identifier			&macroengine::configuration::EntityRegister::findBuiltEntity(const macroengine::t_identifier &identifier) {
  for (auto &&r: _built_entities) {
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


macroengine::configuration::t_built_entity	&macroengine::configuration::EntityRegister::get(std::string const &name) {
  t_identifier 					identifier;

  identifier = findBuiltEntity(toIdentifier(name));
  if (identifier.id != -1) {
    return _built_entities[identifier];
  }
  return _null_entity;
}

macroengine::configuration::t_built_entity	&macroengine::configuration::EntityRegister::get(macroengine::t_entity_id const &id) {
  t_identifier 					identifier;

  identifier = findBuiltEntity(toIdentifier(id));
  if (identifier.id != -1) {
    return _built_entities[identifier];
  }
  return _null_entity;
}

int						macroengine::configuration::EntityRegister::build(std::string const &name) {
  t_identifier 					identifier;

  identifier = findRegisteredEntity(toIdentifier(name));
  log(Strings("core_building_entity", identifier.name));
  if (identifier.id != -1) {
    _built_entities[identifier] = t_built_entity(_register.at(identifier)());
    _built_entities[identifier]->setIdentifier(identifier);
    if (_built_entities.at(identifier) == nullptr) {
      error(Strings("core_fail_building_entity", name));
      return 1;
    }
  } else {
    error(Strings("core_fail_building_entity", name));
    return 1;
  }
  log(Strings("core_entity_id", _built_entities[identifier]->getIdentifier().id));
  log(Strings("core_success"));
  return 0;
}

int						macroengine::configuration::EntityRegister::build(t_entity_id const &id) {
  t_identifier 					identifier;

  identifier = findRegisteredEntity(toIdentifier(id));
  log(Strings("core_building_entity", identifier.name));
  if (identifier.id != -1) {
    _built_entities[identifier] = t_built_entity(_register.at(identifier)());
    _built_entities[identifier]->setIdentifier(identifier);
    if (_built_entities.at(identifier) == nullptr) {
      error(Strings("core_fail_building_entity", identifier.name));
      return 1;
    }
  } else {
    error(Strings("core_fail_building_entity", identifier.name));
    return 1;
  }
  log(Strings("core_entity_id", _built_entities[identifier]->getIdentifier().id));
  log(Strings("core_success"));
  return 0;
}
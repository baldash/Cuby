/*
** GeneralController.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/controller/GeneralController/GeneralController.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Feb 18 20:50:28 2018 Sylvain CHAUGNY
*/

# include			"macroengine-core/utl/strings.hpp"
# include			"macroengine-core/utl/configuration.hpp"
# include			"macroengine-core/utl/exceptions.hpp"
#include			"GeneralController.hpp"
# include			"macroengine-core/entity/Entity/Entity.hpp"

macroengine::controller::GeneralController::GeneralController() :
  _event_controller(_renderer.getWindow()) {
}

void				macroengine::controller::GeneralController::dump() {
}

int				macroengine::controller::GeneralController::configure() {
  _collidable_controller.configure();
  _controllable_controller.configure();
  _drawable_controller.configure();
  _movable_controller.configure();
  _renderer.configure(_game_configuration.window);
  _event_controller.configure();
  return 0;
}

int				macroengine::controller::GeneralController::init(macroengine::configuration::game::GameConfiguration &game,
										    macroengine::configuration::t_built_entities &entities) {
  _game_configuration = game;
  if (configure()) {
    return 1;
  }
  _entities = entities;
  sortBuiltEntities(_entities);
  return 0;
}

int				macroengine::controller::GeneralController::update() {
  retrieveEntities();
  _controllable_controller.update(_sorted[property::CONTROLLABLE], _entities);
  _scriptable_controller.update(_sorted[property::SCRIPTABLE], _entities);
  _movable_controller.update(_sorted[property::MOVABLE], _entities);
  _collidable_controller.update(_sorted[property::COLLIDABLE], _entities);
  _drawable_controller.update(_sorted[property::DRAWABLE], _entities);
  if (CoreClock.isDelayOver()) {
    _renderer.update(_sorted[property::DRAWABLE], _entities);
    _event_controller.update(_sorted[property::CONTROLLABLE], _entities);
  }
  return 0;
}

void				macroengine::controller::GeneralController::retrieveEntities() {
  std::vector<t_identifier> to_remove;

  for (auto &&entity: _entities) {
    if (entity.second->getPermissions().contains(property::FACTORY)) {
      configuration::t_built_entities to_add;
      for (auto &&created: entity.second->asFactory().getCreatedEntities()) {
	if (_entities.find(created.first) == _entities.end()) {
	  _entities[created.first] = created.second;
	} else {
	  throw exception::AlreadyDefinedEntityIDException(Strings("core_already_defined_entity_id", created.first));
	}
      }
      if (entity.second->asFactory().getCreatedEntities().size()) {
	sortBuiltEntities(entity.second->asFactory().getCreatedEntities());
	entity.second->asFactory().getCreatedEntities().clear();
      }
    }
    if (entity.second->getRemove()) {
      to_remove.emplace_back(entity.first);
    }
  }
  for (auto &&str: to_remove) {
    _entities.erase(str);
  }
}

bool				macroengine::controller::GeneralController::isRunning() {
  return _event_controller.isRunning();
}

void				macroengine::controller::GeneralController::sortBuiltEntities(macroengine::configuration::t_built_entities &entities) {
  for (auto &&ent: entities) {
    if (ent.second->getPermissions().contains(property::DRAWABLE)) {
      _sorted[property::DRAWABLE][ent.first] = ent.second;
    }
    if (ent.second->getPermissions().contains(property::CONTROLLABLE)) {
      _sorted[property::CONTROLLABLE][ent.first] = ent.second;
    }
    if (ent.second->getPermissions().contains(property::COLLIDABLE)) {
      _sorted[property::COLLIDABLE][ent.first] = ent.second;
    }
    if (ent.second->getPermissions().contains(property::MOVABLE)) {
      _sorted[property::MOVABLE][ent.first] = ent.second;
    }
    if (ent.second->getPermissions().contains(property::FACTORY)) {
      _sorted[property::FACTORY][ent.first] = ent.second;
    }
    if (ent.second->getPermissions().contains(property::SCRIPTABLE)) {
      _sorted[property::SCRIPTABLE][ent.first] = ent.second;
    }
  }
}

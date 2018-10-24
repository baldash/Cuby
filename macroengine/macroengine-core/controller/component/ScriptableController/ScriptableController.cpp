/*
** ScriptableController.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/controller/component/ScriptableController/ScriptableController.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Mar 01 22:19:59 2018 Sylvain CHAUGNY
*/

#include			"ScriptableController.hpp"
# include			"macroengine-core/utl/configuration.hpp"

void				macroengine::controller::component::ScriptableController::dump() {
}

int				macroengine::controller::component::ScriptableController::configure() {
  setClassName("ScriptableController");
  return 0;
}

int				macroengine::controller::component::ScriptableController::stop() {
  return 0;
}

int				macroengine::controller::component::ScriptableController::update(macroengine::configuration::t_built_entities &entities,
												    macroengine::configuration::t_built_entities &total) {
  for (auto &&ent: entities) {
    for (auto &&callable: ent.second->asScriptable().getCallables()) {
      if (CoreClock.isDelayOver(callable.second.delay_id)) {
	callable.second.data.ticks++;
	callable.second.callable(total, callable.second.data);
      }
    }
  }
  return 0;
}

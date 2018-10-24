/*
** ControllableController.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/controller/ControllableController/ControllableController.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Feb 18 21:18:55 2018 Sylvain CHAUGNY
*/

# include			"macroengine-core/utl/macros/macros_attributes.hpp"
#include			"ControllableController.hpp"
# include			"macroengine-core/utl/configuration.hpp"

void				macroengine::controller::component::ControllableController::dump() {
}

int				macroengine::controller::component::ControllableController::configure() {
  setClassName("ControllableController");
  return 0;
}

int				macroengine::controller::component::ControllableController::stop() {
  return 0;
}

int				macroengine::controller::component::ControllableController::update(UNUSED macroengine::configuration::t_built_entities &entities, UNUSED macroengine::configuration::t_built_entities &total) {
  return 0;
}

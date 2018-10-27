/*
** CollidableController.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/controller/CollidableController/CollidableController.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Feb 18 21:18:55 2018 Sylvain CHAUGNY
*/

# include			"macroengine-core/utl/macros/macros_attributes.hpp"
#include			"CollidableController.hpp"
# include			"macroengine-core/utl/configuration.hpp"

void				macroengine::controller::component::CollidableController::dump() {
}

int				macroengine::controller::component::CollidableController::configure() {
  setClassName("CollidableController");
  return 0;
}

int				macroengine::controller::component::CollidableController::stop() {
  return 0;
}

int				macroengine::controller::component::CollidableController::update(UNUSED macroengine::configuration::t_built_entities &entities, UNUSED macroengine::configuration::t_built_entities &total) {
  return 0;
}

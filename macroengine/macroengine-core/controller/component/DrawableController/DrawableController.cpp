/*
** DrawableController.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/controller/DrawableController/DrawableController.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Feb 18 21:18:55 2018 Sylvain CHAUGNY
*/

# include			"macroengine-core/utl/macros/macros_attributes.hpp"
#include			"DrawableController.hpp"
# include			"macroengine-core/utl/configuration.hpp"

void				macroengine::controller::component::DrawableController::dump() {
}

int				macroengine::controller::component::DrawableController::configure() {
  setClassName("DrawableController");
  return 0;
}

int				macroengine::controller::component::DrawableController::stop() {
  return 0;
}

int				macroengine::controller::component::DrawableController::update(macroengine::configuration::t_built_entities &entities,
												  UNUSED macroengine::configuration::t_built_entities &total) {
  for (auto &&ent: entities) {
    if (ent.second->getPermissionProperties(property::DRAWABLE).contains(property::ANIMATION) && ent.second->asDrawable().animationHandler().enabled()) {
      graphics::Animation	&animation = ent.second->asDrawable().animationHandler().getCurrentAnimation();
      if (animation.isStarted() && !animation.isPaused()) {
	if (CoreClock.isDelayOver(animation.getDelayID())) {
	  animation.update();
	}
      }
    }
  }
  return 0;
}

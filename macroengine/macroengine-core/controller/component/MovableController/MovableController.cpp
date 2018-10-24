/*
** MovableController.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/controller/MovableController/MovableController.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Feb 18 21:18:55 2018 Sylvain CHAUGNY
*/

# include			"macroengine-core/utl/macros/macros_attributes.hpp"
# include			"macroengine-core/utl/vector/VectorF/VectorF.hpp"
#include			"MovableController.hpp"
# include			"macroengine-core/utl/configuration.hpp"

void				macroengine::controller::component::MovableController::dump() {
}

int				macroengine::controller::component::MovableController::configure() {
  setClassName("MovableController");
  return 0;
}

int				macroengine::controller::component::MovableController::stop() {
  return 0;
}

int				macroengine::controller::component::MovableController::update(macroengine::configuration::t_built_entities &entities,
												 UNUSED macroengine::configuration::t_built_entities &total) {
  // for (auto &&ent: entities) {
  //   if (ent.second->getPermissions().contains(property::MOVABLE) && ent.second->asMovable().isUsingConstDelay() &&
  // 	CoreClock.isDelayOver(ent.second->asMovable().getConstDelay()) && ent.second->asMovable().isSelfMovementEnabled()) {
  //     utl::VectorF vec = ent.second->asMovable().getMovement();
  //     ent.second->asMovable().setRawPosition(graphics::utl::Position(ent.second->asMovable().getRawPosition().x + vec.x,
  // 								     ent.second->asMovable().getRawPosition().y + vec.y));
  //     if (ent.second->getPermissions().contains(property::DRAWABLE)) {
  // 	if (ent.second->getPermissionProperties(property::DRAWABLE).contains(property::SPRITE) &&
  // 	  ent.second->asMovable().isAllowedForDrawableSubProperty(property::SPRITE)) {
  // 	  ent.second->asDrawable().spriteHandler()
  // 	    .setPosition(graphics::utl::Position(ent.second->asDrawable().spriteHandler().getPosition().x + vec.x,
  // 						 ent.second->asDrawable().spriteHandler().getPosition().y + vec.y));
  // 	}
  // 	if (ent.second->getPermissionProperties(property::DRAWABLE).contains(property::ANIMATION) &&
  // 	    ent.second->asMovable().isAllowedForDrawableSubProperty(property::ANIMATION)) {
  // 	  ent.second->asDrawable().animationHandler()
  // 	    .setPosition(graphics::utl::Position(ent.second->asDrawable().animationHandler().getPosition().x + vec.x,
  // 						 ent.second->asDrawable().animationHandler().getPosition().y + vec.y));
  // 	}
  //     }
  //   }
  // }
  return 0;
}

/*
** Renderer.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/controller/Renderer/Renderer.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Fri Feb 23 14:38:53 2018 Sylvain CHAUGNY
*/

# include			"macroengine-core/utl/macros/macros_attributes.hpp"
# include			"macroengine-core/utl/strings.hpp"
#include			"Renderer.hpp"
# include			"macroengine-core/configuration/configuration.hpp"

macroengine::controller::Renderer::Renderer() : Object("Renderer") {
}

int				macroengine::controller::Renderer::configure(macroengine::configuration::game::GameWindowConfiguration &config) {
  _render_window.create(sf::VideoMode(static_cast<unsigned int>(config.dimensions.width),
				      static_cast<unsigned int>(config.dimensions.height)),
			"[MACROENGINE] " + config.title,
			config.fullscreen ? sf::Style::Fullscreen : sf::Style::Default);
  _render_window.setFramerateLimit(1 / MACROENGINE_VAR_DEFAULT_CORE_FREQUENCY);
  return 0;
}

int				macroengine::controller::Renderer::update(macroengine::configuration::t_built_entities &entities,
									     UNUSED macroengine::configuration::t_built_entities &total) {
  t_views 			views;

  _render_window.clear();
  for (auto &&item: entities) {
    if (item.second->getPermissionProperties(property::DRAWABLE).contains(property::VIEW) && item.second->asDrawable().viewHandler().enabled()) {
      views.insert(item.second->asDrawable().viewHandler().getAll().begin(), item.second->asDrawable().viewHandler().getAll().end());
    }
  }

  for (auto &&view: views) {
    for (auto &&entity: entities) {
      if (entity.second->getPermissionProperties(property::DRAWABLE).contains(property::SPRITE) && entity.second->asDrawable().spriteHandler().enabled()) {
	updateSprite(entity.second, total, view.second);
      }
      if (entity.second->getPermissionProperties(property::DRAWABLE).contains(property::ANIMATION) && entity.second->asDrawable().animationHandler().enabled()) {
	updateAnimation(entity.second, total, view.second);
      }
      if (entity.second->getPermissionProperties(property::DRAWABLE).contains(property::SHAPE) && entity.second->asDrawable().shapeHandler().enabled()) {
	updateShape(entity.second, total, view.second);
      }
      if (entity.second->getPermissionProperties(property::DRAWABLE).contains(property::TEXT) && entity.second->asDrawable().textHandler().enabled()) {
	updateText(entity.second, total, view.second);
      }
    }
  }
  _render_window.display();
  return 0;
}

void				macroengine::controller::Renderer::dump() {
}

sf::RenderWindow		&macroengine::controller::Renderer::getWindow() {
  return _render_window;
}

int				macroengine::controller::Renderer::updateSprite(macroengine::configuration::t_built_entity &entity,
										   UNUSED macroengine::configuration::t_built_entities &total,
										   graphics::View &view) {
  for (auto &&sprite: entity->asDrawable().spriteHandler().getAll()) {
    if (view.isElementBound(sprite.first, property::SPRITE)) {
      sf::View			tmp = _render_window.getView();

      _render_window.setView(view.getView());
      _render_window.draw(sprite.second.getSprite());
      _render_window.setView(tmp);
    } else {
      _render_window.draw(sprite.second.getSprite());
    }
  }
  return 0;
}

int				macroengine::controller::Renderer::updateAnimation(macroengine::configuration::t_built_entity &entity,
										      UNUSED macroengine::configuration::t_built_entities &total,
										      graphics::View &view) {
  graphics::Animation		&animation = entity->asDrawable().animationHandler().getCurrentAnimation();

  if (animation.isStarted()) {
    if (view.isElementBound(animation.getIdentifier(), property::ANIMATION)) {
      sf::View			tmp = _render_window.getView();

    _render_window.setView(view.getView());
    _render_window.draw(animation.getCurrentFrame());
    _render_window.setView(tmp);
  } else {
    _render_window.draw(animation.getCurrentFrame());
    }
  }
  return 0;
}

int				macroengine::controller::Renderer::updateText(macroengine::configuration::t_built_entity &entity,
										 UNUSED macroengine::configuration::t_built_entities &total,
										 graphics::View &view) {
  return 0;
}

int				macroengine::controller::Renderer::updateShape(macroengine::configuration::t_built_entity &entity,
										  UNUSED macroengine::configuration::t_built_entities &total,
										  graphics::View &view) {
  for (auto &&shape: entity->asDrawable().shapeHandler().getRectangleShapes()) {
    _render_window.draw(shape.second.getShape());
  }
  return 0;
}

int				macroengine::controller::Renderer::updateView(macroengine::configuration::t_built_entity &entity,
										 UNUSED macroengine::configuration::t_built_entities &total,
										 graphics::View &view) {
  return 0;
}

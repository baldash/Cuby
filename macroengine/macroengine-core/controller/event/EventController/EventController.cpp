/*
** EventController.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/controller/EventController/EventController.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Wed Mar 07 19:11:04 2018 Sylvain CHAUGNY
*/

#include			"EventController.hpp"
# include			"macroengine-core/entity/Entity/Entity.hpp"
# include			"macroengine-core/configuration/configuration.hpp"

macroengine::controller::EventController::EventController(sf::RenderWindow &window) :
  _window(window),
  _mouse_position(std::pair<bool, macroengine::utl::Position>(false, sf::Mouse::getPosition())),
  _running(true) {
}

void				macroengine::controller::EventController::dump() {
}

int				macroengine::controller::EventController::configure() {
  return 0;
}

int				macroengine::controller::EventController::update(macroengine::configuration::t_built_entities &entities,
										    macroengine::configuration::t_built_entities &total) {
  updateKeyboardState();
  updateMouseButtonState();
  updateEvents();
  for (auto &&entity: entities) {
    updateKey(entity.second, total);
    updateMouse(entity.second, total);
  }
  return 0;
}


void				macroengine::controller::EventController::updateEvents() {
  sf::Event			event;
  macroengine::utl::Position	pos;

  while (_window.pollEvent(event)) {
    switch (event.type) {
      case sf::Event::Closed:
	_running = false;
	break;
      default:
	break;
    }
  }
  pos = sf::Mouse::getPosition();
  _mouse_position.first = !(_mouse_position.second == pos);
  _mouse_position.second = pos;
}

void				macroengine::controller::EventController::updateKeyboardState() {
  for (int i = input::Keyboard::Unknown; i < input::Keyboard::KeyCount; i++) {
    _keyboard_state[static_cast<input::Keyboard>(i)] = sf::Keyboard::isKeyPressed(static_cast<input::Keyboard>(i));
  }
}

void				macroengine::controller::EventController::updateMouseButtonState() {
  for (int i = 0; i < input::MouseButton::ButtonCount; i++) {
    _mouse_button_state[static_cast<input::MouseButton>(i)] = sf::Mouse::isButtonPressed(static_cast<input::MouseButton>(i));
  }
}

void				macroengine::controller::EventController::updateMouse(configuration::t_built_entity &entity,
											  configuration::t_built_entities &entities) {
  for (auto &&mouse: entity->asControllable().getMouseButtonActions()) {
    if (_mouse_button_state[mouse.first]) {
      for (auto &&action: mouse.second) {
        action.position = _mouse_position.second;
	if (action.toggled || (!action.toggled && !_pressed_mouse_buttons[mouse.first])) {
	  action.data.ticks++;
	  action.data.last_callable_action_called = _last_mouse_action_called;
	  action.data.is_being_pressed = _last_mouse_action_called == action.identifier;
	  action.callable(entities, action.data);
	  _last_mouse_action_called = action.identifier;
	}
	_pressed_mouse_buttons[mouse.first] = true;
      }
    } else {
      _pressed_mouse_buttons[mouse.first] = false;
    }
  }

  if (_mouse_position.first) {
    for (auto &&mouse: entity->asControllable().getMouseMoveActions()) {
      mouse.position = _mouse_position.second;
      mouse.callable(entities, mouse.data);
    }
  }
}

void				macroengine::controller::EventController::updateKey(macroengine::configuration::t_built_entity &entity,
											macroengine::configuration::t_built_entities &entities) {
  for (auto &&key: entity->asControllable().getKeyboardActions()) {
    if (_keyboard_state[key.first]) {
      for (auto &&action: key.second) {
	if (action.toggled || (!action.toggled && !_pressed_keys[key.first])) {
	  action.data.is_being_pressed = (action.data.consecutive_ticks > 0);
	  action.data.last_callable_action_called = _last_keyboard_action_called;
	  action.data.ticks++;
	  action.data.consecutive_ticks++;
	  action.callable(entities, action.data);
	  _last_keyboard_action_called = action.identifier;
	}
	_pressed_keys[key.first] = true;
      }
    } else {
      if (_pressed_keys[key.first]) {
        for (auto &&action: key.second) {
          if (action.ending_callable != nullptr) {
            action.ending_callable_data.ticks++;
            action.ending_callable_data.last_callable_action_called = _last_keyboard_action_called;
            action.ending_callable(entities, action.ending_callable_data);
          }
          action.data.is_being_pressed = false;
          action.data.consecutive_ticks = 0;
        }
      }
      _pressed_keys[key.first] = false;
    }
  }
}

bool				macroengine::controller::EventController::isRunning()
{
  return _running;
}

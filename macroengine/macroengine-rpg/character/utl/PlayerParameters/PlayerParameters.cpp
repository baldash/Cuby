/*
** PlayerParameters.cpp for Macro_Engine in /home/sylvain/Documents/projets/perso/macroengine/macroengine-rpg/character/utl/PlayerParameters/PlayerParameters.cpp
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Tue Jul 31 13:50:56 2018 Sylvain Chaugny
*/

#include "PlayerParameters.hpp"

macroengine::rpg::PlayerParameters::PlayerParameters() {
  _keys[e_player_key::UP] = input::Keyboard::Up;
  _keys[e_player_key::DOWN] = input::Keyboard::Down;
  _keys[e_player_key::LEFT] = input::Keyboard::Left;
  _keys[e_player_key::RIGHT] = input::Keyboard::Right;
  _keys[e_player_key::UNKNOWN] = input::Keyboard::Unknown;

  _key_action_names[e_player_key::UP] = "rpg_player_default_up";
  _key_action_names[e_player_key::DOWN] = "rpg_player_default_down";
  _key_action_names[e_player_key::LEFT] = "rpg_player_default_left";
  _key_action_names[e_player_key::RIGHT] = "rpg_player_default_right";
  _key_action_names[e_player_key::UNKNOWN] = "rpg_player_default_unknown";
}

macroengine::input::Keyboard const	&macroengine::rpg::PlayerParameters::getKey(const macroengine::rpg::e_player_key &key) {
  if (key >= e_player_key::UNKNOWN) {
    return _keys[e_player_key::UNKNOWN];
  }
  return _keys[key];
}

std::string const			&macroengine::rpg::PlayerParameters::getKeyActionName(const macroengine::rpg::e_player_key &key) const {
  if (key >= e_player_key::UNKNOWN) {
    return _key_action_names[e_player_key::UNKNOWN];
  }
  return _key_action_names[key];
}

int					macroengine::rpg::PlayerParameters::setKey(const macroengine::rpg::e_player_key &key,
										       macroengine::input::Keyboard const &value) {
  if (key >= UNKNOWN) {
    return 1;
  }
  _keys[key] = value;
  return 0;
}

void					macroengine::rpg::PlayerParameters::setKeyActionIdentifier(macroengine::rpg::e_player_key const &key, const macroengine::t_identifier &id) {
  _keys_action_identifiers[key] = id;
}

macroengine::t_identifier const		&macroengine::rpg::PlayerParameters::getKeyActionIdentifier(const macroengine::rpg::e_player_key &key) {
  return _keys_action_identifiers[key];
}

/*
** Player.cpp for Macro_Engine in /home/sylvain/Documents/projets/perso/macroengine/macroengine-rpg/character/Player/Player.cpp
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Tue Jul 31 13:26:54 2018 Sylvain Chaugny
*/

#include			"Player.hpp"
#include "Player.hpp"


macroengine::rpg::Player::Player() : Character(), Controllable(),
				     _params() {
  _params.setKeyActionIdentifier(e_player_key::UP,
				 asControllable().addKeyboardAction(_params.getKeyActionName(e_player_key::UP),
								    _params.getKey(e_player_key::UP), makeCallable(Player::moveUp)).identifier);
  asControllable().getKeyboardAction(_params.getKeyActionIdentifier(e_player_key::UP)).toggled = true;

  _params.setKeyActionIdentifier(e_player_key::DOWN,
				 asControllable().addKeyboardAction(_params.getKeyActionName(e_player_key::DOWN),
								    _params.getKey(e_player_key::DOWN), makeCallable(Player::moveDown)).identifier);
  asControllable().getKeyboardAction(_params.getKeyActionIdentifier(e_player_key::DOWN)).toggled = true;

  _params.setKeyActionIdentifier(e_player_key::LEFT,
				 asControllable().addKeyboardAction(_params.getKeyActionName(e_player_key::LEFT),
								    _params.getKey(e_player_key::LEFT), makeCallable(Player::moveLeft)).identifier);
  asControllable().getKeyboardAction(_params.getKeyActionIdentifier(e_player_key::LEFT)).toggled = true;

  _params.setKeyActionIdentifier(e_player_key::RIGHT,
				 asControllable().addKeyboardAction(_params.getKeyActionName(e_player_key::RIGHT),
								    _params.getKey(e_player_key::RIGHT), makeCallable(Player::moveRight)).identifier);
  asControllable().getKeyboardAction(_params.getKeyActionIdentifier(e_player_key::RIGHT)).toggled = true;
}

void				macroengine::rpg::Player::changeMoveKey(macroengine::rpg::e_player_key const &key, const macroengine::input::Keyboard &value) {
  input::Keyboard 		tmp;

  tmp = _params.getKey(key);
  if (tmp == input::Keyboard::Unknown || _params.setKey(key, value)) {
    return;
  }
  asControllable().changeKeyboardAction(toIdentifier(_params.getKeyActionName(key)), tmp, _params.getKey(key));
}

const macroengine::t_identifier	&macroengine::rpg::Player::getKeyActionIdentifier(macroengine::rpg::e_player_key const &key) {
  return _params.getKeyActionIdentifier(key);
}

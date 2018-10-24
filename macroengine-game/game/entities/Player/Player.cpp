#include "Player.hpp"
using namespace macroengine;

Player::Player(): rpg::Player() {
  setClassName("Player");
  changeMoveKey(rpg::e_player_key::UP, input::Keyboard::A);
  storeSprite("sprite_default", findInResourcesDirectory("img/texture/blue.png"));
  storeAnimation("animation_left", findInResourcesDirectory("animation/test.ini"));
  storeAnimation("animation_right", findInResourcesDirectory("animation/test2.ini"));

  asControllable().addEndingCallableToAction(getKeyActionIdentifier(rpg::e_player_key::LEFT), makeCallable(Player::flush_animation));
  asControllable().addEndingCallableToAction(getKeyActionIdentifier(rpg::e_player_key::RIGHT), makeCallable(Player::flush_animation));

  getStatistics().setSpeed(3);

  setSprite("sprite_default");
}

CallableFunction(Player::flush_animation) {
  disableAnimations();
  setSprite("sprite_default");
  error("blep");
}

CallableFunction(Player::moveLeft) {
  if (!data.is_being_pressed) {
    setAnimation("animation_left");
  }
  moveCharacterLeft();
  log("left : " + data.last_callable_action_called.name + ", " + (data.is_being_pressed ? "true" : "false") + ", " + std::to_string(data.consecutive_ticks));
}

CallableFunction(Player::moveRight) {
  if (!data.is_being_pressed) {
    setAnimation("animation_right");
  }
  moveCharacterRight();
  log("right: " + data.last_callable_action_called.name + ", " + (data.is_being_pressed ? "true" : "false") + ", " + std::to_string(data.consecutive_ticks));
}

CallableFunction(Player::moveUp) {
  changeMoveKey(rpg::e_player_key::UP, input::Keyboard::B);
  moveCharacterUp(2);
  log("up");
}

CallableFunction(Player::moveDown) {
  moveCharacterDown();
  log("down");
}

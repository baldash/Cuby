#ifndef MACROENGINE_GAME_PLAYER_HPP
#define MACROENGINE_GAME_PLAYER_HPP

#include <macroengine-rpg/macroengine-rpg.hpp>

class Player : public macroengine::rpg::Player {
public:
  Player();
  virtual ~Player() = default;

  CallableFunction(moveLeft) override;
  CallableFunction(moveRight) override;
  CallableFunction(moveUp) override;
  CallableFunction(moveDown) override;

  CallableFunction(flush_animation);
};


#endif //MACROENGINE_GAME_PLAYER_HPP

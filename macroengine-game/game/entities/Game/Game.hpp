/*
** Game.hpp for macroengine-game in /home/sylvain/Documents/projets/perso/macroengine-game/game/entities/Game/Game.hpp
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Tue Jul 31 08:08:41 2018 Sylvain Chaugny
*/

#ifndef MACROENGINE_GAME_GAME_HPP
#define MACROENGINE_GAME_GAME_HPP

#include <macroengine-core/macroengine-core.hpp>

class Game : public macroengine::property::Scriptable {
public:
  Game();
  virtual ~Game() = default;

  CallableFunction(script);
};

#endif //MACROENGINE_GAME_GAME_HPP

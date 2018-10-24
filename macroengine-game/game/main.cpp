/*
** main.cpp for macroengine-game in /home/sylvain/Documents/projets/perso/macroengine-game/game/main.cpp
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Wed Jul 04 12:31:05 2018 Sylvain Chaugny
*/

#include <macroengine-core/macroengine-core.hpp>
#include "entities/entities.hpp"

int main(int ac, char **av, char **ae) {
  setEnvironment(ac, av, ae);

  registerEntity("game", Game);
  registerEntity("menu_controller", MenuController);
  registerEntity("map_factory", MapFactory);
  registerEntity("player_factory", PlayerFactory);
  runEngine();

  return 0;
}

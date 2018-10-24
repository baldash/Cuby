/*
** GameConfiguration.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/configuration/game/GameConfiguration/GameConfiguration.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Mar 15 13:41:33 2018 Sylvain CHAUGNY
*/

#include							"GameConfiguration.hpp"

void								macroengine::configuration::game::GameConfiguration::dump() {
}

int								macroengine::configuration::game::GameConfiguration::configure(macroengine::parser::ini::IniParser &parser) {
  if (parser.scopeExists(window.getConfigScope())) {
    window.configure(parser[window.getConfigScope()]);
  }
  if (parser.scopeExists(misc.getConfigScope())) {
    misc.configure(parser[misc.getConfigScope()]);
  }
  return 0;
}

const macroengine::configuration::game::GameConfiguration	&macroengine::configuration::game::GameConfiguration::getAsConst() const {
  return *this;
}

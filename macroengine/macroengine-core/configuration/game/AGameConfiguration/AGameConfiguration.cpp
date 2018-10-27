/*
** AGameConfiguration.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/configuration/game/AGameConfiguration/AGameConfiguration.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Mar 15 14:22:54 2018 Sylvain CHAUGNY
*/

#include				"AGameConfiguration.hpp"

macroengine::configuration::game::AGameConfiguration::AGameConfiguration(std::string const &scope) :
  _scope(scope) {
}

std::string const			&macroengine::configuration::game::AGameConfiguration::getConfigScope() {
  return _scope;
}

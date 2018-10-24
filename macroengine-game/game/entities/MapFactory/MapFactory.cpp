/*
** MapFactory.cpp for macroengine-game in /home/sylvain/Documents/projets/perso/macroengine-game/game/entities/MapFactory/MapFactory.cpp
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Wed Jul 04 12:43:04 2018 Sylvain Chaugny
*/

#include "MapFactory.hpp"
#include "entities/MapLevel/MapLevel.hpp"

MapFactory::MapFactory() : Factory() {
  setClassName("MapFactory");
}

macroengine::entity::Entity &MapFactory::invoke(std::string const &str) {
  return asFactory().addEntity(str, new MapLevel());
}

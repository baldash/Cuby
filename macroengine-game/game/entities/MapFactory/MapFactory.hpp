/*
** MapFactory.hpp for macroengine-game in /home/sylvain/Documents/projets/perso/macroengine-game/game/entities/MapFactory/MapFactory.hpp
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Wed Jul 04 12:41:55 2018 Sylvain Chaugny
*/

#ifndef PROJECT_MAPFACTORY_HPP
#define PROJECT_MAPFACTORY_HPP

#include <macroengine-core/macroengine-core.hpp>

class MapFactory : public macroengine::property::Factory {
public:
  MapFactory();
  virtual ~MapFactory() = default;

  macroengine::entity::Entity &invoke(std::string const &str);
};

#endif //PROJECT_MAPFACTORY_HPP

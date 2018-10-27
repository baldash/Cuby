#ifndef MACROENGINE_GAME_PLAYERFACTORY_HPP
#define MACROENGINE_GAME_PLAYERFACTORY_HPP

#include <macroengine-core/macroengine-core.hpp>


class PlayerFactory : public macroengine::property::Factory {
public:
  PlayerFactory();
  virtual ~PlayerFactory() = default;

  macroengine::entity::Entity &invoke(std::string const &str);
};


#endif //MACROENGINE_GAME_PLAYERFACTORY_HPP

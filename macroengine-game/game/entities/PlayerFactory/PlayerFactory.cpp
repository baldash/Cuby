#include "PlayerFactory.hpp"
#include "entities/Player/Player.hpp"

PlayerFactory::PlayerFactory() : Factory() {
  setClassName("PlayerFactory");
}

macroengine::entity::Entity &PlayerFactory::invoke(std::string const &str) {
  return asFactory().addEntity(str, new Player());
}

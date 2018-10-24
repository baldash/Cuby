#include "Game.hpp"
#include "../entities.hpp"

using namespace macroengine;

Game::Game(): Scriptable() {
  asScriptable().addTimedCallable("script", makeCallable(Game::script), clock::Time(MACROENGINE_VAR_DEFAULT_CORE_FREQUENCY));
}

CallableFunction(Game::script) {
  if (data.ticks == 1) {
    findEntity<MapFactory>(entities, toIdentifier("map_factory")).invoke("map_1").as<MapLevel>().loadFromFile(findInResourcesDirectory("map/map1.ini"));
    findEntity<PlayerFactory>(entities, toIdentifier("player_factory")).invoke("player_1");
  }
  log(std::to_string(data.ticks));
}
#include "MenuController.hpp"
#include "entities/entities.hpp"

using namespace macroengine;

MenuController::MenuController() : property::Controllable() {
  asControllable().addKeyboardAction("escape", input::Keyboard::Escape, makeCallable(MenuController::Escape));
  asControllable().addKeyboardAction("space", input::Keyboard::Space, makeCallable(MenuController::Space));
}

CallableFunction(MenuController::Escape) {
  stopEngine();
}

CallableFunction(MenuController::Space) {
  auto &factory = findEntity<MapFactory>(entities, toIdentifier("map_factory")).asFactory();
  if (data.ticks == 1) {
    auto &new_map = factory.invoke("map_level_1");
    new_map.as<MapLevel>().loadFromFile(findInResourcesDirectory("map/map1.ini"));
  } else if (data.ticks == 2) {
    auto &new_map = factory.invoke("map_level_2");
    findEntity<MapLevel>(entities, toIdentifier("map_level_1")).destroy();
    new_map.as<MapLevel>().loadFromFile(findInResourcesDirectory("map/map2.ini"));
  }
}

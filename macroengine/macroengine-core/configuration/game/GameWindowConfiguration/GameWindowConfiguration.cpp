/*
** GameWindowConfiguration.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/configuration/game/GameWindowConfiguration/GameWindowConfiguration.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Mar 15 14:18:30 2018 Sylvain CHAUGNY
*/

# include				"macroengine-core/utl/definitions.hpp"
#include				"GameWindowConfiguration.hpp"

macroengine::configuration::game::GameWindowConfiguration::GameWindowConfiguration() :
  AGameConfiguration("WINDOW"),
  dimensions({MACROENGINE_VAR_DEFAULT_WINDOW_WIDTH, MACROENGINE_VAR_DEFAULT_WINDOW_HEIGHT}),
  title(MACROENGINE_VAR_DEFAULT_WINDOW_TITLE_NAME),
  fullscreen(MACROENGINE_VAR_DEFAULT_WINDOW_FULLSCREEN) {
}

void					macroengine::configuration::game::GameWindowConfiguration::configure(macroengine::parser::ini::IniScope const &scope)
{
  if (scope.keyExists("width"))
    dimensions.width = std::stoul(scope["width"]);
  if (scope.keyExists("height"))
    dimensions.height = std::stoul(scope["height"]);
  if (scope.keyExists("title"))
    title = scope["title"];
  if (scope.keyExists("fullscreen"))
    fullscreen = (scope["fullscreen"] == "true");
}

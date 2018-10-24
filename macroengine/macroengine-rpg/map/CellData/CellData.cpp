/*
** CellData.cpp for Macro_Engine in /home/sylvain/Documents/projects/perso/C++/macroengine/macroengine-rpg/map/CellData/CellData.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sat Jun 02 00:43:56 2018 Sylvain CHAUGNY
*/

# include			<macroengine-core/macroengine-core.hpp>
# include			"macroengine-core/utl/strings.hpp"
# include			"macroengine-core/log/log.hpp"
# include			"CellData.hpp"
# include			"macroengine-core/parser/ini/IniScope/IniScope.hpp"

int				macroengine::rpg::map::CellData::fromScope(const parser::ini::IniScope &scope, utl::Dimensions const &dim) {
  if (!scope.keyExists("name") || !scope.keyExists("texture_file")) {
    error(Strings("rpg_map_cell_scope_bad_formatted", scope.getName()));
    return 1;
  }
  dimensions = dim;
  name = scope["name"];
  texture_file = findInResourcesDirectory(scope["texture_file"]);
  flag = scope.getName()[0];
  crossable_by_player = (scope.keyExists("crossable_by_player")) ? (scope["crossable_by_player"] == "true") : false;
  crossable = (scope.keyExists("crossable")) ? (scope["crossable"] == "true") : false;
  return 0;
}

void				macroengine::rpg::map::CellData::dump() {
  Dump::display("==== CellData ====");
  Dump::display("  flag: <" + std::string(1, flag) + ">");
  Dump::display("  name: <" + name + ">");
  Dump::display("  texture_file: <" + texture_file + ">");
  Dump::display("  dimensions: [" + std::to_string(dimensions.width) + ", " + std::to_string(dimensions.height) + "]");
  Dump::display("  crossable_by_player: " + std::to_string(crossable_by_player));
  Dump::display("  crossable: " + std::to_string(crossable));
  Dump::display("==================");
}

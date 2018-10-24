/*
** Map.cpp for Macro_Engine in /home/sylvain/Documents/projets/perso/macroengine/macroengine-rpg/map/Map/Map.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Wed May 23 10:40:47 2018 Sylvain CHAUGNY
*/

#include			"Map.hpp"

macroengine::rpg::Map::Map() : Drawable() {
  asDrawable().viewHandler().enable();
  asDrawable().spriteHandler().enable();
}

void				macroengine::rpg::Map::dump() {
  Dump::display("==== Map ====");
  Dump::display("cells: " + std::to_string(_cells.size()));
  for (auto &&cell: _cells) {
    Dump::display("[" + std::to_string(cell.first.x) + ", " + std::to_string(cell.first.y) + "]: " +
		  std::string(1, cell.second.getCellData().flag) + " (" + cell.second.getCellData().name + ")");
  }
  Dump::display("cell dictionary: " + std::to_string(_cell_dictionary.size()));
  for (auto &&cell: _cell_dictionary) {
    cell.second.dump();
  }
}

int				macroengine::rpg::Map::loadFromFile(std::string const &file) {
  log(Strings("rpg_map_loading_map_from_file", file));
  if (parseFile(file)) {
    return 1;
  }
  if (getInfosFromParser()) {
    return 1;
  }
  log(Strings("core_success"));
  return 0;
}

int				macroengine::rpg::Map::parseFile(std::string const &file) {
  _file.setFileName(file);
  _file.open();
  if (!_file.good() || _file.read()) {
    error(Strings("rpg_map_couldnt_read_map_file", file), 2);
    return 1;
  }
  if (_parser.parseFromFile(_file)) {
    return 1;
  }
  return 0;
}

int				macroengine::rpg::Map::getInfosFromParser() {
  return getConfigurationInfos() || getDataInfos();
}

int				macroengine::rpg::Map::getConfigurationInfos() {
  log(Strings("rpg_map_retrieving_configuration_infos", _file.getFileName()), 2);
  if (!_parser.scopeExists("CONFIGURATION")) {
    error(Strings("rpg_map_file_bad_formatted_missing_scope", _file.getFileName(), "CONFIGURATION"));
    return 1;
  }
  if (!isKeyExisting("CONFIGURATION", "name") ||
      !isKeyExisting("CONFIGURATION", "texture_width") ||
      !isKeyExisting("CONFIGURATION", "texture_height") ||
      !isKeyExisting("CONFIGURATION", "map_width") ||
      !isKeyExisting("CONFIGURATION", "map_height")) {
    error(Strings("rpg_map_configuration_scope_bad_formatted", _file.getFileName()), 2);
    return 1;
  }
  _name = _parser["CONFIGURATION"]["name"];
  _texture_dimensions.width = std::stoul(_parser["CONFIGURATION"]["texture_width"]);
  _texture_dimensions.height = std::stoul(_parser["CONFIGURATION"]["texture_height"]);
  _dimensions.width = std::stoul(_parser["CONFIGURATION"]["map_width"]) * _texture_dimensions.width;
  _dimensions.height = std::stoul(_parser["CONFIGURATION"]["map_height"]) * _texture_dimensions.height;
  log(Strings("core_success"), 2);
  return 0;
}

int				macroengine::rpg::Map::getDataInfos() {
  log(Strings("rpg_map_retrieving_data_infos", _file.getFileName()), 2);
  if (!_parser.scopeExists("DATA")) {
    error(Strings("rpg_map_file_bad_formatted_missing_scope", _file.getFileName(), "DATA"));
    return 1;
  }
  if (!isKeyExisting("DATA", "map")) {
    error(Strings("rpg_map_data_scope_bad_formatted", _file.getFileName()), 2);
    return 1;
  }
  if (parseMap(_parser["DATA"]["map"])) {
    return 1;
  }
  log(Strings("core_success"), 2);
  return 0;
}


bool				macroengine::rpg::Map::isKeyExisting(std::string const &scope, std::string const &key) {
  if (!_parser.scopeExists(scope)) {
    error(Strings("rpg_map_file_bad_formatted_missing_scope", _file.getFileName(), "CONFIGURATION"));
    return false;
  }
  if (!_parser[scope].keyExists(key)) {
    error(Strings("rpg_map_file_missing_entry_in_scope", _file.getFileName(), key, scope));
    return false;
  }
  return true;
}

int				macroengine::rpg::Map::parseMap(std::string const &map) {
  utl::Position			pos;
  _raw_map = mapStringToRawMap(map);

  log(Strings("rpg_map_parsing_map_from_file", _file.getFileName()), 4);
  for (auto &&line: _raw_map) {
    pos.y++;
    pos.x = 0;
    for (auto &&cell: line) {
      if (!_parser.scopeExists(std::string(1, cell))) {
	error(Strings("rpg_map_file_bad_formatted_missing_cell_scope", _file.getFileName(), std::string(1, cell)), 4);
	return 1;
      }
      if (_cell_dictionary.find(cell) == _cell_dictionary.end()) {
	if (_cell_dictionary[cell].fromScope(_parser[std::string(1, cell)], _texture_dimensions)) {
	  return 1;
	}
      }
      _cells[pos].init(_name + "[" + std::to_string(pos.x) + "," + std::to_string(pos.y));
      _cells[pos].setCellFlag(cell);
      pos.x++;
    }
  }
  if (updateDrawable()) {
    return 1;
  }
  log(Strings("core_success"), 4);
  return 0;
}

std::vector<std::string>	macroengine::rpg::Map::mapStringToRawMap(std::string const &c_str) {
  std::vector<std::string>	map;
  std::string			str = c_str;

  while (!str.empty()) {
    map.emplace_back(str.substr(0, str.find_first_of('\n')));
    str = (str.find_first_of('\n') == std::string::npos) ? "" : str.substr(str.find_first_of('\n') + 1);
  }
  return map;
}

int 				macroengine::rpg::Map::updateDrawable() {
  log(Strings("rpg_map_updating_drawable_component"), 6);
  _view_identifier = asDrawable().viewHandler().add(_name, MainConfiguration.window.dimensions).getIdentifier();
  for (auto &&entry: _cell_dictionary) {
    entry.second.sprite = asDrawable().spriteHandler().addFromFile(std::string(1, entry.first), entry.second.texture_file);
  }
  for (auto &&cell: _cells) {
    graphics::Sprite		&sprite = asDrawable().spriteHandler().addFromSprite(cell.second.getIdentifier().name,
											 _cell_dictionary[cell.second.getCellData().flag].sprite);
    sprite.setPosition(utl::Position((cell.first.x - 1) * _cell_dictionary[cell.second.getCellData().flag].dimensions.width,
				     (cell.first.y - 1) * _cell_dictionary[cell.second.getCellData().flag].dimensions.height));
    cell.second.setCellData(_cell_dictionary[cell.second.getCellData().flag], cell.first, sprite);
    asDrawable().viewHandler().get(_view_identifier).bindElement(cell.second.getCellData().sprite.getIdentifier(), property::SPRITE);
  }
  log(Strings("core_success"), 6);
  return 0;
}

macroengine::graphics::View	&macroengine::rpg::Map::getView() {
  return asDrawable().viewHandler().get(_view_identifier);
}

void				macroengine::rpg::Map::destroy() {
  asDrawable().spriteHandler().clear();
  asDrawable().viewHandler().remove(_view_identifier);
}

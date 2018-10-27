/*
** Text.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/graphics/Text/Text.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sat Mar 10 22:43:55 2018 Sylvain CHAUGNY
*/

# include					"macroengine-core/utl/configuration.hpp"
# include					"macroengine-core/utl/strings.hpp"
# include					"macroengine-core/file/File/File.hpp"
#include					"Text.hpp"

macroengine::graphics::Text::Text() :
  Object("Text") {
}

void						macroengine::graphics::Text::dump() {
}

int						macroengine::graphics::Text::loadFromIni(std::string const &path) {
  file::File					file;
  parser::ini::IniParser			parser;

  log(Strings("core_loading_text", path));
  file.setFileName(path);
  file.open();
  if (!file.good()) {
    error(Strings("core_fail_loading_text", path));
    return 1;
  }
  file.read();
  if (parser.parseFromFile(file)) {
    error(Strings("core_fail_loading_text", path));
    return 1;
  }
  if (getTextEntriesFromIni(parser, path, getFontFromIni(parser, path))) {
    error(Strings("core_fail"));
    return 1;
  }
  log(Strings("core_success"));
  return 0;
}

macroengine::t_entity_id 			macroengine::graphics::Text::getFontFromIni(macroengine::parser::ini::IniParser &parser,
											    std::string const &path) {
  t_entity_id 					id;

  log("  " + Strings("core_loading_font", path));
  if (!parser.scopeExists("FONT")) {
    error("  " + Strings("core_fail_loading_font_unknown"));
    return -1;
  }
  for (auto &&font: _font_entries) {
    if ((parser["FONT"].keyExists("name") && font.second.name == parser["FONT"]["name"]) ||
	(parser["FONT"].keyExists("path") && font.second.path == parser["FONT"]["path"])) {
      return font.second.id;
    }
  }
  if (!parser["FONT"].keyExists("path")) {
    error("  " + Strings("core_fail_loading_font_unknown", path));
    return -1;
  }
  id = EntityIDGenerator.newID();
  _font_entries[id].id = id;
  _font_entries[id].path = parser["FONT"]["path"];
  _font_entries[id].name = parser["FONT"].keyExists("name") ? parser["FONT"]["name"] : parser["FONT"]["path"];
  if (!_font_entries[id].font.loadFromFile(_font_entries[id].path)) {
    error("  " + Strings("core_fail_loading_font_unknown"));
    return -1;
  }
  log("  " + Strings("core_success"));
  return _font_entries[id].id;
}

int						macroengine::graphics::Text::getTextEntriesFromIni(parser::ini::IniParser &parser,
												      std::string const &path,
												      t_entity_id font_id) {
  if (font_id == -1) {
    return 1;
  }
  log("  " + Strings("core_loading_text_entries", path));
  if (!parser.scopeExists("TEXT")) {
    error("  " + Strings("core_fail_loading_text_entry", path));
    return 1;
  }
  for (auto &&entry: parser["TEXT"].getContent()) {
    t_entity_id					id;

    id = getTextEntryFromLine(entry, parser, font_id);
    if (_text_entries[id].name == "" || _text_entries[id].string == "") {
      error("  " + Strings("core_fail_loading_text_entry", path));
      return 1;
    }
    _text_entries[id].id = id;
    log("  " + Strings("core_string_file_found_line", _text_entries[id].name));
  }
  log("  " + Strings("core_success"));
  return 0;
}

macroengine::t_entity_id			macroengine::graphics::Text::getTextEntryFromLine(std::pair<std::string, std::string> const &entry,
												  macroengine::parser::ini::IniParser &parser,
												  macroengine::t_entity_id font_id) {
  t_entity_id 					id;
  std::string					tmp;

  id = EntityIDGenerator.newID();
  _text_entries[id].name = entry.first;
  _text_entries[id].string = entry.second;
  _text_entries[id].text.setString(_text_entries[id].string);
  _text_entries[id].text.setFont(_font_entries[font_id].font);
  if (parser.scopeExists(entry.first)) {
    if (parser[entry.first].keyExists("position")) {
      tmp = parser[entry.first]["position"];
      _text_entries[id].position.x = std::stoi(tmp.substr(0, tmp.find_last_of(", ")));
      _text_entries[id].position.y = std::stoi(tmp.substr(tmp.find_last_of(", ") + 1));
      _text_entries[id].text.setPosition(_text_entries[id].position.x, _text_entries[id].position.y);
    }
    if (parser[entry.first].keyExists("size")) {
      _text_entries[id].size = std::stoi(parser[entry.first]["size"]);
      _text_entries[id].text.setCharacterSize(static_cast<unsigned int>(_text_entries[id].size));
    }
  }
  return id;
}

macroengine::graphics::utl::TextEntry		&macroengine::graphics::Text::get(std::string const &name) {
  for (auto &&entries: _text_entries) {
    if (entries.second.name == name) {
      return entries.second;
    }
  }
  return _empty_text;
}

macroengine::graphics::utl::TextEntry		&macroengine::graphics::Text::get(macroengine::t_entity_id const &id) {
  return _text_entries[id];
}

macroengine::graphics::t_text_entries		&macroengine::graphics::Text::getEntries() {
  return _text_entries;
}

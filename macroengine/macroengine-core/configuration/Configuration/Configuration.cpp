/*
** Configuration.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/configuration/Configuration/Configuration.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Tue Feb 13 23:22:46 2018 Sylvain CHAUGNY
*/

# include						"macroengine-core/utl/macros/macros_definitions.hpp"
# include						"macroengine-core/file/File/File.hpp"
# include 						"macroengine-core/parser/ini/IniParser/IniParser.hpp"
#include						"Configuration.hpp"
# include						"macroengine-core/utl/strings.hpp"

macroengine::configuration::Configuration::Configuration() :
  Object("Configuration"),
  _main_configuration_file(std::string(MACROENGINE_VAR_DEFAULT_RESOURCES_DIRECTORY) + "/" + MACROENGINE_VAR_DEFAULT_CONFIGURATION_FILE) {
}

macroengine::configuration::Environment			&macroengine::configuration::Configuration::getEnvironment() {
  return _environment;
}

macroengine::configuration::EntityRegister		&macroengine::configuration::Configuration::getEntityRegister() {
  return _entity_register;
}

void							macroengine::configuration::Configuration::dump() {
}

macroengine::configuration::strings::StringBuilder	&macroengine::configuration::Configuration::getStringBuilder() {
  return _strings;
}

int							macroengine::configuration::Configuration::configure() {
  int							ret = 0;
  file::File						file;
  parser::ini::IniParser				ini;

  file.setFileName(_main_configuration_file);
  file.open();
  if (!file.good()) {
    warning(Strings("core_fail_configuration_file", _main_configuration_file));
  } else {
    file.read();
    if (ini.parseFromFile(file)) {
      error(Strings("core_fail_configuration_file", _main_configuration_file));
      return 0;
    }
  }
  ret += _game_configuration.configure(ini);

  ret += !ret ? getEnvironment().configure() : 0;
  ret += !ret ? getStringBuilder().configure(ini) : 0;
  ret += !ret ? getEntityRegister().configure() : 0;
  return ret != 0;
}

macroengine::configuration::EntityIDGenerator		&macroengine::configuration::Configuration::getEntityIDGenerator() {
  return _entity_id_generator;
}

void							macroengine::configuration::Configuration::setConfigurationFile(const std::string &file) {
  _main_configuration_file = file;
}

macroengine::configuration::game::GameConfiguration	&macroengine::configuration::Configuration::getGameConfiguration() {
  return _game_configuration;
}

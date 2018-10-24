/*
** main.cpp for Macro_Engine in /home/sylvain/Documents/projects/perso/C++/macroengine/macroengine/build_utl/strings_finder/main.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Mon May 28 22:55:03 2018 Sylvain CHAUGNY
*/

#include			<iostream>
# include			"macroengine-core/build_utl/strings_finder/StringsFinder/StringsFinder.hpp"
#include			"build_utl.hpp"

using namespace			macroengine::build_utl;

int				main(int ac, char **av) {
  Directory			dir;
  std::vector<std::string>	modules;
  file::File			file;
  parser::IniParser		parser;
  strings_finder::StringsFinder	finder;

  if (ac != 2) {
    std::cerr << "[ERROR]" << " no argument found" << std::endl;
    return 1;
  }
  if (finder.initStringBuilder(std::string(av[1]) + "/macroengine-core/configuration/strings/StringBuilder/StringBuilder.cpp")) {
    return 1;
  }
  dir.setRootPath(av[1]);
  modules = dir.findMatchingStart("macroengine-");
  for (auto &&module: modules) {
    file.reset();
    file.setFileName(module + "/strings.ini");
    file.open();
    std::cout << module << "/strings.ini: " << (file.good() ? "OK" : "KO") << std::endl;
    file.read();
    parser.parseFromRawContent(file.getContent());
    if (parser.scopeExists("STRINGS")) {
      finder.addStrings(parser["STRINGS"].getContent());
    } else {
      std::cerr << "Error: " << module << "/strings.ini" << " is not a valid strings file. Skipping" << std::endl;
    }
  }
  finder.writeStrings();
}

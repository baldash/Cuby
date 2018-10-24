/*
** StringsFinder.cpp for Macro_Engine in /home/sylvain/Documents/projets/perso/macroengine/macroengine-core/build_utl/strings_finder/StringsFinder/StringsFinder.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Wed May 30 14:34:50 2018 Sylvain CHAUGNY
*/

#include			<iostream>
#include			<algorithm>
#include			"StringsFinder.hpp"

void				macroengine::build_utl::strings_finder::StringsFinder::addStrings(const macroengine::build_utl::parser::IniScope::t_ini_scope &scope) {
  t_key 			key;

  for (auto &&string: scope) {
    key.first = string.first;
    key.second = string.second;
    _strings[key] = countFlags(key.second);
  }
}


int				macroengine::build_utl::strings_finder::StringsFinder::countFlags(std::string const &str) {
  int				nb;
  std::string			tmp;
  int				i;

  nb = 0;
  tmp = str;
  while ((i = getNextFlag(tmp)) != -1) {
    tmp = tmp.substr(tmp.find(_flags[i]) + 1);
    nb++;
  }
  return nb;
}

int				macroengine::build_utl::strings_finder::StringsFinder::getNextFlag(std::string const &str) {
  std::pair<int, long>		min;

  min.first = 0;
  min.second = str.find(_flags[0]);
  for (unsigned int i = 0; i < _flags.size(); i++) {
    long tmp = str.find(_flags[i]);
    if ((min.second == -1 || tmp < min.second) && tmp != -1) {
      min.first = i;
      min.second = tmp;
    }
  }
  return (min.second == -1) ? -1 : min.first;
}

int				macroengine::build_utl::strings_finder::StringsFinder::initStringBuilder(std::string const &path) {
  _original_filename = path;
  _strings_builder.setFileName(path + ".template");
  _strings_builder.open();
  if (!_strings_builder.good() || _strings_builder.read()) {
    std::cerr << "[ERROR] " << path << " doesn't exist" << std::endl;
    return 1;
  }
  if (getFlags() || getWritingHook()) {
    std::cerr << "[ERROR]" << " bad formatting" << std::endl;
    return 1;
  }

  remove(path.c_str());

  return 0;
}

int				macroengine::build_utl::strings_finder::StringsFinder::getFlags() {
  std::string			tmp;

  for (auto line = _strings_builder.getContent().begin(); line != _strings_builder.getContent().end(); line++) {
    if (*line == "  _flags = {") {
      while (*line != "  };" && line != _strings_builder.getContent().end()) {
	tmp = (*line).substr((*line).find_first_of('\"') + 1);
	_flags.emplace_back(tmp.substr(0, tmp.find_first_of('\"')));
	line++;
      }
      if (line == _strings_builder.getContent().end()) {
        return 1;
      }
    }
  }
  _strings_builder.close();
  return 0;
}

void				macroengine::build_utl::strings_finder::StringsFinder::writeStrings() {
  std::ofstream			outfile(_original_filename, std::ofstream::binary);

  for (size_t i = 0; i < _strings_builder.getContent().size(); i++) {
    outfile.write(_strings_builder.getContent()[i].c_str(), _strings_builder.getContent()[i].length());
    outfile.write("\n", 1);
    if (i == _writing_hook) {
      for (auto &&string: _strings) {
	std::string tmp = "  addString(\"" + string.first.first + "\", \"" + string.first.second + "\", " + std::to_string(string.second) + ");\n";
	outfile.write(tmp.c_str(), tmp.length());
      }
    }
  }
  outfile.close();
}

int				macroengine::build_utl::strings_finder::StringsFinder::getWritingHook() {
  for (auto &&line: _strings_builder.getContent()) {
    if (line == "  // STRINGS FINDER WRITING HOOK") {
      return 0;
    }
    _writing_hook++;
  }
  return 1;
}
/*
** Directory.cpp for Macro_Engine in /home/sylvain/Documents/projets/perso/macroengine/macroengine-core/build_utl/strings_finder/Directory/Directory.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Tue May 29 10:38:34 2018 Sylvain CHAUGNY
*/

#include			<experimental/filesystem>
#include			"Directory.hpp"

macroengine::build_utl::Directory::Directory(const std::string &root) :
  _root_path(root) {
}

void				macroengine::build_utl::Directory::setRootPath(const std::string &path) {
  _root_path = path;
}

const std::string		&macroengine::build_utl::Directory::getRootPath() {
  return _root_path;
}

bool				macroengine::build_utl::Directory::contains(const std::string &) {
  return false;
}

std::vector<std::string>	macroengine::build_utl::Directory::findMatchingStart(std::string const &start) {
  std::vector<std::string>	matching;

  for (auto &&f: std::experimental::filesystem::directory_iterator(_root_path)) {
    if (f.path().generic_string().find(start) != std::string::npos) {
      matching.emplace_back(f.path().generic_string());
    }
  }
  return matching;
}

/*
** File.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/file/File/File.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Fri Jan 26 15:37:09 2018 Sylvain CHAUGNY
*/

#include			"File.hpp"

using namespace		macroengine::build_utl;

file::File::File(const std::string &file) :
  _filename(file),
  _content(),
  _stream() {
}

void			file::File::open() {
  _stream.open(_filename);
}

void			file::File::close() {
  _stream.close();
}

bool			file::File::good() const {
  return _stream.good();
}

int			file::File::read() {
  std::string		buffer("");

  _content.clear();
  while (std::getline(_stream, buffer)) {
    _content.emplace_back(buffer);
  }
  return 0;
}

parser::t_raw_content const	&file::File::getContent() const {
  return _content;
}

void			file::File::setFileName(std::string const &file) {
  _filename = file;
}

std::string const		&file::File::getFileName() const {
  return _filename;
}

void				file::File::reset() {
  _filename = "";
  _content.clear();
  _stream.close();
}

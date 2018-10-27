/*
** File.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/file/File/File.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Fri Jan 26 15:37:09 2018 Sylvain CHAUGNY
*/

# include			"macroengine-core/log/log.hpp"
#include			"File.hpp"


macroengine::file::File::File(const std::string &file) :
  Object("File"),
  _filename(file),
  _content(),
  _stream() {
}

void			macroengine::file::File::open() {
  _stream.open(_filename);
}

void			macroengine::file::File::close() {
  _stream.close();
}

bool			macroengine::file::File::good() const {
  return _stream.good();
}

int			macroengine::file::File::read() {
  std::string		buffer("");

  _content.clear();
  while (std::getline(_stream, buffer)) {
    _content.emplace_back(buffer);
  }
  return 0;
}

macroengine::file::t_raw_content const	&macroengine::file::File::getContent() const {
  return _content;
}

void			macroengine::file::File::setFileName(std::string const &file) {
  _filename = file;
}

std::string const		&macroengine::file::File::getFileName() const {
  return _filename;
}

void				macroengine::file::File::dump()
{
  Dump::display("==== File ====");
  Dump::display("_filename : <" + _filename + ">");
  Dump::display("_content :");
  Dump::display("{");
  for (auto &&line: _content) {
    Dump::display("<" + line + ">");
  }
  Dump::display("}");
  Dump::display("_stream : " + _stream.good());
  Dump::display("===============");
}

void				macroengine::file::File::reset() {
  _filename = "";
  _content.clear();
  _stream.close();
}

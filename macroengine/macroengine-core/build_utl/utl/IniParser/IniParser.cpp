/*
** IniParser.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/parser/ini/IniParser/IniParser.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Mon Feb 05 21:01:31 2018 Sylvain CHAUGNY
*/

#include					"IniParser.hpp"

using namespace					macroengine::build_utl::parser;

IniParser::IniParser() :
  _file_current_line_hook(),
  _file_end_hook(),
  _file_begin_hook() {
}

int						IniParser::parseFromRawContent(const t_raw_content &file) {
  _file_begin_hook = file.begin();
  _file_end_hook = file.end();
  _file_current_line_hook = _file_begin_hook;
  _parsed_content.clear();

  _file_current_line_hook = file.begin();
  while (_file_current_line_hook != file.end()) {
    if (isScope(*_file_current_line_hook)) {
      if (handleNewScope()) {
	return 1;
      }
    } else {
      _file_current_line_hook++;
    }
  }
  return 0;
}


int						IniParser::handleNewScope() {
  std::string					name;
  t_entry					entry;

  name = parseScopeName(*_file_current_line_hook);
  _file_current_line_hook++;
  while (_file_current_line_hook != _file_end_hook && !isScope(*_file_current_line_hook)) {
    if (!isComment(*_file_current_line_hook) && !isEmpty(*_file_current_line_hook)) {
      if (parseScopeEntry(_file_current_line_hook, entry)) {
	return 1;
      }
      if (_parsed_content[name].getName().empty()) {
	_parsed_content[name].setName(name);
      }
      _parsed_content[name].addEntry(entry.first, entry.second);
    }
    _file_current_line_hook++;
  }
  return 0;
}

#include <iostream>

bool						IniParser::isScope(std::string const &line) {
  size_t					first;
  size_t					second;

  if (isComment(line)) {
    return false;
  }

  first = line.find_first_not_of(" \t");
  second = line.find_last_not_of(" \t");
  return line[first] == '[' && line[second] == ']';
}

bool						IniParser::isComment(std::string const &line) {
  return line.find('#') == 0;
}

bool						IniParser::isEmpty(std::string const &line) {
  return line.empty() || line.find_first_not_of(" \t\n") == std::string::npos;
}

const std::string				IniParser::parseScopeName(std::string const &name) {
  std::string					word;

  word = name.substr(name.find_first_not_of(" \t[\""));
  return word.substr(0, word.find_first_of(" \t]\""));
}

int						IniParser::parseScopeEntry(std::string const &line,
									      t_entry &entry) {
  std::string					word1;
  std::string					word2;

  word1 = line.find_first_not_of(" \t\"") == std::string::npos ? "" : line.substr(line.find_first_not_of(" \t\""));
  word1 = word1.substr(0, word1.find_first_of(" \t=\""));

  word2 = line.find_first_of('=') == std::string::npos ? "" : line.substr(line.find_first_of('=') + 1);
  if (word2.find_first_not_of(" \t\"") == std::string::npos || word2.find_last_not_of(" \t\"")  == std::string::npos) {
    word2 = "";
  } else {
    word2 = word2.substr(word2.find_first_not_of(" \t\""), word2.find_last_not_of(" \t\"") - word2.find_first_not_of(" \t\"") + 1);
  }
  if (word1.empty() || word2.empty()) {
    return 1;
  }
  entry.first = word1;
  entry.second = word2;
  return 0;
}

int						IniParser::parseScopeEntry(t_raw_content_ci &hook,
									      t_entry &entry) {
  std::string					word1;
  std::string					word2;

  word1 = (*hook).find_first_not_of(" \t\"") == std::string::npos ? "" : (*hook).substr((*hook).find_first_not_of(" \t\""));
  if (word1.find_first_of(" \t=\"") == std::string::npos) {
    return 1;
  }
  if (word1.find_last_not_of(" \t=\"") == word1.find_first_of(" \t=\"") - 1) {
    bool			can_go_to_end = false;
    t_raw_content_ci		hook_tmp = hook + 1;

    if (hook_tmp == _file_end_hook) {
      return 1;
    }
    if ((*hook_tmp)[0] == '\"' && (*hook_tmp)[(*hook_tmp).length() - 1] != '\"') {
      for (hook_tmp++; (*hook_tmp)[(*hook_tmp).length() - 1] != '\"' && hook_tmp != _file_end_hook; hook_tmp++);
    } else {
      can_go_to_end = true;
      for (; hook_tmp + 1 != _file_end_hook && (*(hook_tmp + 1)).find_first_of('=') == std::string::npos; hook_tmp++);
    }
    if (!can_go_to_end && hook_tmp == _file_end_hook) {
      return 1;
    }
    for (hook++; hook != _file_end_hook && hook != hook_tmp + 1; hook++) {
      word2 += (*hook) + ((hook + 1 == hook_tmp + 1) ? "" : "\n");
    }
    epureWord(word2);
    hook--;
  } else {
    word2 = (*hook).find_first_of('=') == std::string::npos ? "" : (*hook).substr((*hook).find_first_of('=') + 1);
    if (word2.find_first_not_of(" \t\"") == std::string::npos || word2.find_last_not_of(" \t\"")  == std::string::npos) {
      word2 = "";
    } else {
      word2 = word2.substr(word2.find_first_not_of(" \t\""), word2.find_last_not_of(" \t\"") - word2.find_first_not_of(" \t\"") + 1);
    }
  }
  word1 = word1.substr(0, word1.find_first_of(" \t=\""));
  if (word1.empty() || word2.empty()) {
    return 1;
  }
  entry.first = word1;
  entry.second = word2;
  return 0;
}

void						IniParser::epureWord(std::string &word) {
  if (word[0] == '\"') {
    word = word.substr((word[1] == '\n') ? 2 : 1);
  }
  if (word[0] == '\n') {
    word = word.substr((word[1] == '\"') ? 2 : 1);
  }
  if (word[word.length() - 1] == '\"') {
    word = word.substr(0, (word[word.length() - 2] == '\n') ? word.length() - 2 : word.length() - 1);
  }
  if (word[word.length() - 1] == '\n') {
    word = word.substr(0, (word[word.length() - 2] == '\"') ? word.length() - 2 : word.length() - 1);
  }
}

const IniScope	&IniParser::operator[](std::string const &name) {
  return _parsed_content[name];
}

bool						IniParser::scopeExists(std::string const &name) {
  return _parsed_content.find(name) != _parsed_content.end();
}

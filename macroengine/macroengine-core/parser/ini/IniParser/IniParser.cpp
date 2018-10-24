/*
** IniParser.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/parser/ini/IniParser/IniParser.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Mon Feb 05 21:01:31 2018 Sylvain CHAUGNY
*/

# include					"macroengine-core/log/log.hpp"
#include					"IniParser.hpp"
# include					"macroengine-core/utl/strings.hpp"

macroengine::parser::ini::IniParser::IniParser() :
  _file_current_line_hook(),
  _file_end_hook(),
  _file_begin_hook() {
  setClassName("IniParser");
}

int						macroengine::parser::ini::IniParser::parseFromFile(macroengine::file::File &file) {
  return parseFromRawContent(file.getContent());
}

int						macroengine::parser::ini::IniParser::parseFromRawContent(const macroengine::file::t_raw_content &file) {
  _file_begin_hook = file.begin();
  _file_end_hook = file.end();
  _file_current_line_hook = _file_begin_hook;
  _parsed_content.clear();

  _file_current_line_hook = file.begin();
  while (_file_current_line_hook != file.end()) {
    if (isScope(*_file_current_line_hook)) {
      if (handleNewScope()) {
	error(Strings("core_bad_formatted_ini_line_raw_content", std::distance(_file_begin_hook, _file_current_line_hook) + 1));
	return 1;
      }
    } else {
      _file_current_line_hook++;
    }
  }
  return 0;
}


int						macroengine::parser::ini::IniParser::handleNewScope() {
  std::string					name;
  t_entry					entry;

  name = parseScopeName(*_file_current_line_hook);
  _file_current_line_hook++;
  while (_file_current_line_hook != _file_end_hook && !isScope(*_file_current_line_hook)) {
    if (!isComment(*_file_current_line_hook) && !isEmpty(*_file_current_line_hook)) {
      if (parseScopeEntry(_file_current_line_hook, entry)) {
	return 1;
      }
      if (entry.first.empty() || entry.second.empty()) {
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

void						macroengine::parser::ini::IniParser::dump() {
  Dump::display("===== IniParser =====");
  for (auto &&scope: _parsed_content) {
    Dump::display("  [" + scope.first + "]");
    for (auto &&line: scope.second.getContent()) {
      Dump::display("    <" + line.first + "> : <" + line.second + ">");
    }
  }
  Dump::display("=====================");
}

bool						macroengine::parser::ini::IniParser::isScope(std::string const &line) {
  size_t					first;
  size_t					second;

  if (isComment(line)) {
    return false;
  }
  first = line.find_first_not_of(" \t");
  second = line.find_last_not_of(" \t");
  return line[first] == '[' && line[second] == ']';
}

bool						macroengine::parser::ini::IniParser::isComment(std::string const &line) {
  return line.find('#') == 0;
}

bool						macroengine::parser::ini::IniParser::isEmpty(std::string const &line) {
  return line.empty() || line.find_first_not_of(" \t\n") == std::string::npos;
}

const std::string				macroengine::parser::ini::IniParser::parseScopeName(std::string const &name) {
  std::string					word;

  word = name.substr(name.find_first_not_of(" \t[\""));
  return word.substr(0, word.find_first_of(" \t]\""));
}

int						macroengine::parser::ini::IniParser::parseScopeEntry(macroengine::file::t_raw_content_ci &hook,
												     macroengine::parser::ini::t_entry &entry) {
  std::string					word1;
  std::string					word2;
  std::string					working;
  int						count;

  if ((*hook).find('=') == std::string::npos) {
    return 1;
  }
  working = *hook;
  word1 = working.substr(0, working.find_first_of("="));
  working = working.substr(word1.length() + 1);
  epureWord(word1, " \t");
  epureWord(working, " \t");
  if (countCharacterInString(word1, '"', true) != 0) {
    return 1;
  }
  count = countCharacterInString(working, '"');
  if (count == 0 && countCharacterInString(working, '"', true)) {
    return 1;
  }
  if ((!working.empty() && count == 0) || count == 2) {
    word2 = working;
  } else if (count == 1 || working.empty()) {
    word2 = working;
    working = "";
    while (hook != _file_end_hook && count < 2) {
      count += countCharacterInString(working, '"');
      if (count > 2) {
	return 1;
      }
      word2 += working + "\n";
      hook++;
      if (hook != _file_end_hook) {
	working = *hook;
      }
    }
    if (hook == _file_end_hook && count != 2) {
      return 1;
    }
    hook--;
  } else {
    return 1;
  }
  formatWord(word1);
  formatWord(word2);
  entry.first = word1;
  entry.second = word2;
  return 0;
}

void						macroengine::parser::ini::IniParser::formatWord(std::string &str) {
  std::string					tmp;
  size_t					index = 0;

  epureWord(str, "\n\"");
  while (true) {
    index = str.find("\\\"", index);
    if (index == std::string::npos) {
      return ;
    }
    str.replace(index, 2, "\"");
    index += 1;
  }
}

int						macroengine::parser::ini::IniParser::countCharacterInString(std::string const &word, char c, bool count_escaped) {
  int						count = 0;

  for (size_t i = 0; i < word.length(); i++) {
    if (!count_escaped && word[i] == c && (i == 0 || (i > 0 && word[i - 1] != '\\'))) {
      count++;
    } else if (count_escaped && word[i] == c) {
      count++;
    }
  }
  return count;
}

void						macroengine::parser::ini::IniParser::epureWord(std::string &word, std::string const &chars) {
  int						stop = 0;

  if (word.find_first_not_of(chars) != std::string::npos) {
    word = word.substr(word.find_first_not_of(chars));
  }
  stop = word.find_last_not_of(chars);
  if (word[stop] == '\\') {
    stop++;
  }
  word = word.substr(0, stop + 1);
}

const macroengine::parser::ini::IniScope	&macroengine::parser::ini::IniParser::operator[](std::string const &name) {
  return _parsed_content[name];
}

bool						macroengine::parser::ini::IniParser::scopeExists(std::string const &name) {
  return _parsed_content.find(name) != _parsed_content.end();
}

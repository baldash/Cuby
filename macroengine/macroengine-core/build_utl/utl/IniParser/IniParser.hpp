/*
** IniParser.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/parser/ini/IniParser/IniParser.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Mon Feb 05 20:58:54 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_INIPARSER_HPP
# define MACRO_ENGINE_INIPARSER_HPP

# include				<vector>
# include				"IniScope.hpp"

namespace				macroengine {
  namespace				build_utl {
    namespace				parser {

      using				t_scope_content = std::unordered_map<std::string, IniScope>;
      using				t_raw_content = std::vector<std::string>;
      using				t_raw_content_i = std::vector<std::string>::iterator;
      using				t_raw_content_ci = std::vector<std::string>::const_iterator;
      using				t_entry = std::pair<std::string, std::string>;

      class				IniParser {
      private:
	t_raw_content_ci		_file_current_line_hook;
	t_raw_content_ci		_file_end_hook;
	t_raw_content_ci		_file_begin_hook;
	t_scope_content			_parsed_content;

      public:
	IniParser();
	virtual ~IniParser() = default;

	int				parseFromRawContent(t_raw_content const &file);
	IniScope const			&operator[](std::string const &name);
	bool				scopeExists(std::string const &name);

      private:
	bool				isScope(std::string const &line);
	bool				isComment(std::string const &line);
	bool				isEmpty(std::string const &line);

	const std::string		parseScopeName(std::string const &line);
	int				parseScopeEntry(std::string const &line, t_entry &entry);
	int				parseScopeEntry(t_raw_content_ci &hook, t_entry &entry);

	int				handleNewScope();

	void				epureWord(std::string &word);
      };
    }
  }
}

#endif /* !MACRO_ENGINE_INIPARSER_HPP */

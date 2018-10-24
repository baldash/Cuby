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

# include				"macroengine-core/parser/AParser/AParser.hpp"
# include				"macroengine-core/parser/ini/IniScope/IniScope.hpp"

namespace				macroengine {
  namespace				parser {
    namespace				ini {
      /**
       * \class IniParser
       * \brief The ini file Macro Engine parser, based on the AParser class.
       */
      class				IniParser : public AParser {
      private:
	file::t_raw_content_ci		_file_current_line_hook;
	file::t_raw_content_ci		_file_end_hook;
	file::t_raw_content_ci		_file_begin_hook;
	t_scope_content			_parsed_content;

      public:
	IniParser();
	virtual ~IniParser() = default;

	virtual void			dump() override;

	virtual int			parseFromFile(file::File &file) override;
	virtual int			parseFromRawContent(file::t_raw_content const &file) override;

	/**
	 * This operator can be used to access a scope from the ini file.
	 * @param name the scope name
	 * @return a const IniScope reference
	 * \sa macroengine::parser::ini::IniScope
	 */
	IniScope const			&operator[](std::string const &name);

	/**
	 * Checks whether the given scope name exists in the parsed content or not.
	 * @return true if it exists, false otherwise
	 */
	bool				scopeExists(std::string const &name);

      private:
	bool				isScope(std::string const &line);
	bool				isComment(std::string const &line);
	bool				isEmpty(std::string const &line);

	const std::string		parseScopeName(std::string const &line);
	int				parseScopeEntry(file::t_raw_content_ci &hook, t_entry &entry);

	int				handleNewScope();

	void				epureWord(std::string &word, std::string const &chars);
	void				formatWord(std::string &word);

	int				countCharacterInString(std::string const &word, char c, bool count_escaped = false);
      };
    }
  }
}

#endif /* !MACRO_ENGINE_INIPARSER_HPP */

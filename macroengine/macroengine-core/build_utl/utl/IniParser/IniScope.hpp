/*
** IniScope.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/parser/ini/IniScope/IniScope.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Mon Feb 05 21:16:21 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_INISCOPE_HPP
# define MACRO_ENGINE_INISCOPE_HPP

# include				<string>
# include				<unordered_map>

namespace				macroengine {
  namespace				build_utl {
    namespace				parser {
      class				IniScope {
      public:
	using				t_ini_scope = std::unordered_map<std::string, std::string>;

      private:
	std::string			_empty;
	std::string			_name;
	t_ini_scope			_content;

      public:
	IniScope() = default;
	virtual ~IniScope() = default;

	void				addEntry(std::string const &key, std::string const &value);
	std::string const		&operator[](std::string const &key) const;
	t_ini_scope const		&getContent() const;
	void				setName(std::string const &name);
	std::string const		&getName();
	size_t				getSize() const;
	bool				keyExists(std::string const &key) const;
      };
    }
  }
}

#endif /* !MACRO_ENGINE_INISCOPE_HPP */

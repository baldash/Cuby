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
# include				"macroengine-core/Object/Object.hpp"

namespace				macroengine {
  namespace				parser {
    namespace				ini {
      /**
       * \class IniScope
       * \brief This class contains one scope of a parsed ini file with the macroengine::parser::ini::IniParser class.
       */
      class				IniScope : protected Object {
      private:
	std::string			_empty;
	std::string			_name;
	t_ini_scope			_content;

      public:
	IniScope();
	virtual ~IniScope() = default;

	virtual void			dump() override;

	/**
	 * Adds an entry and stores it in the t_ini_scope instance.
	 * @param key the key of the entry
	 * @param value the value of the entry
	 */
	void				addEntry(std::string const &key, std::string const &value);

	/**
	 * This operator allows the user to access a value given its key.
	 * @return a const reference to the found value.
	 */
	std::string const		&operator[](std::string const &key) const;

	/**
	 * Gets the content of the scope.
	 * @return the t_ini_scope instance
	 */
	t_ini_scope const		&getContent() const;

	/**
	 * Sets the name of the parsed scope.
	 * @param name the name of the scope
	 */
	void				setName(std::string const &name);

	/**
	 * Gets the name of the parsed scope.
	 */
	std::string const		&getName() const;

	/**
	 * Gets the size of the scope in terms of lines.
	 */
	size_t				getSize() const;

	/**
	 * Checks whether a key exists or not.
	 * @param key the asked key
	 * @return true if the key exists, false otherwise
	 */
	bool				keyExists(std::string const &key) const;
      };
    }
  }
}

#endif /* !MACRO_ENGINE_INISCOPE_HPP */

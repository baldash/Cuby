/*
** StringBuilder.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/utl/strings/StringBuilder/StringBuilder.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Feb 15 18:40:28 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_STRINGBUILDER_HPP
#define MACRO_ENGINE_STRINGBUILDER_HPP

# include				<cstdarg>
# include				<string>
# include				<unordered_map>
# include				"macroengine-core/Object/Object.hpp"
# include				"macroengine-core/utl/types.hpp"
# include				"macroengine-core/configuration/strings/StringContent/StringContent.hpp"

namespace 				macroengine {
  namespace 				configuration {
    namespace 				strings {
      /**
       * \class StringBuilder
       * \brief allows both user and core to use pre-built, configuration file handled strings.
       * This class should not be called by the user (see examples for which macro to use).
       */
      class				StringBuilder : public Object {
      private:
	t_strings 			_strings;
	t_flags				_flags;
	std::string			_config_file;

      public:
	StringBuilder();
	virtual ~StringBuilder() = default;

	virtual void			dump() override;

	/**
	 * initialization method for the StringBuilder, called by the Configuration class.
	 * @return 0 if OK, 1 otherwise
	 */
	int				configure();

	/**
	 * initialization method for the StringBuilder, called by the Configuration class.
	 * @param parser the main configuration file parser, containing all the game data
	 * @return 0 if OK, 1 otherwise
	 */
	int				configure(parser::ini::IniParser &parser);

	/**
	 * builds a strings, given its id and its params.
	 * Beware: if an error occurs in the flags replacement process (bad number, bad type...), this function may cause a segmentation fault.
	 * @param id the string id
	 * @param ... all kind of argument, matching the asked string flags
	 * @return the built string with the flags replaced by their values
	 */
	std::string			build(std::string const &id, ...);

	/**
	 * adds a string to the pre-built strings array. It should be well formatted, as no verification will occur until a build() call.
	 * @param id the string id
	 * @param str the string itself, well formatted
	 * @param nb_params the number of flags contained in the string
	 */
	void				addString(std::string const &id, std::string const &str, int nb_params);

      private:
	size_t				getNbParams(std::string const &str);
	int				getNextFlag(std::string const &str);

	void				parseSFlag(std::string &str, va_list &ap);
	void				parseLDFlag(std::string &str, va_list &ap);
	void				parseCSFlag(std::string &str, va_list &ap);
	void				parseFFlag(std::string &str, va_list &ap);
	void				parseDFlag(std::string &str, va_list &ap);

	template<typename ParamType, typename VarType>
	int				getNewParam(va_list &ap, ParamType &tmp) {
	  try {
	    tmp = va_arg(ap, VarType);
	  } catch (std::exception const &e) {
	    error(build("exception", e.what()));
	    return 1;
	  }
	  return 0;
	}
      };
    }
  }
}

#endif //MACRO_ENGINE_STRINGBUILDER_HPP

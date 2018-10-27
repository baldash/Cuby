/*
** StringContent.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/utl/strings/StringContent/StringContent.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Feb 15 19:42:20 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_STRINGCONTENT_HPP_
# define MACRO_ENGINE_STRINGCONTENT_HPP_

# include				<string>
# include				"macroengine-core/Object/Object.hpp"

namespace				macroengine {
  namespace 				configuration {
    namespace 				strings {
      /**
       * \class StringContent
       * \brief allows a better use of the StringBuilder class by being just a container, containing the pre-built string and the number of parameters.
       * This class should not be called by the user (see examples for which macro to use).
       */
      struct				StringContent {
	StringContent();

	/**
	 * This constructor takes directly the 2 fields of the class as parameter to speed up the process
	 * @param _str the pre-built string
	 * @param _nb_params the number of parameters
	 */
	StringContent(std::string const &_str, int _nb_params);
	virtual ~StringContent() = default;

	std::string			str;
	int				nb_params;
      };
    }
  }
}

#endif /* !MACRO_ENGINE_STRINGCONTENT_HPP_ */

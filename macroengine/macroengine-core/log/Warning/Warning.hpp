/*
** Warning.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/log/Warning/Warning.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Wed Jan 24 21:25:27 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_WARNING_HPP
# define MACRO_ENGINE_WARNING_HPP

# include		<string>
# include		"macroengine-core/log/macros/macros_log.hpp"

namespace		macroengine {
  namespace		log {
    /**
     * \class Warning
     * \brief This class is used to display a [WARNING] labelled message on the terminal.
     * The user can access it by calling the warning() method on Entity-inherited classes.
     */
    class		Warning {
    public:
      Warning(std::string const &str = "");
      virtual ~Warning() = default;

      static void	display(std::string const &str);
    };
  };
};

#endif /* !MACRO_ENGINE_WARNING_HPP */

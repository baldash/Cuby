/*
** Error.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/log/Error/Error.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Wed Jan 24 21:16:56 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_DUMP_HPP
# define MACRO_ENGINE_DUMP_HPP

# include		<string>
# include		"macroengine-core/log/macros/macros_log.hpp"

namespace 		macroengine {
  namespace		log {
    /**
     * \class Dump
     * \brief This class is used to display a [DUMP] labelled message on the terminal.
     * The user can access it by calling the dump() method on Entity-inherited classes.
     */
    class		Dump {
    public:
      Dump(std::string const &str = "");
      virtual ~Dump() = default;

      static void	display(std::string const &str);
    };
  };
};

#endif /* !MACRO_ENGINE_DUMP_HPP */

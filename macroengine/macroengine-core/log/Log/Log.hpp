/*
** Log.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/log/Log/Log.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Wed Jan 24 21:23:51 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_LOG_HPP
# define MACRO_ENGINE_LOG_HPP

# include		<string>
# include		"macroengine-core/log/macros/macros_log.hpp"

namespace		macroengine {
  namespace		log {
    /**
     * \class Log
     * \brief This class is used to display a [LOG] labelled message on the terminal.
     * The user can access it by calling the log() method on Entity-inherited classes.
     */
    class		Log {
    public:
      Log(std::string const &str = "");
      virtual ~Log() = default;

      static void	display(std::string const &str);
    };
  };
};

#endif /* !MACRO_ENGINE_LOG_HPP */

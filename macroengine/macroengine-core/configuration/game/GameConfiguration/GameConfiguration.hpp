/*
** GameConfiguration.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/configuration/game/GameConfiguration/GameConfiguration.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Mar 15 13:35:36 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_GAMECONFIGURATION_HPP_
# define MACRO_ENGINE_GAMECONFIGURATION_HPP_

# include 				"macroengine-core/configuration/game/GameMiscConfiguration/GameMiscConfiguration.hpp"
# include				"macroengine-core/parser/ini/IniParser/IniParser.hpp"
# include				"macroengine-core/Object/Object.hpp"
# include				"macroengine-core/configuration/game/GameWindowConfiguration/GameWindowConfiguration.hpp"

namespace 				macroengine {
  namespace 				configuration {
    namespace 				game {
      /**
       * @class GameConfiguration
       * \brief implements GameWindowConfiguration and GameMiscConfiguration classes.
       * This class allows the user to properly configure his game with the configuration files.
       * This class should not be called by the user (see examples for which macro to use).
       */
      struct				GameConfiguration : public Object {
      public:
	GameWindowConfiguration		window;
	GameMiscConfiguration		misc;

	GameConfiguration() = default;
	virtual ~GameConfiguration() = default;

	virtual void			dump() override;

	/**
	 * initialization method called by Configuration.
	 * @param parser the main configuration file parser, containing all the main configuration data
	 * @return 0 if OK, 1 otherwise
	 * @sa macroengine::parser::ini::IniParser
	 */
	int				configure(parser::ini::IniParser &parser);

	/**
	 * gets a const reference on itself, to avoid modification.
	 * @return a const reference on itself
	 */
	GameConfiguration const		&getAsConst() const;
      };
    }
  }
}

#endif /* !MACRO_ENGINE_GAMECONFIGURATION_HPP_ */

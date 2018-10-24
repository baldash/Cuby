/*
** AGameConfiguration.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/configuration/game/AGameConfiguration/AGameConfiguration.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Mar 15 14:21:45 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_AGAMECONFIGURATION_HPP
#define MACRO_ENGINE_AGAMECONFIGURATION_HPP

# include				"macroengine-core/parser/ini/IniScope/IniScope.hpp"
# include				<string>

namespace 				macroengine {
  namespace 				configuration {
    namespace 				game {
      /**
       * \class AGameConfiguration
       * \brief the abstraction for GameMiscConfiguration and GameWindowConfiguration.
       * This class should not be called by the user (see examples for which macro to use).
       */
      class				AGameConfiguration {
      private:
	std::string			_scope;

      public:

        /**
         * the constructor takes a scope name as parameter, so that it will know where to search in the main configuration file.
         * @param scope the scope name
         */
	AGameConfiguration(std::string const &scope);
	virtual ~AGameConfiguration() = default;

	/**
	 * gets the configuration scope name (defined in the child classes).
	 * @return the scope name
	 */
	std::string const		&getConfigScope();

	/**
	 * sets all the child class properties with the values contained in the IniScope.
	 * @param scope the specialized data scope
	 * @sa macroengine::parser::ini::IniScope and Configuration Files examples
	 */
	virtual void			configure(parser::ini::IniScope const &scope) = 0;
      };
    }
  }
}

#endif //MACRO_ENGINE_AGAMECONFIGURATION_HPP

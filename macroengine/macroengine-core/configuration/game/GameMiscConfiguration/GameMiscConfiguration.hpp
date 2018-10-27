/*
** GameMiscConfiguration.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/configuration/game/GameMiscConfiguration/GameMiscConfiguration.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Mar 15 14:14:39 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_GAMEMISCCONFIGURATION_HPP_
# define MACRO_ENGINE_GAMEMISCCONFIGURATION_HPP_

# include				"macroengine-core/configuration/game/AGameConfiguration/AGameConfiguration.hpp"

namespace 				macroengine {
  namespace 				configuration {
    namespace 				game {
      /**
       * \class GameMiscConfiguration
       * \brief retrieves the configuration data contained in the MACROENGINE_VAR_CONFIGURATION_FILE_SCOPE_MISC macro.
       * This class should not be called by the user (see examples for which macro to use).
       * \sa Macros
       */
      class				GameMiscConfiguration : public AGameConfiguration {
      public:
	GameMiscConfiguration();
	virtual ~GameMiscConfiguration() = default;

	/**
	 * initialization method called by GameConfiguration class, inherited from AGameConfiguration.
	 * @param scope the specialized data scope
	 */
	virtual void			configure(parser::ini::IniScope const &scope) override;
      };
    }
  }
}

#endif /* !MACRO_ENGINE_GAMEMISCCONFIGURATION_HPP_ */

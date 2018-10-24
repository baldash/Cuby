/*
** UserWindowConfiguration.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/configuration/user_configuration/UserWindowConfiguration/UserWindowConfiguration.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Mar 15 13:33:09 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_GAMEWINDOWCONFIGURATION_HPP_
# define MACRO_ENGINE_GAMEWINDOWCONFIGURATION_HPP_

# include				<string>
# include				"macroengine-core/configuration/game/AGameConfiguration/AGameConfiguration.hpp"
# include 				"macroengine-core/utl/Dimensions/Dimensions.hpp"

namespace 				macroengine {
  namespace 				configuration {
    namespace 				game {

      /**
       * \class GameWindowConfiguration
       * \brief retrieves the configuration data contained in the MACROENGINE_VAR_CONFIGURATION_FILE_SCOPE_WINDOW macro.
       * This class should not be called by the user (see examples for which macro to use).
       * \sa Macros
       */
      class				GameWindowConfiguration : public AGameConfiguration {
      public:
	macroengine::utl::Dimensions	dimensions;
	std::string			title;
	bool				fullscreen;

      public:
	GameWindowConfiguration();
	virtual ~GameWindowConfiguration() = default;

	/**
	 * initialization method called by GameConfiguration class, inherited from AGameConfiguration.
	 * @param scope the specialized data scope
	 */
	virtual void			configure(parser::ini::IniScope const &scope) override;
      };
    }
  }
}


#endif /* !MACRO_ENGINE_GAMEWINDOWCONFIGURATION_HPP_ */

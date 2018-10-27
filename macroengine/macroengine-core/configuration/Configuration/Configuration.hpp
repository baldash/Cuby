/*
** Configuration.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/core/Configuration/Configuration.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Tue Feb 13 23:20:01 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_CONFIGURATION_HPP
#define MACRO_ENGINE_CONFIGURATION_HPP

# include				"macroengine-core/configuration/game/GameConfiguration/GameConfiguration.hpp"
# include				"macroengine-core/Object/Object.hpp"
# include				"macroengine-core/configuration/Environment/Environment.hpp"
# include				"macroengine-core/configuration/EntityRegister/EntityRegister.hpp"
# include				"macroengine-core/configuration/strings/StringBuilder/StringBuilder.hpp"
# include				"macroengine-core/configuration/EntityIDGenerator/EntityIDGenerator.hpp"

namespace 				macroengine {
  namespace 				configuration {

    /**
     * \class Configuration
     * \brief Contains every configuration component, used by the core and by the user to interact with core or user-defined game properties.
     * This class should not be called by the user (see examples for which macro to use).
     */
    class				Configuration : public Object {
    private:
      Environment			_environment;
      EntityRegister			_entity_register;
      strings::StringBuilder		_strings;
      EntityIDGenerator			_entity_id_generator;

      std::string			_main_configuration_file;

      game::GameConfiguration		_game_configuration;

    public:
      Configuration();
      virtual ~Configuration() = default;

      virtual void			dump() override;

      /**
       * initialization method; starts the Configuration components by calling either their own configure() method or their init() method.
       * @return 0 if OK, 1 otherwise
       */
      int				configure();

      /**
       * gets the Environment class instance.
       * @return a reference on the private member
       * @sa macroengine::configuration::Environment
       */
      Environment			&getEnvironment();

      /**
       * gets the EntityRegister class instance.
       * @return a reference on the private member
       * @sa macroengine::configuration::EntityRegister
       */
      EntityRegister			&getEntityRegister();

      /**
       * gets the strings::StringBuilder class instance.
       * @return a reference on the private member
       * @sa macroengine::configuration::strings::StringBuilder
       */
      strings::StringBuilder		&getStringBuilder();

      /**
       * gets the EntityIDGenerator class to access/modify environment properties.
       * @return a reference on the private member
       * @sa macroengine::configuration::EntityIDGenerator
       */
      EntityIDGenerator			&getEntityIDGenerator();

      /**
       * sets the main configuration file of the game. It should be a .ini file (see the Configuration files examples section).
       * @param file the path of the configuration file
       */
      void				setConfigurationFile(std::string const &file);

      /**
       * gets the game::GameConfiguration class instance.
       * usage of the Macro Engine macros recommended to access this class properties.
       * @return a reference on the private member
       * @sa macroengine::configuration::game::GameConfiguration
       */
      game::GameConfiguration		&getGameConfiguration();
    };
  }
}


#endif //MACRO_ENGINE_CONFIGURATION_HPP

/*
** Environment.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/core/configuration/Environment/Environment.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Tue Feb 13 23:21:28 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_ENVIRONMENT_HPP
#define MACRO_ENGINE_ENVIRONMENT_HPP

# include				"macroengine-core/Object/Object.hpp"

namespace 				macroengine {
  namespace 				configuration {
    /**
     * \class Environment
     * \brief Allows the user to define its environment (main arguments: ac, av, ae) and the game resources directory.
     * This class should not be called by the user (see examples for which macro to use).
     */
    class				Environment : public Object {
    private:
      char				**_av;
      char				**_ae;
      int				_ac;
      std::string			_resources_directory;

    public:
      Environment();
      virtual ~Environment() = default;

      virtual void			dump() override;

      /**
       * initialization method for the Environment class, called by the Configuration class.
       * @return 0 if OK, 1 otherwise
       */
      int				configure();

      /**
       * sets the class environment variables
       * @param ac first main parameter
       * @param av second main parameter
       * @param ae third main parameter
       */
      void				set(int ac, char **av, char **ae);

      /**
       * gets the resources directory (set by MACROENGINE_VAR_DEFAULT_RESOURCES_DIRECTORY by default).
       * @return the path to the resources directory, relative to the program launching directory
       * @sa Macros files
       */
      std::string const			&getResourcesDirectory() const;

      /**
       * gets a const reference on itself to prevent modification after initialization.
       * @return a const reference on itself
       */
      Environment const			&getAsConst();
    };
  }
}

#endif //MACRO_ENGINE_ENVIRONMENT_HPP

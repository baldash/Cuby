/*
** Core.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/core/Core/Core.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Tue Feb 13 23:18:11 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_CORE_HPP
#define MACRO_ENGINE_CORE_HPP

# include				"macroengine-core/clock/Clock/Clock.hpp"
# include				"macroengine-core/configuration/Configuration/Configuration.hpp"
# include				"macroengine-core/controller/GeneralController/GeneralController.hpp"

namespace				macroengine {
  namespace				core {

    /**
     * \class Core
     * \brief The main class of the Macro Engine.
     * It contains instances of Configuration, GeneralController and Clock classes.
     * Thus, this class contains everything the game needs to run.
     * All these classes instances and all the Core methods can be accessed by macros. It is not recommended for the user to access them manually.
     */
    class				Core : public Object {
    private:
      configuration::Configuration	_configuration;
      controller::GeneralController	_general_controller;
      clock::Clock			_clock;
      bool				_running;
      int				_debug_mode;

    public:
      Core();
      virtual ~Core() = default;

      virtual void			dump() override;

      /**
       * The initialization method calling every class instance initialization methods. This is called by the run() method.
       * @return 0 if OK, 1 otherwise
       */
      int				configure();

      /**
       * Gets the Configuration class instance.
       * @return a reference on the Configuration class instance
       */
      configuration::Configuration	&getConfiguration();

      /**
       * Gets the GeneralController class instance.
       * @return a reference on the GeneralController class instance
       */
      controller::GeneralController	&getGeneralController();

      /**
       * Gets the Clock class instance.
       * @return a reference on the Clock class instance
       */
      clock::Clock			&getClock();

      /**
       * Checks whether the game is running or not.
       * @return true if the game is running, false otherwise
       */
      bool				isRunning();

      /**
       * Enables the debug mode or not (refer to the macros_definitions.hpp file on how to use this).
       * @param val the debug mode
       */
      void				setCoreDebugMode(int val);

      /**
       * Runs the game. Call this method to initialise and run the game.
       * @return 0 if OK, 1 otherwise
       */
      int				run();

      /**
       * Stops the game.
       * @return 0 if OK, 1 otherwise
       */
      int				stop();

    private:
      bool				isRunnable();
    };
  }
}
#endif //MACRO_ENGINE_CORE_HPP

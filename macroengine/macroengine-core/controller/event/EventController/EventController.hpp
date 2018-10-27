/*
** EventController.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/controller/EventController/EventController.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Wed Mar 07 19:10:10 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_EventController_HPP
#define MACRO_ENGINE_EventController_HPP

# include				<SFML/Graphics/RenderWindow.hpp>
# include 				"macroengine-core/utl/Position/Position.hpp"
# include				"macroengine-core/controller/AController/AController.hpp"
# include				"macroengine-core/Object/Object.hpp"

namespace 				macroengine {
  namespace 				controller {

    /**
     * \class EventController
     * \brief Handles the events processing and registering.
     * This class should not be used by the user.
     */
    class				EventController : public Object {
    private:
      std::vector<sf::Event>		_events;
      sf::RenderWindow			&_window;
      std::map<input::Keyboard, bool>		_keyboard_state;
      std::map<input::Keyboard, bool>		_pressed_keys;

      std::map<input::MouseButton, bool>	_mouse_button_state;
      std::map<input::MouseButton, bool>	_pressed_mouse_buttons;

      t_mouse_position 			_mouse_position;

      bool				_running;

      t_identifier 			_last_mouse_action_called;
      t_identifier 			_last_keyboard_action_called;

    public:

      /**
       * The constructor must take the sf::RenderWindow as parameter for the event polling process.
       */
      EventController(sf::RenderWindow &);
      virtual ~EventController() = default;

      virtual void			dump() override ;

      /**
       * Initialization method called by the GeneralController.
       * @return 0 if OK, 1 otherwise
       */
      int				configure();

      /**
       * Update method called by the EventController. Updates every CONTROLLABLE component.
       * @param entities The array containing the CONTROLLABLE entities
       * @param total Every known entity.
       * @return 0 if OK, 1 otherwise
       */
      int				update(configuration::t_built_entities &entities, configuration::t_built_entities &total);

      /**
       * Checks whether the game is running or not (this will be useful for the Core to known if the game is user-stopped by an event).
       * @return true if the game is running, false if not
       */
      bool				isRunning();

    private:
      void				updateKeyboardState();
      void				updateMouseButtonState();
      void				updateEvents();

      void				updateKey(configuration::t_built_entity &entity, configuration::t_built_entities &);
      void				updateMouse(configuration::t_built_entity &entity, configuration::t_built_entities &);
    };
  }
}

#endif //MACRO_ENGINE_EventController_HPP

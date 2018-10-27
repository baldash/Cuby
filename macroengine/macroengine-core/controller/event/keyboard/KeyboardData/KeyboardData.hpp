/*
** KeyboardData.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/entity/utl/KeyboardData/KeyboardData.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Wed Mar 07 20:29:35 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_KEYBOARDDATA_HPP
#define MACRO_ENGINE_KEYBOARDDATA_HPP

# include						<vector>
# include						<memory>
# include						"macroengine-core/utl/exceptions.hpp"
# include						"macroengine-core/controller/event/keyboard/KeyboardActionParams/KeyboardActionParams.hpp"
# include						"macroengine-core/entity/property/enum/e_property.hpp"
# include						"macroengine-core/configuration/EntityIDGenerator/EntityIDGenerator.hpp"

namespace 						macroengine {
  namespace 						controller {
    namespace 						event {
      namespace 					keyboard {

        /**
         * \class KeyboardData
         * \brief Class used for the keyboard handling from the Controllable component class.
         * This class should not be used by the user (see which macro to use in the examples).
         * @tparam Type the component type
         */
	template<property::e_property Type>
	class						KeyboardData {
	private:
	  KeyboardActionParams				_empty;
	  t_keyboard_data 				_data;
	  configuration::EntityIDGenerator		&_generator;

	public:

	  /**
	   * The constructor must take the EntityIDGenerator as parameter, because of some troubleshooting issues.
	   * @param generator the EntityIDGenerator instance.
	   */
	  KeyboardData(configuration::EntityIDGenerator &generator) :
	    _generator(generator) {
	  }

	  virtual ~KeyboardData() = default;

	  /**
	   * Adds a keyboard action for a specific key.
	   * @param name The name of the action
	   * @param callable the t_callable associated to the action, created with the makeCallable macro
	   * @param k the key of the action
	   * @return a reference on the newly created action
	   */
	  keyboard::KeyboardActionParams		&addKeyboardAction(std::string const &name, ::macroengine::input::Keyboard k, t_callable callable, t_callable ending_callable = nullptr) {
	    keyboard::KeyboardActionParams		params;

	    params.callable = callable;
	    params.ending_callable = ending_callable;
	    params.identifier.id = _generator.newID();
	    params.identifier.name = name;
	    params.data.ticks = 0;
	    params.data.consecutive_ticks = 0;
	    params.data.is_being_pressed = false;
	    return _data[k].emplace_back(params);
	  }

	  /**
	   * Adds an ending callable to an action.
	   * @param identifier the identifier of the action
	   * @param callable the ending callable
	   * @return a reference on the action
	   */
	  keyboard::KeyboardActionParams		&addEndingCallableToAction(t_identifier const &identifier, t_callable callable) {
	    keyboard::KeyboardActionParams		&action = getKeyboardAction(identifier);

	    if (action.identifier.filled()) {
	      action.ending_callable = callable;
	      action.ending_callable_data.ticks = 0;
	      action.ending_callable_data.is_being_pressed = false;
	    }
	    return action;
	  }

	  /**
	   * Binds an existing keyboard action to another key.
	   * @param id The action ID
	   * @param from The former key
	   * @param to The new key
	   * @return a reference on the changed action
	   */
	  keyboard::KeyboardActionParams		&changeKeyboardAction(t_identifier const &id, input::Keyboard const &from, input::Keyboard const &to) {
	    for (auto data = _data[from].begin(); data != _data[from].end(); data++) {
	      if (data->identifier == id || data->identifier.name == id.name || data->identifier.id == id.id) {
	        keyboard::KeyboardActionParams		params = *data;
		_data[from].erase(data);
		return _data[to].emplace_back(params);
	      }
	    }
	    if (id.id != -1) {
	      throw exception::UnknownKeyboardActionIDException(std::to_string(id.id));
	    } else {
	      throw exception::UnknownKeyboardActionNameException(id.name);
	    }
	  }

	  /**
	   * Gets all the keyboard actions for a given key.
	   * @param k the key
	   * @return an array of KeyboardActionParams
	   */
	  std::vector<KeyboardActionParams>		&getKeyboardActions(::macroengine::input::Keyboard k) {
	    return _data[k];
	  }

	  /**
	   * Gets every known keyboard action.
	   * @return the t_keyboard_data array
	   */
	  t_keyboard_data				&getKeyboardActions() {
	    return _data;
	  }

	  /**
	   * Removes an action given its identifier.
	   * @param identifier the action identifier
	   */
	  void						removeKeyboardAction(t_identifier const &identifier) {
	    if (identifier.id != -1) {
	      removeKeyboardAction(identifier.id);
	    } else {
	      removeKeyboardAction(identifier.name);
	    }
	  }

	  /**
	   * Gets an action giver its identifier. If no action is found, an empty one is returned (exception to be added).
	   * @param identifier the action identifier
	   * @return a reference on the found action
	   */
	  KeyboardActionParams				&getKeyboardAction(t_identifier const &identifier) {
	    if (identifier.id != -1) {
	      return getKeyboardAction(identifier.id);
	    } else {
	      return getKeyboardAction(identifier.name);
	    }
	  }

	private:
	  void						removeKeyboardAction(t_entity_id const &id) {
	    for (auto &&key: _data) {
	      for (std::vector<KeyboardActionParams>::iterator i = key.second.begin(); i != key.second.end(); i++) {
		if (i->identifier.id == id) {
		_data[key.first].erase(i);
		  return ;
		}
	      }
	    }
	  }

	  void						removeKeyboardAction(std::string const &name)
	  {
	    for (auto &&key: _data) {
	      for (std::vector<KeyboardActionParams>::iterator i = key.second.begin(); i != key.second.end(); i++) {
		if (i->identifier.name == name) {
		  _data[key.first].erase(i);
		  return ;
		}
	      }
	    }
	  }

	  KeyboardActionParams				&getKeyboardAction(t_entity_id const &id) {
	    for (auto &&key: _data) {
	      for (auto &&action: key.second) {
		if (action.identifier.id == id)
		  return action;
	      }
	    }
	    return _empty;
	  }

	  KeyboardActionParams				&getKeyboardAction(std::string const &name) {
	    for (auto &&key: _data) {
	      for (auto &&action: key.second) {
		if (action.identifier.name == name)
		  return action;
	      }
	    }
	    return _empty;
	  }
	};
      }
    }
  }
}

#endif //MACRO_ENGINE_KEYBOARDDATA_HPP

/*
** MouseData.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/controller/event/mouse/MouseData/MouseData.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Mar 08 20:45:01 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_MOUSEBUTTONDATA_HPP_
# define MACRO_ENGINE_MOUSEBUTTONDATA_HPP_

# include					<vector>
# include					<memory>
# include					"macroengine-core/controller/event/mouse/MouseActionParams/MouseActionParams.hpp"
# include					"macroengine-core/entity/property/enum/e_property.hpp"
# include					"macroengine-core/configuration/EntityIDGenerator/EntityIDGenerator.hpp"

namespace 					macroengine {
  namespace 					controller {
    namespace 					event {
      namespace 				mouse {

	/**
	 * \class KeyboardData
	 * \brief Class used for the mouse button handling from the Controllable component class.
	 * This class should not be used by the user (see which macro to use in the examples).
	 * @tparam Type the component type
	 */
	template <property::e_property Type>
	class					MouseButtonData {
	private:
	  MouseActionParams			_empty;
	  t_mouse_button_data 			_mouse_button_data;
	  configuration::EntityIDGenerator	&_generator;

	public:

	  /**
	   * The constructor must take the EntityIDGenerator as parameter, because of some troubleshooting issues.
	   * @param generator the EntityIDGenerator instance.
	   */
	  MouseButtonData(configuration::EntityIDGenerator &generator) :
	    _generator(generator) {
	  }

	  virtual ~MouseButtonData() = default;

	  /**
	   * Adds a mouse button action for a specific key.
	   * @param name The name of the action
	   * @param callable the t_callable associated to the action, created with the makeCallable macro
	   * @param k the key of the action
	   * @return a reference on the newly created action
	   */
	  mouse::MouseActionParams		&addMouseButtonAction(std::string const &name, ::macroengine::input::MouseButton k, t_callable callable) {
	    MouseActionParams			params;

	    params.identifier.name = name;
	    params.identifier.id = _generator.newID();
	    params.callable = callable;
	    params.data.ticks = 0;
	    return _mouse_button_data[k].emplace_back(params);
	  }

	  /**
	   * Gets all the mouse button actions for a given key.
	   * @param k the key
	   * @return an array of MouseActionParams
	   */
	  std::vector<MouseActionParams>	&getMouseButtonActions(::macroengine::input::MouseButton k) {
	    return _mouse_button_data[k];
	  }

	  /**
	   * Gets every known mouse button action.
	   * @return the t_mouse_button_data array
	   */
	  t_mouse_button_data			&getMouseButtonActions() {
	    return _mouse_button_data;
	  }

	  /**
	   * Gets an action giver its identifier. If no action is found, an empty one is returned (exception to be added).
	   * @param identifier the action identifier
	   * @return a reference on the found action
	   */
	  MouseActionParams			&getMouseButtonAction(t_identifier const &identifier) {
	    if (identifier.id != -1) {
	      return getMouseButtonAction(identifier.id);
	    } else {
	      return getMouseButtonAction(identifier.name);
	    }
	  }

	  /**
	   * Removes an action given its identifier.
	   * @param identifier the action identifier
	   */
	  void					removeMouseButtonAction(t_identifier const &identifier) {
	    if (identifier.id != -1) {
	      removeMouseButtonAction(identifier.id);
	    } else {
	      removeMouseButtonAction(identifier.name);
	    }
	  }

	private:
	  void					removeMouseButtonAction(t_entity_id const &id) {
	    for (auto &&button: _mouse_button_data) {
	      for (std::vector<MouseActionParams>::iterator i = button.second.begin(); i != button.second.end(); i++) {
		if (i->identifier.id == id) {
		  _mouse_button_data[button.first].erase(i);
		  return ;
		}
	      }
	    }
	  }

	  void					removeMouseButtonAction(std::string const &name) {
	    for (auto &&button: _mouse_button_data) {
	      for (std::vector<MouseActionParams>::iterator i = button.second.begin(); i != button.second.end(); i++) {
		if (i->identifier.name == name) {
		  _mouse_button_data[button.first].erase(i);
		  return ;
		}
	      }
	    }
	  }

	  MouseActionParams			&getMouseButtonAction(t_entity_id const &id) {
	    for (auto &&key: _mouse_button_data) {
	      for (auto &&action: key.second) {
		if (action.identifier.id == id)
		  return action;
	      }
	    }
	    return _empty;
	  }

	  MouseActionParams			&getMouseButtonAction(std::string const &name) {
	    for (auto &&key: _mouse_button_data) {
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

#endif /* !MACRO_ENGINE_MOUSEBUTTONDATA_HPP_ */

/*
** MouseData.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/controller/event/mouse/MouseData/MouseData.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Mar 08 20:45:01 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_MOUSEMOVEDATA_HPP_
# define MACRO_ENGINE_MOUSEMOVEDATA_HPP_

# include						<vector>
# include						<memory>
# include						"macroengine-core/controller/event/mouse/MouseActionParams/MouseActionParams.hpp"
# include						"macroengine-core/configuration/EntityIDGenerator/EntityIDGenerator.hpp"

namespace 						macroengine {
  namespace 						controller {
    namespace 						event {
      namespace 					mouse {

	/**
	 * \class MouseMoveData
	 * \brief Class used for the mouse move handling from the Controllable component class.
	 * This class should not be used by the user (see which macro to use in the examples).
	 * @tparam Type the component type
	 */
	template <property::e_property Type>
	class						MouseMoveData {
	private:
	  t_mouse_move_data 				_mouse_move_data;
	  configuration::EntityIDGenerator		&_generator;

	public:

	  /**
	   * The constructor must take the EntityIDGenerator as parameter, because of some troubleshooting issues.
	   * @param generator the EntityIDGenerator instance.
	   */
	  MouseMoveData(configuration::EntityIDGenerator &gen) :
	    _generator(gen) {
	  }

	  virtual ~MouseMoveData() = default;

	  /**
	   * Adds a mouse move action.
	   * @param name The name of the action
	   * @param callable the t_callable associated to the action, created with the makeCallable macro
	   * @return a reference on the newly created action
	   */
	  mouse::MouseActionParams			&addMouseMoveAction(std::string const &name, t_callable callable) {
	    MouseActionParams				params;

	    params.callable = callable;
	    params.identifier.name = name;
	    params.identifier.id = _generator.newID();
	    params.data.ticks = 0;

	    return _mouse_move_data.emplace_back(params);
	  }

	  /**
	   * Gets every known mouse move action added by the user.
	   * @return the t_mouse_mode_data array
	   */
	  t_mouse_move_data				&getMouseMoveActions() {
	    return _mouse_move_data;
	  }

	  /**
	   * Gets the current mouse position.
	   * @return a graphics::utl::Position
	   */
	  macroengine::utl::Position			getMousePosition() {
	    if (_mouse_move_data.size() == 0) {
	      return macroengine::utl::Position(0, 0);
	    } else {
	      return _mouse_move_data[0].position;
	    }
	  }

	  /**
	   * Removes a mouse mode action given its identifier.
	   * @param identifier the action identifier
	   */
	  void						removeMouseMoveAction(t_identifier const &identifier) {
	    if (identifier.id != -1) {
	      removeMouseMoveAction(identifier.id);
	    } else {
	      removeMouseMoveAction(identifier.name);
	    }
	  }

	private:
	  void						removeMouseMoveAction(t_entity_id const &id) {
	    for (t_mouse_move_data::iterator i = _mouse_move_data.begin(); i != _mouse_move_data.end(); i++) {
	      if (i->identifier.id == id) {
		_mouse_move_data.erase(i);
		return ;
	      }
	    }
	  }

	  void						removeMouseMoveAction(std::string const &name) {
	    for (t_mouse_move_data::iterator i = _mouse_move_data.begin(); i != _mouse_move_data.end(); i++) {
	      if (i->identifier.name == name) {
		_mouse_move_data.erase(i);
		return ;
	      }
	    }
	  }
	};
      }
    }
  }
}
#endif /* !MACRO_ENGINE_MOUSEMOVEDATA_HPP_ */

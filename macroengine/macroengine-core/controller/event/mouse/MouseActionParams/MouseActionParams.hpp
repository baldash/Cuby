/*
** MouseActionParams.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/controller/event/mouse/MouseActionParams/MouseActionParams.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Mar 08 20:42:50 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_MOUSEACTIONPARAMS_HPP
#define MACRO_ENGINE_MOUSEACTIONPARAMS_HPP

# include				"macroengine-core/utl/struct/CallableData/CallableData.hpp"
# include				"macroengine-core/utl/Position/Position.hpp"

namespace 				macroengine {
  namespace 				controller {
    namespace 				event {
      namespace 			mouse {
	/**
	 * \struct MouseActionParams
	 * \brief Contains some useful data for the mouse action, such as its identifier or the callable defined by the user.
	 * \sa "Event handling" examples
	 */
	struct 				MouseActionParams {
	  t_identifier 			identifier;
	  utl::CallableData		data;
	  t_callable 			callable;
	  bool				toggled = false;
	  utl::Position			position = {0, 0};
	};
      }
    }
  }
}

#endif //MACRO_ENGINE_MOUSEACTIONPARAMS_HPP

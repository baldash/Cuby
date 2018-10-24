/*
** KeyboardActionParams.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/controller/event/keyboard/KeyboardActionParams/KeyboardActionParams.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Wed Mar 07 21:16:42 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_KEYBOARDACTIONPARAMS_HPP_
# define MACRO_ENGINE_KEYBOARDACTIONPARAMS_HPP_

# include				"macroengine-core/utl/types.hpp"

namespace 				macroengine {
  namespace 				controller {
    namespace 				event {
      namespace 			keyboard {

        /**
         * \struct KeyboardActionParams
         * \brief Contains some useful data for the keyboard action, such as its identifier or the callable defined by the user.
         * \sa "Event handling" examples
         */
	class				KeyboardActionParams {
	public:
	  utl::CallableData		data;
	  utl::CallableData		ending_callable_data;
	  t_identifier 			identifier;

	  t_callable 			ending_callable;
	  t_callable			callable;

	  bool				enabled = true;
	  bool				toggled = false;

	  KeyboardActionParams() = default;
	  virtual ~KeyboardActionParams() = default;
	};
      }
    }
  }
}

#endif /* !MACRO_ENGINE_KEYBOARDACTIONPARAMS_HPP_ */

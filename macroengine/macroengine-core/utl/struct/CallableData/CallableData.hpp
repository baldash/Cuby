/*
** CallableData.hpp for Macro_Engine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/entity/component/utl/CallableData/CallableData.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Fri May 04 22:14:40 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_SCRIPTABLECALLABLEDATA_HPP_
# define MACRO_ENGINE_SCRIPTABLECALLABLEDATA_HPP_

# include				"macroengine-core/utl/struct/s_identifier/s_identifier.hpp"
namespace 				macroengine {
  namespace 				utl {
    /**
     * \struct CallableData
     * \brief This structure is passed as parameter to the user-defined callables.
     * This provides a set of useful values (such as the number of times this callable was called) the user can use or the identifier of the last action called.
     */
    struct				CallableData {
      long				ticks;
      struct s_identifier		last_callable_action_called;
      bool				is_being_pressed;
      long				consecutive_ticks;
    };
  }
}

#endif /* !MACRO_ENGINE_SCRIPTABLECALLABLEDATA_HPP_ */

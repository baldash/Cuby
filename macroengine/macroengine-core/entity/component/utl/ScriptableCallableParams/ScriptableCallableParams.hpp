/*
** ScriptableParams.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/entity/component/utl/ScriptableParams/ScriptableParams.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Wed Mar 14 22:04:30 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_SCRIPTABLECALLABLEPARAMS_HPP_
# define MACRO_ENGINE_SCRIPTABLECALLABLEPARAMS_HPP_

# include				"macroengine-core/utl/macros/macros_misc.hpp"
# include				"macroengine-core/utl/struct/CallableData/CallableData.hpp"

namespace 				macroengine {
  namespace				entity {
    namespace				component {
      /**
       * \struct ScriptableCallableParams
       * \brief Container providing useful informations on a generated script.
       * This will contain its identifier, its callable data and its delay id
       */
      struct				ScriptableCallableParams {
	utl::CallableData		data;
	t_identifier			identifier;
	clock::t_delay_id		delay_id = -1;
	controller::t_callable		callable;
      };
    }
  }
}

#endif /* !MACRO_ENGINE_SCRIPTABLECALLABLEPARAMS_HPP_ */

/*
** macros_misc.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/utl/macros/macros_misc.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Wed Feb 14 00:00:07 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_MACROS_MISC_HPP_
# define MACRO_ENGINE_MACROS_MISC_HPP_

# include			<cmath>
# include			"macroengine-core/utl/macros/macros_attributes.hpp"
# include			"macroengine-core/utl/types.hpp"

/**
 * \def MACROENGINE_NULL
 * Sets the default NULL pointer value.
 */
# ifndef			MACROENGINE_NULL
#  define			MACROENGINE_NULL		(nullptr)
# endif				/* !MACROENGINE_NULL */

/**
 * \def MACROENGINE_PTR_ERROR
 * Sets the default value for the pointer if an error occurs treating with it.
 */
# ifndef			MACROENGINE_PTR_ERROR
#  define			MACROENGINE_PTR_ERROR		(reinterpret_cast<void *>(-1))
# endif				/* !MACROENGINE_PTR_ERROR */

/**
 * \def CallableFunction
 * This macro can be used by the user to build a compatible method prototype with the callable Macro Engine system.
 */
# ifndef			CallableFunction
#  define			CallableFunction(NAME)		void NAME(UNUSED macroengine::configuration::t_built_entities &entities, UNUSED macroengine::utl::CallableData const &data)
# endif				/* !CallableFunction */

/**
 * \def InvokableFunction
 * This macro can be used by the user to build a compatible method prototype with the invokable Macro Engine system.
 */
# ifndef			InvokableFunction
#  define			InvokableFunction		void invoke(std::string const &str)
# endif				/* !InvokableFunction */

/**
 * \def MACROENGINE_FPS_TO_SECONDS
 * This macro can be used to convert a FPS number to seconds.
 */
# ifndef			FPSToSeconds
#  define			FPSToSeconds(N)			(1 / (float)(N))
# endif				/* !FPSToSeconds */

#endif /* !MACRO_ENGINE_MACROS_MISC_HPP_ */

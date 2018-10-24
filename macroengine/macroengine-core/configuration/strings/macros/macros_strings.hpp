/*
** macros_strings.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/utl/macros/macros_strings.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Feb 15 20:23:02 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_MACROS_STRINGS_HPP_
# define MACRO_ENGINE_MACROS_STRINGS_HPP_

# include			"macroengine-core/core/global/g_core.hpp"

/**
 * \def Strings
 * redirection to the StringBuilder::build method from the StringBuilder class instance.
 * @sa macroengine::strings::StringBuilder and examples
 */
# ifndef			MACROENGINE_STRINGS
#  define			Strings		g_core.getConfiguration().getStringBuilder().build
# endif				/* !MACROENGINE_STRINGS */

#endif /* !MACRO_ENGINE_MACROS_STRINGS_HPP_ */

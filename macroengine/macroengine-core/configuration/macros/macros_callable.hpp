/*
** macros_callable.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/configuration/macros/macros_callable.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Fri Feb 16 16:51:38 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_MACROS_CALLABLE_HPP_
# define MACRO_ENGINE_MACROS_CALLABLE_HPP_

# include	<functional>
# include	"macroengine-core/entity/property/enum/e_property.hpp"
# include	"macroengine-core/utl/configuration.hpp"
# include	"macroengine-core/configuration/static/to_identifier.hpp"

/**
 * \def makeCallable(C)
 * creates a t_callable from a method name (of form [UsedDefinedEntity]::[method], see the examples for more info).
 * \param C the method name
 */
# ifndef	MACROENGINE_MAKE_CALLABLE
#  define	makeCallable(C)					std::bind(&C, this, std::placeholders::_1, std::placeholders::_2)
# endif		/* !MACROENGINE_MAKE_CALLABLE */

/**
 * \def toIdentifier
 * wrapper of the macroengine::ToIdentifier::to_identifier methods.
 * @sa macroengine::ToIdentifier class
 */
#ifndef		MACROENGINE_TO_IDENTIFIER
#  define	toIdentifier					macroengine::ToIdentifier::to_identifier
# endif		/* !MACROENGINE_TO_IDENTIFIER */

#endif /* !MACRO_ENGINE_MACROS_CALLABLE_HPP_ */

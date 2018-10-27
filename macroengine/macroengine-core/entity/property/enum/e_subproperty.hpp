/*
** e_subproperty.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/entity/property/enum/e_subproperty.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sat Mar 10 16:42:15 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_E_SUBPROPERTY_HPP_
# define MACRO_ENGINE_E_SUBPROPERTY_HPP_

namespace 				macroengine {
  namespace 				property {

    /**
     * \enum e_subproperty
     * \brief This enum provides a set of subproperties, mainly for the Drawable entity configuration.
     * The user should use this enum at every Drawable entity definition.
     */
    enum				e_subproperty : size_t {
      ANIMATION				= 1,
      SPRITE				= 2,
      TEXT				= 4,
      SHAPE				= 8,
      VIEW				= 16,
    };
  }
}

#endif /* !MACRO_ENGINE_E_SUBPROPERTY_HPP_ */

/*
** e_property.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/enum/e_property.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Wed Jan 24 20:55:28 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_E_PROPERTY_HPP_
# define MACRO_ENGINE_E_PROPERTY_HPP_

# include			<cstddef>

namespace			macroengine {
  namespace			property {

    /**
     * \enum e_property
     * \brief This enum provides a set of values accessible for the core to define the components used by the created entity.
     * This enum should not be used by the user, use the macroengine::property classes instead.
     */
    enum			e_property : size_t {
      NONE			= 0,
      DRAWABLE			= 1,
      CONTROLLABLE		= 2,
      COLLIDABLE		= 4,
      MOVABLE			= 8,
      FACTORY			= 16,
      SCRIPTABLE		= 32,
    };
  }
}

#endif /* !MACRO_ENGINE_E_PROPERTY_HPP_ */

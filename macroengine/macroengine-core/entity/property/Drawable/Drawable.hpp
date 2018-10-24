/*
** Drawable.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/entity/property/enum/Drawable/Drawable.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Wed Feb 14 23:13:57 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_PROPERTY_DRAWABLE_HPP
#define MACRO_ENGINE_PROPERTY_DRAWABLE_HPP

# include				"macroengine-core/entity/Entity/Entity.hpp"
# include				"macroengine-core/entity/property/IProperty/IProperty.hpp"

namespace				macroengine {
  namespace 				property {

    /**
     * \class Drawable
     * \brief The Drawable class defining the DRAWABLE property the the inherited Entity central class.
     * In addition, this class holds a template parameter to specify which Drawable components will be used by the class (see examples).
     * \tparam Props the subproperty parameters for the DRAWABLE property
     */
    template<size_t Props = 0>
    class				Drawable : public IProperty, virtual public entity::Entity {
    public:
      Drawable() {
	addProperty(property::DRAWABLE);
	addSubProperties(property::DRAWABLE, utl::BitMask(Props));
      }

      virtual ~Drawable() = default;
    };
  }
}

#endif //MACRO_ENGINE_PROPERTY_DRAWABLE_HPP

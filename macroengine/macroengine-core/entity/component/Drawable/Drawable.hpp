/*
** Drawable.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/entity/Drawable/Drawable.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Feb 15 00:01:35 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_COMPONENT_DRAWABLE_HPP
#define MACRO_ENGINE_COMPONENT_DRAWABLE_HPP

# include				<SFML/Graphics.hpp>
# include				"macroengine-core/graphics/drawable/view/ViewWrapper/ViewWrapper.hpp"
# include				"macroengine-core/graphics/drawable/shape/ShapeWrapper/ShapeWrapper.hpp"
# include				"macroengine-core/graphics/drawable/sprite/SpriteWrapper/SpriteWrapper.hpp"
# include				"macroengine-core/graphics/drawable/animation/AnimationWrapper/AnimationWrapper.hpp"
# include				"macroengine-core/graphics/drawable/text/TextWrapper/TextWrapper.hpp"
# include				"macroengine-core/entity/component/AComponent/AComponent.hpp"
# include				"macroengine-core/entity/AEntity/AEntity.hpp"

namespace				macroengine {
  namespace 				entity {
    namespace 				component {
      /**
       * \class Drawable
       * \brief The Drawable component of the entity. Enabled if the entity is built with property::DRAWABLE.
       * This class provides getters on every Drawable component (animations, sprites...).
       * The user can enable them by setting the right subproperty in his entity definition (see examples).
       */
      class				Drawable : virtual public AComponent<property::DRAWABLE>, virtual protected AEntity {
      private:
	graphics::AnimationWrapper	_animation_wrapper;
	graphics::SpriteWrapper		_sprite_wrapper;
	graphics::TextWrapper		_text_wrapper;
	graphics::ShapeWrapper		_shape_wrapper;
	graphics::ViewWrapper		_view_wrapper;

      public:
	Drawable();
	virtual ~Drawable() = default;

	/**
	 * Gets the animation handler.
	 * @return a reference on the animation handler
	 */
	graphics::AnimationWrapper	&animationHandler();

	/**
	 * Gets the sprite handler.
	 * @return a reference on the sprite handler
	 */
	graphics::SpriteWrapper		&spriteHandler();

	/**
	 * Gets the text handler.
	 * @return a reference on the text handler
	 */
	graphics::TextWrapper		&textHandler();

	/**
	 * Gets the shape handler.
	 * @return a reference on the shape handler
	 */
	graphics::ShapeWrapper		&shapeHandler();

	/**
	 * Gets the view handler.
	 * @return a reference on the view handler
	 */
	graphics::ViewWrapper		&viewHandler();
      };
    }
  }
}

#endif //MACRO_ENGINE_COMPONENT_DRAWABLE_HPP

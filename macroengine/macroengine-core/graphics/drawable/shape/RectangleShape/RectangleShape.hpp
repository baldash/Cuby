/*
** Box.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/graphics/drawable/Box/Box.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Mon Mar 19 10:44:31 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_RECTANGLESHAPE_HPP
#define MACRO_ENGINE_RECTANGLESHAPE_HPP

# include					<SFML/Graphics/RectangleShape.hpp>
# include					<SFML/Graphics/Text.hpp>
# include					"macroengine-core/graphics/utl/TextEntry/TextEntry.hpp"
# include					"macroengine-core/graphics/drawable/shape/AShape/AShape.hpp"
# include					"macroengine-core/utl/Dimensions/Dimensions.hpp"
# include					"macroengine-core/utl/Position/Position.hpp"
# include					"macroengine-core/utl/types.hpp"

namespace 					macroengine {
  namespace 					graphics {
    /**
     * \class RectangleShape
     * \brief Provides a regtangle shape implementation of the AShape class.
     */
    class					RectangleShape : public AShape {
    private:
      sf::RectangleShape			_shape;
      sf::Color					_color;
      macroengine::utl::Position		_position;
      macroengine::utl::Dimensions		_dimensions;

    public:
      RectangleShape() = default;
      virtual ~RectangleShape() = default;

      /**
       * Sets the shape position.
       * @param position the new position
       * @return a reference on itself
       */
      RectangleShape				&setPosition(macroengine::utl::Position const &position);

      /**
       * Sets the shape position.
       * @param x the new x position
       * @param y the new y position
       * @return a reference on itself
       */
      RectangleShape				&setPosition(size_t x, size_t y);

      /**
       * Sets the shape color.
       * @param color the color
       * @return a reference on itself
       */
      RectangleShape				&setColor(Color const &color);

      /**
       * Sets the shape dimensions.
       * @param dimensions the new dimensions
       * @return a reference on itself
       */
      RectangleShape				&setDimensions(macroengine::utl::Dimensions const &dimensions);

      /**
       * Sets the shape dimensions.
       * @param width the new width
       * @param height the new height
       * @return a reference on itself
       */
      RectangleShape				&setDimensions(size_t width, size_t height);

      /**
       * Adds an offset to the shape, redefining its dimensions.
       * @param offset the offset
       * @return a reference on itself
       */
      RectangleShape				&addOffset(macroengine::utl::Dimensions const &offset);
      /**
       * Adds an offset to the shape, redefining its dimensions.
       * @param width the offset width
       * @param height the offset height
       * @return a reference on itself
       */
      RectangleShape				&addOffset(size_t width, size_t height);

      /**
       * Creates a shape from a given sf::Text. This method created a box of the same dimensions of the text, that can be used as a highlighting utility.
       * @param text the text
       * @return a reference on itself
       */
      RectangleShape				&createFromText(sf::Text const &text);
      /**
       * Creates a shape from a given text::TextEntry. This method created a box of the same dimensions of the text, that can be used as a highlighting utility.
       * @param text the text
       * @return a reference on itself
       */
      RectangleShape				&createFromText(utl::TextEntry const &text);

      /**
       * Gets the created sf::RectangleShape.
       * @return a sf::RectangleShape
       */
      sf::RectangleShape			&getShape();

      /**
       * Gets the created sf::Color.
       * @return a sf::Color
       */
      sf::Color	const				&getColor() const;

      /**
       * Gets the shape position.
       * @return the position
       */
      macroengine::utl::Position const		&getPosition() const;

      /**
       * Gets the shape dimensions.
       * @return the dimensions
       */
      macroengine:: utl::Dimensions const	&getDimensions() const;
    };
  }
}

#endif //MACRO_ENGINE_RECTANGLESHAPE_HPP

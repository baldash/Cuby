/*
** Sprite.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/graphics/Sprite/Sprite.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sat Mar 10 22:36:16 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_SPRITE_HPP
#define MACRO_ENGINE_SPRITE_HPP

# include				<SFML/Graphics/Texture.hpp>
# include				<SFML/Graphics/Sprite.hpp>
# include				"macroengine-core/graphics/drawable/ADrawableHandler/ADrawableHandler.hpp"
# include				"macroengine-core/utl/Position/Position.hpp"
# include				"macroengine-core/Object/Object.hpp"

namespace 				macroengine {
  namespace 				graphics {
    /**
     * \class Sprite
     * \brief The sf::Sprite wrapper, allowing the user to create a sprite from a texture file.
     * See the examples on how to handle this class.
     */
    class				Sprite : public ADrawableHandler, public Object {
    private:
      sf::Texture			_texture;
      sf::Sprite			_sprite;
      macroengine::utl::Position	_position;

    public:
      Sprite();
      virtual ~Sprite();

      virtual void			dump() override;

      /**
       * Loads a sprite from a texture file.
       * @param file the file path
       * @return 0 of OK, 1 otherwise
       */
      Sprite				&loadFromFile(std::string const &file);

      /**
       * Loads a sprite from another Sprite.
       * @param sprite the Sprite.
       * @return 0 of OK, 1 otherwise
       */
      Sprite				&loadFromSprite(Sprite const &sprite);

      /**
       * Sets the sprite position.
       * @param pos the position
       */
      Sprite				&setPosition(macroengine::utl::Position const &pos);

      /**
       * Gets the created sf::Texture. This should be reserved to the Macro Engine core.
       * @return the texture
       */
      sf::Texture const			&getTexture() const;

      /**
       * Gets the created sf::Sprite. This should be reserved to the Macro Engine core.
       * @return the sprite
       */
      sf::Sprite const			&getSprite() const;

      /**
       * Gets the created position.
       * @return the position
       */
      macroengine::utl::Position const	&getPosition() const;
    };
  }
}

#endif //MACRO_ENGINE_SPRITE_HPP

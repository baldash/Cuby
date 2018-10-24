//
// SpriteWrapper.hpp for macroengine in /home/sylvain/Documents/projets/perso/macroengine
//
// Made by Sylvain Chaugny
// Login   <sylvain.chaugny@epitech.eu>
//
// Started on  Wed Apr 25 14:42:39 2018 Sylvain Chaugny

//

#ifndef					MACROENGINE_SPRITEWRAPPER_HPP_
# define				MACROENGINE_SPRITEWRAPPER_HPP_

# include				<string>
# include				"macroengine-core/graphics/drawable/sprite/Sprite/Sprite.hpp"
# include				"macroengine-core/graphics/drawable/ADrawableHandler/ADrawableHandler.hpp"

namespace				macroengine {
  namespace				graphics {
    /**
     * \class SpriteWrapper
     * \brief This class is used to handle multiple sprites and provides a container to store every known sprite for the created entity.
     */
    class				SpriteWrapper : public ADrawableHandler {
    private:
      t_sprites				_sprites;
      t_identifier 			_current_sprite;

    public:
      SpriteWrapper() = default;
      virtual ~SpriteWrapper() = default;

      /**
       * Adds a sprite from a texture path.
       * @param name the sprite name
       * @param path the texture path
       * @return a reference on the created Sprite
       */
      Sprite				&addFromFile(std::string const &name, std::string const &path);

      /**
       * Adds a Sprite from another Sprite.
       * @param name the sprite name
       * @param sprite the other Sprite
       * @return a reference on the created Sprite
       */
      Sprite				&addFromSprite(std::string const &name, Sprite const &sprite);

      /**
       * Checks whether any sprite is selected or not.
       */
       bool				isAnySpriteSelected();

      /**
       * Removes a Sprite given its identifier (id, name or both).
       * @param identifier the identifier
       */
      void				remove(t_identifier const &identifier);

      /**
       * Gets a Sprite given its identifier (id, name or both).
       * If no matching item is found, this throws a exception::UnknownSpriteIDException or a exceptin::UnknownSpriteNameException depending on the identifier content.
       * @param identifier the identifier
       * @return a reference on the found element.
       */
      Sprite				&get(t_identifier const &identifier);

      /**
       * Gets all the created Sprites.
       * @return the t_sprites map instance
       */
      t_sprites 			&getAll();

      /**
       * Sets the current sprite to be drawn by the Renderer class.
       * @param identifier the sprite id (id, name or both)
       */
      void				setCurrentSprite(t_identifier const &identifier);

      /**
       * Gets the current sprite.
       * @return a reference on the current sprite
       */
      Sprite				&getCurrentSprite();

      /**
       * Clears every create sprite.
       */
      void				clear();

    private:
      Sprite				&get(std::string const &name);
      Sprite				&get(t_entity_id const &id);

      void				remove(std::string const &name);
      void				remove(t_entity_id const &id);

      void				setCurrentSprite(t_entity_id const &id);
      void				setCurrentSprite(std::string const &name);
    };
  }
}

#endif				/* !MACROENGINE_SPRITEWRAPPER_HPP_ */

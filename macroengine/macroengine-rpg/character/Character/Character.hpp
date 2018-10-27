/*
** Character.hpp for Macro_Engine in /home/sylvain/Documents/projets/perso/macroengine/macroengine-rpg/character/Character/Character.hpp
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Tue Jul 31 13:24:12 2018 Sylvain Chaugny
*/

#ifndef MACRO_ENGINE_CHARACTER_HPP
#define MACRO_ENGINE_CHARACTER_HPP

# include				"macroengine-rpg/character/utl/CharacterStatistics/CharacterStatistics.hpp"
# include				"macroengine-core/macroengine-core.hpp"
# include				"macroengine-rpg/utl/rpg_types.hpp"

namespace				macroengine {
  namespace				rpg {
    class				Character : public property::Drawable<property::SPRITE | property::ANIMATION>, public property::Scriptable {
    private:
      CharacterStatistics		_stats;
      utl::Position			_position;
      character::t_stored_entities	_stored_animations;
      character::t_stored_entities	_stored_sprites;

      t_identifier 			_empty_identifier;

    public:
      Character();
      virtual ~Character() = default;

      CharacterStatistics		&getStatistics();
      utl::Position			&getPosition();

      void				moveCharacter(utl::Position const &pos);
      void				moveCharacterX(float x, bool update_drawable_position = true);
      void				moveCharacterY(float y, bool update_drawable_position = true);

      void				moveCharacterUp(float offset = 1);
      void				moveCharacterDown(float offset = 1);
      void				moveCharacterLeft(float offset = 1);
      void				moveCharacterRight(float offset = 1);

      void				disableAnimations();
      void				disableSprites();

      graphics::Animation		&storeAnimation(std::string const &name, std::string const &path);
      void				setAnimation(std::string const &name);

      graphics::Sprite			&storeSprite(std::string const &name, std::string const &path);
      void				setSprite(std::string const &name);

      std::string const			&getCurrentAnimationName();
      std::string const			&getCurrentSpriteName();

    private:
      void				updateDrawablePosition();
    };
  }
}

#endif //MACRO_ENGINE_CHARACTER_HPP

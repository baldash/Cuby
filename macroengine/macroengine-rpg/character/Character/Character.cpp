/*
** Character.cpp for Macro_Engine in /home/sylvain/Documents/projets/perso/macroengine/macroengine-rpg/character/Character/Character.cpp
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Tue Jul 31 13:26:18 2018 Sylvain Chaugny
*/

#include				"Character.hpp"
#include "Character.hpp"


macroengine::rpg::Character::Character() : Drawable(), Scriptable(),
					   _stats(),
					   _position() {
}

macroengine::rpg::CharacterStatistics	&macroengine::rpg::Character::getStatistics() {
  return _stats;
}

macroengine::utl::Position		&macroengine::rpg::Character::getPosition() {
  return _position;
}

void					macroengine::rpg::Character::moveCharacter(const macroengine::utl::Position &pos) {
  moveCharacterX(pos.x, false);
  moveCharacterY(pos.y, false);
  updateDrawablePosition();
}

void					macroengine::rpg::Character::moveCharacterX(float x, bool update_drawable_position) {
  _position.x += x * _stats.getSpeed();
  if (update_drawable_position) {
    updateDrawablePosition();
  }
}

void					macroengine::rpg::Character::moveCharacterY(float y, bool update_drawable_position) {
  _position.y += y * _stats.getSpeed();
  if (update_drawable_position) {
    updateDrawablePosition();
  }
}

void					macroengine::rpg::Character::updateDrawablePosition() {
  if (asDrawable().spriteHandler().enabled()) {
    for (auto &&sprite: asDrawable().spriteHandler().getAll()) {
      sprite.second.setPosition(_position);
    }
  }
  if (asDrawable().animationHandler().enabled()) {
    for (auto &&anim: asDrawable().animationHandler().getAll()) {
      anim.second.setPosition(_position);
    }
  }
}

void					macroengine::rpg::Character::moveCharacterUp(float offset) {
  moveCharacterY(-1 * offset);
}

void					macroengine::rpg::Character::moveCharacterDown(float offset) {
  moveCharacterY(offset);
}

void					macroengine::rpg::Character::moveCharacterLeft(float offset) {
  moveCharacterX(-1 * offset);
}

void					macroengine::rpg::Character::moveCharacterRight(float offset) {
  moveCharacterX(offset);
}

macroengine::graphics::Animation	&macroengine::rpg::Character::storeAnimation(std::string const &name, std::string const &path) {
  _stored_animations[name] = asDrawable().animationHandler().addFromIni(name, path).setPosition(_position).getIdentifier();
  return asDrawable().animationHandler().get(_stored_animations[name]);
}

void					macroengine::rpg::Character::setAnimation(std::string const &name) {
  asDrawable().spriteHandler().disable();
  asDrawable().animationHandler().enable();

  if (_stored_animations.find(name) == _stored_animations.end()) {
    //throw exception (but before, rework the exception system
    throw std::exception();
  }
  asDrawable().animationHandler().setCurrentAnimation(_stored_animations[name]);
  updateDrawablePosition();
}

macroengine::graphics::Sprite		&macroengine::rpg::Character::storeSprite(std::string const &name, std::string const &path) {
  _stored_sprites[name] = asDrawable().spriteHandler().addFromFile(name, path).setPosition(_position).getIdentifier();
  return asDrawable().spriteHandler().get(_stored_sprites[name]);
}

void					macroengine::rpg::Character::setSprite(std::string const &name) {
  asDrawable().spriteHandler().enable();
  asDrawable().animationHandler().disable();

  if (_stored_sprites.find(name) == _stored_sprites.end()) {
    //throw exception (but before, rework the exception system
    throw std::exception();
  }
  asDrawable().spriteHandler().setCurrentSprite(_stored_sprites[name]);
  updateDrawablePosition();
}

std::string const			&macroengine::rpg::Character::getCurrentAnimationName() {
  if (asDrawable().animationHandler().isAnyAnimationSelected()) {
    return asDrawable().animationHandler().getCurrentAnimation().getIdentifier().name;
  }
  return _empty_identifier.name;
}

std::string const			&macroengine::rpg::Character::getCurrentSpriteName() {
  if (asDrawable().spriteHandler().isAnySpriteSelected()) {
    return asDrawable().spriteHandler().getCurrentSprite().getIdentifier().name;
  }
  return _empty_identifier.name;
}

void					macroengine::rpg::Character::disableAnimations() {
  asDrawable().animationHandler().disable();
}

void					macroengine::rpg::Character::disableSprites() {
  asDrawable().spriteHandler().disable();
}

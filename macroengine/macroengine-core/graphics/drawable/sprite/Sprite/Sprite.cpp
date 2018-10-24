/*
** Sprite.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/graphics/Sprite/Sprite.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sat Mar 10 22:39:48 2018 Sylvain CHAUGNY
*/

# include					"macroengine-core/log/log.hpp"
# include					"macroengine-core/utl/strings.hpp"
#include					"Sprite.hpp"

macroengine::graphics::Sprite::Sprite() :
  Object("Sprite"),
  _texture(),
  _sprite(),
  _position(0, 0) {
}

macroengine::graphics::Sprite::~Sprite() {
}

void						macroengine::graphics::Sprite::dump() {
}

macroengine::graphics::Sprite 			&macroengine::graphics::Sprite::loadFromFile(std::string const &file) {
  log(Strings("core_loading_texture", file));
  if (!_texture.loadFromFile(file)) {
    error(Strings("core_texture_not_found", file));
    return *this;
  }
  _sprite.setTexture(_texture);
  log(Strings("core_success"));
  return *this;
}


macroengine::graphics::Sprite			&macroengine::graphics::Sprite::loadFromSprite(graphics::Sprite const &sprite) {
  _texture = sprite.getTexture();
  _sprite = sprite.getSprite();
  return *this;
}

macroengine::graphics::Sprite			&macroengine::graphics::Sprite::setPosition(const macroengine::utl::Position &pos) {
  _position = pos;
  _sprite.setPosition(_position.x, _position.y);
  return *this;
}

sf::Texture const 				&macroengine::graphics::Sprite::getTexture() const {
  return _texture;
}

sf::Sprite const 				&macroengine::graphics::Sprite::getSprite() const {
  return _sprite;
}

const macroengine::utl::Position		&macroengine::graphics::Sprite::getPosition() const {
  return _position;
}

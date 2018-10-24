//
// SpriteWrapper.cpp for macroengine in /home/sylvain/Documents/projets/perso/macroengine
//
// Made by Sylvain Chaugny
// Login   <sylvain.chaugny@epitech.eu>
//
// Started on  Wed Apr 25 14:46:36 2018 Sylvain Chaugny

//

# include					"macroengine-core/utl/strings.hpp"
# include					"macroengine-core/utl/exceptions.hpp"
# include					"macroengine-core/utl/configuration.hpp"
#include					"SpriteWrapper.hpp"
#include "SpriteWrapper.hpp"


macroengine::graphics::Sprite			&macroengine::graphics::SpriteWrapper::addFromFile(std::string const &name, std::string const &path) {
  t_identifier 					identifier;

  identifier.id = EntityIDGenerator.newID();
  identifier.name = name;
  _sprites[identifier].setIdentifier(identifier);
  _sprites[identifier].loadFromFile(path);
  _current_sprite = identifier;
  return _sprites[identifier];
}

macroengine::graphics::Sprite			&macroengine::graphics::SpriteWrapper::addFromSprite(std::string const &name, graphics::Sprite const &sprite) {
  t_identifier 					identifier;

  identifier.id = EntityIDGenerator.newID();
  identifier.name = name;
  _sprites[identifier].setIdentifier(identifier);
  _sprites[identifier].loadFromSprite(sprite);
  return _sprites[identifier];
}

macroengine::graphics::Sprite			&macroengine::graphics::SpriteWrapper::get(const macroengine::t_identifier &identifier) {
  if (identifier.filled()) {
    if (_sprites.find(identifier) != _sprites.end()) {
      return _sprites[identifier];
    }
    throw exception::UnknownSpriteIDException(Strings("core_unknown_sprite_id", identifier.id));
  } else if (identifier.id != -1) {
    return get(identifier.id);
  } else {
    return get(identifier.name);
  }
}

macroengine::graphics::Sprite			&macroengine::graphics::SpriteWrapper::get(std::string const &name) {
  for (auto &&sprite: _sprites) {
    if (sprite.first.name == name) {
      return sprite.second;
    }
  }
  throw exception::UnknownSpriteNameException(Strings("core_unknown_sprite_name", name));
}

macroengine::graphics::Sprite			&macroengine::graphics::SpriteWrapper::get(macroengine::t_entity_id const &id) {
  for (auto &&sprite: _sprites) {
    if (sprite.first.id == id) {
      return sprite.second;
    }
  }
  throw exception::UnknownSpriteIDException(Strings("core_unknown_sprite_id", id));
}

macroengine::graphics::t_sprites		&macroengine::graphics::SpriteWrapper::getAll() {
  return _sprites;
}

void						macroengine::graphics::SpriteWrapper::remove(const std::string &name) {
  for (auto id = _sprites.begin(); id != _sprites.end(); id++) {
    if (id->first.name == name) {
      _sprites.erase(id);
      return;
    }
  }
  throw exception::UnknownSpriteNameException(Strings("core_unknown_sprite_name", name));
}

void						macroengine::graphics::SpriteWrapper::remove(const macroengine::t_entity_id &id) {
  for (auto item = _sprites.begin(); item != _sprites.end(); item++) {
    if (item->first.id == id) {
      _sprites.erase(item);
      return;
    }
  }
  throw exception::UnknownSpriteIDException(Strings("core_unknown_sprite_id", id));
}

void						macroengine::graphics::SpriteWrapper::remove(macroengine::t_identifier const &identifier) {
  if (identifier.id != -1) {
    remove(identifier.id);
  } else {
    remove(identifier.name);
  }
}

void						macroengine::graphics::SpriteWrapper::setCurrentSprite(const macroengine::t_identifier &identifier) {
  if (identifier.filled()) {
    if (_sprites.find(identifier) != _sprites.end()) {
      _current_sprite = identifier;
    } else {
      throw exception::UnknownSpriteIDException(Strings("core_unknown_sprite_id", identifier.id));
    }
  } else if (identifier.id != -1) {
    setCurrentSprite(identifier.id);
  } else {
    setCurrentSprite(identifier.name);
  }
}

void						macroengine::graphics::SpriteWrapper::setCurrentSprite(std::string const &name) {
  for (auto &&sprite: _sprites) {
    if (sprite.first.name == name) {
      _current_sprite = sprite.first;
      return;
    }
  }
  throw exception::UnknownSpriteIDException(Strings("core_unknown_sprite_name", name));
}

void						macroengine::graphics::SpriteWrapper::setCurrentSprite(const macroengine::t_entity_id &id) {
  for (auto &&sprite: _sprites) {
    if (sprite.first.id == id) {
      _current_sprite = sprite.first;
      return;
    }
  }
  throw exception::UnknownSpriteIDException(Strings("core_unknown_sprite_id", id));
}

macroengine::graphics::Sprite			&macroengine::graphics::SpriteWrapper::getCurrentSprite() {
  return _sprites[_current_sprite];
}

void						macroengine::graphics::SpriteWrapper::clear() {
  _sprites.clear();
}

bool						macroengine::graphics::SpriteWrapper::isAnySpriteSelected() {
  return _current_sprite.filled();
}

/*
** AnimationWrapper.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/graphics/AnimationWrapper/AnimationWrapper.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Mar 11 20:18:08 2018 Sylvain CHAUGNY
*/

# include				"macroengine-core/utl/strings.hpp"
# include				"macroengine-core/utl/configuration.hpp"
# include				"macroengine-core/utl/exceptions.hpp"
#include				"AnimationWrapper.hpp"
#include "AnimationWrapper.hpp"


macroengine::graphics::AnimationWrapper::AnimationWrapper() :
  Object("AnimationWrapper"),
  _current_animation() {
}

macroengine::graphics::Animation	&macroengine::graphics::AnimationWrapper::addFromIni(std::string const &name, std::string const &ini) {
  t_identifier 				identifier;

  identifier.id = EntityIDGenerator.newID();
  identifier.name = name;
  _animations[identifier].setClassName(getClassName());
  _animations[identifier].loadFromIni(ini);
  _animations[identifier].setIdentifier(identifier);
  return _animations[identifier];
}

void					macroengine::graphics::AnimationWrapper::dump() {
}

macroengine::graphics::Animation	&macroengine::graphics::AnimationWrapper::getCurrentAnimation() {
  if (_current_animation.empty()) {
    throw exception::NoCurrentAnimationSelectedException(Strings("core_no_current_animation_selected"));
  }
  return get(_current_animation);
}

void					macroengine::graphics::AnimationWrapper::setCurrentAnimation(macroengine::t_entity_id const &id) {
  _current_animation = get(id).getIdentifier();
}

void					macroengine::graphics::AnimationWrapper::setCurrentAnimation(std::string const &name) {
  for (auto &&animation: _animations) {
    if (animation.first.name == name) {
      _current_animation = animation.first;
      return;
    }
  }
  throw exception::UnknownAnimationIDException(Strings("core_unknown_animation_name", name));
}


macroengine::graphics::Animation	&macroengine::graphics::AnimationWrapper::get(macroengine::t_entity_id const &id) {
  for (auto &&anim: _animations) {
    if (anim.first.id == id) {
      return anim.second;
    }
  }
  throw exception::UnknownAnimationIDException(Strings("core_unknown_animation_id", id));
}

macroengine::graphics::Animation	&macroengine::graphics::AnimationWrapper::get(std::string const &name) {
  for (auto &&anim: _animations) {
    if (anim.first.name == name) {
      return anim.second;
    }
  }
  throw exception::UnknownAnimationNameException(Strings("core_unknown_animation_name", name));
}

macroengine::graphics::Animation	&macroengine::graphics::AnimationWrapper::get(const macroengine::t_identifier &identifier) {
  if (identifier.filled()) {
    if (_animations.find(identifier) != _animations.end()) {
      return _animations[identifier];
    }
    throw exception::UnknownAnimationIDException(Strings("core_unknown_animation_id", identifier.id));
  } else if (identifier.id != -1) {
    return get(identifier.id);
  } else {
    return get(identifier.name);
  }
}

void					macroengine::graphics::AnimationWrapper::remove(macroengine::t_entity_id const &id) {
  for (t_animations::iterator i = _animations.begin(); i != _animations.end(); i++) {
    if (i->first.id == id) {
      _animations.erase(i);
      return;
    }
  }
  throw exception::UnknownAnimationNameException(Strings("core_unknown_animation_id", id));
}

void					macroengine::graphics::AnimationWrapper::remove(std::string const &name) {
  for (t_animations::iterator i = _animations.begin(); i != _animations.end(); i++) {
    if (i->first.name == name) {
      _animations.erase(i);
      return;
    }
  }
  throw exception::UnknownAnimationNameException(Strings("core_unknown_animation_name", name));
}

void					macroengine::graphics::AnimationWrapper::remove(const macroengine::t_identifier &identifier) {
  if (identifier.id != -1) {
    remove(identifier.id);
  } else {
    remove(identifier.name);
  }
}

macroengine::graphics::Animation	&macroengine::graphics::AnimationWrapper::setCurrentAnimation(const macroengine::t_identifier &identifier) {
  if (identifier.id != -1) {
    setCurrentAnimation(identifier.id);
  } else {
    setCurrentAnimation(identifier.name);
  }
  return getCurrentAnimation();
}

macroengine::graphics::t_animations	&macroengine::graphics::AnimationWrapper::getAll() {
  return _animations;
}

bool					macroengine::graphics::AnimationWrapper::isAnyAnimationSelected() {
  return _current_animation.filled();
}

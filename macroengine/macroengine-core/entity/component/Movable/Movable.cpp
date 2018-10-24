/*
** Movable.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/entity/component/Movable/Movable.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Wed Feb 14 23:44:49 2018 Sylvain CHAUGNY
*/

# include				"macroengine-core/utl/configuration.hpp"
#include				"Movable.hpp"

macroengine::entity::component::Movable::Movable() :
  _position(0, 0),
  _enabled(true),
  _enabled_for_drawable_subproperty(0) {
}

void					macroengine::entity::component::Movable::setMovementFrequency(const macroengine::clock::Time &t) {
  setConstDelay(CoreClock.newDelay(t));
  useConstDelay(true);
}

void					macroengine::entity::component::Movable::setMovement(const macroengine::utl::VectorF &v) {
  _movement = v;
}

const macroengine::utl::VectorF		&macroengine::entity::component::Movable::getMovement() {
  return _movement;
}

void					macroengine::entity::component::Movable::setRawPosition(macroengine::utl::Position const &pos) {
  _position = pos;
}

void					macroengine::entity::component::Movable::setRawPosition(size_t x, size_t y) {
  _position.x = x;
  _position.y = y;
}

macroengine::utl::Position		&macroengine::entity::component::Movable::getRawPosition() {
  return _position;
}

void					macroengine::entity::component::Movable::enableSelfMovement() {
  _enabled = true;
}

void					macroengine::entity::component::Movable::disableSelfMovement() {
  _enabled = false;
}

bool					macroengine::entity::component::Movable::isSelfMovementEnabled() {
  return _enabled;
}

void					macroengine::entity::component::Movable::allowSelfMovementForDrawableSubProperty(macroengine::property::e_subproperty prop) {
  _enabled_for_drawable_subproperty += prop;
}

bool					macroengine::entity::component::Movable::isAllowedForDrawableSubProperty(macroengine::property::e_subproperty prop) {
  return _enabled_for_drawable_subproperty.contains(prop);
}

void					macroengine::entity::component::Movable::allowSelfMovementForAllDrawableSubProperties() {
  _enabled_for_drawable_subproperty += property::ANIMATION;
  _enabled_for_drawable_subproperty += property::SPRITE;
  _enabled_for_drawable_subproperty += property::TEXT;
}
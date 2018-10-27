/*
** Drawable.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/entity/component/Drawable/Drawable.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Feb 15 00:17:45 2018 Sylvain CHAUGNY
*/

#include					"Drawable.hpp"

macroengine::entity::component::Drawable::Drawable() {
  setClassName("Drawable");
}

macroengine::graphics::AnimationWrapper		&macroengine::entity::component::Drawable::animationHandler() {
  return _animation_wrapper;
}

macroengine::graphics::SpriteWrapper		&macroengine::entity::component::Drawable::spriteHandler() {
  return _sprite_wrapper;
}

macroengine::graphics::TextWrapper		&macroengine::entity::component::Drawable::textHandler() {
  return _text_wrapper;
}

macroengine::graphics::ShapeWrapper		&macroengine::entity::component::Drawable::shapeHandler() {
  return _shape_wrapper;
}

macroengine::graphics::ViewWrapper		&macroengine::entity::component::Drawable::viewHandler() {
  return _view_wrapper;
}
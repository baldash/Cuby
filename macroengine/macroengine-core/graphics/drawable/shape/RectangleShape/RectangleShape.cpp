/*
** RectangleShape.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/graphics/drawable/RectangleShape/RectangleShape.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Mon Mar 19 10:55:36 2018 Sylvain CHAUGNY
*/

#include				"RectangleShape.hpp"

macroengine::graphics::RectangleShape	&macroengine::graphics::RectangleShape::setPosition(const macroengine::utl::Position &position) {
  _position = position;
  _shape.setPosition(_position.toSfVector2f());
  return *this;
}

macroengine::graphics::RectangleShape	&macroengine::graphics::RectangleShape::setPosition(size_t x, size_t y) {
  _position.x = x;
  _position.y = y;
  _shape.setPosition(_position.toSfVector2f());
  return *this;
}

macroengine::graphics::RectangleShape	&macroengine::graphics::RectangleShape::setColor(const macroengine::graphics::Color &color) {
  _color = color;
  _shape.setFillColor(color);
  return *this;
}

macroengine::graphics::RectangleShape	&macroengine::graphics::RectangleShape::setDimensions(const macroengine::utl::Dimensions &dimensions) {
  _dimensions = dimensions;
  _shape.setSize(sf::Vector2f(dimensions.width, dimensions.height));
  return *this;
}

macroengine::graphics::RectangleShape	&macroengine::graphics::RectangleShape::setDimensions(size_t width, size_t height) {
  _dimensions.width = width;
  _dimensions.height = height;
  _shape.setSize(sf::Vector2f(_dimensions.width, _dimensions.height));
  return *this;
}

macroengine::graphics::RectangleShape	&macroengine::graphics::RectangleShape::addOffset(const macroengine::utl::Dimensions &offset) {
  _position.x -= offset.width / 2;
  _position.y -= offset.height / 2;
  _shape.setSize(sf::Vector2f(_dimensions.width + offset.width, _dimensions.height + offset.height));
  _shape.setPosition(_position.x, _position.y);
  _dimensions += offset;
  return *this;
}

macroengine::graphics::RectangleShape	&macroengine::graphics::RectangleShape::addOffset(size_t width, size_t height) {
  _position.x -= width / 2;
  _position.y -= height / 2;
  _shape.setSize(sf::Vector2f(_dimensions.width + width, _dimensions.height + height));
  _shape.setPosition(_position.x, _position.y);
  _dimensions.width += width;
  _dimensions.height += height;
  return *this;
}

macroengine::graphics::RectangleShape	&macroengine::graphics::RectangleShape::createFromText(sf::Text const &text) {
  setDimensions(static_cast<size_t>(text.getLocalBounds().width), static_cast<size_t>(text.getLocalBounds().height));
  setPosition(static_cast<size_t>(text.getPosition().x + text.getLocalBounds().left), static_cast<size_t>(text.getPosition().y + text.getLocalBounds().top));
  return *this;
}

macroengine::graphics::RectangleShape	&macroengine::graphics::RectangleShape::createFromText(const macroengine::graphics::utl::TextEntry &text) {
  setDimensions(static_cast<size_t>(text.text.getLocalBounds().width), static_cast<size_t>(text.text.getLocalBounds().height));
  setPosition(static_cast<size_t>(text.position.x + text.text.getLocalBounds().left), static_cast<size_t>(text.position.y + text.text.getLocalBounds().top));
  return *this;
}

sf::RectangleShape			&macroengine::graphics::RectangleShape::getShape() {
  return _shape;
}

const macroengine::utl::Dimensions	&macroengine::graphics::RectangleShape::getDimensions() const {
  return _dimensions;
}

const macroengine::utl::Position	&macroengine::graphics::RectangleShape::getPosition() const {
  return _position;
}

sf::Color const				&macroengine::graphics::RectangleShape::getColor() const {
  return _color;
}

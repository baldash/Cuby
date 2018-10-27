/*
** View.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/graphics/drawable/view/View/View.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Fri Apr 13 18:56:55 2018 Sylvain CHAUGNY
*/

#include						<SFML/Graphics.hpp>
# include						"macroengine-core/utl/strings.hpp"
# include						"macroengine-core/utl/exceptions.hpp"
# include						"macroengine-core/utl/Dimensions/Dimensions.hpp"
# include						"macroengine-core/entity/property/enum/e_subproperty.hpp"
#include						"View.hpp"

macroengine::graphics::View::View() :
  _ratios{0.0f, 0.0f, 1.0f, 1.0f} {
}

sf::View						&macroengine::graphics::View::getView() {
  return _view;
}

void							macroengine::graphics::View::dump() {
}

int							macroengine::graphics::View::init() {
  _view = sf::View(sf::Vector2f(_dimensions.width / 2, _dimensions.height / 2), sf::Vector2f(_dimensions.width, _dimensions.height));
  _view.setViewport(sf::FloatRect(_ratios[VIEW_RATIOS_X], _ratios[VIEW_RATIOS_Y], _ratios[VIEW_RATIOS_WIDTH], _ratios[VIEW_RATIOS_HEIGHT]));
  return 0;
}

macroengine::graphics::View				&macroengine::graphics::View::setDimensions(const macroengine::utl::Dimensions &dimensions) {
  _dimensions = dimensions;
  return *this;
}

const macroengine::utl::Dimensions			&macroengine::graphics::View::getDimensions() {
  return _dimensions;
}

macroengine::graphics::View				&macroengine::graphics::View::bindElement(const macroengine::t_identifier &elem, property::e_subproperty prop) {
  _bound_elements[elem].emplace_back(prop);
  return *this;
}

macroengine::graphics::t_bound_elements const		&macroengine::graphics::View::getAllBoundElements() {
  return _bound_elements;
}

macroengine::graphics::View				&macroengine::graphics::View::removeBoundElement(macroengine::t_entity_id const &id) {
  for (auto &&elem: _bound_elements) {
    if (elem.first.id == id) {
      _bound_elements.erase(elem.first);
      return *this;
    }
  }
  throw exception::UnknownBoundElementNameException(Strings("core_unknown_bound_element_id", id));
}

macroengine::graphics::View				&macroengine::graphics::View::removeBoundElement(std::string const &name) {
  for (auto &&elem: _bound_elements) {
    if (elem.first.name == name) {
      _bound_elements.erase(elem.first);
      return *this;
    }
  }
  throw exception::UnknownBoundElementNameException(Strings("core_unknown_bound_element_name", name));
}

macroengine::graphics::View				&macroengine::graphics::View::removeBoundElement(macroengine::t_identifier const &identifier) {
  if (identifier.id != -1) {
    removeBoundElement(identifier.id);
  } else {
    removeBoundElement(identifier.name);
  }
  return *this;
}

bool							macroengine::graphics::View::isElementBound(const macroengine::t_identifier &identifier, macroengine::property::e_subproperty prop) {
  for (auto &&p: _bound_elements[identifier]) {
    if (p == prop) {
      return true;
    }
  }
  return false;
}

macroengine::graphics::View				&macroengine::graphics::View::setViewHeightRatio(float ratio) {
  return setViewRatio(ratio, VIEW_RATIOS_HEIGHT);
}

macroengine::graphics::View				&macroengine::graphics::View::setViewWidthRatio(float ratio) {
  return setViewRatio(ratio, VIEW_RATIOS_WIDTH);
}

macroengine::graphics::View				&macroengine::graphics::View::setViewXPositionRatio(float ratio) {
  return setViewRatio(ratio, VIEW_RATIOS_X);
}

macroengine::graphics::View				&macroengine::graphics::View::setViewYPositionRatio(float ratio) {
  return setViewRatio(ratio, VIEW_RATIOS_Y);
}

macroengine::graphics::View				&macroengine::graphics::View::setViewRatio(float ratio, macroengine::graphics::View::ratios id) {
  if (ratio < 0 || ratio > 1) {
    warning(Strings("core_view_ratio_must_be_between_0_and_1", ratio));
  }
  ratio = (ratio < 0) ? 0 : ((ratio > 1) ? 1 : ratio);
  _ratios[id] = ratio;
  _view.setViewport(sf::FloatRect(_ratios[VIEW_RATIOS_X], _ratios[VIEW_RATIOS_Y], _ratios[VIEW_RATIOS_WIDTH], _ratios[VIEW_RATIOS_HEIGHT]));
  return *this;

}

macroengine::graphics::View				&macroengine::graphics::View::move(macroengine::utl::Position const &pos) {
  _view.move(pos.x, pos.y);
  return *this;
}

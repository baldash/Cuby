/*
** ADrawableHandler.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/graphics/drawable/ADrawableHandler/ADrawableHandler.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Fri Mar 16 11:00:17 2018 Sylvain CHAUGNY
*/

#include				"ADrawableHandler.hpp"

macroengine::graphics::ADrawableHandler::ADrawableHandler() :
  _enabled(false) {
}

void					macroengine::graphics::ADrawableHandler::enable() {
  _enabled = true;
}

void					macroengine::graphics::ADrawableHandler::disable() {
  _enabled = false;
}

bool					macroengine::graphics::ADrawableHandler::enabled() {
  return _enabled;
}
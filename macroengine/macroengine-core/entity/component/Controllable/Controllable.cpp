/*
** Controllable.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/entity/component/Controllable/Controllable.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Wed Feb 14 23:44:49 2018 Sylvain CHAUGNY
*/

#include				"Controllable.hpp"
# include				"macroengine-core/utl/configuration.hpp"

macroengine::entity::component::Controllable::Controllable() :
  KeyboardData(EntityIDGenerator),
  MouseMoveData(EntityIDGenerator),
  MouseButtonData(EntityIDGenerator) {
}
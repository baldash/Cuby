/*
** CharacterStatistics.cpp for Macro_Engine in /home/sylvain/Documents/projets/perso/macroengine/macroengine-rpg/character/CharacterStatistics/CharacterStatistics.cpp
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Tue Jul 31 13:31:10 2018 Sylvain Chaugny
*/

#include			"CharacterStatistics.hpp"

macroengine::rpg::CharacterStatistics::CharacterStatistics() :
  _speed(1),
  _health(0),
  _stamina(0),
  _magic(0) {
}

void				macroengine::rpg::CharacterStatistics::setSpeed(size_t val) {
  _speed = val;
}

void				macroengine::rpg::CharacterStatistics::setHealth(size_t val) {
  _health = val;
}

void				macroengine::rpg::CharacterStatistics::setStamina(size_t val) {
  _stamina = val;
}

void				macroengine::rpg::CharacterStatistics::setMagic(size_t val) {
  _magic = val;
}

size_t const			&macroengine::rpg::CharacterStatistics::getSpeed() {
  return _speed;
}

size_t const			&macroengine::rpg::CharacterStatistics::getHealth() {
  return _health;
}

size_t const			&macroengine::rpg::CharacterStatistics::getStamina() {
  return _stamina;
}

size_t const			&macroengine::rpg::CharacterStatistics::getMagic() {
  return _magic;
}
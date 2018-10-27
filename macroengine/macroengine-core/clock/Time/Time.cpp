/*
** Time.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/core/clock/Time/Time.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Feb 25 01:30:00 2018 Sylvain CHAUGNY
*/

#include			"Time.hpp"

macroengine::clock::Time::Time(sf::Time const &t) :
  _time(t) {
}

macroengine::clock::Time::Time(float seconds, int milli, long micro) {
  _time = sf::microseconds(long(1000000 * seconds + 1000 * milli + micro));
}

macroengine::clock::Time	&macroengine::clock::Time::operator=(sf::Time const &t) {
  _time = t;
  return *this;
}

macroengine::clock::Time	&macroengine::clock::Time::operator+=(sf::Time const &t) {
  _time += t;
  return *this;
}

macroengine::clock::Time	&macroengine::clock::Time::operator=(const macroengine::clock::Time &t) {
  operator=(t.getTime());
  return *this;
}

macroengine::clock::Time	&macroengine::clock::Time::operator+=(const macroengine::clock::Time &t) {
  operator+=(t.getTime());
  return *this;
}

float				macroengine::clock::Time::asSeconds() const {
  return _time.asSeconds();
}

int				macroengine::clock::Time::asMilliseconds() const {
  return _time.asMilliseconds();
}

long				macroengine::clock::Time::asMicroseconds() const {
  return _time.asMicroseconds();
}

sf::Time const			&macroengine::clock::Time::getTime() const {
  return _time;
}

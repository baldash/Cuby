/*
** Clock.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/core/clock/Clock/Clock.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Feb 25 01:32:04 2018 Sylvain CHAUGNY
*/

# include				"macroengine-core/utl/strings.hpp"
# include				"macroengine-core/utl/exceptions.hpp"
#include				"Clock.hpp"

macroengine::clock::Clock::Clock() :
_core_offset(_global_offset),
_global_offset(Time()) {
}

void					macroengine::clock::Clock::setCoreFrequency(float seconds, int milliseconds, long microseconds) {
  _core_frequency = Time(seconds, milliseconds, microseconds);
  _core_offset = _global_offset;
}

const macroengine::clock::Time		&macroengine::clock::Clock::getOffset(macroengine::clock::t_delay_id id) {
  return _offsets[id].first;
}

const macroengine::clock::Time 		&macroengine::clock::Clock::getDelay(macroengine::clock::t_delay_id id) {
  return _offsets[id].second;
}

void					macroengine::clock::Clock::deleteDelay(macroengine::clock::t_delay_id id) {
  _offsets.erase(id);
}

bool					macroengine::clock::Clock::isDelayOver(macroengine::clock::t_delay_id id) {
  checkId(id);

  Time const				&delay = getDelay(id);
  Time const				&offset = getOffset(id);

  if (id == -1 && _core_frequency.asMicroseconds() + _core_offset.asMicroseconds() <= _global_offset.asMicroseconds()) {
    _core_offset += _core_frequency;
    return true;
  } else if (id != -1 && offset.asMicroseconds() + delay.asMicroseconds() <= _global_offset.asMicroseconds() && _global_offset.asMicroseconds() != 0) {
    if (_offsets[id].first.asMicroseconds() + delay.asMicroseconds() <= _global_offset.asMicroseconds()) {
      _offsets[id].first = _global_offset;
    } else {
      _offsets[id].first += delay;
    }
    return true;
  } else {
    return false;
  }
}

void					macroengine::clock::Clock::update() {
  _global_offset += _clock.restart();
}

macroengine::clock::t_delay_id		macroengine::clock::Clock::newDelay(float seconds, int milliseconds, long microseconds) {
  static int				id = -1;

  id++;
  _offsets[id].second = Time(seconds, milliseconds, microseconds);
  _offsets[id].first = _global_offset;
  return id;
}

macroengine::clock::t_delay_id		macroengine::clock::Clock::newDelay(const macroengine::clock::Time &t) {
  return newDelay(0, 0, t.asMicroseconds());
}

const macroengine::clock::Time		&macroengine::clock::Clock::getGlobalElapsedTime() {
  return _global_offset;
}

void					macroengine::clock::Clock::checkId(macroengine::clock::t_delay_id id) {
  if (id != -1 && _offsets.find(id) == _offsets.end()) {
    throw exception::UnknownClockDelayIDException(Strings("core_exception_unknown_clock_delay_id", id));
  }
}

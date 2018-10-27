/*
** BitMask.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/utl/BitMask/BitMask.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Wed Jan 24 21:14:16 2018 Sylvain CHAUGNY
*/

#include		<climits>
# include		"macroengine-core/log/log.hpp"
# include		"macroengine-core/utl/BitMask/BitMask.hpp"

macroengine::utl::BitMask::BitMask() :
  Object("BitMask"),
  _mask(0) {
}

macroengine::utl::BitMask::BitMask(const size_t &mask) :
  Object("BitMask"),
  _mask(mask) {
}

macroengine::utl::BitMask::BitMask(const macroengine::utl::BitMask &obj) :
  Object("BitMask"),
  _mask(obj._mask) {
}

macroengine::utl::BitMask &macroengine::utl::BitMask::operator=(const macroengine::utl::BitMask &obj) {
  _mask = obj._mask;
  return *this;
}

void			macroengine::utl::BitMask::add(size_t nb) {
  if (!contains(nb)) {
    _mask += nb;
  }
}

bool			macroengine::utl::BitMask::contains(size_t nb) const {
  return (_mask & nb) == nb;
}

void			macroengine::utl::BitMask::dump() {
  long			shift = INT_MAX;
  std::string		buf;

  shift += 1;
  for (int i = 0; i < 32; i++, shift /= 2) {
    buf.push_back(static_cast<char>(((_mask & shift) ? 1 : 0) + '0'));
  }
  Dump::display("==== BitMask ====");
  Dump::display("_mask : " + buf);
  Dump::display("=================");
}

void			macroengine::utl::BitMask::operator+=(size_t nb) {
  add(nb);
}

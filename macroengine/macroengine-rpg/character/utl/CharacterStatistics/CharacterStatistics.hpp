/*
** CharacterStatistics.hpp for Macro_Engine in /home/sylvain/Documents/projets/perso/macroengine/macroengine-rpg/character/struct/CharacterStatistics/CharacterStatistics.hpp
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Tue Jul 31 13:28:20 2018 Sylvain Chaugny
*/

#ifndef MACRO_ENGINE_CHARACTERPARAMS_HPP
#define MACRO_ENGINE_CHARACTERPARAMS_HPP

# include			<cstddef>

namespace			macroengine {
  namespace			rpg {
    class			CharacterStatistics {
    private:
      size_t			_speed;

      size_t			_health;
      size_t			_stamina;
      size_t			_magic;

    public:
      CharacterStatistics();
      virtual ~CharacterStatistics() = default;

      void			setSpeed(size_t val);
      void			setHealth(size_t val);
      void			setStamina(size_t val);
      void			setMagic(size_t val);

      size_t const		&getSpeed();
      size_t const		&getHealth();
      size_t const		&getStamina();
      size_t const		&getMagic();
    };
  }
}

#endif //MACRO_ENGINE_CHARACTERPARAMS_HPP

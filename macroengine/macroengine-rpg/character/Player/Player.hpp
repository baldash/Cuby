/*
** Player.hpp for Macro_Engine in /home/sylvain/Documents/projets/perso/macroengine/macroengine-rpg/character/Player/Player.hpp
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Tue Jul 31 13:21:55 2018 Sylvain Chaugny
*/

#ifndef MACRO_ENGINE_PLAYER_HPP
#define MACRO_ENGINE_PLAYER_HPP

# include			"macroengine-core/macroengine-core.hpp"
# include			"macroengine-rpg/character/Character/Character.hpp"
# include			"macroengine-rpg/character/utl/PlayerParameters/PlayerParameters.hpp"

namespace			macroengine {
  namespace			rpg {
    class			Player : virtual public Character, virtual public property::Controllable {
    private:
      PlayerParameters		_params;

    public:
      Player();
      virtual ~Player() = default;

      virtual CallableFunction(moveUp) = 0;
      virtual CallableFunction(moveDown) = 0;
      virtual CallableFunction(moveLeft) = 0;
      virtual CallableFunction(moveRight) = 0;

      void			changeMoveKey(e_player_key const &key, input::Keyboard const &value);

      t_identifier const	&getKeyActionIdentifier(e_player_key const &key);
    };
  }
}

#endif //MACRO_ENGINE_PLAYER_HPP

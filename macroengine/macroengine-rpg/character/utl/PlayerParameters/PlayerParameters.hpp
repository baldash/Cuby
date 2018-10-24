/*
** PlayerParameters.hpp for Macro_Engine in /home/sylvain/Documents/projets/perso/macroengine/macroengine-rpg/character/utl/PlayerParameters/PlayerParameters.hpp
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Tue Jul 31 13:42:30 2018 Sylvain Chaugny
*/

#ifndef MACRO_ENGINE_PLAYERPARAMETERS_HPP
#define MACRO_ENGINE_PLAYERPARAMETERS_HPP

# include				<macroengine-core/macroengine-core.hpp>
# include				"macroengine-rpg/character/utl/enum/e_player_keys.hpp"

namespace				macroengine {
  namespace 				rpg {
    class				PlayerParameters {
    private:
      input::Keyboard			_keys[e_player_key::KEYS];
      std::string			_key_action_names[e_player_key::KEYS];
      t_identifier			_keys_action_identifiers[e_player_key::KEYS];

    public:
      PlayerParameters();
      virtual ~PlayerParameters() = default;

      input::Keyboard const		&getKey(e_player_key const &key);
      int				setKey(e_player_key const &key, input::Keyboard const &value);

      std::string const			&getKeyActionName(e_player_key const &key) const;

      void				setKeyActionIdentifier(e_player_key const &key, t_identifier const &id);
      t_identifier const		&getKeyActionIdentifier(e_player_key const &key);
    };
  }
}

#endif //MACRO_ENGINE_PLAYERPARAMETERS_HPP

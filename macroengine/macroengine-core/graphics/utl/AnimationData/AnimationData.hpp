/*
** AnimationData.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/graphics/utl/AnimationData/AnimationData.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Mar 01 17:25:56 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_ANIMATIONDATA_HPP
#define MACRO_ENGINE_ANIMATIONDATA_HPP

# include				<string>
# include				<SFML/Graphics.hpp>
# include				<vector>
# include 				<cstddef>
# include				"macroengine-core/utl/Position/Position.hpp"
# include				"macroengine-core/utl/Dimensions/Dimensions.hpp"
# include				"macroengine-core/clock/Clock/Clock.hpp"

namespace 				macroengine {
  namespace 				graphics {
    namespace 				utl {

      /**
       * \struct AnimationData
       * \brief Provides every data concerning created animations. These fields can be modified by the user.
       */
      struct				AnimationData {
	std::string			path = "";
	std::size_t			frames = 0;
	macroengine::utl::Dimensions	frame_dimensions;
	bool				looped = false;
	clock::Time			duration = 0;
	clock::Time			frame_duration = 0;

	sf::Texture			texture;
	std::vector<sf::Sprite>		sprites;

	std::size_t			index = 0;

	clock::t_delay_id 		delay_id;

	macroengine::utl::Position	position;
      };
    }
  }
}

#endif //MACRO_ENGINE_ANIMATIONDATA_HPP

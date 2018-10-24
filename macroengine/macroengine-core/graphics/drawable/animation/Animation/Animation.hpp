/*
** Animation.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/graphics/Animation/Animation.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Mar 01 16:50:00 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_ANIMATION_HPP
#define MACRO_ENGINE_ANIMATION_HPP

# include				<string>
# include				"macroengine-core/graphics/utl/AnimationData/AnimationData.hpp"
# include				"macroengine-core/parser/ini/IniParser/IniParser.hpp"
# include				"macroengine-core/Object/Object.hpp"

namespace 				macroengine {
  namespace 				graphics {
    /**
     * \class Animation
     * \brief The animation wrapper, providing every necessary method to play, update or load animations from configuration files.
     * See the examples on how to use this class.
     */
    class				Animation : public Object {
    private:
      file::File			_data_file;
      graphics::utl::AnimationData	_animation_data;
      bool				_paused;
      bool				_started;

    public:
      Animation();
      virtual ~Animation() = default;

      virtual void			dump() override;

      /**
       * Loads an animation from a configuration file.
       * @param ini_file the .ini configuration file path
       * @return a reference on the created animation
       */
      Animation				&loadFromIni(std::string const &ini_file);

      /**
       * Gets the animation data.
       * @return the animation data
       */
      graphics::utl::AnimationData	&getData();

      /**
       * Starts the animation.
       * @return a reference on itself
       */
      Animation				&start();

      /**
       * Stops the animation.
       * @return a reference on itself
       */
      Animation				&stop();

      /**
       * Pauses the animation.
       * @return a reference on itself
       */
      Animation				&pause();

      /**
       * Resumes the animation.
       * @return a reference on itself
       */
      Animation				&resume();

      /**
       * Updates the animation state, independently from the clock system. A call to update() forces the animation to pass to the next frame.
       * @return a reference on itself
       */
      Animation				&update();

      /**
       * Updates the animation considering its delay to pass to the next frame.
       * @return a reference on itself
       */
      Animation				&updateWithClock();

      /**
       * Sets whether the animation must loop or not.
       * \param loop true if the user wants the animation to loop, false otherwise
       * @return a reference on itself
       */
      Animation				&setLoop(bool loop);

      /**
       * Checks whether the animation is started or not.
       * @return true if it is started, false otherwise
       */
      bool				isStarted();

      /**
       * Checks whether the animation is paused or not.
       * @return true if it is paused, false otherwise
       */
      bool				isPaused();

      /**
       * Gets the current frame. This method should be reserved to the Macro Engine part, the user should not use this.
       * @return a sf::Sprite
       */
      sf::Sprite const			&getCurrentFrame();

      /**
       * Gets the delay ID.
       * @return the delay id
       */
      int				getDelayID();

      /**
       * Gets the animation position.
       * @return the position
       */
      macroengine::utl::Position	&getPosition();

      /**
       * Sets the animation position.
       * @param pos the position
       * @return a reference on itself
       */
      Animation				&setPosition(macroengine::utl::Position const &pos);

      /**
       * Moves the animation to the given position.
       * @param pos the new position
       * @return a reference on itself
       */
      Animation				&move(macroengine::utl::Position const &pos);

      /**
       * Moves the animation to the given position.
       * @param x the new x position
       * @param y the new y position
       * @return a reference on itself
       */
      Animation				&move(int x, int y);

    private:
      int				loadData(parser::ini::IniParser &parser);
      clock::Time			getDuration(std::string const &format);
      int				loadSpriteSheet();
    };
  }
}

#endif //MACRO_ENGINE_ANIMATION_HPP

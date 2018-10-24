/*
** Clock.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/core/Clock/Clock.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Feb 25 01:25:23 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_CLOCK_HPP
#define MACRO_ENGINE_CLOCK_HPP

# include			<map>
# include			<SFML/System.hpp>
# include			"macroengine-core/utl/types.hpp"
# include			"macroengine-core/clock/Time/Time.hpp"

namespace 			macroengine {
  namespace 			clock {

    /**
     * \class Clock
     * \brief Handles clock refresh for every Macro Engine object.
     * This wraps sf::Clock features, adding some methods for the project.
     */
    class			Clock {

    private:
      sf::Clock			_clock;
      Time			_core_frequency;
      Time			_core_offset;
      Time			_global_offset;
      t_offsets			_offsets;

    public:
      Clock();
      virtual ~Clock() = default;

      /**
       * sets core frequency, for core framerate and update rate (default:MACROENGINE_VAR_DEFAULT_CORE_FREQUENCY).
       * Adds its parameters to get the full asked frequency.
       * @param seconds the number of seconds for each core tick
       * @param milliseconds the number of milliseconds for each core tick
       * @param microseconds the number of microseconds for each core tick
       */
      void			setCoreFrequency(float seconds = 1, int milliseconds = 0, long microseconds = 0);

      /**
       * adds new delay to the Core class. This will store the newly created delay into the offsets array.
       * @param seconds the number of seconds for each delay tick
       * @param milliseconds the number of milliseconds for each delay tick
       * @param microseconds the number of microseconds for each delay tick
       * @return a t_delay_id for the newly created delay
       */
      t_delay_id 		newDelay(float seconds = 1, int milliseconds = 0, long microseconds = 0);

      /**
       * adds new delay to the Core class. This will store the newly created delay into  the offsets array.
       * @param t reference on the Time class representing each delay tick
       * @return a t_delay_id for the newly created delay
       */
      t_delay_id 		newDelay(Time const &t);

      /**
       * gets the global elapsed time since the program start
       * @return a Time class containing the elapsed time
       */
      clock::Time const		&getGlobalElapsedTime();

      /**
       * checks whether the delay pointed by id is over or not. If it is over, the delay is updated and waiting for the next tick.
       * @param id the id of the tested delay
       * @return true if the delay is over, false otherwise
       */
      bool			isDelayOver(t_delay_id id = -1);

      /**
       * updates the core frequency (this will be useful to check the created delays).
       * @sa isDelayOver()
       */
      void			update();

      /**
       * deletes the delay pointed by id.
       * @param id the id of the delay
       */
      void			deleteDelay(t_delay_id id);

    private:
      void			checkId(t_delay_id id);
      clock::Time const		&getDelay(t_delay_id id);
      clock::Time const		&getOffset(t_delay_id id);
    };
  }
}

#endif //MACRO_ENGINE_CLOCK_HPP

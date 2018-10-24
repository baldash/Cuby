/*
** Time.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/core/clock/Time/Time.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Feb 25 01:27:15 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_TIME_HPP
#define MACRO_ENGINE_TIME_HPP

# include			<SFML/System/Time.hpp>

namespace 			macroengine {
  namespace 			clock {

    /**
     * \class Time
     * \brief Basically a container for each time definition in the Macro Engine.
     * Handles second, millisecond and microsecond.
     * Converts all its data to microseconds before every operation.
     */
    class			Time {
    private:
      sf::Time			_time;

    public:
      /**
       * copy constructor
       */
      Time(sf::Time const &t);

      /**
       * default constructor, taking every time section as parameter.
       * @param seconds number of seconds
       * @param milli  number of milliseconds
       * @param micro  number of microseconds
       */
      Time(float seconds = 0, int milli = 0, long micro = 0);
      virtual ~Time() = default;

      /**
       * sets the time of the parameter to itself.
       * @param t a sf::Time instance
       * @return a reference on itself
       */
      Time			&operator=(sf::Time const &t);

      /**
       * sets the time of the parameter to itself.
       * @param t another Time instance
       * @return a reference on itself
       */
      Time			&operator=(Time const &t);

      /**
       * adds the time of the parameter to itself.
       * @param t a sf::Time instance
       * @return a reference on itself
       */
      Time			&operator+=(sf::Time const &t);

      /**
       * adds the time of the parameter to itself.
       * @param t another Time instance
       * @return a reference on itself
       */
      Time			&operator+=(Time const &t);

      /**
       * returns its content converted as seconds.
       * @return the contained time as seconds
       */
      float			asSeconds() const;

      /**
       * returns its content converted as microseconds.
       * @return the contained time as microseconds
       */
      long			asMicroseconds() const;

      /**
       * returns its content converted as milliseconds.
       * @return the contained time as milliseconds
       */
      int			asMilliseconds() const;

    private:
      sf::Time const		&getTime() const;
    };
  }
}

#endif //MACRO_ENGINE_TIME_HPP

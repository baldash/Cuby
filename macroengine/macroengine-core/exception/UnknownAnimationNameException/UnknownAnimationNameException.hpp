/*
** UnknownAnimationName.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/exception/UnknownAnimationName/UnknownAnimationName.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Feb 25 02:19:18 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_UNKNOWNANIMATIONNAMEEXCEPTION_HPP
#define MACRO_ENGINE_UNKNOWNANIMATIONNAMEEXCEPTION_HPP

# include				<exception>
# include				<string>

namespace 				macroengine {
  namespace 				exception {
    /**
     * \class UnknownAnimationNameException
     * \brief Exception thrown when the handler don't known the given name
     */
    class				UnknownAnimationNameException : public std::exception {
    private:
      std::string			_what;

    public:
      explicit UnknownAnimationNameException(std::string const &str) noexcept;
      virtual ~UnknownAnimationNameException() = default;

      const char		*what() const throw();
    };
  }
}

#endif //MACRO_ENGINE_UNKNOWNANIMATIONNAMEEXCEPTION_HPP

/*
** BadFormattedStringException.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/exception/BadFormattedStringException/BadFormattedStringException.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Feb 25 22:45:56 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_BADFORMATTEDSTRINGEXCEPTION_HPP
#define MACRO_ENGINE_BADFORMATTEDSTRINGEXCEPTION_HPP

# include				<exception>
# include				<string>

namespace 				macroengine {
  namespace 				exception {
    /**
     * \class BadFormattedStringException
     * \brief Exception thrown when the StringBuilder can't build a string.
     */
    class				BadFormattedStringException : public std::exception {
    private:
      std::string			_what;

    public:
      explicit BadFormattedStringException(std::string const &str) noexcept;
      virtual ~BadFormattedStringException() = default;

      const char		*what() const throw();
    };
  }
}

#endif //MACRO_ENGINE_BADFORMATTEDSTRINGEXCEPTION_HPP

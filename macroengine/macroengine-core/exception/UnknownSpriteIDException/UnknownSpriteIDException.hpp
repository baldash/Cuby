/*
** UnknownSpriteID.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/exception/UnknownSpriteID/UnknownSpriteID.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Feb 25 02:19:18 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_UNKNOWNSPRITEIDEXCEPTION_HPP
#define MACRO_ENGINE_UNKNOWNSPRITEIDEXCEPTION_HPP

# include				<exception>
# include				<string>

namespace 				macroengine {
  namespace 				exception {
    /**
     * \class UnknownSpriteIDException
     * \brief Exception thrown when the handler don't known the given ID
     */
    class				UnknownSpriteIDException : public std::exception {
    private:
      std::string			_what;

    public:
      explicit UnknownSpriteIDException(std::string const &str) noexcept;
      virtual ~UnknownSpriteIDException() = default;

      const char		*what() const throw();
    };
  }
}

#endif //MACRO_ENGINE_UNKNOWNSPRITEIDEXCEPTION_HPP

/*
** UnknownBoundElementName.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/exception/UnknownBoundElementName/UnknownBoundElementName.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Feb 25 02:19:18 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_UNKNOWNBOUNDELEMENTNAMEEXCEPTION_HPP
#define MACRO_ENGINE_UNKNOWNBOUNDELEMENTNAMEEXCEPTION_HPP

# include				<exception>
# include				<string>

namespace 				macroengine {
  namespace 				exception {
    /**
     * \class UnknownBoundElementNameException
     * \brief Exception thrown when the handler don't known the given name
     */
    class 				UnknownBoundElementNameException : public std::exception {
    private:
      std::string			_what;

    public:
      explicit UnknownBoundElementNameException(std::string const &str) noexcept;
      virtual ~UnknownBoundElementNameException() = default;

      const char		*what() const throw();
    };
  }
}

#endif //MACRO_ENGINE_UNKNOWNBOUNDELEMENTNAMEEXCEPTION_HPP

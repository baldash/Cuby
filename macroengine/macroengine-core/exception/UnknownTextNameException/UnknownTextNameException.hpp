/*
** UnknownTextName.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/exception/UnknownTextName/UnknownTextName.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Feb 25 02:19:18 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_UNKNOWNTEXTNAMEEXCEPTION_HPP
#define MACRO_ENGINE_UNKNOWNTEXTNAMEEXCEPTION_HPP

# include				<exception>
# include				<string>

namespace 				macroengine {
  namespace 				exception {
    /**
     * \class UnknownTextNameException
     * \brief Exception thrown when the handler don't known the given name
     */
    class				UnknownTextNameException : public std::exception {
    private:
      std::string			_what;

    public:
      explicit UnknownTextNameException(std::string const &str) noexcept;
      virtual ~UnknownTextNameException() = default;

      const char		*what() const throw();
    };
  }
}

#endif //MACRO_ENGINE_UNKNOWNTEXTNAMEEXCEPTION_HPP

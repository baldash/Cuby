/*
** UnknownEntityID.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/exception/UnknownEntityID/UnknownEntityID.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Feb 25 02:19:18 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_UNKNOWNENTITYIDEXCEPTION_HPP
#define MACRO_ENGINE_UNKNOWNENTITYIDEXCEPTION_HPP

# include				<exception>
# include				<string>

namespace 				macroengine {
  namespace 				exception {
    /**
     * \class UnknownEntityIDException
     * \brief Exception thrown when the handler don't known the given ID
     */
    class				UnknownEntityIDException : public std::exception {
    private:
      std::string			_what;

    public:
      explicit UnknownEntityIDException(std::string const &str) noexcept;
      virtual ~UnknownEntityIDException() = default;

      const char		*what() const throw();
    };
  }
}

#endif //MACRO_ENGINE_UNKNOWNENTITYIDEXCEPTION_HPP

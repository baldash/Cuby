/*
** UnknownEntityName.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/exception/UnknownEntityName/UnknownEntityName.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Feb 25 02:19:18 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_UNKNOWNENTITYNAMEEXCEPTION_HPP
#define MACRO_ENGINE_UNKNOWNENTITYNAMEEXCEPTION_HPP

# include				<exception>
# include				<string>

namespace 				macroengine {
  namespace 				exception {
    /**
     * \class UnknownEntityNameException
     * \brief Exception thrown when the handler don't known the given name
     */
    class				UnknownEntityNameException : public std::exception {
    private:
      std::string			_what;

    public:
      explicit UnknownEntityNameException(std::string const &str) noexcept;
      virtual ~UnknownEntityNameException() = default;

      const char		*what() const throw();
    };
  }
}

#endif //MACRO_ENGINE_UNKNOWNENTITYNAMEEXCEPTION_HPP

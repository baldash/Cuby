/*
** UnknownShapeID.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/exception/UnknownShapeID/UnknownShapeID.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Feb 25 02:19:18 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_UNKNOWNSHAPEIDEXCEPTION_HPP
#define MACRO_ENGINE_UNKNOWNSHAPEIDEXCEPTION_HPP

# include				<exception>
# include				<string>

namespace 				macroengine {
  namespace 				exception {
    /**
     * \class UnknownShapeIDException
     * \brief Exception thrown when the handler don't known the given ID
     */
    class				UnknownShapeIDException : public std::exception {
    private:
      std::string			_what;

    public:
      explicit UnknownShapeIDException(std::string const &str) noexcept;
      virtual ~UnknownShapeIDException() = default;

      const char		*what() const throw();
    };
  }
}

#endif //MACRO_ENGINE_UNKNOWNSHAPEIDEXCEPTION_HPP

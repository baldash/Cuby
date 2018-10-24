/*
** UnknownShapeName.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/exception/UnknownShapeName/UnknownShapeName.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Feb 25 02:19:18 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_UNKNOWNSHAPENAMEEXCEPTION_HPP
#define MACRO_ENGINE_UNKNOWNSHAPENAMEEXCEPTION_HPP

# include				<exception>
# include				<string>

namespace 				macroengine {
  namespace 				exception {
    /**
     * \class UnknownShapeNameException
     * \brief Exception thrown when the handler don't known the given name
     */
    class				UnknownShapeNameException : public std::exception {
    private:
      std::string			_what;

    public:
      explicit UnknownShapeNameException(std::string const &str) noexcept;
      virtual ~UnknownShapeNameException() = default;

      const char		*what() const throw();
    };
  }
}

#endif //MACRO_ENGINE_UNKNOWNSHAPENAMEEXCEPTION_HPP

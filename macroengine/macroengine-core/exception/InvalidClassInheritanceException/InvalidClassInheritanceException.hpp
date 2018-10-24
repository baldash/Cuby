/*
** InvalidClassInheritanceException.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/exception/InvalidClassInheritanceException/InvalidClassInheritanceException.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Feb 25 22:45:56 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_INVALIDINHERITANCEEXCEPTION_HPP
#define MACRO_ENGINE_INVALIDINHERITANCEEXCEPTION_HPP

# include				<exception>
# include				<string>

namespace 				macroengine {
  namespace 				exception {
    /**
     * \class InvalidClassInheritanceException
     * \brief Exception thrown when the GeneralController retrieves a created entity (with a Factory) which ID already belongs to a known entity.
     */
    class				InvalidClassInheritanceException : public std::exception {
    private:
      std::string			_what;

    public:
      explicit InvalidClassInheritanceException(std::string const &str) noexcept;
      virtual ~InvalidClassInheritanceException() = default;

      const char		*what() const throw();
    };
  }
}

#endif //MACRO_ENGINE_INVALIDINHERITANCEEXCEPTION_HPP

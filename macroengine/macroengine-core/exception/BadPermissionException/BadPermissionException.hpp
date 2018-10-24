/*
** BadPermissionException.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/exception/BadPermissionException/BadPermissionException.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Feb 15 17:14:59 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_BADPERMISSIONEXCEPTION_HPP
#define MACRO_ENGINE_BADPERMISSIONEXCEPTION_HPP

# include				<exception>
# include				<string>

namespace 				macroengine {
  namespace 				exception {
    /**
     * \class BadPermissionException
     * \brief Exception thrown when the user hasn't the right to access to a method of Entity because of bad given permissions.
     */
    class				BadPermissionException : public std::exception {
    private:
      std::string			_what;

    public:
      explicit BadPermissionException(std::string const &str) noexcept;
      virtual ~BadPermissionException() = default;

      const char		*what() const throw();
    };
  }
}

#endif //MACRO_ENGINE_BADPERMISSIONEXCEPTION_HPP

/*
** UnknownTextID.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/exception/UnknownTextID/UnknownTextID.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Feb 25 02:19:18 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_UNKNOWNTEXTIDEXCEPTION_HPP
#define MACRO_ENGINE_UNKNOWNTEXTIDEXCEPTION_HPP

# include				<exception>
# include				<string>

namespace 				macroengine {
  namespace 				exception {
    /**
     * \class UnknownTextIDException
     * \brief Exception thrown when the handler don't known the given ID
     */
    class				UnknownTextIDException : public std::exception {
    private:
      std::string			_what;

    public:
      explicit UnknownTextIDException(std::string const &str) noexcept;
      virtual ~UnknownTextIDException() = default;

      const char		*what() const throw();
    };
  }
}

#endif //MACRO_ENGINE_UNKNOWNTEXTIDEXCEPTION_HPP

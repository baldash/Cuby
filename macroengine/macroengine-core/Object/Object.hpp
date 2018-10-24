/*
** Object.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/object/Object.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Fri Jan 26 15:43:24 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_OBJECT_HPP_
# define MACRO_ENGINE_OBJECT_HPP_

# include		<string>
# include		"macroengine-core/utl/exceptions.hpp"
# include		"macroengine-core/utl/types.hpp"

namespace		macroengine {
  /**
   * \class Object
   * \brief This class is the base of almost every Macro Engine class.
   * It is used to provide some of the basic features of the project, such as the identifier or the class name.
   * This also provides a virtual method dump(), which can be called at every point of the code to dump the content of a Macro Engine class.
   */
  class			Object {
  private:
    std::string		_class_name;
    t_identifier 	_identifier;

  public:
    Object();
    Object(std::string const &str);
    virtual ~Object() = default;

    virtual void	dump() = 0;

    /**
     * Sets the class name.
     */
    void		setClassName(std::string const &str);

    /**
     * Gets the class name.
     * @return a const reference to the class name
     */
    std::string const	&getClassName();

    /**
     * Sets the class ID.
     */
    void		setID(t_entity_id const &id);

    /**
     * Gets the class identifier ID.
     * @return a const reference on the class identifier ID
     */
    t_entity_id const	&getID();

    /**
     * Sets the class identifier name.
     */
    void		setName(std::string const &name);

    /**
     * Gets the class identifier name.
     * @return a const reference on the class identifier name
     */
    std::string const	&getName();

    /**
     * Sets the class identifier. If the class name is empty, it takes the identifier name value.
     */
    void		setIdentifier(t_identifier const &identifier);

    /**
     * Gets the class identifier.
     * @return a const reference to the class identifier
     */
    t_identifier const	&getIdentifier() const;

    template<typename	Class>
    Class		&as(entity::Entity *ptr) {
      if (dynamic_cast<Class *>(ptr) == nullptr) {
	throw exception::InvalidClassInheritanceException("");
      }
      return *dynamic_cast<Class *>(ptr);
    }

    /**
     * Redirection to macroengine::log::Error::display(), creating a string with indentation if necessary.
     * @param str the string to display
     */
    void		error(std::string const &str, size_t indentation = 0);

    /**
     * Redirection to macroengine::log::Warning::display(), creating a string with indentation if necessary.
     * @param str the string to display
     */
    void		warning(std::string const &str, size_t indentation = 0);

    /**
     * Redirection to macroengine::log::Log::display(), creating a string with indentation if necessary.
     * @param str the string to display
     */
    void		log(std::string const &str, size_t indentation = 0);
  };
}

#endif /* !MACRO_ENGINE_OBJECT_HPP_ */

/*
** Entity.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/entity/Entity/Entity.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Wed Feb 14 23:08:29 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_ENTITY_HPP
#define MACRO_ENGINE_ENTITY_HPP

# include				"macroengine-core/entity/component/Scriptable/Scriptable.hpp"
# include				"macroengine-core/entity/component/Factory/Factory.hpp"
# include				"macroengine-core/entity/component/Movable/Movable.hpp"
# include				"macroengine-core/entity/component/Controllable/Controllable.hpp"
# include				"macroengine-core/entity/component/Collidable/Collidable.hpp"
# include				"macroengine-core/entity/component/Drawable/Drawable.hpp"
# include				"macroengine-core/entity/AEntity/AEntity.hpp"
# include				"macroengine-core/utl/BitMask/BitMask.hpp"
# include				"macroengine-core/Object/Object.hpp"

namespace				macroengine {
  namespace				entity {

    /**
     * \class Entity
     * \brief The main class of the Macro Engine.
     * The class is used to create entities and to access every component available in the project.
     * This class inherits from every macroengine::component class, and provides getters to access their methods.
     * This class also provides overrides of the log methods (log, warning, error) to prevent the user from using Log::display / Error::display [...] methods.
     * This class should not be used by the user (see example on how to create entities).
     */
    class				Entity : virtual protected AEntity,
						  private component::Collidable,
						  private component::Drawable,
						  private component::Movable,
						  private component::Controllable,
						  private component::Factory,
						  private component::Scriptable {
    private:
      bool				_remove;

    public:
      Entity();
      virtual ~Entity() = default;

      virtual void			dump() override;

      /**
       * Sets the class name.
       * @param name the class name
       */
      void				setClassName(std::string const &name);

      /**
       * Gets the class name.
       * @return the class name
       */
      std::string const			&getClassName();

      /**
       * Gets the entity permissions, given by the user at class definition time.
       * @return a BitMask containing the permissions
       */
      utl::BitMask			&getPermissions();

      /**
       * Gets the entity subproperties of a given permission.
       * @param prop the permission
       * @return a BitMask containing the subproperties
       */
      utl::BitMask			&getPermissionProperties(property::e_property prop);

      /**
       * Casts itself to a Collidable component.
       * @return a reference on itself, casted to a macroengine::component::Collidable
       */
      component::Collidable		&asCollidable();

      /**
       * Casts itself to a Drawable component.
       * @return a reference on itself, casted to a macroengine::component::Drawable
       */
      component::Drawable		&asDrawable();

      /**
       * Casts itself to a Movable component.
       * @return a reference on itself, casted to a macroengine::component::Movable
       */
      component::Movable		&asMovable();

      /**
       * Casts itself to a Controllable component.
       * @return a reference on itself, casted to a macroengine::component::Controllable
       */
      component::Controllable		&asControllable();

      /**
       * Casts itself to a Factory component.
       * @return a reference on itself, casted to a macroengine::component::Factory
       */
      component::Factory		&asFactory();

      /**
       * Casts itself to a Scriptable component.
       * @return a reference on itself, casted to a macroengine::component::Scriptable
       */
      component::Scriptable		&asScriptable();

      /**
       * Asks the core to remove this entity at next core tick.
       */
      void				remove();

      /**
       * Checks whether the entity is asked to be removed.
       * @return true if the entity is asked, false otherwise
       */
      bool				getRemove();

      /**
       * Overriding of the Object::log() method.
       * @param str the string to display
       */
      void				log(std::string const &str, int indentation = 0);

      /**
       * Overriding of the Object::warning() method.
       * @param str the string to display
       */
      void				warning(std::string const &str, int indentation = 0);

      /**
       * Overriding of the Object::error() method.
       * @param str the string to display
       */
      void				error(std::string const &str, int indentation = 0);

      /**
       * Overriding of the Object::getIdentifier() method.
       * @return the entity identifier
       */
      t_identifier const		&getIdentifier() const;

      /**
       * Overriding of the Object::setIdentifier() method.
       * @param identifier the identifier
       */
      void				setIdentifier(t_identifier const &identifier);

      /**
       * Overriding of the Object::as() method.
       */
      template<typename			Class = Entity>
      Class				&as() {
	return Object::as<Class>(this);
      }
    };
  }
}

#endif //MACRO_ENGINE_ENTITY_HPP

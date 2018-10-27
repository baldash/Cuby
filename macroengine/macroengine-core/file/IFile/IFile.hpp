/*
** IFile.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/file/IFile/IFile.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Fri Jan 26 15:31:54 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_IFILE_HPP_
# define MACRO_ENGINE_IFILE_HPP_

# include				<string>
# include				<vector>
# include				"macroengine-core/utl/types.hpp"

namespace				macroengine {
  namespace				file {
    /**
     * \class IFile
     * \brief The interface for the File class.
     */
    class				IFile {
    public:
      virtual ~IFile() = default;

      /**
       * Opens the file given as parameter to the setFileName() method.
       */
      virtual void			open() = 0;

      /**
       * Closes the file.
       */
      virtual void			close() = 0;

      /**
       * Checks whether the file is ready to be read or not.
       * @return true if the file is OK, false otherwise
       */
      virtual bool			good() const = 0;

      /**
       * Reads the file and puts the content in an array defined by the child classes.
       * @return 0 if OK, 1 otherwise
       */
      virtual int			read() = 0;

      /**
       * Gets the raw content read from the file.
       * @return a reference to the raw content array defined by the child class
       */
      virtual t_raw_content const	&getContent() const = 0;

      /**
       * Sets the file name.
       * @param file the file name
       */
      virtual void			setFileName(std::string const &file) = 0;

      /**
       * Gets the file name.
       * @return the file name
       */
      virtual std::string const		&getFileName() const = 0;

      /**
       * Resets every data in the File class.
       */
      virtual void			reset() = 0;
    };
  }
}

#endif /* !MACRO_ENGINE_IFILE_HPP_ */

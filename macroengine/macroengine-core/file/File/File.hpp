/*
** File.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/file/File/File.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Fri Jan 26 15:35:48 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_File_HPP_
# define MACRO_ENGINE_File_HPP_

# include				<fstream>
# include				"macroengine-core/file/IFile/IFile.hpp"
# include				"macroengine-core/Object/Object.hpp"

namespace 				macroengine {
  namespace				file {
    /**
     * \class File
     * \brief The main file handling class. Provides an implementation for reading and getting content.
     * This class can be passed to macroengine::parser classes such as Iniparser class (see examples).
     * To see the description of the File methods, go to the IFile documentation.
     * \sa macroengine::file::IFile
     */
    class				File : public IFile, public Object {
    private:
      std::string			_filename;
      t_raw_content 			_content;
      std::ifstream			_stream;

    public:
      /**
       * This constructor can get the file path as parameter.
       * @param file the file path
       */
      File(std::string const &file = "");
      virtual ~File() = default;

      virtual void			dump() override;

      virtual void			open() override;
      virtual void			close() override;
      virtual bool			good() const override;
      virtual int			read() override;
      virtual t_raw_content const	&getContent() const override;
      virtual void			setFileName(std::string const &file) override;
      virtual std::string const		&getFileName() const override;
      virtual void			reset() override;
    };
  };
};

#endif /* !MACRO_ENGINE_File_HPP_ */

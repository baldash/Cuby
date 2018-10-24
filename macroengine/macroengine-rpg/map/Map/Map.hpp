/*
** Map.hpp for Macro_Engine in /home/sylvain/Documents/projects/perso/C++/macroengine/macroengine-rpg/map/Map/Map.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Mon May 21 20:20:56 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_MAP_HPP
#define MACRO_ENGINE_MAP_HPP

# include				<string>
# include				"macroengine-rpg/utl/rpg_types.hpp"
# include				"macroengine-rpg/map/Cell/Cell.hpp"
# include				"macroengine-rpg/map/CellData/CellData.hpp"
# include				"macroengine-core/Object/Object.hpp"
# include				"macroengine-core/parser/ini/IniParser/IniParser.hpp"

namespace				macroengine {
  namespace				rpg {
    class				Map: public property::Drawable<property::SPRITE | property::VIEW> {
    private:
      file::File			_file;
      parser::ini::IniParser		_parser;
      t_identifier 			_view_identifier;
      utl::Dimensions			_dimensions;
      utl::Dimensions			_texture_dimensions;
      std::string			_name;
      t_raw_map				_raw_map;
      t_cells				_cells;
      t_cell_dictionary 		_cell_dictionary;

    public:
      Map();
      virtual ~Map() = default;

      void				dump();

      int				loadFromFile(std::string const &file);

      graphics::View			&getView();

      void				destroy();

    private:
      int				parseFile(std::string const &file);
      bool				isKeyExisting(std::string const &scope, std::string const &key);

      int				getInfosFromParser();
      int				getConfigurationInfos();
      int				getDataInfos();
      int				parseMap(std::string const &map);

      t_raw_map 			mapStringToRawMap(std::string const &str);
      int				updateDrawable();
    };
  }
}

#endif //MACRO_ENGINE_MAP_HPP

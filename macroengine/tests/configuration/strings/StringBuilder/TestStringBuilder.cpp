/*
** TestStringBuilder.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/tests/utl/strings/StringBuilder/TestStringBuilder.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Feb 15 19:10:30 2018 Sylvain CHAUGNY
*/


#include			<gtest/gtest.h>
#include			"macroengine-core/macroengine-core.hpp"

TEST(TestStringBuilder, non_existing_string)
{
  ASSERT_EQ(Strings("test", std::string("test1"), std::string("test2"), std::string("test3")),
	    "");
}

TEST(TestStringBuilder, registering_entity)
{
  ASSERT_EQ(Strings("core_registering_entity", std::string("test1"), std::string("test2"), std::string("test3")),
	    "Registering entity ID <test1>...");
}

TEST(TestStringBuilder, fail_registering_entity)
{
  ASSERT_EQ(Strings("core_fail_registering_entity", std::string("test1"), std::string("test2"), std::string("test3")),
	    "Fail: entity <test1> is already registered");
}
TEST(TestStringBuilder, success)
{
  ASSERT_EQ(Strings("core_success", std::string("test1"), std::string("test2"), std::string("test3")),
	    "Success");
}

TEST(TestStringBuilder, enabling_entity_at_launch)
{
  ASSERT_EQ(Strings("core_enabling_entity_at_launch", std::string("test1"), std::string("test2"), std::string("test3")),
	    "Enabling entity <test1> at launch...");
}

TEST(TestStringBuilder, fail_enabling_entity_at_launch)
{
  ASSERT_EQ(Strings("core_fail_enabling_entity_at_launch", std::string("test1"), std::string("test2"), std::string("test3")),
	    "Fail: entity <test1> doesn't exist");
}

TEST(TestStringBuilder, building_entity)
{
  ASSERT_EQ(Strings("core_building_entity", std::string("test1"), std::string("test2"), std::string("test3")),
	    "Building entity <test1>...");
}

TEST(TestStringBuilder, fail_building_entity)
{
  ASSERT_EQ(Strings("core_fail_building_entity", std::string("test1"), std::string("test2"), std::string("test3")),
	    "Fail: couldn't build entity <test1>");
}

TEST(TestStringBuilder, building_entity_already_exists)
{
  ASSERT_EQ(Strings("core_building_entity_already_exists", std::string("test1"), std::string("test2"), std::string("test3")),
	    "Success: entity <test1> is already built");
}

TEST(TestStringBuilder, running_game)
{
  ASSERT_EQ(Strings("core_running_engine", std::string("test1"), std::string("test2"), std::string("test3")),
	    "Running engine !");
}

TEST(TestStringBuilder, entity_no_permission)
{
  ASSERT_EQ(Strings("core_entity_no_permission", std::string("test1"), std::string("test2"), std::string("test3")),
	    "Entity <test1> doesn't have test2 permissions");
}

TEST(TestStringBuilder, unknown_class_name)
{
  ASSERT_EQ(Strings("core_unknown_class_name", std::string("test1"), std::string("test2"), std::string("test3")),
	    "Unknown class name");
}

TEST(TestStringBuilder, exception)
{
  ASSERT_EQ(Strings("core_exception", std::string("test1"), std::string("test2"), std::string("test3")),
	    "Exception: <test1>");
}

TEST(TestStringBuilder, unknown_string_id)
{
  ASSERT_EQ(Strings("core_unknown_string_id", std::string("test1"), std::string("test2"), std::string("test3")),
	    "Unknown string ID <test1>");
}

TEST(TestStringBuilder, configuring_entity)
{
  ASSERT_EQ(Strings("core_configuring_entity", std::string("test1"), std::string("test2"), std::string("test3")),
	    "Configuring entity <test1>...");
}

TEST(TestStringBuilder, fail_configuring_entity)
{
  ASSERT_EQ(Strings("core_fail_configuring_entity", std::string("test1"), std::string("test2"), std::string("test3")),
	    "Fail: unable to configure entity <test1>");
}

TEST(TestStringBuilder, strings_file_not_found)
{
  ASSERT_EQ(Strings("core_strings_file_not_found", std::string("test1"), std::string("test2"), std::string("test3")),
	    "Strings file <test1> not found, ignoring custom strings configuration");
}

TEST(TestStringBuilder, bad_formatted_ini_line_raw_content)
{
  ASSERT_EQ(Strings("core_bad_formatted_ini_line_raw_content", 345, std::string("test2"), std::string("test3")),
	    "Bad formatted line in INI file raw content (l. <345>)");
}

TEST(TestStringBuilder, retrieving_string_file_data)
{
  ASSERT_EQ(Strings("core_retrieving_string_file_data", std::string("test1"), std::string("test2"), std::string("test3")),
	    "Retrieving strings file <test1> data...");
}

TEST(TestStringBuilder, fail_retrieving_string_file_data)
{
  ASSERT_EQ(Strings("core_fail_retrieving_string_file_data", std::string("test1"), std::string("test2"), std::string("test3")),
	    "Fail: Couldn't retrieve strings file <test1> data");
}

TEST(TestStringBuilder, string_file_found_line)
{
  ASSERT_EQ(Strings("core_string_file_found_line", std::string("test1"), std::string("test2"), std::string("test3")),
	    "Found line <test1>");
}

TEST(TestStringBuilder, loading_texture)
{
  ASSERT_EQ(Strings("core_loading_texture", std::string("test1"), std::string("test2"), std::string("test3")),
	    "Loading texture from file <test1>...");
}

TEST(TestStringBuilder, fail_loading_texture)
{
  ASSERT_EQ(Strings("core_fail_loading_texture", std::string("test1"), std::string("test2"), std::string("test3")),
	    "Fail: Couldn't load texture from file <test1>");
}

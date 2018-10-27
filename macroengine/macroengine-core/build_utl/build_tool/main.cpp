#include <iostream>
#include "BuildTool/BuildTool.hpp"

using namespace macroengine::build_utl::build_tool;

int main(const int ac, const char **av)
{
  BuildTool tool;

  tool.init();
  return tool.process(ac, av);
}

#include <iostream>
#include <fstream>
#include <asset/file_system.h>
#include <debug/log.h>
#include <sol/sol.hpp>
#include <filesystem>

using namespace std::filesystem;


struct test
{
  int i;
};

struct test2 {};

class fuck
{
public:
  int shit(test* t)
  {
    t->i = 20;
    return 1;
  }
};

using namespace Noche;

int main()
{
  path p("");
  bool result = FileSystem::Exists(R"(C:/Users/TungLam/Downloads)");
  Log::Info("{}", result);
  sol::state state;
  state.open_libraries();
  state.new_usertype<test2>("test2");
  auto test_type = state.new_usertype<test>("test");
  test_type["i"] = &test::i;
  auto type = state.new_usertype<fuck>("fuck");
  type["shit"] = &fuck::shit;
  return 0;
}

#include <iostream>
#include <sol/sol.hpp>


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

int main()
{
  sol::state state;
  state.open_libraries();
  state.new_usertype<test2>("test2");
  auto test_type = state.new_usertype<test>("test");
  test_type["i"] = &test::i;
  auto type = state.new_usertype<fuck>("fuck");
  type["shit"] = &fuck::shit;
  return 0;
}

#include <iostream>
#include <sol/sol.hpp>

int main()
{
  sol::state state;
  state.open_libraries();
  state.do_string("print('fuck')");
  return 0;
}

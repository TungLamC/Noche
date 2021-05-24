#include <iostream>
#include <moonfall/moonfall.hpp>
#include <sol/sol.hpp>

class fuck
{
public:
  int shit()
  {
    std::cout << "shit" << std::endl;
    return 1;
  }
};

int main()
{
  sol::state state;
  state.open_libraries();
  state.do_string("print('fuck')");
  auto type = state.new_usertype<fuck>("fuck");
  type['shit'] = &fuck::shit;
  state.do_string("a = fuck.new(); a:shit();");
  return 0;
}

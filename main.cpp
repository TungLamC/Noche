#include <debug/log.h>
#include <iostream>
#include <tref/Tref.hpp>

#include <std/reflection.h>
#include <tuple>

using namespace std;
using namespace Noche;

namespace Noche
{

class O { };
constexpr auto get_type_info(O*)
{
  return type_info("O", (O*)0, (base_list<dummy_base>*)0, sizeof(O));
}
class A {};
constexpr auto get_type_info(A*)
{
  return type_info("A", (A*)0, (base_list<dummy_base>*)0, sizeof(A));
}
class B: O, A {};
constexpr auto get_type_info(B*)
{
  return type_info("B", (B*)0, (base_list<O, A>*)0, sizeof(B));
}

}

int main()
{
  type_of<B>.each_bases([](auto base, int level) {
    Log::Info("{} {}", typeid(base).name(), level);
  });
  return 0;
}
#include <debug/log.h>
#include <iostream>
#include <tref/Tref.hpp>

#include <std/reflection.h>
#include <tuple>

using namespace std;
using namespace Noche;

namespace Noche
{
struct Top {};
constexpr auto get_type_info(Top*)
{
  return type_info("Top", (Top*)0, (tuple<>*)0, sizeof(Top), nullptr);
}
struct Object {};
constexpr auto get_type_info(Object*)
{
  return type_info("Object", (Object*)0, (tuple<Top>*)0, sizeof(Object), nullptr);
}
struct Asset {};
constexpr auto get_type_info(Asset*)
{
  return type_info("Asset", (Asset*)0, (tuple<>*)0, sizeof(Asset), nullptr);
}
struct Component: Object, Asset {};
constexpr auto get_type_info(Component*)
{
  return type_info("Component", (Component*)0, (tuple<Object, Asset>*)0, sizeof(Component), nullptr);
}
}

int main()
{
  type_of<Component>.each_base([](auto base, int level) {
    Log::Info("{} {}", base.name, level);
  });
  return 0;
}
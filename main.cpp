#include <debug/log.h>
#include <iostream>
#include <tref/Tref.hpp>
#include <type_traits>
#include <yaml-cpp/yaml.h>

using namespace tref;

struct a
{
  TrefType (a);

  int i = 1;
  TrefField (i);
};

struct b
{
  TrefType (b);

  float k = 30;
  TrefField (k);

  a aaa;
  TrefField (aaa);
};

using yaml_node = YAML::Node;

template<typename T>
yaml_node serialize(T target)
{
  yaml_node node;
  class_info<T>().each_field([&](auto field, int level) {
    if constexpr (is_reflected_v<typename decltype(field)::member_t>)
      node[std::string(field.name).c_str()] = serialize(target.*(field.value));
    else
      node[std::string(field.name).c_str()] = target.*(field.value);
    return true;
  });
  return node;
}

int main()
{
  b bb;
  std::string_view  s;
//
//  class_info<b>().each_field([&](auto info, int level) {
//    if constexpr (is_reflected_v<typename decltype(info)::member_t>)
//      std::cout << (bb.*(info.value)).i;
//    else
//      std::cout << info.name << std::endl;
//    return true;
//  });
  yaml_node node = serialize(bb);
  std::cout << node << std::endl;
  return 0;
}
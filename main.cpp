#include <debug/log.h>
#include <iostream>
#include <tref/Tref.hpp>
#include <type_traits>
#include <vector>
#include <sstream>
#include <spdlog/fmt/ostr.h>
#include <yaml-cpp/yaml.h>

using namespace tref;
template <typename Container>
struct is_container : std::false_type { };

template <typename... Ts> struct is_container<std::list<Ts...> > : std::true_type { };
template <typename... Ts> struct is_container<std::vector<Ts...> > : std::true_type { };

struct a
{
  TrefType (a);

  int i = 1;
  TrefField (i);
};

struct b
{
  TrefType (b);
  
  b(): k{}, aaa{}, v{1, 2, 3} { }

  float k = 30;
  TrefField (k);

  a aaa;
  TrefField (aaa);
  
  std::vector<int> v;
  TrefField(v);
};

using yaml_node = YAML::Node;

template<typename T>
yaml_node serialize(T target)
{
  yaml_node node;
  class_info<T>().each_field([&](auto field, int level) {
    if constexpr (is_reflected_v<typename decltype(field)::member_t>)
      node[std::string(field.name).c_str()] = serialize(target.*(field.value));
    else if constexpr (is_container<typename decltype(field)::member_t>::value)
    {
      node[std::string(field.name).c_str()] = target.*(field.value);
    }
    else
      node[std::string(field.name).c_str()] = target.*(field.value);
    return true;
  });
  return node;
}

int main()
{
  b bb;
  yaml_node node = serialize(bb);
  std::stringstream stream;
  stream << node;
  std::string s = stream.str();
  Noche::Log::Info("{}", node);
  return 0;
}
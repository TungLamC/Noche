#include <debug/log.h>
#include <iostream>
#include <tref/Tref.hpp>
#include <type_traits>
#include <vector>
#include <sstream>
#include <spdlog/fmt/ostr.h>
#include <yaml-cpp/yaml.h>
#include <map>
#include <io/asset_manager.h>

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
  
  b(): k{}, aaa{}, v{1, 2, 3}, s{"hahahah"}, m { {"fuck", 2}, {"nihao", 2} } { }

  float k = 30;
  TrefField (k);

  a aaa;
  TrefField (aaa);
  
  std::vector<int> v;
  TrefField(v);
  
  std::string s;
  TrefField(s);
  
  std::map<std::string, float> m;
  TrefField(m);
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

using namespace Noche;

int main()
{
  b bb;
  std::stringstream stream;
  std::string s = stream.str();
  return 0;
}
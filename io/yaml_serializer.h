#ifndef NOCHE_YAML_SERIALIZER_H
#define NOCHE_YAML_SERIALIZER_H

#include <std/reflection.h>
#include <yaml-cpp/yaml.h>

namespace Noche
{
using YamlNode = YAML::Node;

class YamlSerializer
{
public:
  template<typename T>
  static YamlNode Serialize(const T& object)
  {
    static_assert(is_reflected_v<T>, "Serialize need reflected!");
    YamlNode node;
    type_of(T).each_field([&](auto field, int level) {
      if constexpr (is_reflected_v<typename decltype(field)::member_t>)
        node[string(field.name).c_str()] = Serialize(object.*field.value);
      else
        node[string(field.name).c_str()] = object.*field.value;
      return true;
    });
    return node;
  }

  template<typename T>
  static T Deserialize(const YamlNode& root)
  {
    static_assert(is_reflected_v<T>, "Serialize need reflected!");
    T result{};
    type_of(T).each_field([&](auto field, int level) {
      if constexpr (is_reflected_v<typename decltype(field)::member_t>)
        result.*field.value = Deserialize<decltype(field)::member_t>(root[string(field.name).c_str()]);
      else
        result.*field.value = root[string(field.name).c_str()].as<decltype(field)::member_t>();
      return true;
    });
    return result;
  }
};
}

#endif //NOCHE_YAML_SERIALIZER_H

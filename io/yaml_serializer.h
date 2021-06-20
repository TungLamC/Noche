#ifndef NOCHE_YAML_SERIALIZER_H
#define NOCHE_YAML_SERIALIZER_H

#include <string>
#include <yaml-cpp/yaml.h>

namespace Noche
{
using YamlNode = YAML::Node;

class YamlSerializer
{
  template<typename T>
  YamlNode Serialize(T&& object);
};

template<typename T>
YamlNode YamlSerializer::Serialize(T&& object)
{
  return Noche::YamlNode();
}

}

#endif //NOCHE_YAML_SERIALIZER_H

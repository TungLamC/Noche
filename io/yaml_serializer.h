#ifndef NOCHE_YAML_SERIALIZER_H
#define NOCHE_YAML_SERIALIZER_H

#include <string>
#include <yaml-cpp/yaml.h>

namespace noche
{
using yaml_node = YAML::Node;

class yaml_serializer
{
  template<typename T>
  yaml_node serialize(T&& object);
};
}

#endif //NOCHE_YAML_SERIALIZER_H

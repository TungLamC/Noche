#ifndef NOCHE_YAML_SERIALIZER_H
#define NOCHE_YAML_SERIALIZER_H

#include <string>
#include <yaml-cpp/yaml.h>

namespace lam
{
using yaml_node = YAML::Node;

class yaml_serializer
{
  template<typename T>
  yaml_node serialize(T&& object);
};

template<typename T>
yaml_node yaml_serializer::serialize(T&& object)
{
  return lam::yaml_node{};
}

}

#endif //NOCHE_YAML_SERIALIZER_H

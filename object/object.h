#ifndef NOCHE_OBJECT_H
#define NOCHE_OBJECT_H

#include <common/alias.h>
#include <io/yaml_serializer.h>

namespace Noche
{
class Object
{
REFLECT_ROOT_TYPE(Object)

public:
  Object() = default;
  

  virtual ~Object() = default;
};
}

#endif //NOCHE_OBJECT_H

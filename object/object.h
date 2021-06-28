#ifndef NOCHE_OBJECT_H
#define NOCHE_OBJECT_H

#include <std/alias.h>
#include <std/reflection.h>
#include <gc_cpp.h>

namespace Noche
{
class Object: inherit gc
{
  REFLECT_ROOT_TYPE(Object)
public:
  Object() = default;
};
}

#endif //NOCHE_OBJECT_H

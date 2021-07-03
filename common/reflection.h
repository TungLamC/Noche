#ifndef NOCHE_REFLECTION_H
#define NOCHE_REFLECTION_H

#include <common/alias.h>
#include <tref/Tref.hpp>

namespace Noche
{
using namespace std;
using namespace tref;

#define type_of(type) class_info<type>()

#define REFLECT_ROOT_TYPE(CLASS) TrefType(CLASS)

#define REFLECT_TYPE(CLASS) \
  TrefType(CLASS)           \
  friend TrefSubType(CLASS)

#define REFLECT_FIELD(FIELD) TrefField(FIELD)
}

#endif //NOCHE_REFLECTION_H

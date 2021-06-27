#ifndef NOCHE_REFLECTION_H
#define NOCHE_REFLECTION_H

#include <tref/Tref.hpp>

namespace Noche
{
using namespace std;
using namespace tref;

template<typename T>
static constexpr auto type_of = class_info<T>();

#define REFLECT_ROOT_TYPE(CLASS) TrefType(CLASS)

#define REFLECT_TYPE(CLASS) \
  TrefType(CLASS)           \
  friend TrefSubType(CLASS)

#define REFLECT_FIELD(FIELD) TrefField(FIELD)
}

#endif //NOCHE_REFLECTION_H

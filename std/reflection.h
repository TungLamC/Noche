#ifndef NOCHE_REFLECTION_H
#define NOCHE_REFLECTION_H

#include <tuple>
#include <string_view>
#include <std/meta.h>

namespace Noche
{
using namespace std;

struct dummy {};

template<typename Class>
constexpr void get_type_info(Class*);

template<typename Meta, typename Class, typename... Bases>
struct type_info
{
  using meta_t = Meta;
  using class_t = Class;
};
}

#endif //NOCHE_REFLECTION_H

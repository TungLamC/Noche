#ifndef NOCHE_REFLECTION_H
#define NOCHE_REFLECTION_H

#include <tuple>
#include <string_view>
#include <std/meta.h>

namespace Noche
{
using namespace std;

struct dummy
{
};

template<typename Class>
constexpr void get_type_info(Class *);

template<typename T>
constexpr auto type_of = get_type_info((T *) 0);

template<typename Meta, typename Class, typename... Bases>
struct type_info
{
  using meta_t = Meta;
  using class_t = Class;
  using bases_t = tuple<decltype(type_of<Bases>)...>;

  static constexpr auto bases = make_tuple(type_of<Bases>...);

  string_view name;
  meta_t      meta;
  size_t      size;

  constexpr type_info(string_view name, Class *, tuple<Bases...> *, size_t size, Meta meta)
    : name(name), size(size), meta(meta)
  {
  }

  template<typename F>
  constexpr void each_base(F&& visitor, size_t level = 0) const
  {
    for_each_tuple(bases, [&](auto base, size_t index) {
      visitor(base, level);
    });
    for_each_tuple(bases, [&](auto base, size_t index) {
      auto next = level + 1;
      base.each_base(visitor, next);
    });
  }
};
}

#endif //NOCHE_REFLECTION_H

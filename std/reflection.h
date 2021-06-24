#ifndef NOCHE_REFLECTION_H
#define NOCHE_REFLECTION_H

#include <tuple>
#include <string_view>
#include <std/meta.h>

namespace Noche
{
using namespace std;

struct dummy_base {};

template<typename T>
constexpr void get_type_info(T*);

template<typename T>
constexpr auto type_of = get_type_info((T*)0);


template<typename... T>
struct base_list
{
  static constexpr auto bases = std::tuple<decltype(get_type_info((T*)0))...>{ type_of<T>... };

  template<size_t I>
  using type_at = tuple_element_t<I, std::tuple<T...>>;
};

constexpr auto get_type_info(dummy_base*)
{
  return type_info("dummy", (dummy_base*)0, (base_list<dummy_base>*)0, sizeof(dummy_base));
}
template<typename Class, typename... Bases>
struct type_info
{
  using class_t = Class;
  using bases_t = base_list<Bases...>;

  string_view name;
  size_t size;

  constexpr type_info(string_view name, Class*, bases_t* bases, size_t size)
    : name{name}, size{size}
  {
    // todo
  }

  template<typename F>
  constexpr void each_bases(F&& visitor, int level = 0) const
  {
    if constexpr (is_same_v<dummy_base, typename bases_t::type_at<0>>)
      return;
    for_each_tuple(bases_t::bases, [=](auto base) {
      visitor(base, level);
    });
  }
};
}

#endif //NOCHE_REFLECTION_H

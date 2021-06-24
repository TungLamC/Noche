#ifndef NOCHE_META_H
#define NOCHE_META_H

#include <tuple>
#include <type_traits>

namespace Noche
{
using namespace std;

template<typename... T, typename F, size_t... I>
void for_each_tuple(const std::tuple<T...>& tuple, const F& function, std::index_sequence<I...>)
{
  auto temp = {(function(std::get<I>(tuple), I), 0)...};
}

template<typename... T, typename F>
void for_each_tuple(const std::tuple<T...>& tuple, const F& function)
{
  for_each_tuple(tuple, function, std::make_index_sequence<sizeof...(T)>());
}

template<typename F>
void for_each_tuple(const std::tuple<>& tuple, const F& function)
{
}

template<typename From, typename To, typename = void>
struct can_static_cast: std::false_type {};

template<typename From, typename To>
struct can_static_cast<From, To, std::void_t<decltype(static_cast<To>(std::declval<From>()))>>: std::true_type {};

template <typename Base, typename Derived>
struct is_virtual_base_of: std::conjunction<
  is_base_of<Base, Derived>,
  negation<can_static_cast<Base*, Derived*>>
>{};

template<typename Base, typename Derived>
constexpr bool is_virtual_base_of_v = is_virtual_base_of<Base, Derived>::value;
}

#endif //NOCHE_META_H

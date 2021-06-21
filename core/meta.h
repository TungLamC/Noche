#ifndef NOCHE_META_H
#define NOCHE_META_H

#include <tuple>
#include <type_traits>

namespace lam
{
template<typename... T, typename F, size_t... I>
void for_each_tuple(const std::tuple<T...>& tuple, const F& function, std::index_sequence<I...>)
{
  auto temp = {(function(std::get<I>(tuple)), 0)...};
}

template<typename... T, typename F>
void for_each_tuple(const std::tuple<T...>& tuple, const F& function)
{
  for_each_tuple(tuple, function, std::make_index_sequence<sizeof...(T)>());
}
}

#endif //NOCHE_META_H

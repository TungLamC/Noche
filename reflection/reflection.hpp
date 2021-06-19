#ifndef NOCHE_REFLECTION_HPP
#define NOCHE_REFLECTION_HPP

namespace cyou
{
template<int N = 255>
struct id: id<N -1>
{
  enum { value = N };
};

template<>
struct id<0>
{
  enum { value = 0 };
};


void void_a()
{
  auto fuck = id<>{};
  if (fuck.value == 255)
  {
  }
}
}

#endif //NOCHE_REFLECTION_HPP

#ifndef CYOU_HPP
#define CYOU_HPP

#include <tuple>
#include <type_traits>

#ifdef _MSC_VER
#define CYOU_CXX_VERSION _MSVC_LANG
#else
#define CYOU_CXX_VERSION __cplusplus
#endif

#if CYOU_CXX_VERSION < 201700L
#error "cyou need c++17."
#endif

namespace cyou
{
using namespace std;

template<int N = 255>
struct id: id<N - 1> {
  enum { value = N };
};
}


#endif //CYOU_HPP

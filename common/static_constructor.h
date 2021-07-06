#ifndef NOCHE_STATIC_CONSTRUCTOR_H
#define NOCHE_STATIC_CONSTRUCTOR_H

namespace bomb
{
template<typename T>
class static_invoker
{
public:
  static_invoker()
  {
    T::static_constructor();
  }
};

#define static_construct(T) static_invoker<T> static_invoker_of_##T
}

#endif //NOCHE_STATIC_CONSTRUCTOR_H

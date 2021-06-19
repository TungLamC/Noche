#ifndef NOCHE_COMPILE_TIME_REFLECTION_H
#define NOCHE_COMPILE_TIME_REFLECTION_H

namespace Noche
{
reflect_class(Fuck, Base)
  constructor()
  constructor(int, float)
  constructor(fuck, test)
  property(x)
  property(y)
  function(a)
  function(b)
  overload_function(overload, )
reflect_end
}

#endif //NOCHE_COMPILE_TIME_REFLECTION_H

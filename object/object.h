#ifndef NOCHE_OBJECT_H
#define NOCHE_OBJECT_H

namespace noche
{
class Object
{
public:
  virtual void serialize() = 0;
};
}

#endif //NOCHE_OBJECT_H
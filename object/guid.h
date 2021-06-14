#ifndef NOCHE_GUID_H
#define NOCHE_GUID_H

#include <core/type_alias.h>

namespace noche
{
class guid
{
public:
  guid(uint32_t a = 0, uint32_t b = 0, uint32_t c = 0, uint32_t d = 0);

public:
  bool valid() const;

private:
  uint32_t id[4]; 
};
}

#endif //NOCHE_GUID_H

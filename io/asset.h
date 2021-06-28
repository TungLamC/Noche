#ifndef NOCHE_ASSET_H
#define NOCHE_ASSET_H

#include <std/alias.h>
#include <std/reflection.h>
#include <object/object.h>

namespace Noche
{
class Asset: inherit Object
{
REFLECT_TYPE(Asset)
public:
  Asset() = default;
};
}

#endif //NOCHE_ASSET_H

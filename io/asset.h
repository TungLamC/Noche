#ifndef NOCHE_ASSET_H
#define NOCHE_ASSET_H

#include <common/alias.h>
#include <common/reflection.h>
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

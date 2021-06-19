#ifndef NOCHE_ASSET_MANAGER_H
#define NOCHE_ASSET_MANAGER_H

#include <asset/asset.h>
#include <string>
#include <memory>
#include <tuple>

namespace Noche
{
class AssetManager
{
public:
  template<typename T>
  static std::shared_ptr<T> Load(const char* path);
};
}

#endif //NOCHE_ASSET_MANAGER_H

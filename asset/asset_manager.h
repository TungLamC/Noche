#ifndef NOCHE_ASSET_MANAGER_H
#define NOCHE_ASSET_MANAGER_H

#include <asset/asset.h>
#include <string>
#include <memory>
#include <tuple>

namespace noche
{
class asset_manager
{
public:
  template<typename T>
  static std::shared_ptr<T> load(const char* path);
};

}

#endif //NOCHE_ASSET_MANAGER_H

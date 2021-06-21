#ifndef NOCHE_ASSET_MANAGER_H
#define NOCHE_ASSET_MANAGER_H

#include <io/asset.h>
#include <string>
#include <memory>
#include <tuple>

namespace lam
{
class asset_manager
{
public:
  template<typename T>
  static std::shared_ptr<T> load(const char* path);
};

template<typename T>
std::shared_ptr<T> asset_manager::load(const char* path)
{
  return std::shared_ptr<T>();
}
}

#endif //NOCHE_ASSET_MANAGER_H

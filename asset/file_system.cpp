#include <asset/file_system.h>
#include <io.h>

namespace Noche
{
bool FileSystem::Exists(const char* path)
{
  return path != nullptr && access(path, 0x00) == 0;
}
}

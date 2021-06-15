#ifndef NOCHE_FILE_SYSTEM_H
#define NOCHE_FILE_SYSTEM_H

#include <io.h>

namespace Noche
{
class FileSystem
{
public:
  static bool Exists(const char* path);
};
}

#endif //NOCHE_FILE_SYSTEM_H

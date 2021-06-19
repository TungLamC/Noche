#ifndef NOCHE_FILE_SYSTEM_H
#define NOCHE_FILE_SYSTEM_H

#include <filesystem>
#include <io.h>


namespace Noche
{
using namespace std::filesystem;

using Path = std::filesystem::path;

class FileSystem
{
public:
  static bool Exists(const char* path);
};
}

#endif //NOCHE_FILE_SYSTEM_H

#ifndef NOCHE_FILE_SYSTEM_H
#define NOCHE_FILE_SYSTEM_H

#include <filesystem>
#include <io.h>


namespace lam
{
using namespace std::filesystem;

using path = std::filesystem::path;

class file_system
{
public:
  static bool exists(const char* path);
};
}

#endif //NOCHE_FILE_SYSTEM_H

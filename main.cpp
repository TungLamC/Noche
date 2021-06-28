#include <debug/log.h>
#include <std/alias.h>
#include <std/reflection.h>
#include <io/asset.h>
#include <stdlib.h>
#include <crtdbg.h>
#include <gc_cpp.h>

using namespace Noche;

int main()
{
  GC_INIT();
  _CrtDumpMemoryLeaks();
  Asset* a = new Asset();
  int i = 2;
  GC_gcollect();
  return 0;
}
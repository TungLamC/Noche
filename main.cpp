#include <debug/log.h>
#include <std/reflection.h>
#include <io/yaml_serializer.h>
#include <vector>

using namespace std;
using namespace Noche;

struct Embed
{
  REFLECT_ROOT_TYPE(Embed)

  int i;
  REFLECT_FIELD(i)
};

struct Fuck
{
  REFLECT_ROOT_TYPE(Fuck)

  int i = 1;
  REFLECT_FIELD(i)

  float f = 2;
  REFLECT_FIELD(f)
  
  Embed e;
  REFLECT_FIELD(e)
};

int main()
{
  Fuck f;
  f.e.i = 999;
  stringstream ss;
  ss << YamlSerializer::Serialize(f);
  string s = ss.str();
  Fuck temp = YamlSerializer::Deserialize<Fuck>(YAML::Load(s.c_str()));
  return 0;
}
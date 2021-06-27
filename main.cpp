#include <debug/log.h>
#include <std/reflection.h>
#include <io/yaml_serializer.h>
#include <vector>

using namespace std;
using namespace Noche;

struct Fuck
{
  REFLECT_TYPE(Fuck)

  int i = 1; 
  REFLECT_FIELD(i)

  float f = 2;

  vector<int> ffff;
  REFLECT_FIELD(ffff)
};

int main()
{
  Fuck f;
  f.ffff = { 1, 2, 3 };
  stringstream ss;
  ss << YamlSerializer::Serialize(f);
  string s = ss.str();
  Fuck temp = YamlSerializer::Deserialize<Fuck>(YAML::Load(s.c_str()));
  return 0;
}
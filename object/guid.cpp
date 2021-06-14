#include <object/guid.h>

namespace noche
{
guid::guid(uint32_t a, uint32_t b, uint32_t c, uint32_t d): ids{a, b, c, d} {}

bool guid::valid() const { return ids[0] != ids[1] != ids[2] != ids[3] != 0; }

}

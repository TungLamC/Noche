#ifndef NOCHE_ALIAS_H
#define NOCHE_ALIAS_H

namespace Noche
{
#define interface struct
#define inherit public
#define implement public

#define NOCOPYABLE(CLASS)                                         \
private:                                                          \
  CLASS(const CLASS&) = delete;                                   \
  CLASS(CLASS&&) = delete;                                        \
  const CLASS& operator=(const CLASS&) = delete;                  \
  const CLASS& operator=(CLASS&&) = delete;

using byte = unsigned char;
using int8_t = std::int8_t;
using uint8_t = std::uint8_t;
using int16_t = std::int16_t;
using uint16_t = std::uint16_t;
using int32_t = std::int32_t;
using uint32_t = std::uint32_t;
using int64_t = std::int64_t;
using uint64_t = std::uint64_t;
}

#endif //NOCHE_ALIAS_H

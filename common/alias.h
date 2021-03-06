#ifndef NOCHE_ALIAS_H
#define NOCHE_ALIAS_H

#include <functional>
#include <common/reflection.h>

namespace bomb
{
#define interface struct
#define inherit public
#define implement public

#define NOCOPYABLE(CLASS)                                           \
private:                                                            \
    CLASS(const CLASS&) = delete;                                   \
    CLASS(CLASS&&) = delete;                                        \
    const CLASS& operator=(const CLASS&) = delete;                  \
    const CLASS& operator=(CLASS&&) = delete;

#define SERIALIZE(CLASS)

#define NOCHE_TYPE(CLASS)   \
    REFLECT_TYPE(CLASS)     \
    NOCOPYABLE(CLASS)       \
    SERIALIZE(CLASS)

using byte = unsigned char;
using sint8_t = std::int8_t;
using suint8_t = std::uint8_t;
using sint16_t = std::int16_t;
using suint16_t = std::uint16_t;
using sint32_t = std::int32_t;
using uint32_t = std::uint32_t;
using sint64_t = std::int64_t;
using uint64_t = std::uint64_t;
using real32 = float;
using real64 = double;

}

#endif //NOCHE_ALIAS_H

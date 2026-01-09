#pragma once
#include <cstdint>
#include "../core/core.hpp"

namespace apron
{
    namespace utils
    {
        APRON_API void split_u16(uint16_t base, uint8_t* a, uint8_t* b);
        APRON_API void split_u32(uint32_t base, uint8_t* a, uint8_t* b, uint8_t* c, uint8_t *d);
    }
}

#include "splitter.hpp"

APRON_API void apron::utils::split_u16(uint16_t base, uint8_t* a, uint8_t* b)
{
    if (a != nullptr) *a = base >> 8;
    if (b != nullptr) *b = base & 0xFF;
}

APRON_API void apron::utils::split_u32(uint32_t base, uint8_t* a, uint8_t* b, uint8_t* c, uint8_t* d)
{
    if (a != nullptr) *a = base >> 24;
    if (b != nullptr) *b = base >> 16;
    if (c != nullptr) *c = base >> 8;
    if (d != nullptr) *d = base >> 0 & 0xFF;
}



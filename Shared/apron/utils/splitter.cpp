#include "splitter.h"

APRON_API void apron::utils::split_u16(uint16_t base, uint8_t* a, uint8_t* b)
{
    *a = base >> 8;
    *b = base;
}

APRON_API void apron::utils::split_u32(uint32_t base, uint8_t* a, uint8_t* b, uint8_t* c, uint8_t* d)
{
    *a = base >> 24;
    *b = base >> 16;
    *c = base >> 8;
    *d = base >> 0;
}
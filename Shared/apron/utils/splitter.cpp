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

uint8_t* apron::utils::split_u16_as_array(uint16_t base)
{
    uint8_t array[2] = { 0x00, 0x00 };
    split_u16(base, &array[0], &array[1]);
    return array;
}

uint8_t* apron::utils::split_u32_as_array(uint32_t base)
{
    uint8_t array[4] = { 0x00, 0x00, 0x00, 0x00 };
    split_u32(base, &array[0], &array[1], &array[3], &array[4]);
    return array;
}

uint8_t* apron::utils::split_u16_and_u32_as_array(uint16_t baseA, uint32_t baseB)
{
    uint8_t array[6] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
    split_u16(baseA, &array[0], &array[1]);
    split_u32(baseB, &array[2], &array[3], &array[4], &array[5]);
    return array;
}

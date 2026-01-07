#pragma once
#include <cstdint>

enum class instruction_type : uint16_t
{
    MEMORY_COPY             = 0x0000,
    MEMORY_MOVE             = 0x0001,
    MEMORY_WRITE            = 0x0002,
    MEMORY_READ             = 0x0003,
    MEMORY_CLEAR            = 0x0004,

    ARITHMETIC_ADD          = 0x0100,
    ARITHMETIC_SUB          = 0x0101,
    ARITHMETIC_MUL          = 0x0102,
    ARITHMETIC_DIV          = 0x0103,
    ARITHMETIC_MOD          = 0x0104,
};

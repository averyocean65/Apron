#pragma once
#include <cstdint>
#include "instruction_type.h"

namespace apron
{
    namespace instructions
    {
    class instruction
    {
    public:
        uint16_t id;
        uint16_t additional;
        uint32_t data;
    
        instruction(uint16_t pId, uint16_t pAdditional, uint32_t pData);
        instruction(instruction_type pId, uint16_t pAdditional, uint32_t pData);
    };
}
}

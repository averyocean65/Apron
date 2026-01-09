#pragma once
#include <cstdint>
#include "instruction_type.hpp"
#include "../core/core.hpp"

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
    
        APRON_API instruction(uint16_t pId, uint16_t pAdditional, uint32_t pData);
        APRON_API instruction(instruction_type pId, uint16_t pAdditional, uint32_t pData);
    };
}
}

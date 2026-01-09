#pragma once
#include <cstdint>

namespace apron
{
    namespace instructions
    {
        enum class instruction_type : uint16_t
        {
            /**
             * The specification for all of these functions is:
             * <instruction_id> <source, destination> <write_data>
             *
             * for example, writing 0x1234 to register 1 would be:
             * MEMORY_WRITE 0x0100 0x1234
             * Note: the <source, destination> turns into <register 1, register 2>
             *
             * copying from register 2 to register 5 would be:
             * MEMORY_COPY 0x0502 0x0
             */
            
            MEMORY_COPY             = 0x0000,
            MEMORY_MOVE             = 0x0001,
            MEMORY_WRITE            = 0x0002,
            MEMORY_CLEAR            = 0x0003,
        
            /**
             * The specification for all of these functions is:
             * <instruction_id> <destination, register 1> <register 2, register 3, register 4, register 5>
             *
             * for example, multiplying registers 5, 3, 1 and 9 into register 2 would be:
             * ARITHMETIC_MUL 0x0205 0x03010902
             */
        
            ARITHMETIC_ADD          = 0x0100,
            ARITHMETIC_SUB          = 0x0101,
            ARITHMETIC_MUL          = 0x0102,
            ARITHMETIC_DIV          = 0x0103,
            ARITHMETIC_MOD          = 0x0104,
        };
    }
}
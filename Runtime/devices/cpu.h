#pragma once
#include <cstdint>

class cpu
{
private:
    uint32_t mRegisters[];
public:
    cpu(int register_count);
    
    void execute_instruction();
    uint32_t* get_register(int index);
};

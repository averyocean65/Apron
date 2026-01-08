#pragma once
#include <cstdint>
#include <vector>

#include "apron/instructions/instruction.hpp"

class cpu
{
private:
    std::vector<uint32_t> m_registers;

    // not required, just for ease of use
    int m_register_count;
public:
    cpu(int register_count);
    
    void execute_instruction(apron::instructions::instruction instruction);
    uint32_t* get_register(int index);
};

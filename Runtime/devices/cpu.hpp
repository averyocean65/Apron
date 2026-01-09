#pragma once
#include <cstdint>
#include <vector>
#include <map>

#include <apron/instructions/instruction.hpp>

class cpu;
typedef void (*CpuFunction)(cpu*, apron::instructions::instruction);

class cpu
{
private:
    std::vector<uint32_t> m_registers;
    std::map<apron::instructions::instruction_type, CpuFunction> m_function_map;

    // not required, just for ease of use
    int m_register_count;
public:
    cpu(int register_count);
    
    void execute_instruction(apron::instructions::instruction instruction);
    uint32_t* get_register(int index);

    bool does_register_exist(int address);
    
    void print_state();
};
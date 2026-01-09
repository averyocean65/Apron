#include "cpu.h"
#include <apron/utils/splitter.h>

using namespace apron::instructions;

#define REGISTER_FUNCTION(type, func) m_function_map.emplace(type, func)

void move_memory(instruction instruction)
{
    uint8_t source = 0x00;
    uint8_t destination = 0x00;
    apron::utils::split_u16(instruction.additional, &source, &destination);
}

cpu::cpu(int register_count)
    : m_register_count(register_count), m_registers(register_count), m_function_map()
{
    // Register functions
    REGISTER_FUNCTION(instruction_type::MEMORY_MOVE, move_memory);
}

uint32_t* cpu::get_register(int index)
{
    if (index < 0 || index >= m_register_count)
    {
        return nullptr;
    }

    return &m_registers[index];
}

void cpu::execute_instruction(apron::instructions::instruction instruction)
{
    printf("Running instruction: %#04X %#04X %#08X\n", instruction.id, instruction.additional, instruction.data);

    instruction_type type = static_cast<instruction_type>(instruction.id);
    if (!m_function_map.count(type))
    {
        printf("Instruction implementation was not found!\n");
        return;
    }

    CpuFunction func = m_function_map[type];
    func(instruction);
}
#include "cpu.h"

cpu::cpu(int register_count)
    : m_register_count(register_count)
{
    m_registers = std::vector<uint32_t>(register_count);
}

void cpu::execute_instruction(apron::instructions::instruction instruction)
{
    printf("Running instruction: %#04X %#04X %#08X", instruction.id, instruction.additional, instruction.data);

    // TODO
}

uint32_t* cpu::get_register(int index)
{
    if (index < 0 || index >= m_register_count)
    {
        return nullptr;
    }

    return &m_registers[index];
}


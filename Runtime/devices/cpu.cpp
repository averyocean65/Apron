#include "cpu.hpp"
#include <apron/utils/splitter.hpp>

using namespace apron::instructions;

#define REGISTER_FUNCTION(type, func) m_function_map.emplace(type, func)

#pragma region CPU Functions
void move_memory(cpu* cpu, instruction instruction)
{
    uint8_t source, destination = 0x00;
    apron::utils::split_u16(instruction.additional, &source, &destination);
    
    *cpu->get_register(destination) = *cpu->get_register(source);
    *cpu->get_register(source) = 0x00;
}

void copy_memory(cpu* cpu, instruction instruction)
{
    uint8_t source, destination = 0x00;
    apron::utils::split_u16(instruction.additional, &source, &destination);

    *cpu->get_register(destination) = *cpu->get_register(source);
}

void write_memory(cpu* cpu, instruction instruction)
{
    uint8_t source = 0x00;
    apron::utils::split_u16(instruction.additional, &source, nullptr);

    *cpu->get_register(source) = instruction.data;
}

void clear_memory(cpu* cpu, instruction instruction)
{
    uint8_t source = 0x00;
    apron::utils::split_u16(instruction.additional, &source, nullptr);

    *cpu->get_register(source) = 0x00;
}
#pragma endregion

cpu::cpu(int register_count)
    : m_registers(register_count), m_function_map(), m_register_count(register_count)
{
    // Register functions
    REGISTER_FUNCTION(instruction_type::MEMORY_COPY, copy_memory);
    REGISTER_FUNCTION(instruction_type::MEMORY_MOVE, move_memory);
    REGISTER_FUNCTION(instruction_type::MEMORY_WRITE, write_memory);
    REGISTER_FUNCTION(instruction_type::MEMORY_CLEAR, clear_memory);
}

uint32_t* cpu::get_register(int index)
{
    if (index < 0 || index >= m_register_count)
    {
        printf("Error: Register %i was not found!\n", index);
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
    
    m_function_map[type](this, instruction);
}

void cpu::print_state()
{
    printf("-- CPU STATE --\n");
    for (int i = 0; i < m_register_count; i++)
    {
        printf("Reg %i: %#8X\n", i, m_registers[i]);
    }
    printf("-- END CPU STATE --\n");
}
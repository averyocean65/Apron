#include "cpu.hpp"
#include <apron/utils/splitter.hpp>

using namespace apron::instructions;

#define REGISTER_FUNCTION(type, func) m_function_map.emplace(type, func)

#pragma region CPU Functions
void safe_register_write(cpu* cpu, uint8_t address, uint32_t data)
{
    uint32_t* destination = cpu->get_register(address);
    if (destination == nullptr)
    {
        printf("Couldn't write to register %u", address);
        return;
    }

    *destination = data;
}

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

std::vector<uint8_t> arithmetic_get_registers(cpu* cpu, instruction instruction)
{
    std::vector<uint8_t> knownAddresses = std::vector<uint8_t>();
    uint8_t* possibleRegisters = apron::utils::split_u16_and_u32_as_array(instruction.additional, instruction.data);
    for (uint8_t reg : possibleRegisters)
    {
        if (!cpu->does_register_exist(reg))
        {
            continue;
        }

        knownAddresses.push_back(reg);
    }

    return knownAddresses;
}

void arithemtic_add(cpu* cpu, instruction instruction)
{
    std::vector<uint8_t> registers = arithmetic_get_registers(cpu, instruction);
    uint32_t* destination = cpu->get_register(registers[0]);
    for (int i = 1; i < registers.size(); i++)
    {
        *destination += *cpu->get_register(registers[i]);
    }
}

void arithemtic_sub(cpu* cpu, instruction instruction)
{
    std::vector<uint8_t> registers = arithmetic_get_registers(cpu, instruction);
    uint32_t* destination = cpu->get_register(registers[0]);
    for (int i = 1; i < registers.size(); i++)
    {
        *destination -= *cpu->get_register(registers[i]);
    }
}

void arithemtic_mul(cpu* cpu, instruction instruction)
{
    std::vector<uint8_t> registers = arithmetic_get_registers(cpu, instruction);
    uint32_t* destination = cpu->get_register(registers[0]);
    for (int i = 1; i < registers.size(); i++)
    {
        *destination *= *cpu->get_register(registers[i]);
    }
}

void arithemtic_div(cpu* cpu, instruction instruction)
{
    std::vector<uint8_t> registers = arithmetic_get_registers(cpu, instruction);
    uint32_t* destination = cpu->get_register(registers[0]);
    for (int i = 1; i < registers.size(); i++)
    {
        *destination /= *cpu->get_register(registers[i]);
    }
}

void arithemtic_mod(cpu* cpu, instruction instruction)
{
    std::vector<uint8_t> registers = arithmetic_get_registers(cpu, instruction);
    uint32_t* destination = cpu->get_register(registers[0]);
    for (int i = 1; i < registers.size(); i++)
    {
        *destination %= *cpu->get_register(registers[i]);
    }
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

    REGISTER_FUNCTION(instruction_type::ARITHMETIC_ADD, arithemtic_add);
    REGISTER_FUNCTION(instruction_type::ARITHMETIC_SUB, arithemtic_sub);
    REGISTER_FUNCTION(instruction_type::ARITHMETIC_MUL, arithemtic_mul);
    REGISTER_FUNCTION(instruction_type::ARITHMETIC_DIV, arithemtic_div);
    REGISTER_FUNCTION(instruction_type::ARITHMETIC_MOD, arithemtic_mod);
}

uint32_t* cpu::get_register(int index)
{
    index--;
    if (index < 0 || index >= m_register_count)
    {
        printf("Error: Register %i was not found!\n", index);
        return nullptr;
    }

    return &m_registers[index];
}

bool cpu::does_register_exist(int address)
{
    return get_register(address) != nullptr;
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
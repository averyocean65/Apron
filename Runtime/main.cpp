#include <iostream>
#include <apron/core/init.hpp>
#include <apron/instructions/instruction.hpp>
#include <apron/instructions/instruction_type.h>

using namespace apron::instructions;

int main(int argc, char** argv) {
    if (apron_shared_init() != APRON_SUCCESS)
    {
        std::cerr << "Failed to initialize Apron Shared library!\n";
        return 1;
    }
    
    instruction instructions[] = {
        // Write 0x12345678 to register 1
        instruction(instruction_type::MEMORY_WRITE, 0x1, 0x12345678),

        // Copy the data from register 1 into register 2
        instruction(instruction_type::MEMORY_COPY, 0x2, 0x1),

        // Multiply registers 2 and 1 together into register 3
        instruction(instruction_type::ARITHMETIC_MUL, 0x3, 0x00020001)
    };
}
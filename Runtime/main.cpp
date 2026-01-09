#include <iostream>

#include <apron/core/init.h>
#include <apron/instructions/instruction.hpp>
#include <apron/utils/splitter.hpp>

#include "devices/cpu.hpp"

using namespace apron::instructions;

int main(int argc, char** argv) {
    if (apron_shared_init() != APRON_SUCCESS)
    {
        std::cerr << "Failed to initialize Apron Shared library!\n";
        return 1;
    }

    cpu my_cpu = cpu(4);
    my_cpu.execute_instruction(instruction(instruction_type::MEMORY_MOVE, 0x0, 0x0));
}
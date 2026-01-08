#include <iostream>
#include <apron/core/init.hpp>

#include <apron/instructions/instruction.hpp>
#include <apron/instructions/instruction_type.h>

#include <apron/utils/splitter.h>

using namespace apron::instructions;

int main(int argc, char** argv) {
    if (apron_shared_init() != APRON_SUCCESS)
    {
        std::cerr << "Failed to initialize Apron Shared library!\n";
        return 1;
    }
    
    uint16_t baseA = 0x1234;
    uint32_t baseB = 0x12345678;
    
    uint8_t a = 0;
    uint8_t b = 0;
    uint8_t c = 0;
    uint8_t d = 0;

    apron::utils::split_u16(baseA, &a, &b);
    printf("uint16_t split: %02X, %02X\n", a, b);
    
    apron::utils::split_u32(baseB, &a, &b, &c, &d);
    printf("uint32_t split: %02X, %02X, %02X, %02X\n", a, b, c, d);
}
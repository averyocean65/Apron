#include "instruction.hpp"

using namespace apron::instructions;

APRON_API instruction::instruction(uint16_t pId, uint16_t pAdditional, uint32_t pData)
    : id(pId), additional(pAdditional), data(pData)
{ }

APRON_API instruction::instruction(instruction_type pId, uint16_t pAdditional, uint32_t pData)
    : additional(pAdditional), data(pData)
{
    id = static_cast<uint16_t>(pId);
}
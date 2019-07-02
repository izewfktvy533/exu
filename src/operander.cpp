#include <iostream>
#include "../include/operander.h"


std::uint8_t Operander::operand_imm8(Emulator* emulator) {
    return emulator->memory[emulator->registers[emulator->EIP]++];
}


std::uint32_t Operander::operand_imm32(Emulator* emulator) {
    uint32_t imm32 = 0;

    for(int i=0; i<4; i++) {
        imm32 |= operand_imm8(emulator) << (i * 8);
    }

    return imm32;
}


void Operander::operand(Emulator* emulator) {
    switch(emulator->opecode) {
        case 0xb8:
            std::uint8_t registerNumber = emulator->opecode - 0xb8;
            std::int32_t imm32 = operand_imm32(emulator);
            emulator->arg1 = registerNumber;
            emulator->arg2 = imm32;
            break;

    }

}
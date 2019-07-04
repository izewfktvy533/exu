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
        case 0x89:
            {   
            // mov_rm32_r32
            std::int32_t rm32;
            std::int32_t r32 = emulator->registers[emulator->modrm.reg];
            if(emulator->modrm.mod == 3) {
                rm32 = emulator->modrm.rm;
            }
            /* TODO 
            else{

            }
            */

            std::printf("%d %d \n", rm32, r32);

            emulator->operand[0] = rm32;
            emulator->operand[1] = r32;
            }
            break;
            
        
        case 0xb8:
            {
            std::uint8_t registerNumber = emulator->opecode - 0xb8;
            std::int32_t imm32 = operand_imm32(emulator);
            emulator->operand[0] = registerNumber;
            emulator->operand[1] = imm32;

            break;
            }

    }

}
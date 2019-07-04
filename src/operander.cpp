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


std::uint32_t Operander::calcMemoryAddress(Emulator* emulator) {
    std::uint8_t mod  = (emulator->instruction[emulator->MODRM] & 0xc0) >> 6;
    std::uint8_t reg  = (emulator->instruction[emulator->MODRM] & 0x38) >> 3;
    std::uint8_t rm   = (emulator->instruction[emulator->MODRM] & 0x07);
    std::uint8_t sib  = emulator->instruction[emulator->SIB];
    std::uint32_t disp = emulator->instruction[emulator->DISPLACEMENT];


    if (mod == 0) {
        if (rm == 4) {
            std::printf("error: function of calcMemoryAddress\n");
            std::printf("not implemented ModRM mod: %d, rm: %d\n", mod, rm);
            std::exit(1);
        }
        else if (rm == 5) {
            return disp;
        }
        else {
            return emulator->registers[rm];
        }
    }
    else if (mod == 1) {
        if (rm == 4) {
            std::printf("error: function of calcMemoryAddress\n");
            std::printf("not implemented ModRM mod: %d, rm: %d\n", mod, rm);
            std::exit(1);
        }
        else {
            return emulator->registers[rm] + disp;
        }
    }
    else if (mod == 2) {
        if (rm == 4) {
            std::printf("error: function of calcMemoryAddress\n");
            std::printf("not implemented ModRM mod: %d, rm: %d\n", mod, rm);
            std::exit(1);
        }
        else {
            return emulator->registers[rm] + disp;
        }
    }
    else {
        std::printf("error: function of calcMemoryAddress\n");printf("error: function of calc_memory_address\n");
        std::printf("not implemented ModRM mod: %d, rm: %d\n", mod, rm);
        std::exit(1);
    }
}




void Operander::operand(Emulator* emulator) {
    switch(emulator->head) {
        case 0x89:
            /* 
             * mov_rm32_r32
             */
            {
            std::uint8_t mod = (emulator->instruction[emulator->MODRM] & 0xc0) >> 6;
            std::uint8_t reg = (emulator->instruction[emulator->MODRM] & 0x38) >> 3;
            std::uint8_t rm  = (emulator->instruction[emulator->MODRM] & 0x07);
            std::int32_t rm32;
            std::int32_t r32 = reg;

            if(mod == 3) {
                rm32 = rm;
            }
            else{
                rm32 = calcMemoryAddress(emulator);
            }

            emulator->operand[0] = rm32;
            emulator->operand[1] = emulator->registers[r32];
            }

            break;
        
        
        case 0xb8:
            /*
             * mov r32 imm32
             */
            {
            emulator->operand[0] = emulator->head - 0xb8;
            emulator->operand[1] = emulator->instruction[emulator->IMMEDIATE];
            }

            break;
        

        case 0xb9:
            /*
             * mov r32 imm32
             */
            {
            emulator->operand[0] = emulator->head - 0xb8;
            emulator->operand[1] = emulator->instruction[emulator->IMMEDIATE];
            }

            break;

    }

}
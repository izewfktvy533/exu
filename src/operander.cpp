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
    std::uint8_t  mod  = (emulator->instruction[emulator->MODRM] & 0xc0) >> 6;
    std::uint8_t  reg  = (emulator->instruction[emulator->MODRM] & 0x38) >> 3;
    std::uint8_t  rm   = (emulator->instruction[emulator->MODRM] & 0x07);
    std::uint8_t  sib  = emulator->instruction[emulator->SIB];


    if (mod == 0) {
        if (rm == 4) {
            std::printf("error: function of calcMemoryAddress\n");
            std::printf("not implemented ModRM mod: %d, rm: %d\n", mod, rm);
            std::exit(1);
        }
        else if (rm == 5) {
            return emulator->instruction[emulator->DISP32];
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
            std::uint8_t disp8 = emulator->instruction[emulator->DISP8];
            return emulator->registers[rm] + disp8;
        }
    }
    else if (mod == 2) {
        if (rm == 4) {
            std::printf("error: function of calcMemoryAddress\n");
            std::printf("not implemented ModRM mod: %d, rm: %d\n", mod, rm);
            std::exit(1);
        }
        else {
            std::uint32_t disp32 = emulator->instruction[emulator->DISP32];
            return emulator->registers[rm] + disp32;
        }
    }
    else {
        std::printf("error: function of calcMemoryAddress\n");printf("error: function of calc_memory_address\n");
        std::printf("not implemented ModRM mod: %d, rm: %d\n", mod, rm);
        std::exit(1);
    }

}




void Operander::operand(Emulator* emulator) {
    std::uint8_t mod;
    std::uint8_t reg;
    std::uint8_t rm;
    std::int8_t  rm8;
    std::int32_t rm32;
    std::int8_t  r8;
    std::int32_t r32;

    switch(emulator->head) {
        case 0x50:
        case 0x51:
        case 0x52:
        case 0x53:
        case 0x54:
        case 0x55:
        case 0x56:
        case 0x57:
            /*
             * push r32
             */
            emulator->registers[emulator->ESP] = emulator->registers[emulator->ESP] - 4;
            emulator->operand[0] = (std::uint32_t*)&(emulator->memory[emulator->registers[emulator->ESP]]);
            emulator->operand[1] = (std::uint32_t*)&(emulator->registers[emulator->instruction[emulator->OPECODE] - 0x50]);
            break;


        case 0x58:
        case 0x59:
        case 0x5a:
        case 0x5b:
        case 0x5c:
        case 0x5d:
        case 0x5e:
        case 0x5f:
            /*
             * pop r32
             */
            emulator->operand[0] = (std::uint32_t*)&(emulator->registers[emulator->instruction[emulator->OPECODE] - 0x58]);
            emulator->operand[1] = (std::uint32_t*)&(emulator->memory[emulator->registers[emulator->ESP]]);
            emulator->registers[emulator->ESP] = emulator->registers[emulator->ESP] + 4;
            break;



        case 0x88:
            /* 
             * mov rm8 r8
             */
            mod = (emulator->instruction[emulator->MODRM] & 0xc0) >> 6;
            reg = (emulator->instruction[emulator->MODRM] & 0x38) >> 3;
            rm  = (emulator->instruction[emulator->MODRM] & 0x07);
            r8 = (std::int8_t)reg;

            if(mod == 3) {
                rm8 = rm;
                emulator->operand[0] = (std::uint32_t*)(&(emulator->registers[rm8]));
            }
            else{
                rm8 = calcMemoryAddress(emulator);
                std::printf("memory address: 0x%x\n", rm8);
                emulator->operand[0] = (std::uint32_t*)(&(emulator->memory[rm8]));
            }
            
            emulator->operand[1] = (std::uint32_t*)(&(emulator->registers[r8]));

            break;


        case 0x89:
            /* 
             * mov rm32 r32
             */
            mod = (emulator->instruction[emulator->MODRM] & 0xc0) >> 6;
            reg = (emulator->instruction[emulator->MODRM] & 0x38) >> 3;
            rm  = (emulator->instruction[emulator->MODRM] & 0x07);
            r32 = reg;

            if(mod == 3) {
                rm32 = rm;
                emulator->operand[0] = (std::uint32_t*)(&(emulator->registers[rm32]));
            }
            else{
                rm32 = calcMemoryAddress(emulator);
                std::printf("memory address: 0x%x\n", rm32);
                emulator->operand[0] = (std::uint32_t*)(&(emulator->memory[rm32]));
            }

            emulator->operand[1] = (std::uint32_t*)(&(emulator->registers[r32]));

            break;
        
        
        case 0xb8:
        case 0xb9:
        case 0xba:
        case 0xbb:
        case 0xbc:
        case 0xbd:
        case 0xbe:
        case 0xbf:
            /*
             * mov r32 imm32
             */
            emulator->operand[0] = (std::uint32_t*)(&(emulator->registers[emulator->instruction[emulator->OPECODE] - 0xb8]));
            emulator->operand[1] = (std::uint32_t*)(&(emulator->instruction[emulator->IMM32]));

            break;
       

        case 0xc3:
            /*
             * ret
             */
            emulator->operand[0] = (std::uint32_t*)&(emulator->registers[emulator->EIP]);
            emulator->operand[1] = (std::uint32_t*)&(emulator->memory[emulator->registers[emulator->ESP]]);
            emulator->registers[emulator->ESP] = emulator->registers[emulator->ESP] + 4;

            for(int i=0; i < 4; i++) {
                ((std::uint8_t*)emulator->operand[0])[i] = ((std::uint8_t*)emulator->operand[1])[i];
            }
            
            break;
        

        case 0xc9:
            /*
             * leave
             */
            emulator->registers[emulator->ESP] = emulator->registers[emulator->EBP];
            emulator->operand[0] = (std::uint32_t*)&(emulator->registers[emulator->EBP]);
            emulator->operand[1] = (std::uint32_t*)&(emulator->memory[emulator->registers[emulator->ESP]]);
            emulator->registers[emulator->ESP] = emulator->registers[emulator->ESP] + 4;

            for(int i=0; i < 4; i++) {
                ((std::uint8_t*)emulator->operand[0])[i] = ((std::uint8_t*)emulator->operand[1])[i];
            }

            break;


        case 0xe8:
            /*
             * call imm32
             */
            emulator->registers[emulator->ESP] = emulator->registers[emulator->ESP] - 4;
            emulator->operand[0] = (std::uint32_t*)&(emulator->memory[emulator->registers[emulator->ESP]]);
            emulator->operand[1] = (std::uint32_t*)&(emulator->registers[emulator->EIP]);

            for(int i=0; i < 4; i++) {
                ((std::uint8_t*)emulator->operand[0])[i] = (*(emulator->operand[1]) >> (i * 8)) & 0xff;
            }
            
            emulator->registers[emulator->EIP] = (std::uint32_t)emulator->registers[emulator->EIP] + (std::int32_t)emulator->instruction[emulator->IMM32];
            
            break;
           
                
        case 0xe9:
            /*
             * jmp rel16
             * jmp rel32
             */
             emulator->operand[0] = (std::uint32_t*)(&(emulator->registers[emulator->EIP]));
             emulator->operand[1] = (std::uint32_t*)(&(emulator->instruction[emulator->REL32]));

             break;


        case 0xeb:
            /*
             * jmp rel8
             */
            emulator->operand[0] = (std::uint32_t*)(&(emulator->registers[emulator->EIP]));
            emulator->operand[1] = (std::uint32_t*)(&(emulator->instruction[emulator->REL8]));

            break;
    }

}

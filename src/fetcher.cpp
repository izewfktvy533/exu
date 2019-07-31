#include <iostream>
#include <cstring>

#include "../include/fetcher.h"


void Fetcher::fetch(Emulator* emulator) {
    emulator->head = emulator->memory[emulator->registers[emulator->EIP]++];
    memset(emulator->instruction, 0, sizeof(emulator->instruction)*emulator->OFFSETS_COUNT);
   std::uint8_t mod;
    std::uint8_t opecode, reg;
    std::uint8_t rm;


    switch(emulator->head) {
        case  0x01:
            /*
             * add rm32, r32
             */
        case 0x03:
            /*
             * add r32, rm32
             */
            emulator->instruction[emulator->OPECODE] = emulator->head;
            emulator->instruction[emulator->MODRM] = emulator->memory[emulator->registers[emulator->EIP]++];

            mod     = (emulator->instruction[emulator->MODRM] & 0xc0) >> 6;
            opecode = (emulator->instruction[emulator->MODRM] & 0x38) >> 3;
            rm      = (emulator->instruction[emulator->MODRM] & 0x07);

            if(mod != 3 && rm == 4) {
                emulator->instruction[emulator->SIB] = emulator->memory[emulator->registers[emulator->EIP]++];
            }
            if((mod == 0 && rm == 5) || mod == 2) {
                for(int i=0; i<4; i++) {
                    emulator->instruction[emulator->DISP32] |= emulator->memory[emulator->registers[emulator->EIP]++] << (i * 8);
                }
            }
            else if(mod == 1) {
                emulator->instruction[emulator->DISP8] = emulator->memory[emulator->registers[emulator->EIP]++];
            }

            break;
        

        case 0x29:
            /*
             * sub rm32, r32
             */
        case 0x2b:
            /*
             * sub r32, rm32
             */
            emulator->instruction[emulator->OPECODE] = emulator->head;
            emulator->instruction[emulator->MODRM] = emulator->memory[emulator->registers[emulator->EIP]++];

            mod     = (emulator->instruction[emulator->MODRM] & 0xc0) >> 6;
            opecode = (emulator->instruction[emulator->MODRM] & 0x38) >> 3;
            rm      = (emulator->instruction[emulator->MODRM] & 0x07);

            if(mod != 3 && rm == 4) {
                emulator->instruction[emulator->SIB] = emulator->memory[emulator->registers[emulator->EIP]++];
            }
            if((mod == 0 && rm == 5) || mod == 2) {
                for(int i=0; i<4; i++) {
                    emulator->instruction[emulator->DISP32] |= emulator->memory[emulator->registers[emulator->EIP]++] << (i * 8);
                }
            }
            else if(mod == 1) {
                emulator->instruction[emulator->DISP8] = emulator->memory[emulator->registers[emulator->EIP]++];
            }

            break;


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
            emulator->instruction[emulator->OPECODE] = emulator->head;
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
            emulator->instruction[emulator->OPECODE] = emulator->head;
            break;


        case 0x81:
            /*
             * add rm32, imm8
             */
            emulator->instruction[emulator->OPECODE] = emulator->head;
            emulator->instruction[emulator->MODRM] = emulator->memory[emulator->registers[emulator->EIP]++];
            
            mod = (emulator->instruction[emulator->MODRM] & 0xc0) >> 6;
            reg = (emulator->instruction[emulator->MODRM] & 0x38) >> 3;
            rm  = (emulator->instruction[emulator->MODRM] & 0x07);

            if(mod == 1) {
                emulator->instruction[emulator->DISP8] = emulator->memory[emulator->registers[emulator->EIP]++];
            }
            else if((mod == 0 && rm == 5) || mod == 2) {
                for(int i=0; i<4; i++) {
                    emulator->instruction[emulator->DISP32] |= emulator->memory[emulator->registers[emulator->EIP]++] << (i * 8);
                }
            }

            for(int i=0; i<4; i++) {
                emulator->instruction[emulator->IMM32] |= emulator->memory[emulator->registers[emulator->EIP]++] << (i * 8);
            }
            break;


        case 0x83:
            /*
             * add rm16, imm8
             * add rm32, imm8
             * sub rm16, imm8
             * sub rm32, imm8
             */
            emulator->instruction[emulator->OPECODE] = emulator->head;
            emulator->instruction[emulator->MODRM] = emulator->memory[emulator->registers[emulator->EIP]++];
            
            mod = (emulator->instruction[emulator->MODRM] & 0xc0) >> 6;
            reg = (emulator->instruction[emulator->MODRM] & 0x38) >> 3;
            rm  = (emulator->instruction[emulator->MODRM] & 0x07);

            if(mod == 1) {
                emulator->instruction[emulator->DISP8] = emulator->memory[emulator->registers[emulator->EIP]++];
            }
            else if((mod == 0 && rm == 5) || mod == 2) {
                for(int i=0; i<4; i++) {
                    emulator->instruction[emulator->DISP32] |= emulator->memory[emulator->registers[emulator->EIP]++] << (i * 8);
                }
            }

            emulator->instruction[emulator->IMM8] = emulator->memory[emulator->registers[emulator->EIP]++];
            break;


        case 0x88: 
            /*
             * mov rm8, r8
             */
        case 0x89:
            /*
             * mov rm32, r32
             */
        case 0x8a:
            /*
             * mov r8, rm8
             */
        case 0x8b:
            /*
             * mov r32, rm32
             */
            emulator->instruction[emulator->OPECODE] = emulator->head;
            emulator->instruction[emulator->MODRM] = emulator->memory[emulator->registers[emulator->EIP]++];

            mod     = (emulator->instruction[emulator->MODRM] & 0xc0) >> 6;
            opecode = (emulator->instruction[emulator->MODRM] & 0x38) >> 3;
            rm      = (emulator->instruction[emulator->MODRM] & 0x07);

            if(mod != 3 && rm == 4) {
                emulator->instruction[emulator->SIB] = emulator->memory[emulator->registers[emulator->EIP]++];
            }
            if((mod == 0 && rm == 5) || mod == 2) {
                for(int i=0; i<4; i++) {
                    emulator->instruction[emulator->DISP32] |= emulator->memory[emulator->registers[emulator->EIP]++] << (i * 8);
                }
            }
            else if(mod == 1) {
                emulator->instruction[emulator->DISP8] = emulator->memory[emulator->registers[emulator->EIP]++];
            }

            break;
        
        
        case 0xb0:
        case 0xb1:
        case 0xb2:
        case 0xb3:
        case 0xb4:
        case 0xb5:
        case 0xb6:
        case 0xb7:
            /*
             * mov r8, imm8
             */
            emulator->instruction[emulator->OPECODE] = emulator->head;
            emulator->instruction[emulator->IMM8] |= emulator->memory[emulator->registers[emulator->EIP]++];

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
             * mov r32, imm32
             */
            emulator->instruction[emulator->OPECODE] = emulator->head;

            for(int i=0; i<4; i++) {
                emulator->instruction[emulator->IMM32] |= emulator->memory[emulator->registers[emulator->EIP]++] << (i * 8);
            }

            break;
        

        case 0xc3:
            /*
             * ret
             */
            emulator->instruction[emulator->OPECODE] = emulator->head;
            break;


        case 0xc6:
            /*
             * mov rm8, imm8
             */
            emulator->instruction[emulator->OPECODE] = emulator->head;
            emulator->instruction[emulator->MODRM] = emulator->memory[emulator->registers[emulator->EIP]++];
            
            mod = (emulator->instruction[emulator->MODRM] & 0xc0) >> 6;
            reg = (emulator->instruction[emulator->MODRM] & 0x38) >> 3;
            rm  = (emulator->instruction[emulator->MODRM] & 0x07);

            if(mod == 1) {
                emulator->instruction[emulator->DISP8] = emulator->memory[emulator->registers[emulator->EIP]++];
            }
            else if(mod == 2) {
                for(int i=0; i<4; i++) {
                    emulator->instruction[emulator->DISP32] |= emulator->memory[emulator->registers[emulator->EIP]++] << (i * 8);
                }
            }

            emulator->instruction[emulator->IMM8] = emulator->memory[emulator->registers[emulator->EIP]++];
            break;
        

        case 0xc7:
            /*
             * mov rm32, imm32
             */
            emulator->instruction[emulator->OPECODE] = emulator->head;
            emulator->instruction[emulator->MODRM] = emulator->memory[emulator->registers[emulator->EIP]++];
            
            mod = (emulator->instruction[emulator->MODRM] & 0xc0) >> 6;
            reg = (emulator->instruction[emulator->MODRM] & 0x38) >> 3;
            rm  = (emulator->instruction[emulator->MODRM] & 0x07);

            if(mod == 1) {
                emulator->instruction[emulator->DISP8] = emulator->memory[emulator->registers[emulator->EIP]++];
            }
            else if((mod == 0 && rm == 5) || mod == 2) {
                for(int i=0; i<4; i++) {
                    emulator->instruction[emulator->DISP32] |= emulator->memory[emulator->registers[emulator->EIP]++] << (i * 8);
                }
            }

            for(int i=0; i<4; i++) {
                emulator->instruction[emulator->IMM32] |= emulator->memory[emulator->registers[emulator->EIP]++] << (i * 8);
            }

            break;


        case 0xc9:
            /*
             * leave
             */
            emulator->instruction[emulator->OPECODE] = emulator->head;
            break;
                    

        case 0xe8:
            /*
             * call imm32
             */
            emulator->instruction[emulator->OPECODE] = emulator->head;

            for(int i=0; i<4; i++) {
                emulator->instruction[emulator->IMM32] |= emulator->memory[emulator->registers[emulator->EIP]++] << (i * 8);
            }

            break;


        case 0xe9:
            /*
             * jmp rel32
             */
            emulator->instruction[emulator->OPECODE] = emulator->head;
            
            for(int i=0; i<4; i++) {
                emulator->instruction[emulator->REL32] |= emulator->memory[emulator->registers[emulator->EIP]++] << (i * 8);
            }
            
            break;

        
        case 0xeb:
            /*
             * jmp rel8
             */
            emulator->instruction[emulator->OPECODE] = emulator->head;
            emulator->instruction[emulator->REL8] = emulator->memory[emulator->registers[emulator->EIP]++];
            
            break;

    }
}

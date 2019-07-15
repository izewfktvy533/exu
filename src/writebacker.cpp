#include <iostream>

#include "../include/writebacker.h"


void Writebacker::writeback(Emulator* emulator) {
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
            for(int i=0; i < 4; i++) {
                ((std::uint8_t*)emulator->operand[0])[i] = (*(emulator->operand[1]) >> (i * 8)) & 0xff;
            }
            
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
            for(int i=0; i < 4; i++) {
                ((std::uint8_t*)emulator->operand[0])[i] = ((std::uint8_t*)emulator->operand[1])[i];
            }

            break;


        case 0x88:
            /*
             * mov rm8, r8
             */
            *(emulator->operand[0]) = (std::uint8_t)(*(emulator->operand[1]));
            break;


        case 0x89:
            /*
             * mov rm32, r32
             */
            *(emulator->operand[0]) = (std::uint32_t)(*(emulator->operand[1]));
            break;

        
        case 0x8a:
            /*
             * mov r8, rm8
             */
            *(emulator->operand[0]) = (std::uint8_t)(*(emulator->operand[1]));
            break;


        case 0x8b:
            /*
             * mov r32, rm32
             */
            *(emulator->operand[0]) = (std::uint8_t)(*(emulator->operand[1]));
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
            *(emulator->operand[0]) = (std::int32_t)(*(emulator->operand[1]));
            break;

        
        case 0xc6:
            /*
             * mov rm8, imm8
             */
            *(emulator->operand[0]) = (std::int32_t)(*(emulator->operand[1]));
            break;


        case 0xeb:
            /*
             * jmp rel8
             */
            *(emulator->operand[0]) = (std::uint8_t)((*(emulator->operand[0])) + (*((std::int32_t*)(emulator->operand[1]))));
            break;

    }

}

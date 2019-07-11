#include <iostream>

#include "../include/writebacker.h"


void Writebacker::writeback(Emulator* emulator) {
    switch(emulator->head) {
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

        case 0xe9:
            /*
             * jmp rel32
             */
            *(emulator->operand[0]) = (std::uint32_t)((*(emulator->operand[0])) + (*((std::int32_t*)(emulator->operand[1]))));
            break;

        case 0xeb:
            /*
             * jmp rel8
             */
            *(emulator->operand[0]) = (std::uint8_t)((*(emulator->operand[0])) + (*((std::int32_t*)(emulator->operand[1]))));
            break;

    }

}

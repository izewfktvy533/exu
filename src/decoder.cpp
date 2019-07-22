#include <iostream>

#include "../include/decoder.h"


int Decoder::decode(Emulator* emulator) {
    switch(emulator->head) {
        case 0x01:
            /*
             * add rm32, r32
             */

        case 0x03:
            /*
             * add r32, rm32
             */

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

        case 0xc3:
            /*
             * ret
             */

        case 0xc6:
            /*
             * mov rm8, imm8
             */

        case 0xc7:
            /*
             * mov rm32, imm32
             */

        case 0xc9:
            /*
             * leave
             */

        case 0xe8:
            /*
             * call imm32
             */

        case 0xe9:
            /*
             * jmp rel32
             */

        case 0xeb:
            /*
             * jmp rel8
             */

            return 0;

        default:
            return -1;
    }

}

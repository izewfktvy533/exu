#include <iostream>

#include "../include/writebacker.h"


void Writebacker::writeback(Emulator* emulator) {
    switch(emulator->head) {
        case 0x89:
            *(emulator->operand[0]) = *(emulator->operand[1]);
            break;

        case 0xb8:
        case 0xb9:
        case 0xba:
        case 0xbb:
        case 0xbc:
        case 0xbd:
        case 0xbe:
        case 0xbf:
            *(emulator->operand[0]) = *(emulator->operand[1]);
            break;

        case 0xe9:
            *(emulator->operand[0]) += *((std::int32_t*)(emulator->operand[1]));
            break;
    }

}

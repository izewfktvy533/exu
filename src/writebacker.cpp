#include <iostream>

#include "../include/writebacker.h"


void Writebacker::writeback(Emulator* emulator) {
    switch(emulator->head) {
        case 0x89:
            *(emulator->operand[0]) = *(emulator->operand[1]);
            break;

        case 0xb8:
            *(emulator->operand[0]) = *(emulator->operand[1]);
            break;

        case 0xb9:
            *(emulator->operand[0]) = *(emulator->operand[1]);
            break;
    }

}
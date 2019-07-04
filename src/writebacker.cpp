#include <iostream>

#include "../include/writebacker.h"


void Writebacker::writeback(Emulator* emulator) {
    switch(emulator->head) {
        case 0x89:
            {
            /* TODO: Need to change this function because it cannot work pipe line process */
            std::uint8_t mod = (emulator->instruction[emulator->MODRM] & 0xc0) >> 6;

            if(mod == 3) {
                emulator->registers[emulator->operand[0]] = emulator->operand[1];
            }
            else{
                emulator->memory[emulator->operand[0]] = emulator->operand[1];
            }
            }

            break;

        case 0xb8:
            {
            emulator->registers[emulator->operand[0]] = emulator->operand[1];
            }

            break;

        case 0xb9:
            {
            emulator->registers[emulator->operand[0]] = emulator->operand[1];
            }
            break;
    }

}

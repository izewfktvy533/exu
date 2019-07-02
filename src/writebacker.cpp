#include <iostream>
#include "../include/writebacker.h"


void Writebacker::writeback(Emulator* emulator) {
    switch(emulator->opecode) {
        case 0xb8:
            emulator->registers[emulator->arg1] = emulator->arg2;
            break;
    }
    
}

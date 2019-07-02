#include <iostream>
#include "../include/decoder.h"


int Decoder::decode(Emulator* emulator) {
    switch(emulator->opecode) {
        case 0xb8:
            return 0;

        default:
            return -1;
    }
    
}
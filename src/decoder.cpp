#include <iostream>

#include "../include/decoder.h"


int Decoder::decode(Emulator* emulator) {
    switch(emulator->head) {
        case 0x89:
            return 0;

        case 0xb8:
            return 0;
        
        case 0xb9:
            return 0;

        default:
            return -1;
    }

}
#include <iostream>

#include "../include/executer.h"


void Executer::execute(Emulator* emulator) {
    switch(emulator->head) {
        case 0x88:
        case 0x89:
        case 0xb8:
        case 0xb9:
        case 0xba:
        case 0xbb:
        case 0xbc:
        case 0xbd:
        case 0xbe:
        case 0xbf:
        case 0xe9:
        case 0xeb:
            break;
        
    }

}

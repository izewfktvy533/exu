#include <iostream>

#include "../include/executer.h"


void Executer::execute(Emulator* emulator) {
    switch(emulator->head) {
        case 0x01:
            /*
             * add rm32, r32
             */

        case 0x03:
            /*
             * add r32, rm32
             */
            emulator->executedResult = *(emulator->operand[1]) + *(emulator->operand[0]);
            break;
            
        defualt:
            break;
        
    }

}

#include <iostream>
#include <cstring>

#include "../include/fetcher.h"


void Fetcher::fetch(Emulator* emulator) {
    emulator->head = emulator->memory[emulator->registers[emulator->EIP]++];
    memset(emulator->instruction, 0, sizeof(emulator->instruction)*emulator->OFFSETS_COUNT);

    switch(emulator->head) {
        case 0x50:
        case 0x51:
        case 0x52:
        case 0x53:
        case 0x54:
        case 0x55:
        case 0x56:
        case 0x57:
            emulator->instruction[emulator->OPECODE] = emulator->head;
            break;


        case 0x58:
        case 0x59:
        case 0x5a:
        case 0x5b:
        case 0x5c:
        case 0x5d:
        case 0x5e:
        case 0x5f:
            emulator->instruction[emulator->OPECODE] = emulator->head;
            break;


        case 0x88:
        case 0x89:
            {
            emulator->instruction[emulator->OPECODE] = emulator->head;
            emulator->instruction[emulator->MODRM] = emulator->memory[emulator->registers[emulator->EIP]++];

            std::uint8_t mod     = (emulator->instruction[emulator->MODRM] & 0xc0) >> 6;
            std::uint8_t opecode = (emulator->instruction[emulator->MODRM] & 0x38) >> 3;
            std::uint8_t rm      = (emulator->instruction[emulator->MODRM] & 0x07);

            if(mod != 3 && rm == 4) {
                emulator->instruction[emulator->SIB] = emulator->memory[emulator->registers[emulator->EIP]++];
            }

            if((mod == 0 && rm == 5) || mod == 2) {
                for(int i=0; i<4; i++) {
                    emulator->instruction[emulator->DISP32] |= emulator->memory[emulator->registers[emulator->EIP]++] << (i * 8);
                }
            }
            else if(mod == 1) {
                emulator->instruction[emulator->DISP8] = emulator->memory[emulator->registers[emulator->EIP]++];
            }
            }

            break;
        

        case 0xb8:
        case 0xb9:
        case 0xba:
        case 0xbb:
        case 0xbc:
        case 0xbd:
        case 0xbe:
        case 0xbf:
            emulator->instruction[emulator->OPECODE] = emulator->head;

            for(int i=0; i<4; i++) {
                emulator->instruction[emulator->IMM32] |= emulator->memory[emulator->registers[emulator->EIP]++] << (i * 8);
            }

            break;


        case 0xe9:
            emulator->instruction[emulator->OPECODE] = emulator->head;
            
            for(int i=0; i<4; i++) {
                emulator->instruction[emulator->REL32] |= emulator->memory[emulator->registers[emulator->EIP]++] << (i * 8);
            }
            
            break;

        
        case 0xeb:
            emulator->instruction[emulator->OPECODE] = emulator->head;
            emulator->instruction[emulator->REL8] = emulator->memory[emulator->registers[emulator->EIP]++];
            
            break;

    }
}

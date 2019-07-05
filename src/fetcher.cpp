#include <iostream>
#include <cstring>

#include "../include/fetcher.h"


void Fetcher::fetch(Emulator* emulator) {
    emulator->head = emulator->memory[emulator->registers[emulator->EIP]++];
    memset(emulator->instruction, 0, sizeof(emulator->instruction));

    switch(emulator->head) {
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
                    emulator->instruction[emulator->DISPLACEMENT] |= emulator->memory[emulator->registers[emulator->EIP]++] << (i * 8);
                }
            }
            else if(mod == 1) {
                emulator->instruction[emulator->DISPLACEMENT] = emulator->memory[emulator->registers[emulator->EIP]++];
            }
            }
            break;
        

        case 0xb8:
            emulator->instruction[emulator->OPECODE] = emulator->head;

            for(int i=0; i<4; i++) {
                emulator->instruction[emulator->IMMEDIATE] |= emulator->memory[emulator->registers[emulator->EIP]++] << (i * 8);
            }

            break;

        
        case 0xb9:
            emulator->instruction[emulator->OPECODE] = emulator->head;

            for(int i=0; i<4; i++) {
                emulator->instruction[emulator->IMMEDIATE] |= emulator->memory[emulator->registers[emulator->EIP]++] << (i * 8);
            }

            break;

    }
}
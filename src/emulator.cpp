#include <iostream>
#include <cstring>

#include "../include/emulator.h"


void Emulator::init(FILE* fp) {
    memory = new uint8_t[MEMORY_SIZE_BYTE];
    memset(memory, 0, sizeof(memory));
    memset(registers, 0, sizeof(registers));
    std::fread(memory, 1, MEMORY_SIZE_BYTE, fp);
}


void Emulator::destroy() {
    delete memory;
}


void Emulator::dump() {
}


void Emulator::dumpOperand() {
}


void Emulator::dumpRegisters() {
}


void Emulator::dumpMemory() {
    for(int i=0; i<MEMORY_SIZE_BYTE/2; i+=2) {
        if(!(i==0) && !(i % 16)) {
            std::printf("\n");
        }
        if(!(i % 16)) {
            std::printf("%07x ", i);
        }
        std::printf("%02x%02x ", memory[i+1], memory[i]);
    }
    std::printf("\n");
}

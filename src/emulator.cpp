#include <iostream>
#include <cstring>

#include "../include/emulator.h"


void Emulator::init(FILE* fp) {
    memory = new uint8_t[MEMORY_SIZE_BYTE];
    
    memset(memory, 0, sizeof(memory));
    memset(registers, 0, sizeof(registers));
    memset(&head, 0, sizeof(head));
    memset(operand, 0, sizeof(operand));
    memset(instruction, 0 ,sizeof(instruction));

    registers[EIP] = INITIAL_EIP_ENTRY_POINT;
    registers[ESP] = INITIAL_ESP_ENTRY_POINT;
    
    std::fread(&memory[INITIAL_EIP_ENTRY_POINT], 1, MEMORY_SIZE_BYTE, fp);
}


void Emulator::destroy() {
    delete memory;
}


void Emulator::dumpOpecode() {
    std::printf("opecode: 0x%02x\n\n", head);
}


void Emulator::dumpRegisters() {
    std::printf("[Registers]\n");
    std::printf("EAX: 0x%x\n", registers[EAX]);
    std::printf("ECX: 0x%x\n", registers[ECX]);
    std::printf("EDX: 0x%x\n", registers[EDX]);
    std::printf("EBX: 0x%x\n", registers[EBX]);
    std::printf("ESP: 0x%x\n", registers[ESP]);
    std::printf("EBP: 0x%x\n", registers[EBP]);
    std::printf("ESI: 0x%x\n", registers[ESI]);
    std::printf("EDI: 0x%x\n", registers[EDI]);
    std::printf("EIP: 0x%x\n", registers[EIP]);
    std::printf("\n");
}


void Emulator::dumpMemory() {
    std::printf("[Memory]\n");

    //for(int i=INITIAL_EIP_ENTRY_POINT; i<MEMORY_SIZE_BYTE/2; i+=2) {
    for(int i=INITIAL_EIP_ENTRY_POINT; i<INITIAL_EIP_ENTRY_POINT + 16*9; i+=2) {
        if(!(i==INITIAL_EIP_ENTRY_POINT) && !(i % 16)) {
            std::printf("\n");
        }
        if(!(i % 16)) {
            std::printf("%07x ", i);
        }
        std::printf("%02x%02x ", memory[i+1], memory[i]);
    }
    std::printf("\n");
}


void Emulator::dump() {
    dumpOpecode();
    dumpRegisters();
    dumpMemory();
    std::cout << std::endl;
}

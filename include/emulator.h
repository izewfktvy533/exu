#ifndef _EMULATOR_H_
#define _EMULATOR_H_

#include "modrm.h"
#include "sib.h"
#include "disp.h"


class Emulator {
    public:
        const int MEMORY_SIZE_BYTE = 512 * 1024;
        //const std::uint32_t INITIAL_ESP_ENTRY_POINT = 0x7c00;
        const std::uint32_t INITIAL_ESP_ENTRY_POINT = 0x00;
        //const std::uint32_t INITIAL_EIP_ENTRY_POINT = 0x7c00;
        const std::uint32_t INITIAL_EIP_ENTRY_POINT = 0x00;
        
        enum Registers {
            EAX,
            ECX,
            EDX,
            EBX,
            ESP,
            EBP,
            ESI,
            EDI,
            EIP,
            REGISTERS_COUNT
        };

        enum Offsets{
            PREFIX,
            OPECODE,
            MODRM,
            SIB,
            DISP8,
            DISP32,
            IMME8,
            IMM32,
            REL8,
            REL32,
            OFFSETS_COUNT
        };

        std::uint32_t  registers[REGISTERS_COUNT];
        std::uint8_t*  memory;
        std::uint8_t   head;
        std::uint32_t* operand[2];
        std::uint32_t  instruction[OFFSETS_COUNT];

        void init(FILE*);
        void destroy();
        void dump();
        void dumpRegisters();
        void dumpMemory();
        void dumpOpecode();

};


#endif 

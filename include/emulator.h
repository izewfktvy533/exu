#ifndef _EMULATOR_H_
#define _EMULATOR_H_

#include "modrm.h"
#include "sib.h"
#include "disp.h"


class Emulator {
    public:    
        void init(FILE*);
        void destroy();
        void dump();
        void dumpRegisters();
        void dumpMemory();
        void dumpOpecode();

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
        std::uint32_t registers[REGISTERS_COUNT];
        std::uint8_t* memory;
        std::uint8_t  opecode;
        ModRM modrm;
        SIB   sib;
        DISP  disp;
        int operand[2];

        void parseModRM();
    
    private:
        const int MEMORY_SIZE_BYTE = 512;
        
};


#endif 
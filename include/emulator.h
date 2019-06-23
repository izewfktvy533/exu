#ifndef _EMULATOR_H_
#define _EMULATOR_H_


class Emulator {
    public:    
        void init(FILE*);
        void destroy();
        void dump();
        void dumpRegisters();
        void dumpMemory();
        void dumpOpecode();

    private:
        const int MEMORY_SIZE_BYTE = 512;
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
        std::uint32_t    registers[REGISTERS_COUNT];
        std::uint8_t*    memory;
        std::uint8_t     opecode;
};


#endif 

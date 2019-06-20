#ifndef _EMULATOR_H_
#define _EMULATOR_H_

//#include "fetcher.h"
//#include "decoder.h"
//#include "operander.h"
//#include "excuter.h"
//#include "writebacker.h"


class Emulator {
    public:    
        int  init();
        int  fetch();
        int  decode();
        int  operand();
        int  execute();
        int  writeback();
        int  destory();
        void dump();
        void dumpRegisters();
        void dumpMemory();
        void dumpOpecode();

    private:
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
        //Fetcher     fetcher;
        //Decoder     decoder;
        //Operander   operander;
        //Executer    executer;
        //Writebacker writebacker;
};


#endif _EMULATOR_H_

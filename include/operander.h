#ifndef _OPERANDER_H_
#define _OPERANDER_H_

#include "emulator.h"


class Operander {
    public:
        void operand(Emulator*);

    private:
        std::uint8_t  operand_imm8(Emulator*);
        std::uint32_t operand_imm32(Emulator*);
        std::uint32_t calcMemoryAddress(Emulator*);

};


#endif
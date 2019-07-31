#include <iostream>

#include "../include/executer.h"


void Executer::execute(Emulator* emulator) {
    std::uint8_t reg;


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


        case 0x29:
            /*
             * sub rm32, r32
             */
        
        case 0x2b:
            /*
             * sub r32, rm32
             */
            emulator->executedResult = *(emulator->operand[0]) + *(emulator->operand[1]);
            break;

        
        case 0x81:
            reg = (emulator->instruction[emulator->MODRM] & 0x38) >> 3;
            
            switch(reg) {
                case 0:
                    /*
                     * add rm32, imm8
                     */
                    emulator->executedResult = *(emulator->operand[0]) + *(emulator->operand[1]);

                    std::printf("operand0: 0x%x\n", *emulator->operand[0]);
                    std::printf("operand1: 0x%x\n", *emulator->operand[1]);
                    std::printf("executed: 0x%x\n", emulator->executedResult);
                    break;
            }
            break;


        case 0x83:
            reg = (emulator->instruction[emulator->MODRM] & 0x38) >> 3;
            
            switch(reg) {
                case 0:
                    /*
                     * add rm16, imm8
                     * add rm32, imm8
                     */
                    emulator->executedResult = *(emulator->operand[0]) + *(emulator->operand[1]);

                    std::printf("operand0: 0x%x\n", *emulator->operand[0]);
                    std::printf("operand1: 0x%x\n", *emulator->operand[1]);
                    std::printf("executed: 0x%x\n", emulator->executedResult);
                    break;
                
                case 5:
                    /*
                     * sub rm16, imm8
                     * sub rm32, imm8
                     */
                    emulator->executedResult = *(emulator->operand[0]) - *(emulator->operand[1]);

                    std::printf("operand0: 0x%x\n", *emulator->operand[0]);
                    std::printf("operand1: 0x%x\n", *emulator->operand[1]);
                    std::printf("executed: 0x%x\n", emulator->executedResult);
                    break;
            }
            break;


            
        defualt:
            break;
        
    }

}

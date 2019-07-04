#include <iostream>
#include <cstring>

#include "../include/emulator.h"
#include "../include/fetcher.h"
#include "../include/decoder.h"
#include "../include/operander.h"
#include "../include/executer.h"
#include "../include/writebacker.h"


int main(int argc, char* argv[]) {
    char* fileName;
    FILE* fp;
    std::string input;
    Emulator*   emulator = new Emulator;
    Fetcher     fetcher;
    Decoder     decoder;
    Operander   operander;
    Executer    executer;
    Writebacker writebacker;


    if(argc != 2) {
        std::cout << "invaliable arguments" << std::endl;
        return 1;
    }

    fileName = argv[1];
    fp = std::fopen(fileName, "rb");
    emulator->init(fp);
    std::fclose(fp);
    
    emulator->dump();
    
    while(1) {
        std::cout << "Please input Enter key > ";
        fgetc(stdin);

        fetcher.fetch(emulator);
        if(decoder.decode(emulator) < 0) {
            std::cout << "Decode Error" << std::endl;
        }
        operander.operand(emulator);
        executer.execute(emulator);
        writebacker.writeback(emulator);

        emulator->dump();
    }
    
    emulator->destroy();

    return 0;
}
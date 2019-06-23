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
        std::printf("invaliable arguments\n");
        return 1;
    }
    fileName = argv[1];

    fp = std::fopen(fileName, "rb");
    emulator->init(fp);
    std::fclose(fp);
    
    while(1) {
        std::cout << "Please input Enter key > ";
        fgetc(stdin);
        fetcher.fetch(emulator);
        decoder.decode(emulator);
        operander.operand(emulator);
        executer.execute(emulator);
        writebacker.writeback(emulator);
        
        emulator->dumpMemory();
    }
    
    emulator->destroy();

    return 0;
}

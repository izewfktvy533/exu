#include <iostream>
//#include <cstring>
//#include <fstream>

#include "../include/emulator.h"


int main(int argc, char* argv[]) {
    char* fileName;
    FILE* fp;
    Emulator emulator;


    if(argc != 2) {
        std::printf("invaliable arguments\n");
        return 1;
    }
    fileName = argv[1];

    fp = std::fopen(fileName, "rb");
    emulator.init(fp);
    std::fclose(fp);
    
    emulator.dumpMemory();
    emulator.destroy();

    return 0;
}

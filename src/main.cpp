#include <iostream>
#include <cstring>
#include <fstream>
//#include "emulator.h"


using namespace std;


int main(int argc, char* argv[]) {
    //Emulator emulator;
    //emulator.init();


    if(argc != 2) {
    }

    char* fileName = argv[1];
    FILE* f = fopen(fileName, "rb");

    size_t size = 1;
    size_t count = 512;
    uint8_t* buf = new uint8_t[count];
    
    memset(buf, 0, sizeof(buf));
    fread(buf, size, count, f);

    for(int i=0; i<count/2; i+=2) {
        if(!(i==0) && !(i % 16)) {
            printf("\n");
        }
        printf("%02x%02x ", buf[i+1], buf[i]);
    }
    printf("\n");

    //emulator.destroy();

    return 0;
}

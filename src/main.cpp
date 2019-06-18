#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
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
    vector<uint8_t> buf(count);
    
    //memset(buf, 0, buf.size());
    fread(&buf[0], size, count, f);

    for(int i=0; i<buf.size()/2; i+=2) {
        if(!(i==0) && !(i % 16)) {
            printf("\n");
        }
        printf("%02x%02x ", buf[i+1], buf[i]);
    }
    printf("\n");

    //emulator.destroy();

    return 0;
}

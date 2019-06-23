#include <iostream>
#include "../include/fetcher.h"


void Fetcher::fetch(Emulator* emulator) {
    emulator->opecode = emulator->memory[emulator->registers[emulator->EIP]++];
}

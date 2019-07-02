#ifndef _DECODER_H_
#define _DECODER_H_

#include "emulator.h"
//TODO: #include "modrm.h"


class Decoder {
    public:
        int decode(Emulator*);

};


#endif
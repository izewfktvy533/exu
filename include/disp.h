#ifndef _DISP_H_
#define _DISP_H_


class DISP {
    public:
        union {
            std::uint8_t disp8;
            std::uint8_t disp32;
        };

};


#endif
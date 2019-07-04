#ifndef _SIB_H_
#define _SIB_H_


class SIB {
    public:
        union {
            std::uint8_t sib;
            std::uint8_t scale;
            std::uint8_t index;
            std::uint8_t base;
        };

};


#endif
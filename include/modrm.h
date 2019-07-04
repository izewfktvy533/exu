#ifndef _MODRM_H_
#define _MODRM_H_


class ModRM {
    public:
        union {
            std::uint8_t reg;
            std::uint8_t opecode;
        };
        std::uint8_t mod;
        std::uint8_t rm;

};


#endif
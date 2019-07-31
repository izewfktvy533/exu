BITS 32
    org 0x7c00
    add dword [eax+0x7bf0], 0x77777777
    jmp 0

BITS 32
    org 0x7c00
    mov edx, 0x11223344
    push edx
    mov edx, 0x70
    pop edx
    jmp 0

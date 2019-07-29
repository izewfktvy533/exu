BITS 32
    org 0x7c00
    mov eax, 0x7bf0
    add dword [eax], 8
    jmp 0

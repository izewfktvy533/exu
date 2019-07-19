BITS 32
    org 0x7c00
    mov eax, 0x7bf0
    mov dword [eax-0x10], 1
    mov ecx, 2
    add [eax-0x10], ecx;
    jmp 0

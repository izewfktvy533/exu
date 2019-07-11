BITS 32
    org 0x7c00
    mov edx, 0x11112222
    mov ecx, 0x7c20
    mov eax, 0x60
    push edx
    push ecx
    push eax
    jmp 0

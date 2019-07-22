BITS 32
    org 0x7c00
    mov dword [eax+0x7bf0], 2
    mov eax, 1
    mov ecx, 0x7bf0
    add eax, [ecx]
    jmp 0

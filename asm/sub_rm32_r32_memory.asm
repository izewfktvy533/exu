BITS 32
    org 0x7c00
    mov eax, 0x7bf0
    mov dword [eax], 5
    mov ecx, 2
    sub [eax], ecx
    jmp 0

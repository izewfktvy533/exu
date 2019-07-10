BITS 32
    org 0x7c00
    mov ecx, 0x7c20
    mov eax, 0x60
    mov [ecx], eax
    mov eax, ecx
    jmp 0x00

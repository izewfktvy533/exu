BITS 32
    org 0x7c00
    mov ecx, 0x60
    mov eax, 41
    mov [ecx], eax
    mov eax, ecx
    jmp 0

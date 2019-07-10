BITS 32
    org 0x7c00
    mov ecx, 0x7c10
    mov eax, 41
    mov [ecx], eax
    jmp 0

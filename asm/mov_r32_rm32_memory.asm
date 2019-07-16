BITS 32
    org 0x7c00
    mov ecx, 0x7bff
    mov edx, 0x31
    mov [ecx], edx
    mov eax, ecx
    mov eax, [ecx-0x0f]
    jmp 0

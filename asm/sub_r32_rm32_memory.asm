BITS 32
    org 0x7c00
    mov byte [eax+0x7bf2], 0x01
    mov eax, 1
    mov ecx, 2
    sub eax, [0x7bf2]
    jmp 0

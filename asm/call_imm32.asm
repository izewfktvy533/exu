BITS 32
    org 0x7c00

start:
    mov eax, 0x00f1
    mov ebx, 0x0029
    call add_routine
    mov edx, ecx
    jmp 0

add_routine:
    mov ecx, eax
    ret

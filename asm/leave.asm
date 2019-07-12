BITS 32
    org 0x7c00

start:
    mov eax, 0x29
    call routine1
    mov esi, ebx
    jmp 0

routine1:
    push ebp
    mov ebp, esp
    mov ecx, eax
    call routine2
    mov ebx, edx
    mov esp, ebx
    leave
    ret

routine2:
   mov edx, ecx 
   ret

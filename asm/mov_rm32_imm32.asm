BITS 32
    org 0x7c00
    mov dword [ebp-0x4],0x28
    mov dword [eax+0x7bf0], 0x29
    mov eax, 0x7be0
    mov dword [eax], 0x02
    jmp 0

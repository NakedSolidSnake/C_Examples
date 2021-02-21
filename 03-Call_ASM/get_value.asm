global get_value_asm

segment .text

get_value_asm:
    mov eax, edi
    add eax, 1
    ret
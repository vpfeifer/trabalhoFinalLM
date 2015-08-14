global mulEscalar

section .data

section .text

_start:

mulEscalar:
	push ebp
	mov  ebp,esp
    mov  ecx, [ebp+8]   ; argument 1 : tamanho da matriz
    mov  dl, [esp+12]   ; argument 2 : escalar que será multiplicado pela matriz
    mov  ebx, [esp+16]  ; argument 3 : endereço inicial da matriz
    mov  eax,[ebx]
    mul  dl
    pop  ebp
    ret
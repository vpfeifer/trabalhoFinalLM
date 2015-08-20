global mulMatrizes

section .data

section .text

_start:

mulMatrizes:
	push 	ebp					; coloca o ebp no topo da pilha
	mov  	ebp,esp				; copia o endereço da pilha (esp) para ebp
    mov  	ecx, [ebp+8]   		; argument 1 : tamanho da matriz
    mov  	dl, [esp+12]   		; argument 2 : escalar que será multiplicado pela matriz
    mov  	ebx, [esp+16]  		; argument 3 : endereço inicial da matriz
    mov  	eax,[ebx]			; primeiro elemento da matriz em eax
    mul  	dl					; 
    pop  	ebp
    ret
'global mulMatrizes

section .data

valinc:		db	4
menor:		dd	127
tamanho:	db	0
escalar:	db	0

section .text

_start:

mulMatrizes:
	push 	ebp					; coloca o ebp no topo da pilha
	mov  	ebp,esp				; copia o endereço da pilha (esp) para ebp

	xor		ebx,ebx

    mov  	ebx,  [ebp+8]   	; argument 1 : tamanho da matriz
    mov		[tamanho],ebx		; move para memoria o tamanho da matriz

    mov  	ebx, [ebp+12]   	; argument 2 : escalar que será multiplicado pela matriz
    mov		[escalar],ebx		; move para memoria o tamanho da matriz

    mov 	ebx, [ebp+16]  		; argument 3 : endereço inicial da matriz A
    mov		edx, [ebp+20]		; argument 4 : endereço inicial da matriz B

    xor ecx,ecx					; zerando ecx para cl = i = 0 e ch = j = 0

 	loop_A:
 		xor edi,edi 			;auxsoma = 0
 		xor ch,ch				; j=0
	 		loop_B :
	 			xor eax,eax
	 			mov eax,[tamanho]	
	 			mul cl 					; i * tamanho
	 			add al, ch				; i * tamanho + j
	 			mul byte [valinc]
	 			mov eax, [ebx + eax] 	; mA[i * tamanho + j]
	 			mul byte [escalar]		; 5 * mA[i * tamanho + j]
	 			mov esi, eax
	 			mov eax, [tamanho]
	 			mul ch					; j * tamanho
	 			add al, cl 				; j * tamanho + i
	 			mul byte [valinc]
	 			mov eax, [edx + eax]	; mB[j * tamanho +i]
	 			imul eax, esi			; 5 * mA[i * tamanho + j] * mB[j * tamanho +i]
	 			add	 edi, eax			; auxsoma += 5 * mA[i * tamanho + j] * mB[j * tamanho +i]
	 			inc ch					; j++
	 	
	 			cmp ch,[tamanho]
	 			jne	loop_B 		
	 			
 		cmp edi, [menor]				; if(auxSoma < menorValor)
 		jge continue_A				
 		mov [menor],edi					; menor = auxSoma;
 	continue_A:
 		inc cl
 		cmp cl,[tamanho]
 		jne loop_A

 	mov eax,[menor]
    pop  	ebp
    ret
global calc_nasm

section .data

menor:		dd	999999999
aux: 		dd	0

section .text

_start:

calc_nasm:
	push 	ebp							; coloca o ebp no topo da pilha
	mov  	ebp,esp						; copia o endereço da pilha (esp) para ebp
	mov 	[menor], DWORD 999999999
    
    mov 	ebx, [ebp+16]  				; argument 3 : endereço inicial da matriz A
    mov		edx, [ebp+20]				; argument 4 : endereço inicial da matriz B;

    xor ecx,ecx							; zerando ecx,para i=0 para cl = i = 0 e ch = j = 0
    xor esi,esi							; j=0

 	loop_A:
 		xor edi,edi 					;auxsoma = 0
 		xor esi,esi						; j=0
	 		loop_B :
	 			xor 	eax,eax
	 			mov 	eax,[ebp+8]			; tamanho	
	 			imul 	eax,ecx 			; i * tamanho
	 			add 	eax, esi			; i * tamanho + j
	 			imul 	eax,4				; multiplica por 4 para andar no array de int
	 			mov  	eax,[ebx + eax] 	; mA[i * tamanho + j]
	 			imul 	eax,[ebp+12]		; 5 * mA[i * tamanho + j]
	 			mov 	[aux],eax			; coloca o primeiro elemento da multiplicação na memória
	 			mov 	eax,[ebp+8]
	 			imul 	eax,esi				; j * tamanho
	 			add 	eax,ecx 			; j * tamanho + i
	 			imul 	eax,4
	 			mov 	eax,[edx + eax]		; mB[j * tamanho +i]
	 			imul 	eax,[aux]			; 5 * mA[i * tamanho + j] * mB[j * tamanho +i]
	 			add	 	edi,eax				; auxsoma += 5 * mA[i * tamanho + j] * mB[j * tamanho +i]
	 			inc 	esi					; j++
	 	
	 			cmp esi,[ebp+8]
	 			jne	loop_B 		
	 			
 		cmp 	edi,[menor]					; if(auxSoma < menorValor)
 		jge 	continue_A				
 		mov 	[menor],edi					; menor = auxSoma;
 	continue_A:
 		inc ecx
 		cmp ecx,[ebp+8]
 		jne loop_A

 	mov eax,[menor]
    pop  	ebp
    ret
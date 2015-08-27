.global calc_gas

.data

valinc:         .byte 4
menor:          .long 9999
tamanho:        .byte 0
escalar:        .byte 0

.text

_start: 

calc_gas: 
    pushl   %ebp                                                        # coloca o ebp no topo da pilha
    movl    %esp,%ebp                                                   # copia o endereço da pilha (esp) para ebp

    xorl            %ebx,%ebx

    movb $4,%bl
    movb %bl,valinc

    movl $99999,%ebx
    movl %ebx,menor

    movb        8(%ebp),%bl                                             # argument 1 : tamanho da matriz
    movb        %bl,tamanho                                             # move para memoria o tamanho da matriz

    movb        12(%ebp),%bl                                            # argument 2 : escalar que será multiplicado pela matriz
    movb        %bl,escalar                                             # move para memoria o tamanho da matriz

    movl        16(%ebp),%ebx                                           # argument 3 : endereço inicial da matriz A
    movl        20(%ebp),%edx                                           # argument 4 : endereço inicial da matriz B

    xorl %ecx,%ecx                                                      # zerando ecx para cl = i = 0 e ch = j = 0

        loop_A: 
                xorl %edi,%edi                                          #auxsoma = 0
                xorb %ch,%ch                                            # j=0
                        loop_B :
                                xorl %eax,%eax
                                movb tamanho,%al
                                mulb %cl                                # i * tamanho
                                addb %ch,%al                            # i * tamanho + j
                                mulb valinc
                                movl (%ebx,%eax),%eax                   # mA[i * tamanho + j]
                                mulb escalar                            # 5 * mA[i * tamanho + j]
                                movl %eax,%esi
                                movb tamanho,%al
                                mulb %ch                                # j * tamanho
                                addb %cl,%al                            # j * tamanho + i
                                mulb valinc
                                movl (%edx,%eax),%eax                   # mB[j * tamanho +i]
                                imull %esi,%eax                         # 5 * mA[i * tamanho + j] * mB[j * tamanho +i]
                                addl  %eax,%edi                         # auxsoma += 5 * mA[i * tamanho + j] * mB[j * tamanho +i]
                                incb  %ch                                # j++
                                cmpb tamanho,%ch
                                jne  loop_B

                cmpl menor,%edi                                         # if(auxSoma < menorValor)
                jge continue_A
                movl %edi,menor                                         # menor = auxSoma;
        continue_A: 
                incb %cl
                cmpb tamanho,%cl
                jne loop_A
    
    movl menor,%eax
    popl %ebp
    ret
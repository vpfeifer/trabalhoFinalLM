.global calc_gas

.data

menor:          .long 999999999
aux:            .long 0

.text

_start: 

calc_gas: 
        pushl   %ebp                                                    # coloca o ebp no topo da pilha
        movl    %esp,%ebp                                       # copia o endereço da pilha (esp) para ebp
        movl    $999999999, menor

    movl        16(%ebp),%ebx                           # argument 3 : endereço inicial da matriz A
    movl        20(%ebp),%edx                           # argument 4 : endereço inicial da matriz B;

    xorl %ecx,%ecx                                              # zerando ecx,para i=0 para cl = i = 0 e ch = j = 0
    xorl %esi,%esi                                              # j=0

        loop_A: 
                xorl %edi,%edi                                  #auxsoma = 0
                xorl %esi,%esi                                          # j=0
                        loop_B :
                                xorl    %eax,%eax
                                movl    8(%ebp),%eax                    # tamanho       
                                imull   %ecx,%eax                       # i * tamanho
                                addl    %esi,%eax                       # i * tamanho + j
                                imull   $4,%eax                         # multiplica por 4 para andar no array de int
                                movl    (%ebx,%eax),%eax        # mA[i * tamanho + j]
                                imull   12(%ebp),%eax           # 5 * mA[i * tamanho + j]
                                movl    %eax,aux                        # coloca o primeiro elemento da multiplicação na memória
                                movl    8(%ebp),%eax
                                imull   %esi,%eax                       # j * tamanho
                                addl    %ecx,%eax                       # j * tamanho + i
                                imull   $4,%eax
                                movl    (%edx,%eax),%eax        # mB[j * tamanho +i]
                                imull   aux,%eax                        # 5 * mA[i * tamanho + j] * mB[j * tamanho +i]
                                addl            %eax,%edi                       # auxsoma += 5 * mA[i * tamanho + j] * mB[j * tamanho +i]
                                incl    %esi                                    # j++

                                cmpl 8(%ebp),%esi
                                jne     loop_B

                cmpl    menor,%edi                                      # if(auxSoma < menorValor)
                jge     continue_A
                movl    %edi,menor                                      # menor = auxSoma;
        continue_A: 
                incl %ecx
                cmpl 8(%ebp),%ecx
                jne loop_A

        movl menor,%eax
    popl        %ebp
    ret

#include <stdio.h>
#include <stdlib.h>

/*
1. Escreva um programa que realize a leitura de um valor positivo N. A seguir, o programa deve
fazer a leitura de uma série de números inteiros positivos, interrompida pela leitura de um valor
negativo. No seu final, o programa deve mostrar na tela quantos valores diferentes de N foram
informados antes da última ocorrência de N na série lida. Se o valor N não aparecer na
sequência, deve ser mostrada uma mensagem explicitando esta situação. 

*/

int main()
{
    int n, p, c = 0, z = 0, x = 0;

    printf("Digite um valor positivo \n");
    scanf("%d", &n);

    printf("Digite uma sequencia de numeros positivos e um negativo para finalizar: \n");
    scanf("%d", &p);

    while (p >= 0)
    {
        if (p != n)
            c++;
        else
        {
            x = 1;
            z = z + c;
            printf("c antes: %d \n", c);
            c = 0;
            printf("c depois: %d \n", c);
        }
        scanf("%d", &p);
    }

    if (x == 0)
    {
        printf("Nao foram informados valores iguais a 'n' \n");
    }
    else
    {
        printf("Foram informados %d valores diferentes de %d antes da ultima ocorrencia de %d", z, n, n);
    }
    system("pause");
    return 0;
}
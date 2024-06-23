#include <stdio.h>
#include <stdlib.h>

/*
2. Escreva um programa que inicie com a leitura de um valor inteiro positivo N. A seguir, deve
ser lida uma sequência de valores inteiros, interrompida pela leitura de um valor negativo. Ao
final, deve ser exibido o maior valor informado na sequência que seja menor do que N. 

*/

int main()
{
    int n, p, z = -1;

    printf("Digite um valor positivo \n");
    scanf("%d", &n);

    printf("Digite uma sequencia de numeros positivos e um negativo para finalizar: \n");
    scanf("%d", &p);

    while (p >= 0)
    {

        if (p < n)
        {
            if (p > z)
            {
                z = p;
            }
        }

        scanf("%d", &p);
    }

    if (z == -1)
    {
        printf("Nao foram informados valores menores que %d", n);
    }
    else
    {
        printf("O maior valor menor que %d informado foi %d", n, z);
    }
    system("pause");
    return 0;
}
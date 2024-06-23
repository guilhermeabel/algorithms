#include <stdio.h>
#include <stdlib.h>

/*
3. Escrever um programa que leia um inteiro n e mostre na tela todos os valores inteiros entre 1
e 1000 que são divisíveis por n.
*/

int main()
{
    int n, i, x = 0;
    printf("Digite um numero inteiro \n");
    scanf("%d", &n);
    for (i = 0; i < 1000; i++)
    {
        if ((i % n) == 0)
        {
            printf("%d \n", i);
            x++;
        }
    }
    printf("Um total de %d numeros entre 1 e 1000 sao divisiveis por %d \n", x, n);
    system("pause");
    return 0;
}
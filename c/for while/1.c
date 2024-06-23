#include <stdio.h>
#include <stdlib.h>
/*
1. Faça um algoritmo para ler dois valores inteiros. O primeiro representa o primeiro elemento
de uma progressão aritmética, e o segundo a razão. Calcule e mostre os 10 elementos
seguintes.

*/
int main()
{
    int i, primeiro, razao, proximo;

    printf("Digite o primeiro elemento da PA \n");
    scanf("%d", &primeiro);

    printf("Digite a razao da PA \n");
    scanf("%d", &razao);

    for (i = 1; i <= 10; i++)
    {
        printf("Elemento %d: %d \n", i, primeiro);
        proximo = primeiro + razao;
        primeiro = proximo;
    }

    system("pause");
    return 0;
}
#include <stdio.h>

/*
6. Escreva um programa que leia um número inteiro não negativo e coloque em outra variável o
valor inteiro cuja representação decimal possui os mesmos dígitos que a representação
decimal do valor lido, porém em ordem inversa.
Ex: lido o valor 235, o resultado deve ser o valor inteiro 532. 
*/

int main()
{

    int var, res = 0;
    printf("Type any positive integer value \n");
    scanf("%d", &var);

    do
    {
        res = res * 10 + (var % 10);
        var = var / 10;
    } while (var > 0);
    printf("%d", var);
}

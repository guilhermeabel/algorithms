#include <stdio.h>
#include <stdlib.h>
/* 1. Escreva um programa que leia dois valores inteiros, um representando o número total de
elementos de uma amostragem, e outro representando uma fração desta amostragem. A
seguir, o programa deve calcular a porcentagem representada pela fração e retornar este valor.
 */
int main()
{
    int nota1, nota2;
    float exame;
    printf("Digite a nota 1: \n");
    scanf("%d", &nota1);
    printf("Digite a nota 2: \n");
    scanf("%d", &nota2);
    if (((nota1 + nota2)/2))
    exame = (float)nota2 / nota1 * 100.0;
    printf("A fracao representa %.2f %c do valor inicial \n", exame, 37);

    getchar();
    system("pause");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

/*
1. Escreva um programa que leia duas frações, no formato numerador/denominador
(numerador e denominador são inteiros!). O programa deve calcular e mostrar a fração
resultante da soma das frações lidas, no mesmo formato e simplificada. O programa deve ser
feito sem o uso de variáveis de tipo ponto flutuante (float e double). 

*/

int main()
{

    int num1, num2, den1 = 0, den2 = 0;

    while (den1 < 1 && den2 < 1)
    {

        printf("Digite a primeira funcao");
        scanf("%d/%d", &num1, &den1);

        printf("Digite a segunda funcao");
        scanf("%d/%d", &num2, &den2);

    }
}
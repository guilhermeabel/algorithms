#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// 5. Escrever um programa que leia a data de nascimento de uma pessoa e a data atual e
// calcule o número de dias que a pessoa já viveu. Para simplificar, considere que todos os
// meses têm 30 dias, e todos os anos 365 dias.

int main()
{
    int idade, ano_atual, dias;

    printf("Digite sua data de nascimento no formato DD/MM/AAAA \n");
    scanf("%d/%d/%d", &idade,&idade,&idade);
    
    printf("Digite o ano atual \n");
    scanf("%d", &ano_atual);
    idade = ano_atual - idade;
    dias = idade * 365;
    printf("Voce viveu: %d dias. \n", dias);


    getchar();
    system("pause");
    return 0;
}
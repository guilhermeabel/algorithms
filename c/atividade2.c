#include <stdio.h>
#include <stdlib.h> 
/* 2. Escrever um programa que leia dois valores numéricos, um representando o valor do salário
de um trabalhador e o outro o percentual de reajuste que este salário deve receber. O
programa deve calcular e mostrar na tela o salário após o reajuste.
 */
int main()
{
    int var1, var2;
    printf("Digite o salario: \n");
    scanf("%d", &var1);
    printf("Digite o aumento: \n");
    scanf("%d", &var2);
    var1 = var1+((float)var1*((float)var2/100.0));
    printf("O salario total com reajuste e %d \n", var1);

    getchar();
    system("pause");
    return 0;
}
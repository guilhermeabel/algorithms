#include <stdio.h>
#include <stdlib.h>
/* 3. Escrever um programa que leia um valor em Reais e calcule o menor número possível de
notas de R$100,00, R$50,00, R$20,00, R$10,00, R$5,00, R$2,00 e R$1,00 em que o valor lido
pode ser decomposto. Ignore os centavos. O programa deve mostrar o número total de notas.
 */
int main()
{

    int var1, var2, var3;
    printf("Digite o valor: \n");
    scanf("%d", &var1);

    var3 = var1 / 100;
    printf("Sao necessarias %d notas de 100 \n", var1 / 100);
    var2 = var1 % 100;

    var3 += var2 / 50;
    printf("Sao necessarias %d notas de 50 \n", var2 / 50);
    var1 = var2 % 50;

    var3 += var1 / 20;
    printf("Sao necessarias %d notas de 20 \n", var1 / 20);
    var2 = var1 % 20;

    var3 += var2 / 10;
    printf("Sao necessarias %d notas de 10 \n", var2 / 10);
    var1 = var2 % 10;

    var3 += var1 / 5;
    printf("Sao necessarias %d notas de 5 \n", var1 / 5);
    var2 = var1 % 5;

    var3 += var2 / 2;
    printf("Sao necessarias %d notas de 2 \n", var2 / 2);
    var1 = var2 % 2;

    var3 += var1 / 1;
    printf("Sao necessarias %d notas de 1 \n", var1 / 1);
    var2 = var1 % 1;

    printf("Sao necessarias %d notas no total \n", var3);

    getchar();
    system("pause");
    return 0;
}
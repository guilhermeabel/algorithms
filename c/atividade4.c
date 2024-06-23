#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// 4. Escreva um programa que leia um número de dois dígitos e subtraia o valor de cada um dos
// dígitos do valor lido. O valor resultante deve ser exibido.

int main()
{
    int numero, dezena, unidade, novo_numero;

    printf("Digite um numero inteiro de dois digitos entre 11 e 99 \n");
    scanf("%d", &numero);
    if (numero > 99 || numero <= 10)
    {
        printf("Pau no seu cu");
        return 0;
    }

    dezena = (numero / 10) - 1;
    unidade = (numero % 10) - 1;
    printf("O novo numero e: %d%d. \n", dezena, unidade);

    // dezena = (numero / 10);
    // unidade = (numero % 10);
    // numero - dezena+unidade;
    // printf("O novo numero e: %d. \n", numero);

    getchar();
    system("pause");
    return 0;
}
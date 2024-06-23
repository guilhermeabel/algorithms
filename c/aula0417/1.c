#include <stdlib.h>
#include <stdio.h>

int main()
{
    int valor1, valor2, resultado = 0;
    printf("Digite o valor 1: \n");
    scanf("%d", &valor1);
    printf("Digite o valor 2: \n");
    scanf("%d", &valor2);

    while (valor2 > 0)
    {
        resultado += valor1;
        valor2--;
        if (valor2 == 0)
        {
            printf("O resultado do produto e: %d \n", resultado);
        }
    }
    system("pause");
    return 0;
}

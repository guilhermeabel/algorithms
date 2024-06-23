#include <stdio.h>
#include <stdlib.h>

/*
4. Existem números, chamados de números perfeitos, que apresentam a peculiar característica
de terem valor igual à soma dos seus divisores (diferentes do próprio número). Como exemplo,
podemos considerar o número 6, que pode ser dividido por 1, 2 e 3, números estes que
somados resultam exatamente 6. Escreva um programa que mostre na tela todos os números
entre 1 e 100 que apresentam esta característica.
*/

int main()
{
    long int x = 0, z = 0, v = 0;

    printf("How many do ya want kiddo? \n");
    scanf("%ld", &z);

    for (long int i = 2; v < z; i += 2)
    {
        for (register long int j = 1; j < i; j++)
        {
            if ((i % j) == 0)
                x = x + j;
        }
        if (x == i)
        {
            printf("%ld \n", i);
            v++;
        }
        x = 0;
    }
    system("pause");
    return 0;
}

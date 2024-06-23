#include <stdio.h>
#include <stdlib.h>

/*
5. Escrever um programa que leia um valor inteiro e calcule e mostre a soma de todos os
dígitos da representação decimal deste número. Por exemplo, a soma dos dígitos de 432 é 9 (4
+ 3 + 2). Lembre-se: para 432 / 10, quociente 43 e resto 2.

*/

int main()
{
    int n, j, z, result = 0;

    printf("Type an integer value \n");
    scanf("%d", &n);

    for (int i = 10; i <= n * 10; i *= 10)
    {
        j = i / 10;
        z = (n % i) / j;
        result += z;
    }

    printf("The sum of the digits in %d is: %d \n", n, result);
}

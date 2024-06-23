#include <stdio.h>
#include <stdlib.h>

/* 
2. Escrever um programa que lê 15 valores, um de cada vez, e conta quantos deles estão no
intervalo [10,20], quantos estão dentro do intervalo [26,30] e quantos deles estão fora destes
intervalos, mostrando estas informações.

*/

int main()
{
    int i, f, out;
    int cond1 = 0, cond2 = 0;

    for (i = 1; i <= 15; i++)
    {
        printf("Digite o valor %d \n", i);
        scanf("%d", &f);

        if (f >= 10 && f <= 20)
        {
            cond1++;
        }
        else if (f >= 26 && f <= 30)
        {
            cond2++;
        }
    }

    out = 15 - (cond1 + cond2);

    printf("%d valores satisfazem a condicao 1 \n", cond1);
    printf("%d valores satisfazem a condicao 2 \n", cond2);
    printf("%d valores nao satisfazem nenhuma condicao \n", out);

    system("pause");
    return 0;
}
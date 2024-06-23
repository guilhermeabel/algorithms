#include <stdio.h>
#include <stdlib.h>

int inverte(int x)
{
    int inv = 0;
    do
    {
        inv = inv * 10 + (x % 10);
        x = x / 10;
    } while (x > 0);
    return (inv);
}

main()
{
    int x;
    printf("Introduza o numero a verificar:\n");
    scanf("%d", &x);
    if (inverte(x) == x)
    {
        printf("Capicua!\n");
    }
    else
        printf("Nao e capicua\n");
    system("pause");
    return 0;
}


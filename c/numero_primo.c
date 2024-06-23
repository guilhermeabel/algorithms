#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Escreva o 10001 numero primo

int main()
{

    int i, Number, count;

    for (Number = 1; Number <= 100; Number++)
    {
        count = 0;
        for (i = 2; i <= Number / 2; i++)
        {
            if (Number % i == 0)
            {
                count++;
                break;
            }
        }
        if (count == 0 && Number != 1)
        {
            printf(" %d \n", Number);
        }
    }

    getchar();
    system("pause");
    return 0;
}
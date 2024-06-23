#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    int var1;
    float var2 = 0;
    char ans;
    int r = 0;
    for (int i = 0; i < 999; i++)
    {
    inicio:
        printf("Digite um numero: \n");
        scanf("%d", &var1);
        var2 += var1;
        r++;
        printf("Deseja continuar? S/N \n");
        scanf("%s", &ans);
        if ((ans == 'S' || ans == 's') && (ans != 'N' || ans != 'n'))
        {
            goto inicio;
        }
        else
        {
            goto fim;
        }
    }
fim:
    printf("A media dos numeros e: ");
   
    printf("%f", (var2 / r));

    getchar();
    system("pause");
    return 0;
}
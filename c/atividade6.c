#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// 6. Escreva um programa que leia um horário (hora, minuto e segundo) e mostre o horário um
// segundo depois. Por exemplo, se o horário lido for 12:34:25, o horário mostrado deve ser
// 12:34:26; se o horário lido for 12:59:59, o horário mostrado deve ser 13:00:00.

int main()
{
    int hora, minuto, segundo;

    printf("Digite o horario no formato HH:MM:SS \n");
    scanf("%d:%d:%d", &hora, &minuto, &segundo);

    if (hora > 23 || hora < 00)
    {
        printf("Digite um horario valido \n");
        return 0;
    }
    if (minuto > 59 || minuto < 00)
    {
        printf("Digite um horario valido \n");
        return 0;
    }
    if (segundo > 58 || segundo < 00)
    {
        printf("Digite um horario valido \n");
        return 0;
    }
    if (segundo != 59)
    {
        segundo++;
        printf("O horario apos 1 segundo sera: %d:%d:%d. \n", hora, minuto, segundo);
    }
    if (segundo == 59)
    {
        if (hora != 23)
        {
            hora++;
            char minuto[] = "00";
            char segundo[] = "00";
            printf("O horario apos 1 segundo sera: %d:%s:%s. \n", hora, minuto, segundo);
        }
        if (hora == 23)
        {
            char hora[] = "00";
            char minuto[] = "00";
            char segundo[] = "00";
            printf("O horario apos 1 segundo sera: %s:%s:%s. \n", hora, minuto, segundo);
        }
    }

    getchar();
    system("pause");
    return 0;
}
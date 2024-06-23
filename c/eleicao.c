#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    long int vot;
    int nec;

    printf("Qual o numero de votos validos: \n");
    scanf("%d", &vot);
    nec = (vot/2)+1;
    printf("Para ser eleito, sao necessarios : %d votos. \n", nec);
    printf("%x \n", &nec);

    getchar();
    system("pause");
    return 0;
}

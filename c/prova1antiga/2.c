#include <stdio.h>

int main()
{
    int km, distancia;
    float litros;
    printf("KM por litro");
    scanf("%d", &km);
    printf("Distancia");
    scanf("%d", &distancia);
    litros = distancia / km;
    printf("Total de %.2f litros e um gasto de %.2f \n", litros, litros * 4.3);

    return 0;
}
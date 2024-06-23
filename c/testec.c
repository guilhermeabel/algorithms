#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int checkNumber(int number1, int number2)
{
    if (number1 > number2)
    {
        printf("%d is bigger than %d \n Their addresses are, respectively: %x, %x", number1, number2, &number1, &number2);
    }
    if (number1 < number2)
    {
        printf("%d is bigger than %d \n Their addresses are, respectively: %x, %x", number2, number1, &number1, &number2);
    }

    if (number1 == number2)
    {
        printf("The numbers are equal. \n Their addresses are, respectively: %x, %x", &number1, &number2);
    }
}

int main()
{
    int number1;
    int number2;
    int res;

    printf("Enter the first number: ");
    scanf("%d", &number1);

    printf("Enter the second number: ");
    scanf("%d", &number2);

    res = checkNumber(number1, number2);

    //setlocale(LC_ALL, "Portuguese");

    /* char usuario[10];
    int a;
    int usuario_idade;

    printf("Digite seu nome: ");
    scanf("%s", usuario);

    printf("Digite sua idade: ");
    scanf("%d", &usuario_idade);

    for (a = 10; a < 20; a += 1)
    {
        printf("Seu nome é %s e sua idade é %d \n", usuario, usuario_idade);

        printf("value of a: %d\n", a);
    } */

    getchar();
    system("pause");
    return 0;
}

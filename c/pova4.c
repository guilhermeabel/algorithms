#include<stdio.h>
main() {
  char str[30];
  int num, i;
  printf("Digite a palavra: ");
  scanf("%s", str);
  printf("\nDigite o numero: ");
  scanf("%d", &num);
  for (i=0; str[i]; i++);
  if (i < num) printf("A palavra não tem tantas letras");
  else {
    for (i=0; str[i+num]; i++) str[i]=str[i+num];
    str[i] = '\0';
    }
  printf("\nPalavra sem as %d primeiras letras: %s", num, str);
  }

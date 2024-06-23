#include<stdio.h>

main() {
  int i, vet[1000], soma;
  for (i = 0; i < 1000; i++) {
    scanf ("%d", &vet[i]);
    }
  soma = 0;
  for (i = 0; i < 500; i++) {
    soma += vet[i];
    }
  for (; i < 1000; i++) {
    soma -= vet[i];
    }
  printf("Diferenca: %d", soma);
  }

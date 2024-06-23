#include<stdio.h>

main() {
  int i, j, col, mat[50][50], flag = 0;
  for (i = 0; i < 50; i++)
    for (j = 0; j < 50; j++)
      scanf ("%d", &mat[i][j]);
  for (col = 0; col < 50 && flag == 0; col++) {  /* para conparar, passo apenas pelos elementos da primeira linha, pois um elemento nao pode ocorrer em todas se nao aparece na primeira */
    /* nos for abaixo, verifica so o elemento da primeira linha (indicado por [0][col] aparece nas outras linhas */
    flag = 1;
    for (i = 0; i < 50 && flag; i++) {
      for (j = 0; j < 50 && mat[i][j] != mat[0][col]; j++);
      if (j == 50)   /* se j chegou a tamanho, não achou o valor, então nessa linha aqulee valor da primeira linha noa ocorre. */
        flag = 0;
      }
    }
  if (flag == 0)
    printf("Nao ha elemento que se repete em todas as linhas.");
  else
    printf("Ha elemento que se repete em todas as linhas.");
  }

#include <stdio.h>
#include <stdlib.h>

/* MATRIZ DE ADJACENCIA*/
#define NUMNOS 7

/*VARIAVEIS PARA PILHAS E FILAS*/
int pilha[10];
int fila[10];
int topo, base, fim, inicio, max;

/*PROCEDIMENTOS PARA CONTROLE DA PILHA E DA FILA*/
void Empilhar(int valor)
{
    if (topo < max)
    {
        topo++;
        pilha[topo] = valor;
    }
    else
        printf("Pilha cheia, valor n�o inclu�do.\n");
}

int Desempilhar(void)
{
    int retorno;
    if (topo >= base)
    {
        retorno = pilha[topo];
        topo--;
    }
    else
        retorno = -1;
    return retorno;
}

void Incluir(int valor)
{
    if (fim < max)
    {
        fim++;
        fila[fim] = valor;
    }
    else
        printf("Fila Cheia, valor n�o inclu�do.\n");
}

int Excluir(void)
{
    int retorno, i;
    if (fim >= inicio)
    {
        retorno = fila[inicio];
        for (i = 0; i < fim; i++)
            fila[i] = fila[i + 1];
        fim--;
    }
    else
        retorno = -1;
    return retorno;
}

/*PROCEDIMENTOS GRAFO*/
void construir_grafo(int grafo[NUMNOS][NUMNOS])
{
    int i, j;
    for (i = 0; i < 7; i++)
        for (j = 0; j < 7; j++)
            grafo[i][j] = 0;
    grafo[0][3] = 1;
    grafo[0][2] = 1;
    grafo[2][3] = 1;
    grafo[3][1] = 1;
    grafo[3][6] = 1;
    // grafo[2][4] = 1;
    grafo[1][5] = 1;
    grafo[5][4] = 1;
    grafo[6][0] = 1;
    grafo[6][5] = 1;
    grafo[0][1] = 1;
    grafo[1][2] = 1;
    //  grafo[3][4] = 1;
    grafo[4][5] = 1;
    grafo[5][6] = 1;
}

void Amplitude(int no, int grafo[NUMNOS][NUMNOS])
{
    int i;
    int visitado[NUMNOS];
    for (i = 0; i < NUMNOS; i++)
        visitado[i] = 0;
    printf("%d ", no);
    visitado[no] = 1;
    while (no != -1)
    {
        for (i = 0; i < NUMNOS; i++)
            if (grafo[no][i] == 1 && !visitado[i])
            {
                Incluir(i);
                printf("%d ", i);
                visitado[i] = 1;
            }
        no = Excluir();
    }
}

/************************* EXERCICIOS *************************
**************************************************************/

int verificaCaminhoProfRec(int a, int b, int grafo[NUMNOS][NUMNOS], int visitado[NUMNOS])
{
    int i, ret;
    if (a == b)
    {
        printf("%d ", a);
        return 1;
    }
    visitado[a] = 1;
    for (i = 0; i < NUMNOS; i++)
        if (grafo[a][i] == 1 && !visitado[i])
        {
            ret = verificaCaminhoProfRec(i, b, grafo, visitado);
            if (ret)
            {
                printf("%d ", a);
                return 1;
            }
        }
    return 0;
}

/* dados dois nós do grafo, verificar SE HÁ UM CAMINHO que parte do primeiro e chega no segundo */
int verificaCaminhoProf(int a, int b, int grafo[NUMNOS][NUMNOS])
{
    int visitado[NUMNOS];
    int i;
    for (i = 0; i < NUMNOS; i++)
        visitado[i] = 0;
    if (a == b)
    {
        if (grafo[a][a])
            return 1;
        else
            return 0;
    }
    return verificaCaminhoProfRec(a, b, grafo, visitado);
}

/*PRINCIPAL*/
int main(void)
{
    /*VARIAVEIS PARA O GRAFO*/
    int grafo[NUMNOS][NUMNOS];
    int caminho[NUMNOS];
    int i, j, l, ret;
    construir_grafo(grafo);
    i = 0;
    j = 4;
    if (verificaCaminhoProf(i, j, grafo))
    {
        printf("\nExiste caminho entre os nos %d e %d.\n", i, j);
    }
    else
    {
        printf("\nNAO existe caminho entre os nos %d e %d.\n", i, j);
    }

    return 0;
}
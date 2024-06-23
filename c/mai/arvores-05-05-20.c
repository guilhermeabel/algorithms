#include <stdio.h>
#include <stdlib.h>

#define GRAU 2 //Alterei o grau para 2 pois o exercício 2 requer uma árvore binária.

struct elemento
{
    int valor;
    struct elemento *filhos[GRAU];
};
/*
    1. Escreva uma função que receba como parâmetro um ponteiro
    apontando para a raiz de uma árvore e retorne um valor inteiro
    que é a soma dos campos valor de todos os nós da árvore.
*/

int soma(struct elemento *arv)
{
    int i, sum;
    if (arv)
    {
        sum = arv->valor;
        for (i = 0; i < GRAU; i++)
        {
            sum = sum + soma(arv->filhos[i]);
        }
        return sum;
    }
    return 0;
}

/*
    2. Escreva uma função que receba como parâmetro um ponteiro para a raiz de uma 
    árvore binária e retorne o nível do nó folha que é atingido por um caminho no 
    qual o sucessor do nó corrente é sempre o nó de menor valor dentre os nós filhos 
    de corrente.
*/

int retornaNivel(struct elemento *arv, int nivel)
{
    if (arv)
    {
        if (arv->filhos[0] && arv->filhos[1]) // verificar se ambos filhos nao nulos
        {
            if (arv->filhos[1]->valor < arv->filhos[0]->valor) // testar qual o menor
                retornaNivel(arv->filhos[1], nivel + 1); // acessar e incrementar nivel
            else
                retornaNivel(arv->filhos[0], nivel + 1); // acessar e incrementar nivel
        }
        else if (!(arv->filhos[0]) && !(arv->filhos[1])) // verificar se ambos filhos nulos
        {
            return nivel; //se nao ha mais filhos, retornar nivel
        }
        else if (!(arv->filhos[0])) // verificar se nulo filho 1
        {
            retornaNivel(arv->filhos[1], nivel + 1); // acessar e incrementar nivel
        }
        else if (!(arv->filhos[1])) // verificar se nulo filho 2
        {
            retornaNivel(arv->filhos[0], nivel + 1); // acessar e incrementar nivel
        }
    }
    else
        return 0; // nao ha arvore
}

// -----------------------------------------------------------------
struct elemento *inserir(int valor, struct elemento *arv)
{
    struct elemento *novo, *raiz;
    int i;
    novo = (struct elemento *)malloc(sizeof(struct elemento));
    novo->valor = valor;
    for (i = 0; i < GRAU; i++)
        novo->filhos[i] = NULL;
    if (!arv)
        return novo;
    raiz = arv;
    printf("A posicao corrente da arvore esta ocupada (pelo valor %d).\n", arv->valor);
    printf("Em qual das subarvores de corrente a insercao deve ser feita (0 a %d):", GRAU - 1);
    scanf("%d", &i);
    while (arv->filhos[i])
    {
        arv = arv->filhos[i];
        printf("A posicao corrente da arvore esta ocupada (pelo valor %d).\n", arv->valor);
        printf("Em qual das subarvores de corrente a insercao deve ser feita (0 a %d):", GRAU - 1);
        scanf("%d", &i);
    }
    arv->filhos[i] = novo;
    return raiz;
}

void exibir(struct elemento *arv, int nivel)
{
    int i, n;
    for (n = nivel; n > 0; n--)
        printf("   ");
    if (arv)
    {
        printf("%d\n", arv->valor);
        for (i = 0; i < GRAU; i++)
            exibir(arv->filhos[i], nivel + 1);
    }
    else
        printf("-\n");
}

void eliminar(struct elemento *arv)
{
    int i;
    if (arv)
    {
        for (i = 0; i < GRAU; i++)
            eliminar(arv->filhos[i]);
        free(arv);
    }
}

int contarNos(struct elemento *arv)
{
    int i, c;
    if (arv)
    {
        c = 1; /* corrente */
        for (i = 0; i < GRAU; i++)
            c = c + contarNos(arv->filhos[i]);
        return c;
    }
    return 0;
}

int main()
{
    struct elemento *arvore = NULL;
    arvore = inserir(4, arvore);
    arvore = inserir(10, arvore);
    arvore = inserir(8, arvore);
    arvore = inserir(2, arvore);
    /*
    arvore = inserir(6, arvore);
    arvore = inserir(7, arvore);
    arvore = inserir(3, arvore);
    arvore = inserir(1, arvore);
*/
    exibir(arvore, 0);
    printf("\nA soma dos nos e: %d. \n", soma(arvore));
    printf("\nA arvore tem %d nos.\n", contarNos(arvore));
    printf("\nNivel mais alto atraves do menor valor: %d\n", retornaNivel(arvore, 0));

    eliminar(arvore);
}
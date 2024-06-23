#include <stdio.h>
#include <stdlib.h>

#define GRAU 2

struct elemento
{
    int valor;
    struct elemento *filhos[GRAU];
};

/*****************************************************************************
                             CODIGO DA FILA
*****************************************************************************/

struct elementoFila
{
    struct elemento *valor;
    struct elementoFila *prox;
} * inicio, *fim;

void incluir(struct elemento *valor)
{
    struct elementoFila *novo;
    novo = (struct elementoFila *)malloc(sizeof(struct elementoFila));
    novo->valor = valor;
    novo->prox = NULL;
    if (!fim)
        inicio = novo;
    else
        fim->prox = novo;
    fim = novo;
}

struct elemento *excluir(void)
{
    struct elemento *retorno;
    struct elementoFila *aux;
    if (inicio)
    {
        retorno = inicio->valor;
        aux = inicio;
        inicio = inicio->prox;
        if (!inicio)
            fim = NULL;
        free(aux);
        return retorno;
    }
    return NULL;
}

/*****************************************************************************
                         CODIGOS DE 5 E 6 DE MAIO
*****************************************************************************/

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

void exibirAmp(struct elemento *arv)
{
    int i;
    while (arv)
    {
        printf("%d  ", arv->valor);
        for (i = 0; i < GRAU; i++)
        {
            if (arv->filhos[i])
                incluir(arv->filhos[i]);
        }
        arv = excluir();
    }
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

/*****************************************************************************
                                 EXERCICIOS
*****************************************************************************/

/*
1. Escreva uma função que receba como parâmetro um ponteiro para a raiz de uma árvore binária e retorne 
o número de nós da árvore que têm valor par.
*/

int nosPares(struct elemento *arv)
{
    int i, c = 0;
    if (arv)
    {
        if (!(arv->valor % 2))
            c += 1;
        for (i = 0; i < GRAU; i++)
            c += nosPares(arv->filhos[i]);
        return c;
    }
    return 0;
}

/*
2. Escreva uma função que receba como parâmetro um ponteiro para a raiz de uma árvore binária e retorne 
o menor nível (nível mais baixo) que tenha pelo menos um nó que não tenha todos os filhos. Atenção, 
não se trata de contar nós folha. Nós folha não tem qualquer filho. O objetivo aqui é achar o nó de 
mais baixo nível que não tenha todos os filhos e retornar seu nível.
*/

int semFilhos(struct elemento *arv, int nivel)
{
    if (arv)
    {
        if (!(arv->filhos[0]) || (!arv->filhos[1]))
            return nivel;  
        return semFilhos(arv->filhos[1], nivel + 1);
        return semFilhos(arv->filhos[0], nivel + 1);
    }
    return 0;
}
/**/
int main()
{
    struct elemento *arvore = NULL;
    inicio = fim = NULL;
    arvore = inserir(4, arvore);
    arvore = inserir(2, arvore);
    arvore = inserir(8, arvore);
    arvore = inserir(5, arvore);
    
    arvore = inserir(6, arvore);
    arvore = inserir(7, arvore);
    arvore = inserir(3, arvore);
    arvore = inserir(1, arvore);
    
    exibir(arvore, 0);
    printf("A arvore tem %d nos. \n", contarNos(arvore));
    printf("A arvore tem %d nos pares. \n", nosPares(arvore));
    printf("Sequencia visitada em percurso em amplitude ou largura:\n");
    exibirAmp(arvore);

    printf("\n");
    printf("Nivel do no sem algum dos filhos mais baixo: %d.\n", semFilhos(arvore, 0));

    eliminar(arvore);
}
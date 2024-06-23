#include <stdio.h>
#include <stdlib.h>

struct elemento
{
    int valor; /* representa o seriam v�rios campos */
    struct elemento *fdir;
    struct elemento *fesq;
};

struct elemento *localizarPai(int, struct elemento *);

void mostrar(int nivel, struct elemento *arv)
{
    int i;
    for (i = 0; i < nivel; i++)
        printf("   ");
    if (arv)
    {
        printf("%d\n", arv->valor);
        mostrar(nivel + 1, arv->fesq);
        mostrar(nivel + 1, arv->fdir);
    }
    else
        printf("-\n");
}

void eliminar(struct elemento *arv)
{
    if (arv)
    {
        eliminar(arv->fesq);
        eliminar(arv->fdir);
        free(arv);
    }
}

void mostrar2(int nivel, struct elemento *arv)
{
    int i;
    if (arv)
    {
        mostrar2(nivel + 1, arv->fdir);
        for (i = 0; i < nivel; i++)
            printf("   ");
        printf("%d\n", arv->valor);
        mostrar2(nivel + 1, arv->fesq);
    }
    else
    {
        for (i = 0; i < nivel; i++)
            printf("   ");
        printf("-\n");
    }
}

/****************************************************************************************
                       FUNÇÕES DE 02 E 03 JUNHO 2020
****************************************************************************************/

struct elemento *noDeMenorValor(struct elemento *arv)
{
    if (!arv)
        return NULL;
    while (arv->fesq)
        arv = arv->fesq;
    return arv;
}

struct elemento *noDeMaiorValor(struct elemento *arv)
{
    if (!arv)
        return NULL;
    if (arv->fdir)
        return noDeMaiorValor(arv->fdir); /* arv = noDeMaiorValor(arv->fdir); */
    return arv;
}

struct elemento *noValorMaisProximoRaiz(struct elemento *arv)
{
    struct elemento *aMai = NULL, *aMen;
    if (!arv)
        return NULL;
    if (arv->fdir)
    {
        aMai = arv->fdir;
        while (aMai->fesq)
            aMai = aMai->fesq;
    }
    if (!(arv->fesq))
        return aMai;
    aMen = arv->fesq;
    while (aMen->fdir)
        aMen = aMen->fdir;
    if (!aMai)
        return aMen;
    if ((aMai->valor - arv->valor) < (arv->valor - aMen->valor))
        return aMai;
    else
        return aMen;
}

/*
struct elemento *noDeMaiorValor2 (struct elemento *arv) {
  struct elemento *aux;
  if (!arv) return NULL;
  aux = noDeMaiorValor2(arv->fdir);
  if (aux)
    return aux;
  return arv;
  }
  */

struct elemento *eliminarNo(int valor, struct elemento *arv)
{
    struct elemento *pai, *no, *aux;
    pai = localizarPai(valor, arv);
    if (!pai)
    {
        if (arv && arv->valor == valor)
        {
            if (arv->fesq == NULL && arv->fdir == NULL)
            {
                free(arv);
                return NULL;
            }
            else if (arv->fesq == NULL)
            { /* no tem a subarvore da direita */
                no = arv->fdir;
                free(arv);
                return no;
            }
            else if (arv->fdir == NULL)
            { /* no tem a subarvore da esquerda */
                no = arv->fesq;
                free(arv);
                return no;
            }
            else
            { /* tem as duas subarvores */
                no = aux = arv->fesq;
                for (; aux->fdir; aux = aux->fdir)
                    ;
                aux->fdir = arv->fdir;
                free(arv);
                return no;
            }
        }
        else
        {
            return arv;
        }
    }
    else
    { /* foi encontrado um no pai */
        if (pai->valor > valor)
        { /* o no a ser eliminado e filho da esq desse pai */
            no = pai->fesq;
            /* eliminar no folha */
            if (no->fesq == NULL && no->fdir == NULL)
            {
                pai->fesq = NULL;
            }
            /* eliminar no folha com apenas uma subarvore */
            else if (no->fesq == NULL)
            { /* no tem a subarvore da direita */
                pai->fesq = no->fdir;
            }
            else if (no->fdir == NULL)
            { /* no tem a subarvore da esquerda */
                pai->fesq = no->fesq;
            }
            else
            { /* tem as duas subarvores */
                aux = no->fesq;
                pai->fesq = aux;
                for (; aux->fdir; aux = aux->fdir)
                    ;
                aux->fdir = no->fdir;
            }
            free(no);
        }
        else
        { /* o no a ser eliminado e filho da direita */
            no = pai->fdir;
            /* eliminar no folha */
            if (no->fesq == NULL && no->fdir == NULL)
            {
                pai->fdir = NULL;
            }
            /* eliminar no folha com apenas uma subarvore */
            else if (no->fesq == NULL)
            { /* no tem a subarvore da direita */
                pai->fdir = no->fdir;
            }
            else if (no->fdir == NULL)
            { /* no tem a subarvore da esquerda */
                pai->fdir = no->fesq;
            }
            else
            { /* tem as duas subarvores */
                aux = no->fesq;
                pai->fdir = aux;
                for (; aux->fdir; aux = aux->fdir)
                    ;
                aux->fdir = no->fdir;
            }
            free(no);
        }
    }
    return arv;
}

/****************************************************************************************
                       FUNÇÕES DE 27 MAIO 2020
****************************************************************************************/

struct elemento *localizarRec(int valor, struct elemento *arv)
{
    if (!arv)
    {
        return NULL;
    }
    if (arv->valor == valor)
    {
        return arv;
    }
    if (valor >= arv->valor)
    {
        return localizarRec(valor, arv->fdir);
    }
    return localizarRec(valor, arv->fesq);
}

struct elemento *localizarPai(int valor, struct elemento *arv)
{
    if (!arv || arv->valor == valor)
    {
        return NULL;
    }
    while (arv != NULL)
    {
        if (valor >= arv->valor)
        {                                               /* se o valor estiver na arvore, esta na subarvore da direita de arv */
            if (arv->fdir && arv->fdir->valor == valor) /* se a raiz da subarvre (filho) da direita tem o valor procurado */
                return arv;
            arv = arv->fdir;
        }
        else
        {
            if (arv->fesq && arv->fesq->valor == valor)
                return arv;
            arv = arv->fesq;
        }
    }
    return arv;
}

/****************************************************************************************
                       FUNÇÕES DE 26 MAIO 2020
****************************************************************************************/

struct elemento *inserir(int valor, struct elemento *arv)
{
    struct elemento *novo, *raiz;
    novo = (struct elemento *)malloc(sizeof(struct elemento));
    novo->valor = valor;
    novo->fesq = novo->fdir = NULL;
    if (!arv)
    {
        return novo;
    }
    raiz = arv;
    while (novo)
    {
        if (valor >= arv->valor)
        {
            if (arv->fdir)
                arv = arv->fdir;
            else
            {
                arv->fdir = novo;
                novo = NULL;
            }
        }
        else
        {
            if (arv->fesq)
                arv = arv->fesq;
            else
            {
                arv->fesq = novo;
                novo = NULL;
            }
        }
    }
    return raiz;
}

struct elemento *inserirRec(int valor, struct elemento *arv)
{
    struct elemento *novo;
    if (!arv)
    {
        novo = (struct elemento *)malloc(sizeof(struct elemento));
        novo->valor = valor;
        novo->fesq = novo->fdir = NULL;
        return novo;
    }
    if (valor >= arv->valor)
    {
        arv->fdir = inserirRec(valor, arv->fdir);
    }
    else
    {
        arv->fesq = inserirRec(valor, arv->fesq);
    }
    return arv;
}

struct elemento *localizar(int valor, struct elemento *arv)
{
    if (!arv)
    {
        return NULL;
    }
    while (arv != NULL && arv->valor != valor)
    {
        if (valor >= arv->valor)
            arv = arv->fdir;
        else
        {
            arv = arv->fesq;
        }
    }
    return arv;
}

/***************************************************************************************
 *                                  EXERCÍCIOS                                         *
****************************************************************************************/

/*
1. Escreva uma função que receba como parâmetros um ponteiro apontando para a raiz de uma árvore 
binária de pesquisa e dois valores inteiros X e Y. Considere que a árvore não possui valores repetidos. 

A função deve localizar os nós de valor X e Y e, se um não for filho do outro, trocar ambos de lugar. 

A árvore resultante não será uma Árvore Binária de Pesquisa. Se pelo menos um dos elementos não existir, 
ou se um nó for filho do outro, a árvore não deve ser modificada
*/

struct elemento *trocarNos(struct elemento *arv, int x, int y)
{
    struct elemento *aux0 = arv;
    struct elemento *aux1 = localizar(x, arv);
    struct elemento *aux2 = localizar(y, arv);
    struct elemento *aux3;

    if (aux1 && aux2)
    {
        if ((aux1->fesq == aux2) || (aux1->fdir == aux2))
            return 0;
        if ((aux2->fesq == aux1) || (aux2->fdir == aux1))
            return 0;

        aux3->valor = aux2->valor;
        aux2->valor = aux1->valor;
        aux1->valor = aux3->valor;

        return aux0;
    }
    return 0;
}

/*
2.Escreva uma função que receba como parâmetro um ponteiro para a raiz de uma árvore binária de 
pesquisa e retorne um ponteiro para o nó FOLHA de menor valor. 
*/

struct elemento *menorFolha(struct elemento *arv)
{
    if (!arv)
        return NULL;
    while (arv->fesq != NULL)
        arv = arv->fesq;
    if (arv->fdir)
        arv = arv->fdir;
    return arv;
}

int main()
{
    struct elemento *raiz = NULL, *aux;

    raiz = inserir(54, raiz);
    raiz = inserir(25, raiz);
    raiz = inserir(31, raiz);
    raiz = inserir(84, raiz);
    raiz = inserir(89, raiz);
    raiz = inserir(109, raiz);
    raiz = inserir(10, raiz);
    // raiz = inserirRec(112, raiz);
    // raiz = inserirRec(42, raiz);
    // raiz = inserir(5, raiz);
    // raiz = inserir(8, raiz);
    // raiz = inserir(16, raiz);
    // raiz = inserir(39, raiz);
    // raiz = inserir(60, raiz);
    // raiz = inserir(86, raiz);
    // raiz = inserir(85, raiz);
    // raiz = inserir(88, raiz);

    aux = localizar(56, raiz);
    if (aux)
        printf("Valor %d encontrado na arvore.\n", aux->valor);
    else
        printf("Valor 56 nao encontrado na arvore.\n");

    aux = localizar(10, raiz);
    if (aux)
        printf("Valor %d encontrado na arvore.\n", aux->valor);
    else
        printf("Valor 10 nao encontrado na arvore.\n");

    aux = localizarRec(112, raiz);
    if (aux)
        printf("Valor %d encontrado na arvore.\n", aux->valor);
    else
        printf("Valor 112 nao encontrado na arvore.\n");

    aux = localizarRec(11, raiz);
    if (aux)
        printf("Valor %d encontrado na arvore.\n", aux->valor);
    else
        printf("Valor 11 nao encontrado na arvore.\n");

    aux = localizarPai(112, raiz);
    if (aux)
        printf("Valor no pai do no de valor 112 e o no de valor %d.\n", aux->valor);
    else
        printf("Valor 112 nao encontrado na arvore ou nao tem pai por ser a raiz.\n");

    aux = localizarPai(11, raiz);
    if (aux)
        printf("Valor no pai do no de valor 11 e o no de valor %d.\n", aux->valor);
    else
        printf("Valor 11 nao encontrado na arvore ou nao tem pai por ser a raiz.\n");

    aux = localizarPai(54, raiz);
    if (aux)
        printf("Valor no pai do no de valor 54 e o no de valor %d.\n", aux->valor);
    else
        printf("Valor 54 nao encontrado na arvore ou nao tem pai por ser a raiz.\n");

    aux = noDeMenorValor(raiz);
    if (aux)
        printf("O valor do no de menor valor e %d.\n", aux->valor);
    else
        printf("Arvore vazia.\n");

    aux = noDeMaiorValor(raiz);
    if (aux)
        printf("O valor do no de maior valor e %d.\n", aux->valor);
    else
        printf("Arvore vazia.\n");

    aux = noValorMaisProximoRaiz(raiz);
    if (aux)
        printf("O valor do no de valor mais proximo da raiz e %d.\n", aux->valor);
    else
        printf("Arvore vazia.\n");

    raiz = eliminarNo(30, raiz);
    printf("\n");
    printf("=========================================\n");
    //mostrar2(0, raiz);

    raiz = eliminarNo(84, raiz);
    printf("\n");
    printf("=========================================\n");
    //mostrar2(0, raiz);

    raiz = eliminarNo(54, raiz);
    printf("\n");
    printf("=========================================\n");
    //mostrar2(0, raiz);

    printf("\n");
    printf("=========================================\n");

    //mostrar(0, raiz);
    printf("=========================================\n");
    mostrar2(0, raiz);
    printf("=========================================\n");
    aux = menorFolha(raiz);
    if (aux)
        printf("O menor no folha e: %d\n", aux->valor);
    printf("=========================================\n");
    
    trocarNos(raiz, 89, 109);

    mostrar2(0, raiz);
    printf("=========================================\n");

    eliminar(raiz);
}
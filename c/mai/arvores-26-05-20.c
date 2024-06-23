#include <stdio.h>
#include <stdlib.h>

struct elemento
{
    int valor;
    struct elemento *fdir;
    struct elemento *fesq;
};

struct elemento *func(struct elemento *cor)
{
    struct elemento *p1, *p2;
    if (cor)
    {
        if (!cor->fesq && !cor->fdir)
        {
            return cor;
        }
        else
        {
            p1 = func(cor->fesq);
            p2 = func(cor->fdir);
            if (p1 && p2)
            {
                if (p1->valor < p2->valor)
                    return p2;
                else
                    return p1;
            }
            if (p1)
                return p1;
            return p2;
        }
    }
    return NULL;
}

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
                       FUNÇOES DE 26 MAIO 2020
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
/****************************************************************************************
                       FUN��ES DE 27 MAIO 2020
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

/*
Escreva uma função que receba como parâmetros um ponteiro apontando para a raiz de uma árvore 
binária de pesquisa e dois valores inteiros M e N. 

Faça com que a função retorne 1 se existe um nó com valor igual a M no caminho entre a raiz e o 
nó de valor igual a N, 

ou se existe um nó com valor igual a N no caminho entre a raiz e o nó de 
valor igual a M. 

Caso esta situação não ocorra, deve ser retornado 0.
*/

int existeValorNoPercurso(struct elemento *arv, int m, int n)
{
    int valorIntermediario = 0, valorFinal = 0;
    if (!arv)
        return 0;

    while (arv != NULL)
    {
        if (arv->valor == m)
            valorIntermediario = 1;

        if (arv->valor == n)
        {
            valorFinal = 1;
            break;
        }

        if (n >= arv->valor)
            arv = arv->fdir;
        else
            arv = arv->fesq;
    }

    if (valorIntermediario && valorFinal)
        return 1;

    valorIntermediario = 0;
    valorFinal = 0;

    while (arv != NULL)
    {
        if (arv->valor == n)
            valorIntermediario = 1;

        if (arv->valor == m)
        {
            valorFinal = 1;
            break;
        }

        if (m >= arv->valor)
            arv = arv->fdir;
        else
            arv = arv->fesq;
    }

    if (valorIntermediario && valorFinal)
        return 1;
}

int main()
{
    struct elemento *raiz = NULL, *aux;
    int valor1, valor2;
    raiz = inserir(1, raiz);
    raiz = inserir(2, raiz);
    raiz = inserir(4, raiz);
    raiz = inserir(8, raiz);
    raiz = inserir(9, raiz);

    raiz = inserir(5, raiz);
    raiz = inserir(3, raiz);

    raiz = inserir(3, raiz);
    raiz = inserir(16, raiz);
    raiz = inserir(4, raiz);
    raiz = inserir(7, raiz);
    raiz = inserir(7, raiz);
    raiz = inserir(5, raiz);

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

    //mostrar(0, raiz);
    printf("=========================================\n");
    mostrar2(0, raiz);

    valor1 = 54;
    valor2 = 112;
    if (existeValorNoPercurso(raiz, valor1, valor2))
        printf("%d Existe no percurso ate %d ou vice versa\n", valor1, valor2);
    else
        printf("%d nao existe no percurso ate %d, nem vice versa\n", valor1, valor2);

    printf("=========================================\n");

    aux = func(raiz);
    if (aux)
    {
        printf("\n cu dum cu \n %d", aux->valor);
    }
    eliminar(raiz);
}
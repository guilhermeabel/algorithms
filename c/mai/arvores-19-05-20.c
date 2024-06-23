#include <stdio.h>
#include <stdlib.h>

struct elemento
{
    int valor;
    struct elemento *fdir;
    struct elemento *fesq;
};

//  int armazenada[16] = { 0, 10, 2, 3, 47, -1, 6, 7, 58, 9, 10, 11, 12, 103, 14, 15 };
struct elemento *alocar(int no, int armazenada[])
{
    struct elemento *novo;
    if (armazenada[no] != -1 && no < 16)
    {
        novo = (struct elemento *)malloc(sizeof(struct elemento));
        novo->valor = armazenada[no];
        novo->fesq = alocar(no * 2, armazenada);
        novo->fdir = alocar(no * 2 + 1, armazenada);
        return novo;
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

void prefixado(struct elemento *arv)
{
    if (arv)
    {
        // 1 visita a raiz
        printf("%d ", arv->valor);
        // 2 percorre a subarvore da esquerda
        prefixado(arv->fesq);
        // 3 percorre a subarvore da direita
        prefixado(arv->fdir);
    }
}

void central(struct elemento *arv)
{
    if (arv)
    {
        central(arv->fesq);
        printf("%d ", arv->valor);
        central(arv->fdir);
    }
}

void posfixado(struct elemento *arv)
{
    if (arv)
    {
        posfixado(arv->fesq);
        posfixado(arv->fdir);
        printf("%d ", arv->valor);
    }
}

struct elemento *localizar(int valor, struct elemento *arv)
{
    struct elemento *aux;
    if (arv)
    {
        if (arv->valor == valor)
            return arv;
        aux = localizar(valor, arv->fesq);
        if (aux)
            return aux;
        return localizar(valor, arv->fdir);
    }
    return NULL;
}

/****************************************************************************************
                       FUNCOES DE 19 MAIO 2020
****************************************************************************************/

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

void prefixadoCont(int no, int armazenada[])
{
    if (armazenada[no] != -1 && no < 16)
    {
        printf("%d ", armazenada[no]);
        prefixadoCont(no * 2, armazenada);
        prefixadoCont(no * 2 + 1, armazenada);
    }
}

int contaAteNivel(struct elemento *arv, int nivel)
{
    if (!arv)
    {
        return 0;
    }
    if (nivel == 0)
    {
        return 1;
    }
    return 1 + contaAteNivel(arv->fesq, nivel - 1) + contaAteNivel(arv->fdir, nivel - 1);
}

int contaNivelEmDiante(struct elemento *arv, int nivel)
{
    if (!arv)
    {
        return 0;
    }
    if (nivel > 0)
    {
        return contaNivelEmDiante(arv->fesq, nivel - 1) + contaNivelEmDiante(arv->fdir, nivel - 1);
    }
    return 1 + contaNivelEmDiante(arv->fesq, 0) + contaNivelEmDiante(arv->fdir, 0);
}

/****************************************************************************************
                       FUNÇOES DE 20 MAIO 2020
****************************************************************************************/

int contaNosDeUmNivel(struct elemento *arv, int nivel)
{
    if (!arv)
    {
        return 0;
    }
    if (nivel == 0)
    {
        return 1;
    }
    return contaNosDeUmNivel(arv->fesq, nivel - 1) + contaNosDeUmNivel(arv->fdir, nivel - 1);
}

/* somar valores no caminho entre raiz e no folha que � atingido indo sempre pela direita, a menos que so tenha o filho da esquerda */
int somaCaminho(struct elemento *arv)
{
    if (!arv)
    {
        return 0;
    }
    if (arv->fdir)
    {
        return arv->valor + somaCaminho(arv->fdir);
    }
    return arv->valor + somaCaminho(arv->fesq);
}

/* somar valores no caminho entre raiz e no folha que � atingido indo sempre pela direita, a menos que so tenha o filho da esquerda */
int somaCaminho2(struct elemento *arv)
{
    int ac = 0;
    if (!arv)
    {
        return 0;
    }
    while (arv)
    {
        ac = ac + arv->valor;
        if (arv->fdir)
            arv = arv->fdir;
        else
            arv = arv->fesq;
    }
    return ac;
}

/****************************************************************************************
*                                   EXERCICIOS                                          *
****************************************************************************************/
/*
Construa uma função em C que receba como parâmetro um ponteiro apontando para a raiz de uma árvore 
binária e retorne 1 se todo nó não folha dessa árvore tem valor maior que seu(s) filho(s), e 0 caso 
contrário.
*/
int temValorMaior(struct elemento *arv)
{
    if (arv)
    {
        if (!arv->fesq && !arv->fdir)
            return 1;

        if (!(arv->fesq))
        {
            if (arv->fdir->valor > arv->valor)
                return 0;
            return temValorMaior(arv->fdir);
        }

        if (!(arv->fdir))
        {
            if (arv->fesq->valor > arv->valor)
                return 0;
            return temValorMaior(arv->fesq);
        }

        if (arv->fesq && arv->fdir)
        {
            if (arv->fdir->valor > arv->valor)
                return 0;
            return temValorMaior(arv->fdir);
            if (arv->fesq->valor > arv->valor)
                return 0;
            return temValorMaior(arv->fesq);
        }
    }
    return 0;
}
/* 
2. Escreva uma função que receba como parâmetros um ponteiro para a raiz de uma árvore binária e um 
valor inteiro g (cujos valores possíveis são 0, 1 ou 2), e retorne o número de nós da árvore que têm 
grau igual a g.
*/

int grau(struct elemento *arv, int g, int cont)
{
    if (arv)
    {
        if (g == 2)
        {
            if (arv->fesq && arv->fdir)
            {
                cont = grau(arv->fesq, g, cont);
                cont = grau(arv->fdir, g, cont);
                return cont + 1;
            }
        }

        if (g == 0)
        {
            if (!arv->fesq && !arv->fdir)
            {
                return cont + 1;
            }
        }

        if (g == 1)
        {
            if (!arv->fesq && arv->fdir)
            {
                cont = grau(arv->fdir, g, cont);
                return cont + 1;
            }
            if (!arv->fdir && arv->fesq)
            {
                cont = grau(arv->fesq, g, cont);
                return cont + 1;
            }
        }
        if (g == 2)
        {
            return cont;
        }
        if (g < 2)
        {
            return cont + grau(arv->fesq, g, cont) + grau(arv->fdir, g, cont);
        }
    }
    else
        return 0;
}


/* extra */

int retornaNivel(struct elemento *arv, int nivel)
{
    if (arv)
    {
        if (arv->fesq && arv->fdir) // verificar se ambos filhos nao nulos
        {
            if (arv->fdir->valor < arv->fesq->valor) // testar qual o menor
                retornaNivel(arv->fdir, nivel + 1); // acessar e incrementar nivel
            else
                retornaNivel(arv->fesq, nivel + 1); // acessar e incrementar nivel
        }
        else if (!(arv->fesq) && !(arv->fdir)) // verificar se ambos filhos nulos
        {
            return nivel; //se nao ha mais filhos, retornar nivel
        }
        else if (!(arv->fesq)) // verificar se nulo filho 1
        {
            retornaNivel(arv->fdir, nivel + 1); // acessar e incrementar nivel
        }
        else if (!(arv->fdir)) // verificar se nulo filho 2
        {
            retornaNivel(arv->fesq, nivel + 1); // acessar e incrementar nivel
        }
    }
    else
        return 0; // nao ha arvore
}


int main()
{
    int armazenada[16] = {0, 100, 99, 98, 97, -1, 95, 92, 87, 76, 71, 66, 44, 33, 22, 15};
    struct elemento *aux, *raiz = NULL;
    printf("\n\nPre no Vetor: ");
    prefixadoCont(1, armazenada);
    raiz = alocar(1, armazenada);
    printf("\n\nPre: ");
    prefixado(raiz);
    printf("\n\nCentral: ");
    central(raiz);
    printf("\n\nPos: ");
    posfixado(raiz);
    printf("\n\n");

    aux = localizar(47, raiz);
    if (aux)
    {
        printf("Valor localizado: %d\n", aux->valor);
    }
    else
    {
        printf("Valor %d nao existe na arvore\n", 47);
    }

    aux = localizar(103, raiz);
    if (aux)
    {
        printf("Valor localizado: %d\n", aux->valor);
    }
    else
    {
        printf("Valor %d nao existe na arvore\n", 103);
    }

    aux = localizar(105, raiz);
    if (aux)
    {
        printf("Valor localizado: %d\n", aux->valor);
    }
    else
    {
        printf("Valor %d nao existe na arvore\n", 105);
    }

    printf("A arvore tem %d nos de nivel ate %d.\n", contaAteNivel(raiz, 2), 2);

    printf("A arvore tem %d nos do nivel %d ou maior.\n", contaNivelEmDiante(raiz, 2), 2);

    printf("=========================================\n");
    mostrar(0, raiz);
    //mostrar2(0, raiz);
    printf("=========================================\n");
    if (temValorMaior(raiz))
        printf("Existe o padrao\n");
    else
        printf("Nao existe o padrao\n");

    printf("grau 0: %d\n", grau(raiz, 0, 0));
    printf("grau 1: %d\n", grau(raiz, 1, 0));
    printf("grau 2: %d\n", grau(raiz, 2, 0));
    eliminar(raiz);
}
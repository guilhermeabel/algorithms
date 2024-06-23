#include <stdio.h>
#include <stdlib.h>

struct no
{
    int valor;
    struct no *fdir;
    struct no *fesq;
};

int soma(struct no *arv)
{
    int s = 0;
    if (!arv)
        return 0;
    if (arv->fdir)
    {
        s = arv->fdir->valor + soma(arv->fdir);
    }
    if (arv->fesq)
    {
        s = s + soma(arv->fesq);
    }
    return s;
}
struct no *alocar(int no, int armazenada[])
{
    struct no *novo;
    if (armazenada[no] != -1 && no < 16)
    {
        novo = (struct no *)malloc(sizeof(struct no));
        novo->valor = armazenada[no];
        novo->fesq = alocar(no * 2, armazenada);
        novo->fdir = alocar(no * 2 + 1, armazenada);
        return novo;
    }
    return NULL;
}

void mostrar2(int nivel, struct no *arv)
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
int main()
{
    int armazenada[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, -1, 3, -1, 4, 5, 7};
    struct no *raiz = NULL;
    raiz = alocar(1, armazenada);
    mostrar2(0, raiz);
    printf("soma: %d\n", soma(raiz));
}
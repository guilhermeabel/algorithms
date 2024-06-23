#include <stdio.h>
#include <stdlib.h>

struct no {
 int valor;
 struct no *fdir;
 struct no *fesq;
 };

struct no *func(struct no *cor) {
 struct no *p1, *p2;
 if (cor) {
 if (!cor->fesq && !cor->fdir) {
 return cor;
 }
 else {
 p1 = func(cor->fesq);
 p2 = func(cor->fdir);
 if (p1 && p2) {
 if (p1->valor < p2->valor)
 return p2;
 else return p1;
 }
 if (p1) return p1;
 return p2;
 }
 }
 return NULL;
 }

int main (){
    struct no *arv = NULL;
    arv = func(raiz);
    if (arv){
        printf("\n cu dum cu \n %d", arv->valor);
    }
    return 0;
}
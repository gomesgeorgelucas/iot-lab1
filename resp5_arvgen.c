#include <stdio.h>
#include <stdlib.h>

struct arvgen
{
    int info;
    struct arvgen *prim;
    struct arvgen *prox;
};
typedef struct arvgen ArvGen;

ArvGen *cria(int info)
{
    ArvGen *a = (ArvGen *)malloc(sizeof(ArvGen));
    a->info = info;
    a->prim = NULL;
    a->prox = NULL;
    return a;
}

void insere(ArvGen *raiz, ArvGen *filho)
{
    filho->prox = raiz->prim;
    raiz->prim = filho;
}

void libera(ArvGen *a)
{
    ArvGen *p = a->prim;
    while (p != NULL)
    {
        ArvGen *t = p->prox;
        libera(p);
        p = t;
    }
    free(a);
}

void imprime(ArvGen *a)
{
    ArvGen *p;
    printf("%d\n", a->info);
    for (p = a->prim; p != NULL; p = p->prox)
        imprime(p);
}

int busca(ArvGen *a, char c)
{
    ArvGen *p;
    if (a->info == c)
        return 1;
    else
    {
        for (p = a->prim; p != NULL; p = p->prox)
        {
            if (busca(p, c))
                return 1;
        }
    }
    return 0;
}

int main()
{
    ArvGen *raiz = cria(43);
    ArvGen *filho1 = cria(22);
    ArvGen *filho2 = cria(21);
    ArvGen *filho3 = cria(58);
    ArvGen *filho4 = cria(45);

    ArvGen *neto11 = cria(66);
    ArvGen *neto12 = cria(31);
    ArvGen *neto31 = cria(71);
    ArvGen *neto32 = cria(59);
    ArvGen *neto33 = cria(12);
    ArvGen *neto41 = cria(35);

    insere(filho1, neto12);
    insere(filho1, neto11);

    insere(filho3, neto33);
    insere(filho3, neto32);
    insere(filho3, neto31);

    insere(filho4, neto41);

    insere(raiz, filho4);
    insere(raiz, filho3);
    insere(raiz, filho2);
    insere(raiz, filho1);

    imprime(raiz);

    if (busca(raiz, 12))
        printf("Encontrou 12\n");
    else
        printf("Nao encontrou 12\n");

    if (busca(raiz, 88))
        printf("Encontrou 88\n");
    else
        printf("Nao encontrou 88\n");

    libera(raiz);
}

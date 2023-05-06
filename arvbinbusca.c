#include <stdio.h>
#include <stdlib.h>

struct arv
{
    int info;
    struct arv *esq;
    struct arv *dir;
};

typedef struct arv Arv;

int vazia(const Arv *a)
{
    return a == NULL;
}

Arv *busca(Arv *r, int v)
{
    if (r == NULL)
        return NULL;
    else if (r->info > v)
        return busca(r->esq, v);
    else if (r->info < v)
        return busca(r->dir, v);
    else
        return r;
}

Arv *insere(Arv *a, int v)
{
    if (a == NULL)
    {
        a = (Arv *)malloc(sizeof(Arv));
        a->info = v;
        a->esq = a->dir = NULL;
    }
    else if (v < a->info)
        a->esq = insere(a->esq, v);
    else /* v < a->info */
        a->dir = insere(a->dir, v);
    return a;
}

Arv *libera(Arv *a)
{
    if (!vazia(a))
    {
        libera(a->esq); /* libera sae */
        libera(a->dir); /* libera sad */
        free(a);        /* libera raiz */
    }
    return NULL;
}

void imprime_in(Arv *r)
{
    if (!vazia(r))
    {
        imprime_in(r->esq);
        printf("%d ", r->info);
        imprime_in(r->dir);
    }
}

void main(void)
{
    Arv *raiz;

    raiz = insere(raiz, 1);
    imprime_in(raiz);
    printf("\n");
    raiz = insere(raiz, 2);
    imprime_in(raiz);
    printf("\n");
    raiz = insere(raiz, 3);
    imprime_in(raiz);
    printf("\n");
    raiz = insere(raiz, 5);
    imprime_in(raiz);
    printf("\n");
    raiz = insere(raiz, 15);
    imprime_in(raiz);
    printf("\n");
    raiz = insere(raiz, 7);
    imprime_in(raiz);
    printf("\n");

    if (busca(raiz, 2) != NULL)
        printf("O valor 2 foi encontrado.\n");
    else
        printf("O valor 2 nao foi encontrado.\n");

    if (busca(raiz, 8) != NULL)
        printf("O valor 8 foi encontrado.\n");
    else
        printf("O valor 8 nao foi encontrado.\n");

    libera(raiz);
}

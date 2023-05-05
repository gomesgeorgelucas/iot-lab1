#include <stdio.h>
#include <stdlib.h>

struct arv
{
    int info;
    struct arv *esq;
    struct arv *dir;
};

typedef struct arv Arv;

Arv *inicializa(void)
{
    return NULL;
}

Arv *cria(int c, Arv *sae, Arv *sad)
{
    Arv *p = (Arv *)malloc(sizeof(Arv));
    p->info = c;
    p->esq = sae;
    p->dir = sad;
    return p;
}

int vazia(const Arv *a)
{
    return a == NULL;
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

void imprime_pre(Arv *a)
{
    if (!vazia(a))
    {
        printf("%d ", a->info); /* mostra raiz */
        imprime_pre(a->esq);    /* mostra sae */
        imprime_pre(a->dir);    /* mostra sad */
    }
}

void imprime_in(Arv *a)
{
    if (!vazia(a))
    {
        imprime_in(a->esq);     /* mostra sae */
        printf("%d ", a->info); /* mostra raiz */
        imprime_in(a->dir);     /* mostra sad */
    }
}

void imprime_pos(Arv *a)
{
    if (!vazia(a))
    {
        imprime_pos(a->esq);
        imprime_pos(a->dir);
        printf("%d ", a->info);
    }
}

int main()
{
    Arv *exemplo2 = cria(45,
                         cria(5,
                              cria(12, inicializa(), inicializa()),
                              cria(34, inicializa(),
                                   cria(67, inicializa(), inicializa()))),
                         cria(80, inicializa(),
                              cria(40, inicializa(), inicializa())));
    printf("Pre-Fixado: ");
    imprime_pre(exemplo2);
    printf("\nIn-Fixado: ");
    imprime_in(exemplo2);
    printf("\nPos-Fixado: ");
    imprime_pos(exemplo2);
    printf("\n");

    printf("Realiza Enxerto\n");

    exemplo2->dir->esq = cria(3, cria(66, inicializa(), inicializa()), cria(31, inicializa(), inicializa()));

    printf("Pre-Fixado: ");
    imprime_pre(exemplo2);
    printf("\nIn-Fixado: ");
    imprime_in(exemplo2);
    printf("\nPos-Fixado: ");
    imprime_pos(exemplo2);
    printf("\n");

    return 0;
}

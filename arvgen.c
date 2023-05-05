#include <stdio.h>
#include <stdlib.h>

struct arvgen {
  int info;
  struct arvgen *prim;
  struct arvgen *prox;
};
typedef struct arvgen ArvGen;


ArvGen* cria (int info)
{
  ArvGen *a =(ArvGen *)malloc(sizeof(ArvGen));
  a->info = info;
  a->prim = NULL;
  a->prox = NULL;
  return a;
}

void insere (ArvGen* a, ArvGen* f)
{
  f->prox = a->prim;
  a->prim = f;
}



void libera (ArvGen* a)
{
  ArvGen* p = a->prim;
  while (p!=NULL) {
    ArvGen* t = p->prox;
    libera(p);
    p = t;
  }
  free(a);
}

void imprime (ArvGen* a)
{
  ArvGen* p;
  printf("%d\n",a->info);
  for (p=a->prim; p!=NULL; p=p->prox)
    imprime(p);
}

int busca (ArvGen* a, char c)
{
  ArvGen* p;
  if (a->info==c)
    return 1;
  else {
    for (p=a->prim; p!=NULL; p=p->prox) {
      if (busca(p,c))
        return 1;
    }
  }
  return 0;
}

int main()
{
	
}

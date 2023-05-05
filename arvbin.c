#include <stdio.h>
#include <stdlib.h>

struct arv {
  int info;
  struct arv* esq;
  struct arv* dir;
};

typedef struct arv Arv;

Arv* inicializa(void)
{
  return NULL;
}

Arv* cria(int c, Arv* sae, Arv* sad)
{
  Arv* p=(Arv*)malloc(sizeof(Arv));
  p->info = c;
  p->esq = sae;
  p->dir = sad;
  return p;
}

int vazia(Arv* a)
{
  return a==NULL;
}

Arv* libera (Arv* a){
  if (!vazia(a)){
    libera(a->esq); /* libera sae */
    libera(a->dir); /* libera sad */
    free(a); /* libera raiz */
  }
  return NULL;
}

void imprime_pre (Arv* a)
{

}

void imprime_in (Arv* a)
{

}

void imprime_pos (Arv* a)
{

}

int main()
{
	
}

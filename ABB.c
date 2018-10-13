#include <stdio.h>
#include <stdlib.h>

struct no{
  int val;
  struct no *esq;
  struct no *dir;
};typedef struct no no;

struct no* NovoNo(int val){

  struct no* no = (struct no*)malloc(sizeof(struct no));

  no->val = val;
  no->dir = NULL;
  no->esq = NULL;

  return(no);
};

void pre_ordem(no *raiz);
void em_ordem(no *raiz);
void pos_ordem(no *raiz);
int busca_binaria(no *ABB, int valor);
void insere_ABB_recursivo(no *ABB, int valor);
int tam_ABB_v2;
int chaves_ABB_v2[5];

void pre_ordem(no *raiz){
  if(raiz == NULL){
    return;
  }
  printf("%d -", raiz->val);
  pre_ordem(raiz->esq);
  pre_ordem(raiz->dir);
}


void em_ordem(no *raiz){
  if(raiz == NULL){
    return;
  }
  em_ordem(raiz->esq);
  printf("%d -", raiz->val);
  em_ordem(raiz->dir);
}


void pos_ordem(no *raiz){
  if(raiz == NULL){
    return;
  }
  pos_ordem(raiz->esq);
  pos_ordem(raiz->dir);
  printf("%d -", raiz->val);
  
}

int busca_binaria(no *ABB, int valor){


   if(ABB->val == valor){
    return 1;
  }else if(ABB->val > valor){
    if(ABB->esq !=NULL){
      busca_binaria(ABB->esq, valor);
    }else{
      return 0;
    }
  }else if(ABB->val < valor){
    if(ABB->dir != NULL){
      busca_binaria(ABB->dir, valor);
    }else{
      return 0;
    }
  }
}

void insere_ABB_recursivo(no *ABB, int valor){
  if(ABB->val > valor){
    if(ABB->esq !=NULL){
      insere_ABB_recursivo(ABB->esq, valor);
    }else{
      ABB->esq = NovoNo(valor);
    }
  }else{
    if(ABB->dir != NULL){
      insere_ABB_recursivo(ABB->dir, valor);
    }else{
      ABB->dir = NovoNo(valor);
    }
  }
}


int main(void) {
  //Preenche árvore
  struct no *raiz = NovoNo(1);

  raiz->esq = NovoNo(2);
  raiz->dir = NovoNo(3);

  raiz->esq->esq = NovoNo(4);
  raiz->esq->dir = NovoNo(5);

  raiz->dir->esq = NovoNo(6);
  raiz->dir->dir = NovoNo(7);
 //
  printf("Imprime pre-ordem \n");
  pre_ordem(raiz);
  printf("\n");

  printf("Imprime em ordem \n");
  em_ordem(raiz);
  printf("\n");

  printf("Imprime pos-ordem \n");
  pos_ordem(raiz);
  printf("\n");

//ABB
  //construindo arvore
  struct no *ABB = NovoNo(3);

  ABB->esq =  NovoNo(1);
  ABB->dir =  NovoNo(7);

  ABB->esq->dir =  NovoNo(2);
  ABB->dir->esq =  NovoNo(5);

  ABB->dir->esq->esq =  NovoNo(4);
  ABB->dir->esq->dir =  NovoNo(6);
  //
  printf("Chegando árvore ABB \n");
  pre_ordem(ABB);
//
  if(busca_binaria(ABB, 9)){
    printf("\n Elemento ja existe");
  }else{
    insere_ABB_recursivo(ABB,9);
  }
  printf("\n");
  pre_ordem(ABB);

  struct no *ABB_v2 = NovoNo(5);
  int tam_ABB_v2 = 6;
  int chaves_ABB_v2[6] = {6,2,1,3,8,7};


  for(int i=0; i<=tam_ABB_v2 -1; i++){
    if(busca_binaria(ABB_v2, chaves_ABB_v2[i])){
    printf("\n Elemento ja existe");
    }else{
    insere_ABB_recursivo(ABB_v2,chaves_ABB_v2[i]);
    }
  }

  printf("\n");
  pre_ordem(ABB_v2);


}